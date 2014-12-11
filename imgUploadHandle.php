<?php
	require_once 'lib/class.DB.inc';

/*
  This page takes the uploaded image and (1) resizes it, (2) determines filesizes of resizing, (3) saves into mySQL database
  Other Notes: If you need to accept images greater than 10MB and you are running into issues where the image will not upload, you can (1) modify the php.ini file to accept a greater filesize, (2) modify the .htaccess file in the root of your website to include something such as "php_value upload_max_filesize 100M" and "php_value post_max_size 101M"
  Author: Joe McCormack
  Site: www.virtualsecrets.com

  Changes by Oskar:
  - Stripped code for larger resizes, only need size 100
  - Implemented workspace database functionality
  - Fixed debugging messages
  - Added user updating
*/
$imgStoreLocation = "tmp/";	/* Location on your website where re-sized images are temporarily stored so that their file sizes can be determined */
$imgMaxFileSize = 9765;							/* Maximum filesize to accept (10MB): 10,000,000 / 1024 = 9765  */

define("MAX_SIZE", $imgMaxFileSize);
$error_status = 0;
$error_message = "";
$img_mime_type = "";
$img_100_height = 0;
$img_100_size = 0;
$img_300_height = 0;
$img_300_size = 0;
$img_1024_height = 0;
$img_1024_size = 0;

/*
  FUNCTION TO STORE RESIZED IMAGES INTO MYSQL DATABASE TABLE
  NOTE: The example database table could be represented as --
	CREATE TABLE imgUploadTbl (
	imgID INT NOT NULL AUTO_INCREMENT
	, imgCreatedOn DATETIME NOT NULL
	, imgUpdatedOn TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
	, imgDimension VARCHAR(100) NOT NULL
	, imgMime VARCHAR(255) NOT NULL
	, imgSize INT NOT NULL
	, imgData LONGBLOB NOT NULL
	, PRIMARY KEY(imgID))
*/
function userImgUploadAccept($imgDimension, $imgMime, $imgSize, $imgData) {
	$status = "success";
	$mySQLDatabaseTableName = "imguploadtbl";
	// Setup connection
	$connDB = DB::getDb();
	// Add the resized image
	try {
	     // Query
	     $statement = $connDB->prepare("INSERT INTO $mySQLDatabaseTableName (imgDimension, imgMime, imgSize, imgData) values (:imgDimension, :imgMime, :imgSize, :imgData)");
	     // Assign and execute query
	     $statement->bindParam(':imgDimension', $imgDimension);
	     $statement->bindParam(':imgMime', $imgMime);
	     $statement->bindParam(':imgSize', $imgSize);
	     $statement->bindParam(':imgData', $imgData);
	     $statement->execute();
	    }
	catch(PDOException $e) { $status = $e->getMessage(); print $status; }

	// Update user
	$insertedId = $connDB->lastInsertId();
	$stmt = $connDB->prepare("UPDATE users SET avatar = :avatar WHERE id = :user_id");
	$stmt->bindParam(':avatar', $insertedId);
	$stmt->bindParam(':user_id', $_POST['user_id']);
	$stmt->execute();

	//Close the connection
	$connDB = null;
	return $status;
}

