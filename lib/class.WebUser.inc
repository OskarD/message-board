<?php
	require_once 'lib/class.DB.inc';

	WebUser::startSession();

	/**
	 * @author Oskar Danielsson
	 */
	class WebUser {
		private static
			$level;

		public static function isLoggedIn() {
			if(isset($_SESSION['user_id']))
				return true;
			return false;
		}

		public static function getUserId() {
			return $_SESSION['user_id'];
		}

		public static function logIn($userId) {
			$_SESSION['user_id'] = $userId;
		}

		public static function logOut() {
			$_SESSION = array();
			session_destroy();
		}

		public static function startSession() {
			if(session_id() == '') {
			    session_start();
			}
		}

		// Database functions
		public static function register($name, $password, $email) {
			$db = DB::getDb();

			$query ="SELECT 
						name, 
						email 
					FROM 
						users
					WHERE
						name = :name
					OR
						email = :email";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":name", $name);
			$stmt->bindParam(":email", $email);
			$stmt->execute();

			$result = $stmt->fetch(PDO::FETCH_ASSOC);
			if(isset($result['name'])) {
				if($result['name'] == $name)
					return 'name_exists';
				else
					return 'email_exists';
			}

			$query ="INSERT INTO users (
						name,
						password,
						email
					)
					VALUES (
						:name,
						:password,
						:email
					)";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":name", $name);
			$stmt->bindParam(":password", $password);
			$stmt->bindParam(":email", $email);
			$stmt->execute();

			$userId = $db->lastInsertId();

			return 'registered';
		}

		public static function verifyUserPasswordCombination($name, $password) {
			$db = DB::getDb();

			$query ="SELECT id FROM users WHERE name = :name AND password = :password";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":name", $name);
			$stmt->bindParam(":password", $password);
			$stmt->execute();

			$result = $stmt->fetch(PDO::FETCH_ASSOC);

			if($result == false)
				return false;
		
			self::logIn($result['id']);
			return true;
		}
	}
?>