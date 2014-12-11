<?php
	require_once 'class.DB.inc';

	class Image {
		private
			$id,
			$createdDate,
			$dimension,
			$mime,
			$size,
			$data;

		public function setId($id) {
			$this->id = $id;
		}

		public function getId() {
			return $this->id;
		}

		public function setCreatedDate($createdDate) {
			$this->createdDate = $createdDate;
		}

		public function getCreatedDate() {
			return $this->createdDate;
		}

		public function setDimension($dimension) {
			$this->dimension = $dimension;
		}

		public function getDimension() {
			return $this->dimension;
		}

		public function setMime($mime) {
			$this->mime = $mime;
		}

		public function getMime() {
			return $this->mime;
		}

		public function setSize($size) {
			$this->size = $size;
		}

		public function getSize() {
			return $this->size;
		}

		public function setData($data) {
			$this->data = $data;
		}

		public function getData() {
			return $this->data;
		}

		public function __construct($id, $createdDate, $dimension, $mime, $size, $data) {
			$this->id = $id;
			$this->createdDate = $createdDate;
			$this->dimension = $dimension;
			$this->mime = $mime;
			$this->size = $size;
			$this->data = $data;
		}

		public function getHTML() {
			return '<img src="data:image/jpeg;base64,'.base64_encode( $this->getData() ).'"/>';
		}

		// Database functions
		public static function getById($id) {
			$db = DB::getDb();

			$stmt = $db->prepare("SELECT * FROM imguploadtbl WHERE imgID = :imgID");
			$stmt->bindParam(':imgID', $id);
			$stmt->execute();

			$row = $stmt->fetch(PDO::FETCH_ASSOC);

			return new Image(
				$row['imgID'],
				$row['imgCreatedOn'],
				$row['imgDimension'],
				$row['imgMime'],
				$row['imgSize'],
				$row['imgData']
				);
		}
	}
?>