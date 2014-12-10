<?php
	require_once 'lib/pages/class.EditPostPage.inc';

	$page = new EditPostPage($_GET['post_id']);
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();

		print $page->getHTMLPage();
	?>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>