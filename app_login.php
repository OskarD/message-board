<?php
	header('Content-Type: application/json');

	require_once 'lib/class.AppUser.inc';

	if(isset($_GET['name'])) {
		$user = AppUser::getByName($_GET['name']);

		$array = array(
			'id'			=> $user->getId(),
			'name' 			=> $user->getName(),
			'loginString' 	=> $user->getLoginString(),
			'email'			=> $user->getEmail(),
			'defaultGroup' 	=> $user->getDefaultGroup()
		);

		print json_encode($array);
	}
?>