<?php
	require_once 'class.Table.inc';
	require_once 'class.User.inc';
	require_once 'class.Group.inc';

	/**
	 * @author Oskar Danielsson
	 */
	class DB {
		public static
			$db;

		private function __construct() {}

		public static function getDb() {
			if(!isset(self::$db)) {
				self::$db = new PDO("mysql:host=localhost;dbname=forum;charset=utf8", "root", "password");
				self::$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			}
			
			return self::$db;
		}
	}
?>