<?php
	require_once 'class.Post.inc';

	class Topic {
		private
			$id,
			$date,
			$table,
			$name,
			$user,
			$posts;

		public function setId($id) {
			$this->id = $id;
		}

		public function getId() {
			return $this->id;
		}

		public function setDate($date) {
			$this->date = $date;
		}

		public function getDate() {
			return $this->date;
		}

		public function setTable($table) {
			$this->table = $table;
		}

		public function getTable() {
			return $this->table;
		}

		public function setName($name) {
			$this->name = $name;
		}

		public function getName() {
			return $this->name;
		}

		public function setUser($user) {
			$this->user = $user;
		}

		public function getUser() {
			return $this->user;
		}

		public function setUserGroup($userGroup) {
			$this->userGroup = $userGroup;
		}

		public function getUserGroup() {
			return $this->userGroup;
		}

		public function setPosts(array $posts) {
			foreach($posts as $post) {
				$this->addPost($post);
			}
		}

		public function addPost(Post $post) {
			$this->posts[] = $post;
		}

		public function getPosts() {
			return $this->posts;
		}

		function __construct($id, $date, $table, $name, $user, $posts = array()){
			$this->setId($id);
			$this->setDate($date);
			$this->setTable($table);
			$this->setName($name);
			$this->setUser($user);
			$this->setPosts($posts);
		}
	}
?>