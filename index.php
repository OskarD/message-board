<?php
	require_once 'lib/pages/class.IndexPage.inc';

	$page = new IndexPage("Home");
	print $page->getHead();
?>
<body>
	<?php
		print $page->getHeader();
	?>

	<div class="body">
		<h2>Home</h2><br />
		<p>Welcome to my forums!</p><br />
		<p>Feel free to register in order to make new topics and reply to posts.</p><br />
		<p>All passwords are encrypted before they are transmitted anywhere.</p><br />
		<p>You can find the source of this page at <a class='bold' target='_blank' href="https://bitbucket.org/OskarD/message-board">Bitbucket here</a>.</p><br />
		<p>You can also visit my regular website at: <a class='bold' href="http://www.OskarD.me/">www.OskarD.me</a></p><br /><br />
		<p>NEW: Now there is also an, although very basic, Android app available for this forum! <a class='bold' href='https://play.google.com/store/apps/details?id=me.oskard.finalproject'>Get it here!</a></p>
	</div>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>