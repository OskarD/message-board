<?php
	require_once 'lib/class.Page.inc';
	require_once 'lib/class.Topic.inc';
	require_once 'lib/class.DB.inc';

	/**
	 * @author Oskar Danielsson
	 */
	class ViewTablePage extends Page {
		private
			$tableId,
			$table,
			$topics;

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
			$this->setTable(DB::getTableWithId($tableId));
		}

		public function getTableHTMLView() {
			$output = "
				<div class='view_table'>
					<h2>" . $this->getTable()->getName() . "</h2>
					<div class='view_table_topic_list'>
						<ol>";

			foreach(DB::getTopicsWithTableId($this->getTable()->getId()) as $topic) {
				$output .= "<li><a href='view_topic.php?topic_id=" . $topic->getId() . "'>" . $topic->getName() . "</a>";

				$lastPost = DB::getLastPostWithTopicId($topic->getId());
				$lastPostUser = DB::getUserWithId($lastPost->getUserId());

				$output .= "
							<div class='view_table_topic_last_post'>
								Last post by " . $lastPostUser->getHTMLLinkedName() . " at " . $lastPost->getDate() . "
							</div>";

				$output .= "</li>";
			}

			$output .= "
						</ol>
					</div>
				</div>";



			return $output;
		}
	}
?>
