<?php
	require_once 'lib/pages/class.ForumIndexPage.inc';
	$page = new ForumIndexPage("Home",false);
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();

		print $page->getForumHTMLOverview();
	?>

	

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>