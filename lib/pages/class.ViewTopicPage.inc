<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.DB.inc';

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
			$output = "<div class='topic'><h2>View Topic: " . $this->getTopic()->getName() . "</h2>";

			$output .= "<div class='topic_subject'>Subject: " . $this->getTopic()->getHTMLLinkedName() . "</div>";
			
			$topicCreator = $this->topic->getTopicCreator();

			$output .= "<div class='topic_created'>Created by: " . $topicCreator->getName() . " at " . $this->getTopic()->getDate() . "</div>";

			$output .= "<div class='topic_posts'>";

			foreach($this->getPosts() as $post) {
				$output .= "<div class='post'>
								<div class='post_info'>Post by: " . $post->getCreator()->getName() . " at " . $post->getDate() . "</div>
								<div class='post_text'>" . $post->getText() . "</div>";
			}

			$output .= "</div>";

			return $output . "</div>";
		}
	}
?>