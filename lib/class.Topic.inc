<?php
	require_once 'class.Post.inc';
	require_once 'class.DB.inc';

	class Topic {
		private
			$id,
			$date,
			$table,
			$name,
			$user,
			$posts;

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

		public function setTable($table) {
			$this->table = $table;
		}

		public function getTable() {
			return $this->table;
		}

		public function setName($name) {
			$this->name = $name;
		}

		public function getName() {
			return $this->name;
		}

		public function setUser($user) {
			$this->user = $user;
		}

		public function getUser() {
			return $this->user;
		}

		public function setUserGroup($userGroup) {
			$this->userGroup = $userGroup;
		}

		public function getUserGroup() {
			return $this->userGroup;
		}

		public function setPosts(array $posts) {
			$this->posts = array();
			
			foreach($posts as $post) {
				$this->addPost($post);
			}
		}

		public function addPost(Post $post) {
			$this->posts[] = $post;
		}

		public function getPosts() {
			return $this->posts;
		}

		function __construct($id, $date, $table, $name, $user, $posts = array()){
			$this->setId($id);
			$this->setDate($date);
			$this->setTable($table);
			$this->setName($name);
			$this->setUser($user);
			$this->setPosts($posts);
		}

		public function getHTMLLinkedName() {
			return "<a href='view_topic.php?topic_id=" . $this->getId() . "'>" . $this->getName() . "</a>";
		}

		// Database functions
		public static function create($tableId, $name, $text, $userId) {
			$db = DB::getDb();

			$query ="INSERT INTO topics (
						`table`,
						name,
						user
					)
					VALUES (
						:table_id,
						:name,
						:user_id
					)";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":table_id", $tableId);
			$stmt->bindParam(":name", $name);
			$stmt->bindParam(":user_id", $userId);
			$stmt->execute();

			$inserted = $db->lastInsertId();

			Post::create($inserted, $userId, $text);

			return $inserted;
		}

		public function getLastPost() {
			$db = DB::getDb();
			$query ="SELECT * FROM posts WHERE topic = :topic_id ORDER BY date DESC LIMIT 1";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":topic_id", $this->id);
			$stmt->execute();

			$post = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Post($post['id'], $post['date'], $post['topic'], $post['user'], $post['text']);
		}

		public function loadPosts() {
			$db = DB::getDb();
			$query ="SELECT * FROM posts WHERE topic = :topic_id ORDER BY date ASC";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":topic_id", $this->id);
			$stmt->execute();

			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

			$posts = array();
			foreach($result as $post) {
				$posts[] = new Post($post['id'], $post['date'], $post['topic'], $post['user'], $post['text']);
			}

			return $posts;
		}

		public static function getTopicWithId($topicId) {
			$db = DB::getDb();

			$query ="SELECT * FROM topics WHERE id = :topic_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":topic_id", $topicId);
			$stmt->execute();

			$result = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Topic($result['id'], $result['date'], $result['table'], $result['name'], $result['user']);
		}

		public function getTopicCreator() {
			$db = DB::getDb();

			$query ="SELECT 
						 users.id as id, 
						 users.name as name, 
						 users.password as password, 
						 users.email as email, 
						 users.default_group as default_group
					FROM 
						users 
					JOIN 
						topics
					ON 
						topics.user = users.id
					WHERE 
						topics.id = :topic_id";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":topic_id", $this->id);
			$stmt->execute();

			$user = $stmt->fetch(PDO::FETCH_ASSOC);

			return new User($user['id'], $user['name'], $user['password'], $user['email'], $user['default_group']);
		}
	}
?>