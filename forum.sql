-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 29, 2014 at 08:08 AM
-- Server version: 5.5.16
-- PHP Version: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `messageboard`
--

-- --------------------------------------------------------

--
-- Table structure for table `groups`
--

CREATE TABLE IF NOT EXISTS `groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(30) COLLATE utf8_bin NOT NULL,
  `description` varchar(256) COLLATE utf8_bin NOT NULL,
  `admin` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=3 ;

--
-- Dumping data for table `groups`
--

INSERT INTO `groups` (`id`, `name`, `description`, `admin`) VALUES
(1, 'Regular User', 'All regular users are part of this group', 0),
(2, 'Administrator', 'Message Board Administrators', 1);

-- --------------------------------------------------------

--
-- Table structure for table `logins`
--

CREATE TABLE IF NOT EXISTS `logins` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `ip` varchar(15) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user` (`user`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=7 ;

-- --------------------------------------------------------

--
-- Table structure for table `posts`
--

CREATE TABLE IF NOT EXISTS `posts` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `topic` int(11) NOT NULL,
  `user` int(11) NOT NULL,
  `text` blob NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user` (`user`),
  KEY `topic` (`topic`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=15 ;

-- --------------------------------------------------------

--
-- Table structure for table `tables`
--

CREATE TABLE IF NOT EXISTS `tables` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `name` varchar(30) COLLATE utf8_bin NOT NULL,
  `user_group_viewing` int(11) NOT NULL DEFAULT '0',
  `user_group_posting` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=7 ;

--
-- Dumping data for table `tables`
--

INSERT INTO `tables` (`id`, `date`, `name`, `user_group_viewing`, `user_group_posting`) VALUES
(4, '2014-11-29 06:55:56', 'Announcements', 0, 2),
(5, '2014-11-29 06:55:56', 'General', 0, 0),
(6, '2014-11-29 06:55:56', 'Trash', 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `topics`
--

CREATE TABLE IF NOT EXISTS `topics` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `table` int(11) NOT NULL,
  `name` varchar(35) COLLATE utf8_bin NOT NULL,
  `user` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user` (`user`),
  KEY `table` (`table`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=24 ;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(30) COLLATE utf8_bin NOT NULL,
  `password` varchar(32) COLLATE utf8_bin NOT NULL,
  `email` varchar(50) COLLATE utf8_bin NOT NULL,
  `default_group` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`),
  UNIQUE KEY `email` (`email`),
  KEY `default_group` (`default_group`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=15 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `name`, `password`, `email`, `default_group`) VALUES
(7, 'Oskar', '49174e529aa19bf1de200d3594bba6ff', 'oskar.danielsson@hotmail.com', 1);

--
-- Triggers `users`
--
DROP TRIGGER IF EXISTS `addNewUserToRegularUserGroup`;
DELIMITER //
CREATE TRIGGER `addNewUserToRegularUserGroup` AFTER INSERT ON `users`
 FOR EACH ROW INSERT INTO usersgroups (userid, groupid)
VALUES (NEW.id, 1)
//
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `usersgroups`
--

CREATE TABLE IF NOT EXISTS `usersgroups` (
  `userid` int(11) NOT NULL,
  `groupid` int(11) NOT NULL,
  `moderator` tinyint(1) NOT NULL DEFAULT '0',
  UNIQUE KEY `unique` (`userid`,`groupid`),
  KEY `userid` (`userid`),
  KEY `groupid` (`groupid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `usersgroups`
--

INSERT INTO `usersgroups` (`userid`, `groupid`, `moderator`) VALUES
(7, 1, 1),
(7, 2, 1);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `logins`
--
ALTER TABLE `logins`
  ADD CONSTRAINT `logins_ibfk_1` FOREIGN KEY (`user`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `posts`
--
ALTER TABLE `posts`
  ADD CONSTRAINT `posts_ibfk_1` FOREIGN KEY (`topic`) REFERENCES `topics` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE,
  ADD CONSTRAINT `posts_ibfk_2` FOREIGN KEY (`user`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE;

--
-- Constraints for table `topics`
--
ALTER TABLE `topics`
  ADD CONSTRAINT `topics_ibfk_1` FOREIGN KEY (`user`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE,
  ADD CONSTRAINT `topics_ibfk_2` FOREIGN KEY (`table`) REFERENCES `tables` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE;

--
-- Constraints for table `usersgroups`
--
ALTER TABLE `usersgroups`
  ADD CONSTRAINT `usersgroups_ibfk_1` FOREIGN KEY (`userid`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `usersgroups_ibfk_2` FOREIGN KEY (`groupid`) REFERENCES `groups` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
