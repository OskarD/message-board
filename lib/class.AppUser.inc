<?php
	require_once 'class.User.inc';
	require_once 'class.DB.inc';

	class AppUser extends User {
		protected
			$loginString;

		protected
			$avatarData;

		public function getLoginString() {
			return md5($this->name . $this->password);
		}

		public function getAvatarData() {
			return $this->avatarData;
		}

		function __construct($id, $name, $password, $email, $defaultGroup, $avatar, $avatarData) {
			parent::__construct($id, $name, $password, $email, $defaultGroup, $avatar);
			$this->avatarData = $avatarData;
		}

		// Database functions
		public static function getByName($name) {
			$db = DB::getDb();

			$query ="SELECT id, name, password, email, default_group, avatar, imgData FROM users JOIN imguploadtbl ON avatar = imgID WHERE name = :user_name";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_name", $name);
			$stmt->execute();

			$user = $stmt->fetch(PDO::FETCH_ASSOC);

			return new AppUser($user['id'], $user['name'], $user['password'], $user['email'], $user['default_group'], $user['avatar'], $user['imgData']);
		}
	}