<?php
	require_once 'lib/pages/class.ViewTablePage.inc';

	$page = new ViewTablePage($_GET['table_id']);
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();

		print $page->getTableHTMLView();
	?>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>