<?php
	require_once 'lib/class.Post.inc';
	require_once 'lib/class.WebUser.inc';

	Post::create($_POST['topic_id'], WebUser::getUserId(), $_POST['text']);

	header('Location: view_topic.php?topic_id=' . $_POST['topic_id']);
?>