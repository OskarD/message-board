<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.DB.inc';
	require_once 'lib/class.GroupUser.inc';

	class ViewGroupPage extends Page {
		private
			$group;

		public function setGroup($group) {
			$this->group = $group;
		}

		public function getGroup() {
			return $this->group;
		}

		function __construct($groupId, $compress = false) {
			parent::__construct("To be replaced", $compress);
			$this->loadGroup($groupId);
			$this->setTitle("View Group: " . $this->getGroup()->getName());
		}

		public function loadGroup($groupId) {
			$this->setGroup(Group::getGroupById($groupId));
		}

		public function getGroupHTMLPage() {
			$output = "
				<div class='group_view'>
					<h2>Group page: " . $this->getGroup()->getName() . "</h2>
					Description: " . $this->getGroup()->getDescription();

			$members = $this->group->getMembers();

			if(count($members) > 0) {
				$output .= "<div class='group_view_members'>";

				$moderators = array();
				$regularMembers = array();

				foreach($members as $member) {
					if($member->isGroupModerator())
						$moderators[] = $member;
					else
						$regularMembers[] = $member;
				}

				if(count($moderators) > 0) {
					$output .= "<div class='group_view_moderators'><h3>Group Moderators</h3><ol>";

					foreach($moderators as $moderator) {
						$output .= "<li>" . $moderator->getHTMLLinkedName() . "</li>";
					}

					$output .= "</ol></div>";
				}

				if(count($regularMembers) > 0) {
					$output .= "<div class='group_view_regular_users'><h3>Group Members</h3><ol>";

					foreach($regularMembers as $regularMember) {
						$output .= "<li>" . $regularMember->getHTMLLinkedName() . "</li>";
					}

					$output .= "</ol></div>";
				}
				$output .= "</div>";
			}

			return $output . "</div>";
		}
	}
?>