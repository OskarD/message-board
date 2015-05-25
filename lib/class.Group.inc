<?php
	require_once 'class.GroupUser.inc';
	require_once 'class.DB.inc';

	class Group {
		private
			$id,
			$name,
			$description,
			$admin,
			$members;

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

		public function setDescription($description) {
			$this->description = $description;
		}

		public function getDescription() {
			return $this->description;
		}

		public function setAdmin($admin) {
			$this->admin = $admin;
		}

		public function getAdmin() {
			return $this->admin;
		}

		public function addMember(GroupUser $member) {
			$this->members[] = $member;
		}

		public function setMembers(array $members) {
			$this->members = array();

			foreach($members as $member) {
				$this->addMember($member);
			}
		}

		public function getMembers() {
			if(!isset($this->members))
				$this->loadMembers();

			return $this->members;
		}

		function __construct($id, $name, $description, $admin) {
			$this->setId($id);
			$this->setName($name);
			$this->setDescription($description);
			$this->setAdmin($admin);
		}

		public function getHTMLLinkedName() {
			return "<a href='view_group.php?group_id=" . $this->getId() . "'>" . $this->getName() . "</a>";
		}

		// Database functions
		public static function getGroupById($groupId) {
			$db = DB::getDb();

			$query ="SELECT * FROM groups WHERE id = :group_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":group_id", $groupId);
			$stmt->execute();

			$group = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Group($group['id'], $group['name'], $group['description'], $group['admin']);
		}

		public function loadMembers() {
			$db = DB::getDb();
			$query ="SELECT
						users.id as id,
						users.name as name,
						users.password as password,
						users.email as email,
						users.default_group as default_group,
						usersgroups.moderator as moderator
					FROM
						users
					JOIN
						usersgroups
					ON
						usersgroups.userid = users.id
					WHERE
						usersgroups.groupid = :group_id";

			$stmt = $db->prepare($query);
			$stmt->bindParam(":group_id", $this->id);
			$stmt->execute();

			$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

			foreach($result as $member) {
				$this->addMember( new GroupUser($member['id'], $member['name'], $member['password'], $member['email'], $member['default_group'], $member['moderator']) );
			}
		}
	}
?>