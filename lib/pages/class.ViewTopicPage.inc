<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.DB.inc';
	require_once 'lib/class.WebUser.inc';

	class ViewTopicPage extends Page {
		private
			$topic,
			$posts = array(),
			$table;

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

		public function setTable(Table $table) {
			$this->table = $table;
		}

		public function getTable() {
			if(!isset($this->table))
				$this->table = Table::getTableById($this->topic->getTable());

			return $this->table;
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
				<div class='view_topic'><h2><a href='forum_index.php'>Forum</a> <span class='right_arrow'></span> " . $this->getTable()->getHTMLLinkedName(). " <span class='right_arrow'></span> " . $this->getTopic()->getHTMLLinkedName() . "</h2>";

			$output .= "
					<div class='view_topic_thread_info'>
						<div class='view_topic_subject'>
							Subject: " . $this->getTopic()->getHTMLLinkedName() . "
						</div>";
			
			$topicCreator = $this->topic->getTopicCreator();

			$output .= "
						<div class='view_topic_created'>
							Created by: <span class='bold'>" . $topicCreator->getHTMLLinkedName() . "</span> at " . $this->getTopic()->getDate() . "
						</div>
					</div>";

			$output .= "
					<div class='view_topic_posts'>";

			foreach($this->getPosts() as $post) {
				$creator = $post->getCreator();

				$output .= "
						<div class='view_topic_post inner_container'>
							<div class='view_topic_post_info'>
								<span class='post_creator'>" . $creator->getHTMLLinkedName() . "</span><span class='post_date'> at " . $post->getDate() . "</span>";

				if(WebUser::isLoggedIn() && WebUser::getUserId() == $creator->getId()) {
					$output .= "<span class='stick_right'><a href='edit_post.php?post_id=" . $post->getId() . "'><span class='btn'>Edit</span></a></span>";
				}

				$output .= "
							</div>
							<div class='view_topic_post_text'>
								" . Post::formatText($post->getText()) . "
							</div>
						</div>";
			}

			$output .= "
					</div>";

			if(WebUser::isLoggedIn()) {
				$output .= "
					<div class='view_topic_new_post'>
						<h3>Reply</h3>
						<form id='post_reply' action='post_reply.php' method='post'>
							<textarea id='text' name='text' rows='20' cols='88'></textarea><br />
							<button class='btn' type='submit'>Post Reply</button>
							<input type='hidden' id='topic_id' name='topic_id' value='" . $this->getTopic()->getId() . "' />
						</form>
					</div>";
			}

			return $output . "
					</div>";
		}
	}
?>