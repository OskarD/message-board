<?php
	require_once 'lib/pages/class.XPage.inc';

	$page = new XPage("Home");
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();
	?>

	<div class="body">This is the body area</div>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>