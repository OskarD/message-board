<?php
	require_once 'lib/pages/class.IndexPage.inc';

	$page = new IndexPage("Home");
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();
	?>

	<div class="body"><h2>Home</h2>This is the body area</div>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>