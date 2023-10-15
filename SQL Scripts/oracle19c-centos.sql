-- 01 创建表空间
-- 注意表空间的路径 根据实际安装环境进行调整
-- /opt/oracle/oradata/ORCLCDB是我自己安装在CentOS8上的Oracle的数据目录

CREATE TABLESPACE ts_seckey_admin 
    LOGGING  
    DATAFILE '/opt/oracle/oradata/ORCLCDB/ts_seckeymng_admin.dbf' SIZE 50M 
    EXTENT MANAGEMENT LOCAL;


CREATE TABLESPACE ts_seckey_op
    LOGGING 
    DATAFILE '/opt/oracle/oradata/ORCLCDB/ts_seckeymng_op.dbf' SIZE 200M
    EXTENT MANAGEMENT LOCAL;

-- 如果表不够了自动扩充50m    
ALTER DATABASE DATAFILE '/opt/oracle/oradata/ORCLCDB/ts_seckeymng_admin.dbf' AUTOEXTEND ON NEXT   50M MAXSIZE UNLIMITED;
ALTER DATABASE DATAFILE '/opt/oracle/oradata/ORCLCDB/ts_seckeymng_op.dbf' AUTOEXTEND ON NEXT  200M MAXSIZE UNLIMITED; 

commit;


-- 02 创建方案 (创建用户)
CREATE USER c##SECMNG  PROFILE DEFAULT 
    IDENTIFIED BY SECMNG DEFAULT TABLESPACE USERS
    ACCOUNT UNLOCK;

-- 资源和登录权限
GRANT resource TO c##SECMNG;
GRANT create session TO c##SECMNG;
ALTER USER c##SECMNG QUOTA UNLIMITED ON ts_seckey_admin;
ALTER USER c##SECMNG QUOTA UNLIMITED ON ts_seckey_op;
ALTER USER c##SECMNG QUOTA UNLIMITED ON USERS;

-- 创建 网点信息表 --编号 名称 描述 授权码 状态(0可用  1不可用)
CREATE TABLE c##SECMNG.SECNODE(
	id     				char(4) PRIMARY KEY, 
	name     			VARCHAR2(128) NOT NULL,
 	nodedesc      		VARCHAR2(512),
 	createtime			date,
 	authcode			NUMBER(12),
 	state     			NUMBER(4)
)TABLESPACE ts_seckey_admin;

INSERT INTO c##SECMNG.secnode VALUES('0001', 'Internet Banking Center', 'New York Finance Street', '15-July-2023', 1, 0);
INSERT INTO c##SECMNG.secnode VALUES('1111', 'California Branch', 'Winema Cmn', '15-July-2023', 1111, 0);
commit;

-- 创建 网点密钥表, 客户端网点 服务器端网点 密钥号 密钥产生时间 密钥状态 
CREATE TABLE c##SECMNG.SECKEYINFO(
	clientid          	char(4) constraint c##secmng_seckeynode_clientid_fk references c##SECMNG.SECNODE(id),
	serverid          	char(4) constraint c##secmng_seckeynode_serverid_fk references c##SECMNG.SECNODE(id),
	keyid            	NUMBER(9) PRIMARY KEY, 
	createtime			date,
	state				NUMBER(4),
	seckey				VARCHAR2(512)
)TABLESPACE ts_seckey_admin;

--创建索引 在新的表空间上
CREATE  INDEX c##SECMNG.IX_SECKEYINFO_clientid ON c##SECMNG.SECKEYINFO(clientid) TABLESPACE ts_seckey_admin;

commit;


-- keysn序列号
CREATE TABLE c##SECMNG.KEYSN(
	ikeysn 		number(12)  PRIMARY KEY
) TABLESPACE ts_seckey_admin;

INSERT INTO c##SECMNG.KEYSN(ikeysn) VALUES (1);
commit;


CREATE TABLE c##SECMNG.SRVCFG(
	key				VARCHAR2(64),
	valude			VARCHAR2(128)
)TABLESPACE ts_seckey_admin;
	
-- 创建 交易信息表 交易者 交易时间 交易事件 交易描述 （什么人 在什么时间 干了什么事）
CREATE TABLE c##SECMNG.TRAN(
	iID					Number(12) PRIMARY KEY,
 	tran_operator     	NUMBER,
 	trantime			date,
 	tranid          	NUMBER(4),
 	trandesc      		VARCHAR2(512)	
)TABLESPACE ts_seckey_op;


-- 创建索引
CREATE INDEX c##SECMNG.IX_TRAN_tran_operator ON c##SECMNG.TRAN(tran_operator) TABLESPACE ts_seckey_op;

-- 创建触发器 自增字段
CREATE SEQUENCE c##SECMNG.SEQiID INCREMENT BY 1 START WITH 1 
    MAXVALUE 1.0E28 MINVALUE 1 NOCYCLE 
    CACHE 20 NOORDER;
    
CREATE OR REPLACE TRIGGER c##SECMNG.SEQiID
  BEFORE INSERT ON c##SECMNG.TRAN
    for each row
begin
    select c##SECMNG.SEQiID.nextval into :new.iID from dual;
end;
/


INSERT INTO c##SECMNG.TRAN(tran_operator, trantime, tranid, trandesc) VALUES(1, '15-July-2023', 1, 'Create Internet Banking Boss Node - Test Data');

commit;

------停止-----
-- 04创建新用户方案 	通过 SECMNGUSER1 来访问数据库, 让管理终端系统用   
CREATE USER "c##SECMNGADMIN"  PROFILE "DEFAULT" IDENTIFIED BY "123456" DEFAULT TABLESPACE "USERS" ACCOUNT UNLOCK;

GRANT "CONNECT" TO "c##SECMNGADMIN";
GRANT SELECT ANY TABLE TO "c##SECMNGADMIN";

GRANT resource TO "c##SECMNGADMIN";
GRANT create session TO "c##SECMNGADMIN";


GRANT DELETE ON c##SECMNG.SRVCFG TO "c##SECMNGADMIN";
GRANT INSERT ON c##SECMNG.SRVCFG TO "c##SECMNGADMIN";
GRANT UPDATE ON c##SECMNG.SRVCFG TO "c##SECMNGADMIN";


GRANT DELETE ON c##SECMNG.SECNODE TO "c##SECMNGADMIN";
GRANT INSERT ON c##SECMNG.SECNODE TO "c##SECMNGADMIN";
GRANT UPDATE ON c##SECMNG.SECNODE TO "c##SECMNGADMIN";

GRANT DELETE ON c##SECMNG.SECKEYINFO TO "c##SECMNGADMIN";
GRANT INSERT ON c##SECMNG.SECKEYINFO TO "c##SECMNGADMIN";
GRANT UPDATE ON c##SECMNG.SECKEYINFO TO "c##SECMNGADMIN";

GRANT DELETE ON c##SECMNG.TRAN TO "c##SECMNGADMIN";
GRANT INSERT ON c##SECMNG.TRAN TO "c##SECMNGADMIN";
GRANT UPDATE ON c##SECMNG.TRAN TO "c##SECMNGADMIN";

commit;

    
 
-- Insert Into SECMNG.SECKEYINFO(clientid, serverid, keyid, createtime, state, seckey)
-- values ('1111', '0001', 1, to_date('2015-07-14 21:09:09', 'yyyy-mm-dd hh24:mi:ss'), 0, 'zzz')  ;
