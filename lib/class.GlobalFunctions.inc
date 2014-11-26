<?php
	class GlobalFunctions {
		function var_dump_pre($mixed = null) {
			echo '<pre>';
			var_dump($mixed);
			echo '</pre>';
		}
	}
?>