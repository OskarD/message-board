<?php
	require_once 'lib/pages/class.ViewTopicPage.inc';

	$page = new ViewTopicPage($_GET['topic_id']);
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();

		print $page->getTopicHTML();
	?>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>