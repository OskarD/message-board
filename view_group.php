<?php
	require_once 'lib/pages/class.ViewGroupPage.inc';

	$page = new ViewGroupPage($_GET['group_id']);
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();

		print $page->getGroupHTMLPage();
	?>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>