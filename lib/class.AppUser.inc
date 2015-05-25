<?php
	require_once 'class.User.inc';
	require_once 'class.DB.inc';

	class AppUser extends User {
		protected
			$loginString;

		public function getLoginString() {
			return md5($this->name . $this->password);
		}

		// Database functions
		public static function getByName($name) {
			$db = DB::getDb();

			$query ="SELECT * FROM users WHERE name = :user_name";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_name", $name);
			$stmt->execute();

			$user = $stmt->fetch(PDO::FETCH_ASSOC);

			return new AppUser($user['id'], $user['name'], $user['password'], $user['email'], $user['default_group'], $user['avatar']);
		}
	}