<?php
	require_once 'lib/pages/class.ViewUserPage.inc';

	$page = new ViewUserPage($_GET['user_id']);
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();

		print $page->getUserHTMLProfile();
	?>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>