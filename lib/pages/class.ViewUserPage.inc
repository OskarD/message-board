<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.DB.inc';
	require_once 'lib/class.User.inc';

	class ViewUserPage extends Page {
		private
			$user;

		public function setUser($user) {
			$this->user = $user;
		}

		public function getUser() {
			return $this->user;
		}

		function __construct($userId, $compress = false) {
			parent::__construct("To be replaced", $compress);
			$this->loadUser($userId);
			$this->setTitle("View User: " . $this->getUser()->getName());
		}

		public function loadUser($userId) {
			$this->setUser(User::getUserById($userId));
		}

		public function getUserHTMLProfile() {
			$output = "
				<div class='profile_view'>
					<h2>User profile: " . $this->getUser()->getName() . "</h2>
					Username: " . $this->getUser()->getName() . "<br />
					E-mail: " . $this->getUser()->getEmail();

			$groups = $this->getUser()->getGroups();

			if(count($groups) > 0) {
				$output .= "
					<div class='profile_view_groups'>Groups:
						<ol>";
				foreach($groups as $group) {
					$output .= "<li>" . $group->getHTMLLinkedName() . "</li>";
				}
				$output .= "
						</ol>
					</div";
			}

			$postCount = $this->getUser()->getPostCount();

			$output .= "<div class='profile_view_stats'><strong>Forum Statistics</strong><br />
							Posts made: " . $postCount . "<br />
							First login: " . $this->getUser()->getFirstLogin()->getDate() . "<br />
							Last login: " .  $this->getUser()->getLastLogin()->getDate() . "
						</div>";

			return $output . "
					</div>";
		}
	}
?>