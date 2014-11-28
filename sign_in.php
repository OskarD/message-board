<?php
	require_once 'lib/pages/class.SignInPage.inc';

	$page = new SignInPage("Sign In");
	print $page->getHead("<script src='js/md5.js'></script>
						<script src='js/signin_script.js'></script>", true);
?>
<body>
	<?php
		print $page->getHeader();
	?>

	<div class='sign_in_view'>
		<h2>Sign In</h2>
		<form id='form_sign_in' method='post' action="index.php">
			Username<br />
			<input type='text' id='username' name='username' required /><br />
			Password<br />
			<input type='password' id='password' name='password' required /><br />
			<button type="submit" id='submit' name='submit'>Sign in</button>
		</form>
	</div>

	<div class='result'></div>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>