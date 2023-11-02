#include "Client.h"

Client::Client(string jsonFile)
{
	// 解析json文件, 读文件 -> Value
	ifstream inf(jsonFile);
	Reader r;
	Value root;
	r.parse(inf, root);
	// 将root中的键值对value值取出
	m_ip = root["ip"].asString();
	m_port = root["port"].asInt();
	cout << "IP : " << m_ip << ",端口 : " << m_port << endl;
	// 共享内存
	string shmKey = root["ShmKey"].asString();
	int maxNode = root["ShmMaxNode"].asInt();
	m_shm = new SecKeyShm(shmKey, maxNode);
	init();

}

Client::~Client()
{
	delete m_aes;
	delete m_shm;
	m_socket->disConnect();
	delete m_socket;
}


void Client::init()
{

	NodeSHMInfo node = m_shm->shmFirstRead();
	m_keyid = node.seckeyID;
	m_key = node.seckey;
	m_aes = new AesCrypto(m_key);
	m_socket->connectToHost(m_ip, m_port);

}

void Client::start()
{
	m_socket->sendMsg(to_string(m_keyid));	// 发送密钥号
	string msg = m_socket->recvMsg();	//读取
	if (msg.compare(string{ "key error" }) == 0)
	{
		cout << "密钥不存在，退出程序" << endl;
		exit(1);
	}
	else if (msg.compare(string{ "key pass" }) == 0)
	{
		cout << "密钥检测成功" << endl;
	}


}

void Client::load(string dirname)
{

	// 写入 | 二进制| 追加
#if 0
	string msg = {};
	ofstream outFile(dirname.c_str(), ios::out | ios::binary);
	while (outFile.write(msg.c_str(), msg.length()))
	{
		msg = m_aes->aesCBCDecrypt(m_socket->recvMsg());
	}

	outFile.close();
#else
	string msg;
	int size = 0;
	int ret = 0;
	cout << "开始下载 ...." << endl;
	int fd = open(dirname.c_str(), O_CREAT | O_RDWR, 0664);

	while (1)
	{
		//memset(buffer, 0, 8192);
		//char* buffer = new char[8192];
		//read(m_socket->m_socket, buffer, sizeof(buffer));
		//ret = write(fd, buffer, sizeof(buffer));		//不加密接收

		msg = m_aes->aesCBCDecrypt(m_socket->recvMsg("file"));		// 循环接受加密的文件数据数据流
		ret = write(fd, msg.data(), msg.length());

		size += ret;
		if (size >= m_len + 400)
		{
			cout << "下载完成" << endl;
			break;
		}
	}
	//delete buffer;
	close(fd);
#endif
	return;

}

void Client::up(string fileName)
{
	ifstream r(fileName, ios::in | ios::binary);
	char* buffer = new char[8192];
	while (!r.eof())
	{
		memset(buffer, 0, 8192);
		r.readsome(buffer, 8192);
		string data{ buffer };
		m_socket->sendMsg(m_aes->aesCBCEncrypt(data));		// 循环发送加密的文件数据数据流
	}		//发送完成
	delete buffer;
	r.close();
}


void Client::msg()
{
	while (1)
	{
		string sdata;
		string rdata;
		cout << "<: " << (rdata = m_aes->aesCBCDecrypt(m_socket->recvMsg())) << endl;
		if (rdata.compare(string{ "exit" }))	//如果收到exit，退出
		{
			break;
		}

		cout << "> ";
		cin >> sdata;
		if (sdata.compare(string{ "exit" }))	//如果你想退出，就输入退出
		{
			m_socket->sendMsg(m_aes->aesCBCEncrypt(string{ "exit" }));
			break;
		}
		m_socket->sendMsg(m_aes->aesCBCEncrypt(sdata));

	}
}


int Client::GetFileSize(string dirname)
{
	//通过系统调用直接得到文件的大小
	struct stat buf;
	if (stat(dirname.c_str(), &buf) < 0)
		return 0;
	return (unsigned long)buf.st_size;
}
