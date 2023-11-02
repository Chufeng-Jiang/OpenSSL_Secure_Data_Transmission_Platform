/*
Navicat MySQL Data Transfer
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '123456';
Source Server         : 192.168.78.251-bj24
Source Server Version : 50620
Source Host           : 192.168.78.251:3306
Source Database       : mydb66

Target Server Type    : MYSQL
Target Server Version : 50620
File Encoding         : 65001

Date: 2017-10-10 09:53:50
*/
 
create database securedata DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

use securedata;

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for keysn
-- ----------------------------
DROP TABLE IF EXISTS `keysn`;
CREATE TABLE `keysn` (
  `ikeysn` int(12) NOT NULL,
  PRIMARY KEY (`ikeysn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of keysn
-- ----------------------------
INSERT INTO `keysn` VALUES ('1');

-- ----------------------------
-- Table structure for seckeyinfo
-- ----------------------------
DROP TABLE IF EXISTS `seckeyinfo`;
CREATE TABLE `seckeyinfo` (
  `clientid` int(4) DEFAULT NULL,
  `serverid` int(4) DEFAULT NULL,
  `keyid` int(9) NOT NULL,
  `createtime` date DEFAULT NULL,
  `state` int(4) DEFAULT NULL,
  `seckey` varchar(512) DEFAULT NULL,
  PRIMARY KEY (`keyid`),
  KEY `seckeynode_serverid_fk` (`serverid`),
  KEY `IX_seckeyinfo_clientid` (`clientid`),
  CONSTRAINT `seckeynode_clientid_fk` FOREIGN KEY (`clientid`) REFERENCES `secnode` (`id`),
  CONSTRAINT `seckeynode_serverid_fk` FOREIGN KEY (`serverid`) REFERENCES `secnode` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of seckeyinfo
-- ----------------------------

-- ----------------------------
-- Table structure for secnode
-- ----------------------------
DROP TABLE IF EXISTS `secnode`;
CREATE TABLE `secnode` (
  `id` int(4) NOT NULL,
  `name` varchar(512) NOT NULL,
  `nodedesc` varchar(512) DEFAULT NULL,
  `createtime` date DEFAULT NULL,
  `authcode` int(12) DEFAULT NULL,
  `state` int(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of secnode
-- ----------------------------
INSERT INTO `secnode` VALUES ('0001', 'Internet Banking Center', 'New York Finance Street', '2023-07-15', '1', '0');
INSERT INTO `secnode` VALUES ('1111', 'California Branch', 'Winema Cmn', '2023-07-15', 1111, 0);

-- ----------------------------
-- Table structure for srvcfg
-- ----------------------------
DROP TABLE IF EXISTS `srvcfg`;
CREATE TABLE `srvcfg` (
  `key` varchar(64) DEFAULT NULL,
  `valude` varchar(128) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of srvcfg
-- ----------------------------
INSERT INTO `srvcfg` VALUES ('secmng_server_ip', '192.168.111.130');

-- ----------------------------
-- Table structure for tran
-- ----------------------------
DROP TABLE IF EXISTS `tran`;
CREATE TABLE `tran` (
  `iID` int(12) NOT NULL,
  `tran_operator` int(12) DEFAULT NULL,
  `trantime` date DEFAULT NULL,
  `tranid` int(4) DEFAULT NULL,
  `trandesc` varchar(512) DEFAULT NULL,
  PRIMARY KEY (`iID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tran
-- ----------------------------
SET FOREIGN_KEY_CHECKS=1;
