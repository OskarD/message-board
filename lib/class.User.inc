<?php
	require_once 'class.DB.inc';

	class User {
		protected
			$id,
			$name,
			$password,
			$email,
			$defaultGroup,
			$avatar;

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

		public function setAvatar($avatar) {
			$this->avatar = $avatar;
		}

		public function getAvatar() {
			return $this->avatar;
		}
		
		function __construct($id, $name, $password, $email, $defaultGroup, $avatar) {
			$this->setId($id);
			$this->setName($name);
			$this->setPassword($password);
			$this->setEmail($email);
			$this->setdefaultGroup($defaultGroup);
			$this->setAvatar($avatar);
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

			return new User($user['id'], $user['name'], $user['password'], $user['email'], $user['default_group'], $user['avatar']);
		}

		public function getGroups() {
			$db = DB::getDb();

			$query ="SELECT 
						groups.id as id, 
						groups.name as name, 
						groups.description as description,
						groups.admin as admin
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
				$groups[] = new Group($group['id'], $group['name'], $group['description'], $group['admin']);
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

		public function getLastLogin() {
			$db = DB::getDb();

			$query ="SELECT * FROM logins WHERE user = :user_id ORDER BY date DESC LIMIT 1";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_id", $this->id);
			$stmt->execute();

			$result = $stmt->fetch(PDO::FETCH_ASSOC);

			return new LoginInstance($result['id'], $result['user'], $result['date'], $result['ip']);
		}

		public function getFirstLogin() {
			$db = DB::getDb();

			$query ="SELECT * FROM logins WHERE user = :user_id ORDER BY date ASC LIMIT 1";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_id", $this->id);
			$stmt->execute();

			$result = $stmt->fetch(PDO::FETCH_ASSOC);

			return new LoginInstance($result['id'], $result['user'], $result['date'], $result['ip']);
		}

		function getJsonData() {
			$var = get_object_vars($this);
			foreach($var as &$value){
				if(is_object($value) && method_exists($value,'getJsonData')){
					$value = $value->getJsonData();
				}
			}
			return $var;
		}
	}
?>