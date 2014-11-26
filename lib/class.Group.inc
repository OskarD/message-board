<?php
	class Group {
		private
			$id,
			$name,
			$admin;

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

		public function setAdmin($admin) {
			$this->admin = $admin;
		}

		public function getAdmin() {
			return $this->admin;
		}

		function __construct($id, $name, $admin) {
			$this->setId($id);
			$this->setName($name);
			$this->setAdmin($admin);
		}

		public function getHTMLLinkedName() {
			return "<a href='view_group.php?group_id=" . $this->getId() . "'>" . $this->getName() . "</a>";
		}
	}
?>