/*
  ACCEPT FILE UPLOAD
*/
$image = $_FILES["image"]["name"];
$uploadedfile = $_FILES['image']['tmp_name'];
if ($image) {
	     $filename = stripslashes($_FILES['image']['name']);

	     /* Ensure the file is JPG/PNG */
	     if (($_FILES['image']['type'] != "image/jpg") && ($_FILES['image']['type'] != "image/jpeg") && ($_FILES['image']['type'] != "image/png")) { $error_status = 2; $error_message = "File uploaded was not a JPG or PNG file."; }  
	     else {
		   /* Ensure the file is less than 10MB */
		   $size = filesize($_FILES['image']['tmp_name']);
		   if ($size > (MAX_SIZE * 1024)) { $error_status = 3; $error_message = "File uploaded needs to be less than 10MB."; }
		   else {
			 $extension = "jpg";
			 if(($_FILES['image']['type'] == "image/jpg") || ($_FILES['image']['type'] == "image/jpeg")) { $uploadedfile = $_FILES['image']['tmp_name']; $src = imagecreatefromjpeg($uploadedfile); }
			 else if (($_FILES['image']['type'] == "image/png")) { $extension = "png"; $uploadedfile = $_FILES['image']['tmp_name']; $src = imagecreatefrompng($uploadedfile); }
			 $img_mime_type = $_FILES['image']['type'];

			 /* Get original dimensions of the image */
			 list($width, $height) = getimagesize($uploadedfile);

			 /* Resize the original image to 100, 300, 1020 */
			 /* Resize 1 */
			 $img_100_height = ($height / $width) * 100;
			 $img_100_tmp = imagecreatetruecolor(100, $img_100_height); 
			 imagecopyresampled($img_100_tmp, $src, 0, 0, 0, 0, 100, $img_100_height, $width, $height);
			 ob_start(); if ($extension == "jpg") { imagejpeg($img_100_tmp); } else { imagepng($img_100_tmp); } $img_100_tmpStream = ob_get_contents(); ob_end_clean();

			 /* Resize 2 */
			 //$img_300_height = ($height / $width) * 300;
			 //$img_300_tmp = imagecreatetruecolor(300, $img_300_height);
			 //imagecopyresampled($img_300_tmp, $src, 0, 0, 0, 0, 300, $img_300_height, $width, $height);
			 //ob_start(); if ($extension == "jpg") { imagejpeg($img_300_tmp); } else { imagepng($img_300_tmp); } $img_300_tmpStream = ob_get_contents(); ob_end_clean();

			 /* Resize 3 */
			 /* Note: Resizing does not work if on a byte-boundary such as 1024; so use a somewhat smaller number that is not on a byte-boundary */
			 //$img_1024_height = ($height / $width) * 1020;
			 //$img_1024_tmp = imagecreatetruecolor(1020, $img_1024_height);
			 //imagecopyresampled($img_1024_tmp, $src, 0, 0, 0, 0, 1020, $img_1024_height, $width, $height);
			 //ob_start(); if ($extension == "jpg") { imagejpeg($img_1024_tmp); } else { imagepng($img_1024_tmp); } $img_1024_tmpStream = ob_get_contents(); ob_end_clean();

			 /* Get file sizes of the resized images by temporarily dumping them to the filesystem */
			 $today = date("YmdHis"); $physicalPath = $imgStoreLocation . $today;

			 /* Temporarily save images to the filesystem */
			 if ($extension == "jpg") {
			 			   imagejpeg($img_100_tmp, $physicalPath . "_100." . $extension);
			 			   //imagejpeg($img_300_tmp, $physicalPath . "_300." . $extension);
			 			   //imagejpeg($img_1024_tmp, $physicalPath . "_1024." . $extension);
			 			  }
			 else {
			       imagepng($img_100_tmp, $physicalPath . "_100." . $extension);
			       //imagepng($img_300_tmp, $physicalPath . "_300." . $extension);
			       //imagepng($img_1024_tmp, $physicalPath . "_1024." . $extension);
			      }

			 /* Get image sizes in bytes */
			 $img_100_size = filesize($physicalPath . "_100." . $extension);
			 //$img_300_size = filesize($physicalPath . "_300." . $extension);
			 //$img_1024_size = filesize($physicalPath . "_1024." . $extension);

			 /* Remove files from filesystem */
			 unlink($physicalPath . "_100." . $extension);
			 //unlink($physicalPath . "_300." . $extension);
			 //unlink($physicalPath . "_1024." . $extension);

			 /* Save resized images to database */
			 $status = userImgUploadAccept(100, $img_mime_type, $img_100_size, $img_100_tmpStream);
			 //if ($status == "success") { $status = userImgUploadAccept(300, $img_mime_type, $img_300_size, $img_300_tmpStream); }
			 //if ($status == "success") { $status = userImgUploadAccept(1024, $img_mime_type, $img_1024_size, $img_1024_tmpStream); }
			 if ($status != "success") {
						    $error_status = 4;
						    $error_message = "There was a problem adding resized images to the database.";
						   }
			 /* Free up memory */
			 imagedestroy($src);
			 imagedestroy($img_100_tmp);
			 //imagedestroy($img_300_tmp);
			 //imagedestroy($img_1024_tmp);
			}
		  }
	    }
else { $error_status = 1; $error_message = "There was a problem with the file being uploaded."; }

/*
  PAGE OUTPUT
*/
print "<html><head>\n";
print "<title>Image Upload Status</title>\n";
print "</head><body>\n";
if($error_status != 0)
	print $error_status . " " . $error_message;
else
	header("Location: view_user.php?user_id=" . $_POST['user_id']);
print "</body>\n";
print "</html>\n";
exit;
?>