<?php
	require_once 'class.Topic.inc';
	require_once 'class.DB.inc';

	class Table {
		private
			$id,
			$date,
			$name,
			$userGroupViewing,
			$userGroupPosting,
			$topics,
			$lastActiveTopic;

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

		public function setName($name) {
			$this->name = $name;
		}

		public function getName() {
			return $this->name;
		}

		public function setUserGroupViewing($userGroup) {
			$this->userGroupViewing = $userGroup;
		}

		public function getUserGroupViewing() {
			return $this->userGroupViewing;
		}

		public function setUserGroupPosting($userGroup) {
			$this->userGroupPosting = $userGroup;
		}

		public function getUserGroupPosting() {
			return $this->userGroupPosting;
		}

		public function addTopic(Topic $topic) {
			if(!isset($this->topics))
				$this->topics = array();

			$this->topics[] = $topic;
		}

		public function setTopics(array $topics) {
			$this->topics = array();

			foreach($topics as $topic) {
				$this->addTopic($topic);
			}
		}

		public function getTopics() {
			if(!isset($this->topics))
				$this->loadTopics();

			return $this->topics;
		}

		public function setLastActiveTopic(Topic $lastActiveTopic) {
			$this->lastActiveTopic = $lastActiveTopic;
		}

		public function getLastActiveTopic() {
			if(!isset($this->lastActiveTopic))
				$this->loadLastActiveTopic();

			return $this->lastActiveTopic;
		}

		function __construct($id, $date, $name, $userGroupViewing, $userGroupPosting){
			$this->setId($id);
			$this->setName($name);
			$this->setUserGroupViewing($userGroupViewing);
			$this->setUserGroupPosting($userGroupPosting);
		}

		public function getHTMLLinkedName() {
			return "<a href='view_table.php?table_id=" . $this->getId() . "'>" . $this->getName() . "</a>";
		}

		// Database functions
		public static function getTableById($tableId) {
			$db = DB::getDb();

			$query ="SELECT * FROM tables WHERE id = :table_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":table_id", $tableId);
			$stmt->execute();

			$table = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Table($table['id'], $table['date'], $table['name'], $table['user_group_viewing'], $table['user_group_posting']);
		}

		private function loadLastActiveTopic() {
			$db = DB::getDb();

			$query ="SELECT 
						topics.id as id,
						posts.date as `date`,
						topics.table as `table`,
						topics.name as name,
						topics.user as user
					FROM 
						topics
					JOIN
						posts
					ON
						posts.topic = topics.id
					WHERE 
						`table` = :table_id 
					ORDER BY
						posts.date DESC
					LIMIT 1";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":table_id", $this->id);
			$stmt->execute();

			$result = $stmt->fetch(PDO::FETCH_ASSOC);

			$this->setLastActiveTopic(new Topic($result['id'], $result['date'], $result['table'], $result['name'], $result['user']));
		}

		private function loadTopics() {
			$db = DB::getDb();

			$query ="SELECT 
						* 
					FROM 
						topics 
					WHERE 
						`table` = :table_id 
					ORDER BY 
						date DESC";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":table_id", $this->id);
			$stmt->execute();

			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

			$topics = array();
			foreach($result as $topic) {
				$topics[] = new Topic($topic['id'], $topic['date'], $topic['table'], $topic['name'], $topic['user']);
			}

			$this->setTopics($topics);
		}
	}
?>