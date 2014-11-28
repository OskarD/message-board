<?php
	require_once 'lib/class.WebUser.inc';
	WebUser::logOut();
	header('Location: index.php');
?>