<?php
	require_once 'lib/class.Post.inc';

	Post::dbUpdate($_POST['post_id'], $_POST['text']);

	header('Location: view_topic.php?topic_id=' . $_POST['topic_id']);
?>