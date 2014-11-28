<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.Topic.inc';
	require_once 'lib/class.DB.inc';
	require_once 'lib/class.WebUser.inc';

	/**
	 * @author Oskar Danielsson
	 */
	class ViewTablePage extends Page {
		private
			$tableId,
			$table,
			$topics;

		public function getTableId() {
			return $this->tableId;
		}

		public function setTable(Table $table) {
			$this->table = $table;
		}

		public function getTable() {
			return $this->table;
		}

		public function setTopics(array $topics) {
			foreach($topics as $topic) {
				$this->addTopic($topic);
			}
		}

		public function addTopic(Topic $topic) {
			$this->topics[] = $topic;
		}

		public function getTopics() {
			return $this->topics;
		}

		function __construct($tableId, $compress = false) {
			parent::__construct("To be replaced", $compress);
			$this->loadTable($tableId);
			$this->setTitle($this->getTable()->getName());
		}

		public function loadTable($tableId) {
			$this->setTable(Table::getTableById($tableId));
		}

		public function getTableHTMLView() {
			$output = "
				<div class='view_table'>
					<h2>" . $this->getTable()->getName() . "</h2>";

			if(WebUser::isLoggedIn()) {
				$output .= "
					<div class='view_table_new_topic'>
						<a href='new_topic.php?table=" . $this->getTable()->getId() . "'>Create new topic</a>
					</div>";
			}

			$output .= "
					<div class='view_table_topic_list'>
						<h3>Topics</h3>
						<ol>";

			foreach($this->table->getTopics() as $topic) {
				$output .= "<li><a href='view_topic.php?topic_id=" . $topic->getId() . "'>" . $topic->getName() . "</a>";

				$lastPost = $topic->getLastPost();
				$lastPostCreator = $lastPost->getCreator();

				$output .= "
							<div class='view_table_topic_last_post'>
								Last post by " . $lastPostCreator->getHTMLLinkedName() . " at " . $lastPost->getDate() . "
							</div>";

				$output .= "</li>";
			}

			$output .= "
						</ol>
					</div>";

			return $output . "</div>";
		}
	}
?>

