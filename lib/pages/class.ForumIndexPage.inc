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

		public function getTables() {
			return $this->tables;
		}

		public function loadPage() {
			$db = DB::getDb();

			$query ="SELECT 
						tables.id as table_id,
						tables.name as table_name,
						topics.id as topic_id,
						topics.name as topic_name
					FROM 
						tables
					LEFT JOIN
						topics
					ON
						tables.id = topics.table
					LEFT JOIN
						posts
					ON
						posts.topic = topics.id
					ORDER BY
						tables.id ASC, posts.date DESC";

			$stmt = $db->prepare($query);
			$stmt->execute();

			$this->tables = $stmt->fetchAll(PDO::FETCH_ASSOC);

			for($i = 0; $i < count($this->tables); $i++) {
				$query = "SELECT count(*) FROM topics WHERE topics.table = :table_id";

				$stmt = $db->prepare($query);
				$stmt->bindParam(":table_id", $this->tables[$i]['table_id']);
				$stmt->execute();

				$result = $stmt->fetch();

				$this->tables[$i]['topic_count'] = $result[0];
			}
		}

		public function getForumHTMLOverview() {
			$output = "<h2>Forum</h1><ol class='forum_overview'>";

			foreach($this->getTables() as $table) {
				$output .= "<li class='forum_overview_table'><a href='view_table.php?table_id=" . $table['table_id'] . "'>" . $table['table_name'] . "</a>";

				if(!empty($table['topic_id'])) {
					$output .= "
						<div class='forum_overview_topic_count'>
							Topics: " . $table['topic_count'] . "
						</div>
						<div class='forum_overview_last_topic'>
							Last topic: <a href='view_topic.php?topic_id=" . $table['topic_id'] . "'>" . $table['topic_name'] . "</a>
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

