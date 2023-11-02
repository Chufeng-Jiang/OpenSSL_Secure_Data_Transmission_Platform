#include "Server.h"


Server::Server(string jsonFile)
{

	// 解析json文件, 读文件 -> Value
	ifstream ifs(jsonFile);
	Reader r;
	Value root;
	r.parse(ifs, root);
	// 将root中的键值对value值取出
	m_port = root["Port"].asInt();
	// 共享内存
	string shmKey = root["ShmKey"].asString();
	int maxNode = root["ShmMaxNode"].asInt();
	m_shm = new SecKeyShm(shmKey, maxNode);


}


int Server::GetFileSize(string dirname)
{
	//通过系统调用直接得到文件的大小
	struct stat buf;
	if (stat(dirname.c_str(), &buf) < 0)
		return 0;
	return (unsigned long)buf.st_size;
}

void Server::startServer()
{

	m_server = new TcpServer;
	m_pool = new ThreadPool(8, 24);

	m_server->setListen(m_port);


	while (1)
	{
		cout << "等待客户端连接...." << endl;
		TcpSocket* socket = m_server->acceptConnet();
		if (socket == nullptr)
		{
			continue;
		}
		cout << "客户端连接成功...." << endl;

		// 先判断密钥
		string str = socket->recvMsg();		// 是阻塞读取---> 方便线程池使用
		int keyid = atoi(str.c_str());
		NodeSHMInfo shmInfo = m_shm->shmRead(keyid);
		if (string(shmInfo.seckey).empty())		//为空
		{
			str = string{ "key error" };   // 密钥错误
		}
		else					//不为空
		{
			str = string{ "key pass" };		// 密钥通过
		}

		socket->sendMsg(str);		// 回复是否有效	，不加密
		string key = string(shmInfo.seckey);		// 该套接字对应的密钥
		ThreadInfo* info = new ThreadInfo{ key };
		// 初始化info
		info->m_socket = socket;					// 套接字

		/////
		Task t;
		t.arg = info;
		t.function = working;

		m_pool->addPoolTask(t);

	}
}

void* Server::working(void* arg)
{

	//密钥通过后，会再次发数据过来
	// 1.0 解析传过来的数据
	ThreadInfo* info = (ThreadInfo*)arg;

	// 1.1 解密数据
	string str = info->m_socket->recvMsg();
	string msg = info->aes->aesCBCDecrypt(str);
	// 1.2 分析数据
	if (msg.compare(string{ "down" }) == 0)
	{
		string d = info->aes->aesCBCEncrypt(string{ "OK" });		// 加密,OK 可以下载
		info->m_socket->sendMsg(d);
		info->m_mode = LOAD;
	}
	else if (msg.compare(string{ "up" }) == 0)
	{
		info->m_mode = UP;
	}
	else
	{
		info->m_mode = MSG;
	};
	// 2.0 根据数据执行对应的操作
	switch (info->m_mode)
	{
	case MODE::MSG:		//1对1聊天
	{
		string sdata;
		string rdata;
		while (1)
		{
			cout << "> ";
			pthread_mutex_lock(&info->m_lock);
			cin >> sdata;									// 从终端读取
			pthread_mutex_unlock(&info->m_lock);

			if (sdata.compare(string{ "exit" }) == 0)		// 如果你想退出,就退出
			{
				info->m_socket->sendMsg(info->aes->aesCBCEncrypt(string{ "exit" }));
				break;
			}
			info->m_socket->sendMsg(info->aes->aesCBCEncrypt(sdata));		// 回复
			rdata = info->aes->aesCBCDecrypt(info->m_socket->recvMsg());
			cout << "<: " << rdata << endl;;
			if (rdata.compare(string{ "exit" }))	//如果收到exit，退出
			{
				break;
			}

		}
		break;
	}

	case MODE::LOAD:	//下载
	{
		string ld = info->m_socket->recvMsg();				// 接收
		ld = info->aes->aesCBCDecrypt(ld);
		FILE* file = fopen(ld.c_str(), "r");
		if (NULL == file)
		{

			cout << "打开 " << ld << " 失败" << endl;
			info->m_socket->sendMsg(info->aes->aesCBCEncrypt(string{ "文件没找到" }));			// 回复文件查找失败
		}
		else
		{
			fclose(file);
			info->m_fileName = ld;
			info->m_length = GetFileSize(ld);
			cout << "文件大小 ：" << info->m_length << endl;
			info->m_socket->sendMsg(info->aes->aesCBCEncrypt(to_string(info->m_length)));			// 返回大小
			info->up();
		}
		break;
	}

	case MODE::UP:		// 上传
	{

		break;
	}

	default:
		break;
	}

	delete info;		//清理内存
}



