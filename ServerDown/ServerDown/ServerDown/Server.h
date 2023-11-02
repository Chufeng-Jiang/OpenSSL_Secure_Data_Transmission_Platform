#pragma once
#include <string> 
#include "ThreadPool.h"
#include "TcpServer.h"
#include "AesCrypto.h"
#include "SecKeyShm.h"
#include "json/json.h"
#include <unistd.h>
#include <sys/stat.h>


using namespace std;
using namespace Json;
const int LENGTH = 8192;		//8K
enum MODE
{
	LOAD, //下载
	UP,   //上传 
	MSG   //发信息
};
class ThreadInfo
{
public:

	ThreadInfo(string key) :m_key{ key }
	{
		aes = new AesCrypto(m_key);
		pthread_mutex_init(&m_lock, NULL);
	};
	~ThreadInfo()
	{
		m_socket->disConnect();
		delete m_socket;
		delete aes;
		pthread_mutex_destroy(&m_lock);
	};
	TcpSocket* m_socket;	//套接字
	AesCrypto* aes;		//加解密对象
	string m_key;		//密钥
	MODE m_mode;	//模式
	pthread_mutex_t m_lock; //锁

	string m_fileName;	// 文件名称
	int m_length;		// 文件大小

	void up()	//上传
	{
#if 0

		char* buffer = new char[1024];
		ifstream inFile(m_fileName.c_str(), ios::in | ios::binary);
		while (inFile.read(buffer, sizeof(buffer)))
		{
			cout << "读取了 " << inFile.gcount() << " 个字节" << endl;
			string data{ buffer };
			m_socket->sendMsg(aes->aesCBCEncrypt(data));		// 循环发送加密的文件数据数据流
			memset(buffer, 0, 1024);
		}
		delete buffer;
		inFile.close();
#else
		int fd = open(m_fileName.c_str(), O_RDONLY);
		char* buffer = new char[1024];
		int size = 0;
		while (1)
		{
			memset(buffer, 0, 1024);
			int ret = read(fd, buffer, sizeof(buffer));		// 从文件中读
			//if (ret == EOF)
			//{
			//	cout << "读完了" << endl;
			//	break;
			//}
			if (ret > 0)
			{
				size += ret;
			}

			string data{ buffer };
			m_socket->sendMsg(aes->aesCBCEncrypt(data));// 循环发送加密的文件数据数据流
			//ret = write(m_socket->m_socket, buffer, sizeof(buffer));		// 不加密发送

			//if (size >= m_length)
			//{
			//	cout << "发送完成" << endl;
			//	break;
			//}
		}		//发送完成
		delete buffer;
		close(fd);
#endif
	}
	string down()		//下载
	{

	}


};

class Server
{
private:
	ThreadPool* m_pool;	// 线程池对象
	TcpServer* m_server;		//服务器
	int m_port;		//端口
	SecKeyShm* m_shm;	//共享内存

public:

	Server(string jsonFile);
	~Server()
	{
		delete m_pool;
		delete m_server;
	}
	void startServer();
	static void* working(void* arg);
	static int GetFileSize(string dirName);

};

