#pragma once
#include <string>
#include <json/json.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "RsaCrypto.h"
#include "Hash.h"
#include "Codec.h"
#include "RequestFactory.h"
#include "TcpSocket.h"
#include "ResponseFactory.h"
#include "SecKeyShm.h"
#include "NodeSHMInfo.h"	
using namespace std;
using namespace Json;

class ClientInfo
{
public:
	string serverID;
	string clientID;
	string ip;
	unsigned short port;
};

enum Command
{
	CONSULT = 1,	//密钥协商
	CHECK,		//密钥校验
	Logout		//密钥注销
};

class ClientOP
{
public:
	explicit ClientOP(string jsonFile);
	~ClientOP();

	/// <summary>
	/// 密钥协商
	/// </summary>
	bool secKeyConsult();
	/// <summary>
	/// 密钥校验
	/// </summary>
	bool seckeyCheck();
	/// <summary>
	/// 密钥注销
	/// </summary>
	bool seckeyLogout();
private:
	ClientInfo m_info;
	SecKeyShm* m_shm;
	string priKey;
	int priSecKeyID;

};

