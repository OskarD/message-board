<?php
	/**
	 * @author Oskar Danielsson
	 */
	class NavigationItem {
		private
			$name,
			$link,
			$newTab;

		function __construct($name, $link, $newTab = false) {
			$this->name = $name;
			$this->link = $link;
			$this->newTab = $newTab;
		}

		public function getHTML() {
			$output = "<li><a href='" . $this->link . "'";

			if($this->newTab == true)
				$output .= " target='_blank'";

			return $output .  ">" . $this->name . "</a></li>";
		}
	}
?>