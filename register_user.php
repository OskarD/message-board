<?php
	require_once 'lib/class.WebUser.inc';

	echo json_encode( array ('success_result' => WebUser::register($_POST['username'], $_POST['password'], $_POST['email']) ) );
?>