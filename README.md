# 基于openssl实现的密钥分发模块

ClientDown  文件下载客户端

ClientSecKey 密钥传输客户端

(未使用interface完成密钥校验，而是客户端完成密钥校验)

ServerDown 文件下载服务器

ServerSecKey  密钥传输服务器

该项目是基于VS2022开发的linux项目
连接到服务器后，打开mysql，在指定db目录下执行以下语句



```sql
-- 创建 网点信息表 --编号 名称 描述 授权码 状态(0可用  1不可用)

CREATE TABLE `SECNODE` (
  `id` varchar(32) NOT NULL COMMENT '编号',
  `name` varchar(128) NOT NULL COMMENT '名称',
  `nodedesc` varchar(512) DEFAULT NULL COMMENT '描述',
  `createtime` varchar(20) DEFAULT NULL COMMENT '密钥产生时间',
  `authcode` int DEFAULT NULL COMMENT '授权码',
  `state` int DEFAULT NULL COMMENT '状态(0可用  1不可用)',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



INSERT INTO SECNODE VALUES('China-HangZhou-001', '大中华区华东分区杭州市1号机', '服务机:杭州市萧山区翻斗科技中心3号楼', '2022-08-19',1035, 0);
INSERT INTO SECNODE VALUES('China-Herbin-002', '大中华区东北分区哈尔滨市2号机', '客户机:哈尔滨市南岗区中央大街36号', '2022-08-19', 2684, 0);
-- 创建 网点密钥表, 客户端网点 服务器端网点 密钥号 密钥产生时间 密钥状态 



CREATE TABLE `SECKEYINFO` (
  `clientid` varchar(32) DEFAULT NULL COMMENT '客户端网点',
  `serverid` varchar(32) DEFAULT NULL COMMENT '服务器端网点',
  `keyid` int NOT NULL AUTO_INCREMENT COMMENT '密钥号',
  `createtime` varchar(20) DEFAULT NULL COMMENT '密钥产生时间',
  `state` int DEFAULT NULL COMMENT '密钥状态',
  `seckey` varchar(512) DEFAULT NULL COMMENT '密钥',
  PRIMARY KEY (`keyid`),
  KEY `client_fk` (`clientid`),
  KEY `server_fk` (`serverid`),
  CONSTRAINT `SECKEYINFO_ibfk_client` FOREIGN KEY (`clientid`) REFERENCES `SECNODE` (`id`),
  CONSTRAINT `SECKEYINFO_ibfk_server` FOREIGN KEY (`serverid`) REFERENCES `SECNODE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
```

在双端分别创建对应的SHM,写好配置文件
```json
//ClientSecKey
{
    "ClientID":"China-Herbin-002",
    "ServerID":"China-HangZhou-001",
    "ServerIP":"192.168.168.132",
    "ServerPort":8888,
    "ShmKey":"./shm",
    "ShmMaxNode":1
}

// ServerSecKey
{
    "ServerID":"China-HangZhou-001",
    "Port":8888,
    "dbUser":"root",
    "dbPasswd":"root",
    "dbName":"seckeydb",
    "ShmKey":"./shm",
    "ShmMaxNode":32

}

// ClientDown
{
    "ip":"192.168.168.132",
    "port":10018,
    "ShmKey":"/home/lihua/projects/ClientSecKey/bin/x64/Debug/shm",
    "ShmMaxNode":1
}


// ServerDown
{
    "Port":10018,
    "ShmKey":"/home/lihua/projects/ServerSecKey/bin/x64/Debug/shm",
    "ShmMaxNode":32
}
```





