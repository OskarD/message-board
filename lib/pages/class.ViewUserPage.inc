<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.DB.inc';
	require_once 'lib/class.User.inc';
	require_once 'lib/class.Image.inc';
	require_once 'lib/class.Webuser.inc';

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
				<div class='inner_container profile_view'>
					<div class='profile_view_basic'>
						<h2>User profile: " . $this->getUser()->getName() . "</h2>
						Username: " . $this->getUser()->getName() . "<br />
						E-mail: " . $this->getUser()->getEmail() . "
					</div>
					<div class='avatar'>";

			if($this->getUser()->getAvatar() != null) {
				$image = Image::getById($this->getUser()->getAvatar());
				$output .= $image->getHTML();
			}

			if(WebUser::getUserId() == $this->getUser()->getId()) {
				$output .= "
						Upload an avatar image:
						<form method='post' action='imgUploadHandle.php' enctype='multipart/form-data'>
						<input type='file' name='image' /><br />
						<input type='submit' name='userSbtBtn' value='Upload Image' />
						<input type='hidden' name='user_id' value='" . $this->getUser()->getId() . "' />
						</form>";

			}
			$output .= "
					</div>";

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
					</div>";
			}

			$postCount = $this->getUser()->getPostCount();

			$output .= "
					<div class='profile_view_stats'><strong>Forum Statistics</strong><br />
						Posts made: " . $postCount . "<br />
						First login: " . $this->getUser()->getFirstLogin()->getDate() . "<br />
						Last login: " .  $this->getUser()->getLastLogin()->getDate() . "
					</div>";

			return $output . "
				</div>";
		}
	}
?>