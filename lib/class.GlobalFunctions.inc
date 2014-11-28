<?php
	class GlobalFunctions {
		public static function var_dump_pre($mixed = null) {
			echo '<pre>';
			var_dump($mixed);
			echo '</pre>';
		}

		//Function to check if the request is an AJAX request
		public static function isAjax() {
			return isset($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest';
		}
	}
?>