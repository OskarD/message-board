<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.DB.inc';

	/**
	 * @author Oskar Danielsson
	 */
	class ForumIndexPage extends Page {
		private
			$tables = array();

		function __construct($title, $compress = true) {
			parent::__construct($title, $compress);
			$this->loadPage();
		}

		public function addTable(Table $table) {
			$this->tables[] = $table;
		}

		public function setTables(array $tables) {
			foreach($tables as $table) {
				$this->addTable($table);
			}
		}

		public function getTables() {
			return $this->tables;
		}

		public function loadPage() {
			$db = DB::getDb();

			$query ="SELECT 
						*
					FROM 
						tables
					ORDER BY
						id ASC";

			$stmt = $db->prepare($query);
			$stmt->execute();

			foreach($stmt->fetchAll(PDO::FETCH_ASSOC) as $table) {
				$this->addTable( new Table($table['id'], $table['date'], $table['name'], $table['user_group_viewing'], $table['user_group_posting']) );
			}
		}

		public function getForumHTMLOverview() {
			$output = "<h2>Forum</h1><ol class='forum_overview'>";

			foreach($this->getTables() as $table) {
				$output .= "<li class='forum_overview_table'>" . $table->getHTMLLinkedName();

				$lastTopic = $table->getLastActiveTopic();

				if(!is_null($lastTopic->getId())) {
					$output .= "
						<div class='forum_overview_topic_count'>
							Topics: " . count($lastTopic->loadPosts()) . "
						</div>
						<div class='forum_overview_last_topic'>
							Last topic: " . $lastTopic->getHTMLLinkedName() . "
						</div>";
				}
				else
					$output .= "<div class='forum_overview_last_topic'>There are no topics in this table.</div>";

				$output .= "</li>";
			}

			return $output . "</ol>";
		}
	}
?>

