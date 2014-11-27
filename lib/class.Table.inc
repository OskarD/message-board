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
			$topics;

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
			$this->topics[] = $topic;
		}

		public function setTopics(array $topics) {
			foreach($topics as $topic) {
				$this->addTopic($topics);
			}
		}

		public function getTopics() {
			return $this->topics;
		}

		function __construct($id, $date, $name, $userGroupViewing, $userGroupPosting, $topics = array()){
			$this->setId($id);
			$this->setName($name);
			$this->setUserGroupViewing($userGroupViewing);
			$this->setUserGroupPosting($userGroupPosting);
			$this->setTopics($topics);
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

		public function loadTopics() {
			$db = DB::getDb();

			$query ="SELECT * FROM topics WHERE `table` = :table_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":table_id", $this->id);
			$stmt->execute();

			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

			$topics = array();
			foreach($result as $topic) {
				$topics[] = new Topic($topic['id'], $topic['date'], $topic['table'], $topic['name'], $topic['user']);
			}

			return $topics;
		}
	}
?>