<?php
	require_once 'lib/pages/class.UsersPage.inc';
	require_once 'lib/class.DB.inc';

	$page = new UsersPage("Home");
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();
	?>

	<div class="body">
		<?php
			print $page->getUserHTMLList();
		?>
	</div>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>