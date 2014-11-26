<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.DB.inc';

	class ViewTopicPage extends Page {
		private
			$topic,
			$posts = array();

		public function setTopic($topic) {
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
			$this->setTopic(DB::getTopicWithId($topicId));
		}

		public function loadPosts() {
			$this->setPosts(DB::getPostsWithTopicId($this->getTopic()->getId()));
		}

		public function getTopicHTML() {
			$output = "<div class='topic'><h2>View Topic: " . $this->getTopic()->getName() . "</h2>";


			return $output . "</div>";
		}
	}
?>