<?php
	require_once 'lib/class.Topic.inc';
	require_once 'lib/class.WebUser.inc';

	$insertedId = Topic::create($_POST['table_id'], $_POST['name'], $_POST['text'], WebUser::getUserId());

	header('Location: view_topic.php?topic_id=' . $insertedId);
?>