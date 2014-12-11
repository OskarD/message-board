<?php
	class GroupUser extends User {
		private
			$groupId,
			$groupModerator;

		public function setGroupId($groupId) {
			$this->groupId = $groupId;
		}

		public function getGroupId() {
			return $this->groupId;
		}

		public function setGroupModerator($groupModerator) {
			if($groupModerator == 1)
				$groupModerator = true;
			else if($groupModerator == 0)
				$groupModerator = false;

			$this->groupModerator = $groupModerator;
		}

		public function isGroupModerator() {
			if(!isset($this->groupModerator))
				$this->loadGroupModeratorStatus();

			return $this->groupModerator;
		}

		function __construct($id, $name, $password, $email, $defaultGroup, $groupId, $groupModerator = null) {
			parent::__construct($id, $name, $password, $email, $defaultGroup, null);
			$this->setGroupId($groupId);

			if($groupModerator != null)
				$this->setGroupModerator($groupModerator);
		}

		// Database functions
		public static function getGroupStatusByGroupId($groupId) {
			$db = DB::getDb();

			$query ="SELECT * FROM groups WHERE id = :group_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":group_id", $groupId);
			$stmt->execute();

			$group = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Group($group['id'], $group['name'], $group['admin']);
		}

		public function loadGroupModeratorStatus() {
			$db = DB::getDb();

			$query ="SELECT moderator FROM usersgroups WHERE userid = :user_id AND groupid = :group_id";
			$stmt = $db->prepare($query);
			$stmt->bindParam(":user_id", $this->id);
			$stmt->bindParam(":group_id", $this->groupId);
			$stmt->execute();

			$result = $stmt->fetch(PDO::FETCH_ASSOC);

			$this->setGroupModerator($result['moderator']);
		}
	}
?>