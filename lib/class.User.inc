<?php
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
	}
?>