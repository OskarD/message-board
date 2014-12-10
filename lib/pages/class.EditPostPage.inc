<?php
	require_once 'lib/class.Page.inc';

	class EditPostPage extends Page {
		private
			$post;

		public function setPost(Post $post) {
			$this->post = $post;
		}

		public function getPost() {
			return $this->post;
		}

		function __construct($postId, $compress = true) {
			parent::__construct("Edit post", $compress);
			$this->loadPost($postId);
		}

		public function loadPost($postId) {
			$this->setPost(Post::getPostById($postId));
		}

		public function getHTMLPage() {
			$topic = $this->getPost()->getTopic();
			$topic = Topic::getTopicWithId($topic);

			$output = "
				<div class='edit_post'>
					<h2>Edit Post on topic: " . $topic->getHTMLLinkedName() . " </h2>
					<form action='update_post.php' method='post'>
						Text:<br />
						<textarea id='text' name='text' rows='20' cols='88'>" . $this->getPost()->getText() . "</textarea><br />
						<button class='btn' type='submit' id='submit' name='submit'>Save</button>
						<input type='hidden' id='post_id' name='post_id' value='" . $this->getPost()->getId() . "' />
						<input type='hidden' id='topic_id' name='topic_id' value='" . $topic->getId() . "' />
					</form>
				</div>";

			return $output;
		}
	}
?>