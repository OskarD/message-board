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
					<h2><a href='forum_index.php'>Forum</a> <span class='right_arrow'></span> " . $this->getTable()->getHTMLLinkedName() . "</h2>";

			if(WebUser::isLoggedIn()) {
				$output .= "
					<div class='view_table_new_topic'>
						<span class='btn'><a href='new_topic.php?table=" . $this->getTable()->getId() . "'>Create new topic</a></span>
					</div>";
			}

			$output .= "
					<div class='view_table_topic_list'>
						<h3>Topics</h3>
						<ol>";

			$topics = $this->table->getTopics();

			if(count($topics) > 0) {
				foreach($this->table->getTopics() as $topic) {
					$output .= "
								<li>
									<div class='forum_list'>
										<div class='forum_list_topic_name bold'>
											" . $topic->getHTMLLinkedName() . "
										</div>";

					$lastPost = $topic->getLastPost();
					$lastPostCreator = $lastPost->getCreator();

					$output .= "
										<div class='view_table_topic_last_post'>
											Last post by " . $lastPostCreator->getHTMLLinkedName() . " at " . $lastPost->getDate() . "
										</div>
									</div>
								</li>";
				}
			}
			else
				$output .= "There are no topics in this table yet.";

			$output .= "
						</ol>
					</div>";

			return $output . "</div>";
		}
	}
?>

