#pragma once
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>
#include <json/json.h>
#include "TcpServer.h"
#include "RequestFactory.h"
#include "ResponseFactory.h"
#include "BaseShm.h"
#include "AesCrypto.h"
#include "TcpServer.h"
#include "TcpSocket.h"
#include "RsaCrypto.h"
#include "Hash.h"
#include "TcpSocket.h"
#include "SecKeyShm.h"
#include "MysqlOP.h"

using namespace std;
using namespace Json;

enum Command
{
	CONSULT = 1,	//密钥协商
	CHECK,		//密钥校验
	Logout		//密钥注销
};


// 处理客户端请求
class ServerOP
{
public:
	enum KeyLen { Len16 = 16, Len24 = 24, Len32 = 32 };
	explicit ServerOP(string jsonFile);
	~ServerOP();
	// 启动服务器
	void startServer();
	// 线程工作函数 -> 推荐使用
	static void* working(void* arg);
	// 友元破坏了类的封装
	friend void* workHard(void* arg);
	// 秘钥协商
	string seckeyConsult(RequestMsg* reqMsg);
	// 密钥校验
	string seckeyCheck(RequestMsg* reqMsg);

	// 密钥注销
	string seckeyLogout(RequestMsg* reqMsg);

private:
	// 生成随机字符串 对称加密的密钥
	string getRandStr(int num);
private:
	string m_serverID;
	unsigned short m_port;
	string  m_dbUser;
	string m_dbPassword;
	string m_dbName;
	map<pthread_t, TcpSocket*> m_list;
	TcpServer* m_server = nullptr;
	SecKeyShm* m_shm;
	MysqlOP op;
};

void* workHard(void* arg);
