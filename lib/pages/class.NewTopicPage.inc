<?php
	require_once 'lib/class.Page.inc';

	class NewTopicPage extends Page {
		private
			$tableId;

		public function setTableId($tableId) {
			$this->tableId = $tableId;
		}

		public function getTableId() {
			return $this->tableId;
		}

		function __construct($title, $tableId, $compress = true) {
			parent::__construct($title, $compress);
			$this->setTableId($tableId);
		}

		public function getHTMLPage() {
			$output = "
				<div class='new_topic'>
					<h2>Create New Topic</h2>
					<form id='topic_name' action='create_topic.php' method='post'>
						Topic subject:<br />
						<input type='text' id='name' name='name' required /><br />
						Text:<br />
						<textarea id='text' name='text' rows='20' cols='80'></textarea><br />
						<button type='submit' id='submit' name='submit'>Create</button>
						<input type='hidden' id='table_id' name='table_id' value='" . $this->getTableId() . "' />
					</form>
				</div>";

			return $output;
		}
	}
?>