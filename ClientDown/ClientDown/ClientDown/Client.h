#pragma once
#include <string>
#include <json/json.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "SecKeyShm.h"
#include "TcpSocket.h"
#include "AesCrypto.h"

using namespace std;
using namespace Json;
class Client
{
public:
	Client(string jsonFile);
	~Client();
	void start();
	void load(string fileName);	//下载
	void up(string fileName);		//上传
	void msg();
	// 共享内存对象
	SecKeyShm* m_shm;
	TcpSocket* m_socket;
	AesCrypto* m_aes;
	int m_len;
private:

	void  init();		// 初始化
	int GetFileSize(string dirname);

	string m_ip;				// 服务器IP
	unsigned short m_port;	    // 端口
	string m_key;	//密钥
	int m_keyid;	//密钥号
};


