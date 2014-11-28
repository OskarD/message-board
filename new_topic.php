<?php
	require_once 'lib/pages/class.NewTopicPage.inc';

	$page = new NewTopicPage("New Topic", $_GET['table']);
	print $page->getHead("<script src='js/create_topic_script.js'></script>");
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