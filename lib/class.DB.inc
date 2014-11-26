<?php
	require_once 'class.Table.inc';
	require_once 'class.User.inc';
	require_once 'class.Group.inc';

	/**
	 * @author Oskar Danielsson
	 */
	class DB {
		public static
			$db;

		private function __construct() {}

		public static function getDb() {
			if(!isset(self::$db)) {
				self::$db = new PDO("mysql:host=localhost;dbname=messageboard;charset=utf-8", "root", "password");
				self::$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			}
			
			return self::$db;
		}

		public static function getPostCountByUserId($userId) {
			$db = self::getDb();

			$query ="SELECT count(*) as count FROM posts WHERE user = :user_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_id", $userId);
			$stmt->execute();

			$result = $stmt->fetch(PDO::FETCH_ASSOC);

			return $result['count'];
		}

		public static function getGroupsForUserWithId($userId) {
			$db = self::getDb();

			$query ="SELECT 
						groups.id as id, groups.name as name, groups.admin as admin
					FROM 
						groups 
					JOIN 
						usersgroups 
					ON 
						groups.id = usersgroups.groupid
					JOIN 
						users 
					ON 
						users.id = usersgroups.userid
					WHERE 
						users.id = :user_id";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_id", $userId);
			$stmt->execute();

			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

			$groups = array();
			foreach($result as $group) {
				$groups[] = new Group($group['id'], $group['name'], $group['admin']);
			}

			return $groups;
		}

		public static function getUserWithId($userId) {
			$db = self::getDb();

			$query ="SELECT * FROM users WHERE id = :user_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_id", $userId);
			$stmt->execute();

			$user = $stmt->fetch(PDO::FETCH_ASSOC);

			return new User($user['id'], $user['name'], $user['password'], $user['email'], $user['default_group']);
		}

		public static function getTableWithId($tableId) {
			$db = self::getDb();

			$query ="SELECT * FROM tables WHERE id = :table_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":table_id", $tableId);
			$stmt->execute();

			$table = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Table($table['id'], $table['date'], $table['name'], $table['user_group_viewing'], $table['user_group_posting']);
		}

		public static function getTopicsWithTableId($tableId) {
			$db = self::getDb();

			$query ="SELECT * FROM topics WHERE `table` = :table_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":table_id", $tableId);
			$stmt->execute();

			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

			$topics = array();
			foreach($result as $topic) {
				$topics[] = new Topic($topic['id'], $topic['date'], $topic['table'], $topic['name'], $topic['user']);
			}

			return $topics;
		}

		public static function getTopicWithId($topicId) {
			$db = self::getDb();

			$query ="SELECT * FROM topics WHERE id = :topic_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":topic_id", $topicId);
			$stmt->execute();

			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

			$topics = array();
			foreach($result as $topic) {
				$topics[] = new Topic($topic['id'], $topic['date'], $topic['table'], $topic['name'], $topic['user']);
			}

			return $topics;
		}

		public static function getPostsWithTopicId($topic) {
			$db = self::getDb();
			$query ="SELECT * FROM posts WHERE topic = :topic_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":topic_id", $topicId);
			$stmt->execute();

			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

			$posts = array();
			foreach($result as $post) {
				$posts[] = new Post($post['id'], $post['date'], $post['topic'], $post['user'], $post['text']);
			}

			return $posts;
		}

		public static function getPostWithId($postId) {
			$db = self::getDb();
			$query ="SELECT * FROM posts WHERE id = :post_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":post_id", $postId);
			$stmt->execute();

			$post = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Post($post['id'], $post['date'], $post['topic'], $post['user'], $post['text']);
		}

		public static function getLastPostWithTopicId($topicId) {
			$db = self::getDb();
			$query ="SELECT * FROM posts WHERE topic = :topic_id ORDER BY date DESC LIMIT 1";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":topic_id", $topicId);
			$stmt->execute();

			$post = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Post($post['id'], $post['date'], $post['topic'], $post['user'], $post['text']);
		}
	}
?>