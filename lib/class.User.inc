<?php
	require_once 'class.DB.inc';

	class User {
		private
			$id,
			$name,
			$password,
			$email,
			$defaultGroup;

		public function setId($id) {
			$this->id = $id;
		}

		public function getId() {
			return $this->id;
		}

		public function setName($name) {
			$this->name = $name;
		}

		public function getName() {
			return $this->name;
		}

		public function setPassword($password) {
			$this->password = $password;
		}

		public function getPassword() {
			return $this->password;
		}

		public function setEmail($email) {
			$this->email = $email;
		}

		public function getEmail() {
			return $this->email;
		}

		public function setDefaultGroup($defaultGroup) {
			$this->defaultGroup = $defaultGroup;
		}

		public function getDefaultGroup() {
			return $this->defaultGroup;
		}
		
		function __construct($id, $name, $password, $email, $defaultGroup) {
			$this->setId($id);
			$this->setName($name);
			$this->setPassword($password);
			$this->setEmail($email);
			$this->setdefaultGroup($defaultGroup);
		}

		public function getHTMLLinkedName() {
			return "<a href='view_user.php?user_id=" . $this->getId() . "'>" . $this->getName() . "</a>";
		}

		// Database functions
		public static function getUserById($userId) {
			$db = DB::getDb();

			$query ="SELECT * FROM users WHERE id = :user_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_id", $userId);
			$stmt->execute();

			$user = $stmt->fetch(PDO::FETCH_ASSOC);

			return new User($user['id'], $user['name'], $user['password'], $user['email'], $user['default_group']);
		}

		public function getGroups() {
			$db = DB::getDb();

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
			$stmt->bindParam(":user_id", $this->id);
			$stmt->execute();

			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

			$groups = array();
			foreach($result as $group) {
				$groups[] = new Group($group['id'], $group['name'], $group['admin']);
			}

			return $groups;
		}

		public function getPostCount() {
			$db = DB::getDb();

			$query ="SELECT count(*) as count FROM posts WHERE user = :user_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_id", $this->id);
			$stmt->execute();

			$result = $stmt->fetch(PDO::FETCH_ASSOC);

			return $result['count'];
		}
	}
?>