<?php
	require_once 'lib/class.DB.inc';

	class LoginInstance {
		private
			$id,
			$userId,
			$date,
			$ip;

		public function setId($id) {
			$this->id = $id;
		}

		public function getId() {
			return $this->id;
		}

		public function setUserId($userId) {
			$this->userId = $userId;
		}

		public function getUserId() {
			return $this->userId;
		}

		public function setDate($date) {
			$this->date = $date;
		}

		public function getDate() {
			return $this->date;
		}

		public function setIp($ip) {
			$this->ip = $ip;
		}

		public function getIp() {
			return $this->ip;
		}

		function __construct($id, $userId, $date, $ip) {
			$this->setId($id);
			$this->setUserId($id);
			$this->setDate($date);
			$this->setIp($ip);
		}

		// Database functions
		public static function insertIntoDb($userId, $ip) {
			$db = DB::getDb();

			$query ="INSERT INTO logins (user, ip) VALUES (:user_id, :ip)";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_id", $userId);
			$stmt->bindParam(":ip", $ip);
			$stmt->execute();
		}
	}
?>