<?php
	require_once 'lib/class.WebUser.inc';

	if(isset($_GET['name'], $_GET['email'], $_GET['password'])) {
		WebUser::register($_GET['name'], $_GET['password'], $_GET['email']);
		print "Registered.";
	}
	else
		"Nothing to do here..."
?>