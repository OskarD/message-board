<?php
	require_once 'class.NavigationItem.inc';

	/**
	 * @author Oskar Danielsson
	 */
	class Navigation {
		private
			$navigationItems = array();

		public function addItem($name, $link, $newTab = false) {
			$this->navigationItems[] = new NavigationItem($name, $link, $newTab = false);
		}

		public function getHTML() {
			$output = "<nav><ol>";

			foreach($this->navigationItems as $navigationItem) {
				$output .= $navigationItem->getHTML();
			}

			return $output .= "</ol></nav>";
		}
	}
?>