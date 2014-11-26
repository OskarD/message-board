<?php
	require_once 'class.Topic.inc';

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
	}
?>