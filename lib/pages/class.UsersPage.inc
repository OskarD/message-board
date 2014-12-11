<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.DB.inc';
	require_once 'lib/class.User.inc';

	/**
	 * @author Oskar Danielsson
	 */
	class UsersPage extends Page {
		private
			$users = array();

		function __construct() {
			parent::__construct();
			$this->loadUsers();
		}

		/**
		 * Loads all the users into the users array
		 */
		public function loadUsers() {
			$db = DB::getDb();

			$stmt = $db->prepare("SELECT * FROM users");
			$stmt->execute();			

			$users = $stmt->fetchAll(PDO::FETCH_ASSOC);

			foreach($users as $user) {
				$this->addUser(new User($user['id'], $user['name'], $user['password'], $user['email'], $user['default_group'], $user['avatar']));
			}
		}

		public function addUser(User $user) {
			$this->users[] = $user;
		}

		public function getUsers() {
			return $this->users;
		}

		public function getUserHTMLList(){
			$result = "
				<h2>Users</h2>
				<div class='inner_container'>
					<ol class='userlist'>";

			foreach($this->getUsers() as $user) {
				$result .= "<li>" . $user->getHTMLLinkedName() . "</li>";
			}

			return $result . "
					</ol>
				</div>";
		}
	}
?>