<?php
	require_once 'class.WebUser.inc';
	require_once 'class.Navigation.inc';

	/**
	 * @author Oskar Danielsson
	 */
	abstract class Page {

		// Keeps track of any other instances so we don't double-compress (Will turn the page into a hashed string)
		private static
			$compressed = false;

		private 
			$title,
			$navigation;

		public function setTitle($title) {
			$this->title = $title;
		}

		public function getTitle() {
			return $this->title;
		}

		function __construct($title = "Title unset", $compress = true) {
			ini_set('display_startup_errors',1);
			ini_set('display_errors',1);
			error_reporting(-1);

			$this->setTitle($title);

			if($compress == true && self::$compressed == false)
			{
				self::$compressed = true;
				$this->compress();
			}
			else if($compress == false)
			{
				ob_start();
			}

			$this->navigation = new Navigation();

			$this->addNavigationItem("Home", "index.php");
			$this->addNavigationItem("Users", "users.php");
			$this->addNavigationItem("Forum", "forum_index.php");

			if(WebUser::isLoggedIn()) {
				$this->addNavigationItem("Sign Out", "sign_out.php");
			}
			else {
				$this->addNavigationItem("Sign In", "sign_in.php");
				$this->addNavigationItem("Register", "register.php");
			}
		}

		/**
		 * Add an item to the navigation div
		 */
		public function addNavigationItem($name, $link, $newTab = false) {
			$this->navigation->addItem($name, $link, $newTab);
		}

		/**
		 * Get the navigation
		 */
		public function getNavigation($showInformation = true) {
			return $this->navigation->getHTML();
		}

		/**
		 * Gets the page head with all all the necessary tags
		 * This needs to be called before anything else is printed on the page
		 * @return string
		 */
		public function getHead($extraContent = "", $useJQuery = false) {
			//  Google JQuery: <script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>

			$output = '
				<!doctype html>
				<html>
					<head>
					  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
					  <title>Oskar\'s Forum - ' . $this->title . '</title>
					  <link rel="stylesheet" href="css/styles.css" type="text/css">';

			if($useJQuery == true)
				$output .= "<script src='js/jquery-1.11.1.min.js'></script>";

			$output .= $extraContent . '
					</head>
			';

			return $output;
		}

		/**
		 * Prints the tail of the page
		 * @return string
		 */
		public function getTail()
		{
			if(self::$compressed == false)
				ob_end_flush();

			return "</html>";
		}

		public function getHeader() {
			$output = "
			<div class='header'>
				<h1>Oskar's Forum</h1>";


			if(WebUser::isLoggedIn()) {
				$user = User::getUserById( WebUser::getUserId() );
				$output .= "
				<div class='logged_in_user_info'>Logged in: <span class='bold'>" . $user->getHTMLLinkedName() . "</span></div>";
			}

			$output .= $this->getNavigation();

			return $output . "
				</div>
				<div class='bordered content_wrapper'>";
		}

		public function getFooter() {
			return "
				</div>
				<div class='bordered footer'>
					Footer, copyright and shit
				</div>";
		}

		/**
		 * Compresses the page and allows faster transfer to browser
		 * (Also avoids problems with long strings)
		 */
		public function compress()
		{
			if(substr_count($_SERVER['HTTP_ACCEPT_ENCODING'], 'gzip'))
				ob_start("ob_gzhandler");
			else
				ob_start();
		}
	}
?>