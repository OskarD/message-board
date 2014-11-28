<?php
	require_once 'lib/class.GlobalFunctions.inc';

	if (GlobalFunctions::isAjax()) {
		require_once 'lib/class.WebUser.inc';

		echo json_encode( 
			array(
				'success_state' => WebUser::verifyUserPasswordCombination($_POST['username'], $_POST['password']) 
				,'debug_message' => 'Checked user: ' . $_POST['username'] . ' and password: ' . $_POST['password'] 
			) 
		);
	}
?>