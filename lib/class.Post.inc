<?php
	require_once 'class.Topic.inc';
	require_once 'class.DB.inc';

	class Post {
		private
			$id,
			$date,
			$topic,
			$userId,
			$text;

		public function setId($id) {
			$this->id = $id;
		}

		public function getId() {
			return $this->id;
		}

		public function setDate($date) {
			$this->date = $date;
		}

		public function getDate() {
			return $this->date;
		}

		public function setTopic($topic) {
			$this->topic = $topic;
		}

		public function getTopic() {
			return $this->topic;
		}

		public function setUserId($userId) {
			$this->userId = $userId;
		}

		public function getUserId() {
			return $this->userId;
		}

		public function setText($text) {
			$this->text = $text;
		}

		public function getText() {
			return $this->text;
		}

		function __construct($id, $date, $topic, $userId, $text){
			$this->setId($id);
			$this->setDate($date);
			$this->setTopic($topic);
			$this->setUserId($userId);
			$this->setText($text);
		}

		public static function formatText($text) {
			return nl2br($text);
		}

		// Database functions
		public static function create($topicId, $userId, $text) {
			$db = DB::getDb();

			$query ="INSERT INTO posts (
						`topic`,
						`user`,
						`text`
					)
					VALUES (
						:topic_id,
						:user_id,
						:post_text
					)";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":topic_id", $topicId);
			$stmt->bindParam(":user_id", $userId);
			$stmt->bindParam(":post_text", $text);
			$stmt->execute();

			return $db->lastInsertId();
		}

		public static function getPostById($postId) {
			$db = DB::getDb();
			$query ="SELECT * FROM posts WHERE id = :post_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":post_id", $postId);
			$stmt->execute();

			$post = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Post($post['id'], $post['date'], $post['topic'], $post['user'], $post['text']);
		}

		public function getCreator() {
			$db = DB::getDb();

			$query ="SELECT 
						 users.id as id, 
						 users.name as name, 
						 users.password as password, 
						 users.email as email, 
						 users.default_group as default_group,
						 users.avatar as avatar
					FROM 
						users 
					JOIN 
						posts
					ON 
						posts.user = users.id
					WHERE 
						posts.id = :post_id";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":post_id", $this->id);
			$stmt->execute();

			$user = $stmt->fetch(PDO::FETCH_ASSOC);

			return new User($user['id'], $user['name'], $user['password'], $user['email'], $user['default_group'], $user['avatar']);
		}

		public static function dbUpdate($postId, $text) {
			$db = DB::getDb();

			$query ="UPDATE
						posts
					SET
						text = :text
					WHERE
						id = :post_id";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":text", $text);
			$stmt->bindParam(":post_id", $postId);
			$stmt->execute();
		}
	}
?>