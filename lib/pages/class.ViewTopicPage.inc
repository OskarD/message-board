<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.DB.inc';
	require_once 'lib/class.WebUser.inc';

	class ViewTopicPage extends Page {
		private
			$topic,
			$posts = array();

		public function setTopic(Topic $topic) {
			$this->topic = $topic;
		}

		public function getTopic() {
			return $this->topic;
		}

		public function addPost(Post $post) {
			$this->posts[] = $post;
		}

		public function setPosts(array $posts) {
			foreach($posts as $post) {
				$this->addPost($post);
			}
		}

		public function getPosts() {
			return $this->posts;
		}

		function __construct($topicId, $compress = false) {
			parent::__construct("To be replaced", $compress);
			$this->loadTopic($topicId);
			$this->setTitle("View Topic: " . $this->getTopic()->getName());
			$this->loadPosts();
		}

		public function loadTopic($topicId) {
			$this->setTopic(Topic::getTopicWithId($topicId));
		}

		public function loadPosts() {
			$this->setPosts($this->topic->loadPosts());
		}

		public function getTopicHTML() {
			$output = "
				<div class='view_topic'><h2>View Topic: " . $this->getTopic()->getName() . "</h2>";

			$output .= "
					<div class='view_topic_subject'>Subject: " . $this->getTopic()->getHTMLLinkedName() . "</div>";
			
			$topicCreator = $this->topic->getTopicCreator();

			$output .= "
					<div class='view_topic_created'>Created by: " . $topicCreator->getName() . " at " . $this->getTopic()->getDate() . "</div>";

			$output .= "
					<div class='view_topic_posts'>";

			foreach($this->getPosts() as $post) {
				$output .= "
						<div class='view_topic_post'>
							<div class='view_topic_post_info'>Post by: " . $post->getCreator()->getHTMLLinkedName() . " at " . $post->getDate() . "</div>
							<div class='view_topic_post_text'>" . $post->getText() . "</div>
						</div>";
			}

			$output .= "
					</div>";

			if(WebUser::isLoggedIn()) {
				$output .= "
					<div class='view_topic_new_post'>
						<h3>Reply</h3>
						<form id='post_reply' action='post_reply.php' method='post'>
							<textarea id='text' name='text' rows='20' cols='80'></textarea><br />
							<button type='submit'>Post Reply</button>
							<input type='hidden' id='topic_id' name='topic_id' value='" . $this->getTopic()->getId() . "' />
						</form>
					</div>";
			}

			return $output . "
					</div>";
		}
	}
?>