#include "ServerOP.h"


ServerOP::ServerOP(string jsonFile)
{
	// 解析json文件, 读文件 -> Value
	ifstream ifs(jsonFile);
	Reader r;
	Value root;
	r.parse(ifs, root);
	// 将root中的键值对value值取出
	m_serverID = root["ServerID"].asString();
	m_port = root["Port"].asInt();
	m_dbUser = root["dbUser"].asString();
	m_dbPassword = root["dbPasswd"].asString();
	m_dbName = root["dbName"].asString();
	// 共享内存
	string shmKey = root["ShmKey"].asString();
	int maxNode = root["ShmMaxNode"].asInt();
	m_shm = new SecKeyShm(shmKey, maxNode);
}

ServerOP::~ServerOP()
{
	if (!m_server)
	{
		delete m_server;
		m_shm->delShm();	// 标记删除
		delete m_shm;
	}
}

void ServerOP::startServer()
{
	m_server = new TcpServer;
	m_server->setListen(m_port);
	while (1)
	{
		cout << "等待客户端连接...." << endl;
		TcpSocket* server = m_server->acceptConnet();
		if (server == nullptr)
		{
			continue;
		}
		cout << "客户端连接成功...." << endl;
		// 创建子线程
		pthread_t tid;
		// 这个回调可以是类的静态函数, 类的友元函数, 普通的函数
		pthread_create(&tid, NULL, workHard, this);
		m_list.insert(make_pair(tid, server));
		pthread_detach(tid);
	}
}


void* ServerOP::working(void* arg)
{
	return nullptr;
}



string ServerOP::seckeyConsult(RequestMsg* reqMsg)
{
	// 0. 对签名进行校验 -> 公钥解密 -> 得到公钥
	// 将收到的公钥数据写入本地磁盘
	ofstream ofs("public.pem");
	ofs << reqMsg->data();
	ofs.close();
	// 创建非对称加密对象
	ResponseInfo info;
	RsaCrypto rsa("public.pem", false);
	// 创建哈希对象
	Hash h(HashType::T_SHA224);
	h.addData(reqMsg->data());
	bool bl = rsa.rsaVerify(h.result(), reqMsg->sign());
	if (!bl)
	{
		info.status = false;
		cout << "签名校验失败!!!" << endl;
	}
	else
	{
		// 1. 生成随机字符串
		//   对称加密的秘钥, 使用对称加密算法 aes, 秘钥长度: 16, 24, 32byte
		string randStr = getRandStr(Len16);
		// 2. 通过公钥加密
		string seckey = rsa.rsaPubKeyEncrypt(randStr);
		// 3. 初始化回复的数据
		info.clientID = reqMsg->clientid();
		info.serverID = m_serverID;
		info.data = seckey;
		info.status = true;

		//cout << "密钥" << randStr << endl;
		//创建保存的类
		NodeSHMInfo node;
		strcpy(node.clientID, info.clientID.data());
		strcpy(node.serverID, info.serverID.data());
		strcpy(node.seckey, randStr.c_str());
		node.status = true;

		// 4.保存到数据库
		bool b = op.connectDB(m_dbUser.data(), m_dbPassword.data(), m_dbName.data());
		if (!b)
		{
			cout << "connectDB faild\n" << endl;
		}
		int res = op.writeSecKey(&node);
		if (res == -1)		// -1表示插入失败
		{
			info.status = node.status = false;
		}
		else
		{
			info.seckeyID = node.seckeyID = res;
			//cout << __FUNCTION__ << ":" << __LINE__ << res << endl;;
			// 5.写入共享内存
			m_shm->shmWrite(&node);
			//cout << __FUNCTION__ << ":" << __LINE__ << endl;
		}

	}



	// 5. 序列化
	CodecFactory* factory = new ResponseFactory(info);
	Codec* c = factory->createCodec();
	string data = c->encodeMsg();
	// 6.释放内存
	delete c;
	delete factory;
	// 7. 发送数据
	return data;
}

string ServerOP::seckeyCheck(RequestMsg* reqMsg)
{
	/*
	string pubKey = reqMsg->data();

	int res;
	ResponseInfo info;
	// 3. 初始化回复的数据
	info.clientID = reqMsg->clientid();
	info.serverID = m_serverID;

	//创建保存的类
	NodeSHMInfo node;
	strcpy(node.clientID, info.clientID.data());
	strcpy(node.serverID, info.serverID.data());

	// 4.保存到数据库
	bool b = op.connectDB(m_dbUser.data(), m_dbPassword.data(), m_dbName.data());
	if (!b)
	{
		cout << "connectDB faild\n" << endl;
	}
	string priKey = reqMsg->sign();
	string  str = op.selectSecKey(&node);
	if (strcmp(str.c_str(), priKey.c_str() == 0)
	{
		res = 0;
	}

	*/


}

string ServerOP::seckeyLogout(RequestMsg* reqMsg)
{
	/*
	string pubKey = reqMsg->data();


		int res;
		ResponseInfo info;
	// 3. 初始化回复的数据
	info.clientID = reqMsg->clientid();
	info.serverID = m_serverID;
	info.data = to_string(res);;
	info.status = true;
	*/
}


void* workHard(void* arg)
{
	sleep(1);
	ServerOP* op = (ServerOP*)arg;
	// 1. 接收客户端数据 -> 编码
	TcpSocket* tcp = op->m_list[pthread_self()];
	string msg = tcp->recvMsg();
	// 2. 反序列化 -> 得到原始数据 RequestMsg 类型
	CodecFactory* factory = new RequestFactory(msg);
	Codec* c = factory->createCodec();
	RequestMsg* req = (RequestMsg*)c->decodeMsg();		// 这个 会自动析构，不用delete
	/*cout << req->cmdtype() << endl;*/
	// 3. 取出数据
	// 判断客户端是什么请求
	string data;
	switch (req->cmdtype())
	{
	case CONSULT:
		// 秘钥协商
		data = op->seckeyConsult(req);
		break;
	case CHECK:
		// 秘钥校验
		data = op->seckeyCheck(req);
		break;
	case Logout:
		data = op->seckeyLogout(req);
		// 密钥注销
	default:
		data = string("SEND ERROR");
		break;
	}
	tcp->sendMsg(data);
	delete c;
	delete factory;
	// tcp对象如何处理
	tcp->sendMsg(data);
	tcp->disConnect();
	op->m_list.erase(pthread_self());
	delete tcp;

	return nullptr;
}

string ServerOP::getRandStr(int num)
{
	srand(time(NULL));	// 以当前时间为种子
	string retStr = string();
	char* buf = "~`@#$%^&*()_+=-{}[];':";
	for (int i = 0; i < num; ++i)
	{
		int flag = rand() % 4;
		switch (flag)
		{
		case 0:	// 0-9
			retStr.append(1, rand() % 10 + '0');
			break;
		case 1:	// a-z
			retStr.append(1, rand() % 26 + 'a');
			break;
		case 2:	// A-Z
			retStr.append(1, rand() % 26 + 'A');
			break;
		case 3:	// 特殊字符
			retStr.append(1, buf[rand() % strlen(buf)]);
			break;
		}
	}
	return retStr;
}


