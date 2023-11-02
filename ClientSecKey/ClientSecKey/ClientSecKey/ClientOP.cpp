#include "ClientOP.h"

ClientOP::ClientOP(string jsonFile)
{
	// 解析json文件, 读文件 -> Value
	ifstream inf(jsonFile);
	Reader r;
	Value root;
	r.parse(inf, root);
	// 将root中的键值对value值取出
	m_info.serverID = root["ServerID"].asString();
	m_info.clientID = root["ClientID"].asString();
	m_info.ip = root["ServerIP"].asString();
	m_info.port = root["ServerPort"].asInt();
	cout << "IP : " << m_info.ip << ",端口 : " << m_info.port << endl;

	// 共享内存
	string shmKey = root["ShmKey"].asString();
	int maxNode = root["ShmMaxNode"].asInt();
	m_shm = new SecKeyShm(shmKey, maxNode);

}

ClientOP::~ClientOP()
{
	delete m_shm;
}

bool ClientOP::secKeyConsult()
{
	// 0.0 生成密钥对, 将公钥字符串读出
	RsaCrypto rsa;
	// 生成密钥对
	rsa.generateRsakey(1024);
	// 读公钥文件
	ifstream ifs("public.pem");
	stringstream pubkey;
	pubkey << ifs.rdbuf();
	Hash h(HashType::T_SHA224);
	h.addData(pubkey.str());// 对公钥进行哈希运算后再对哈希值签名
	// 1.0 初始化序列化数据
	// 序列化的类对象 <- 工厂类创建
	RequestInfo reqInfo;
	reqInfo.clientID = m_info.clientID;
	reqInfo.serverID = m_info.serverID;
	reqInfo.cmd = Command::CONSULT;
	reqInfo.data = pubkey.str();			// 非对称加密的公钥
	reqInfo.sign = rsa.rsaSign(h.result());	// 公钥的签名
	cout << "签名完成..." << endl;
	CodecFactory* factory = new RequestFactory{ reqInfo };
	Codec* c = factory->createCodec();
	// 1.1 序列化  得到序列化之后的数据, 可以将其发送给服务器端
	string encstr = c->encodeMsg();
	// 1.2 释放资源
	delete c;
	delete factory;

	// 2.0 链接服务器
	TcpSocket* client = new TcpSocket{};
	cout << m_info.ip << ", 端口:" << m_info.port << endl;
	int ret = client->connectToHost(m_info.ip, m_info.port);
	if (ret != 0)
	{
		cout << "连接服务器失败..." << endl;
		return false;
	}
	cout << "连接服务器成功..." << endl;
	// 2.1 发送序列化的数据
	client->sendMsg(encstr);
	// 等待服务器回复
	string msg = client->recvMsg();

	// 3.0 解析服务器数据 -> 解码(反序列化)
	// 数据还原到 RespondMsg
	factory = new ResponseFactory(msg);
	c = factory->createCodec();
	RespondMsg* resData = (RespondMsg*)c->decodeMsg();
	// 3.1 判断状态
	if (!resData->status())
	{
		cout << "秘钥协商失败" << endl;
		return false;
	}
	// 将得到的密文解密
	priKey = rsa.rsaPriKeyDecrypt(resData->data());
	cout << "对称加密的秘钥: " << priKey << endl;

	cout << m_info.clientID << "----------" << m_info.serverID << resData->seckeyid() << endl;

	// 3.2 写入共享内存
	NodeSHMInfo info;
	strcpy(info.clientID, m_info.clientID.data());
	strcpy(info.serverID, m_info.serverID.data());
	strcpy(info.seckey, priKey.data());
	info.seckeyID = resData->seckeyid();
	info.status = true;
	m_shm->shmWrite(&info);
	// 3.3 释放资源

	delete c;
	delete factory;
	client->disConnect();	// // 这是一个短连接, 通信完成, 断开连接
	delete client;
	return true;

}


// 有安全隐患，应该在客户端发送密钥在服务端校验
bool ClientOP::seckeyCheck()
{
	/*
	bool res;
	//生成密钥对, 将公钥字符串读出
	RsaCrypto rsa;
	// 读公钥文件
	ifstream ifs("public.pem");
	stringstream pubkey;
	pubkey << ifs.rdbuf();
	// 1.0 初始化序列化数据
	// 序列化的类对象 <- 工厂类创建
	RequestInfo reqInfo;
	reqInfo.clientID = m_info.clientID;
	reqInfo.serverID = m_info.serverID;
	reqInfo.cmd = Command::CHECK;
	reqInfo.data = pubkey.str();			// 非对称加密的公钥
	reqInfo.sign = priKey;
	CodecFactory* factory = new RequestFactory{ reqInfo };
	Codec* c = factory->createCodec();
	// 1.1 序列化  得到序列化之后的数据, 可以将其发送给服务器端
	string encstr = c->encodeMsg();
	// 1.2 释放资源
	delete c;
	delete factory;

	// 2.0 链接服务器
	TcpSocket* client = new TcpSocket{};
	cout << m_info.ip << ", 端口:" << m_info.port << endl;
	int ret = client->connectToHost(m_info.ip, m_info.port);
	if (ret != 0)
	{
		cout << "连接服务器失败..." << endl;
		return false;
	}
	cout << "连接服务器成功..." << endl;
	// 2.1 发送序列化的数据
	client->sendMsg(encstr);
	// 等待服务器回复
	string msg = client->recvMsg();

	// 3.0 解析服务器数据 -> 解码(反序列化)
	// 数据还原到 RespondMsg
	factory = new ResponseFactory(msg);
	c = factory->createCodec();
	RespondMsg* resData = (RespondMsg*)c->decodeMsg();
	// 将得到的密文解密
	string str = rsa.rsaPriKeyDecrypt(resData->data());
	int x = atoi(str.c_str());
	switch (x)
	{
	case 0:
		cout << "密钥校验成功，密钥可用" << endl;
		res = true;;
	case 1:
		cout << "密钥校验失败，通信端不存在" << endl;
		res = false;
	case 2:
		cout << "密钥校验失败，密钥错误" << endl;
		res = false;
	}
	return res;
	*/
}

bool ClientOP::seckeyLogout()
{
	/*
	bool res;
	//生成密钥对, 将公钥字符串读出
	RsaCrypto rsa;
	// 读公钥文件
	ifstream ifs("public.pem");
	stringstream pubkey;
	pubkey << ifs.rdbuf();
	// 1.0 初始化序列化数据
	// 序列化的类对象 <- 工厂类创建
	RequestInfo reqInfo;
	reqInfo.clientID = m_info.clientID;
	reqInfo.serverID = m_info.serverID;
	reqInfo.cmd = Command::Logout;
	reqInfo.data = pubkey.str();			// 非对称加密的公钥
	reqInfo.sign = priKey;
	CodecFactory* factory = new RequestFactory{ reqInfo };
	Codec* c = factory->createCodec();
	// 1.1 序列化  得到序列化之后的数据, 可以将其发送给服务器端
	string encstr = c->encodeMsg();
	// 1.2 释放资源
	delete c;
	delete factory;

	// 2.0 链接服务器
	TcpSocket* client = new TcpSocket{};
	cout << m_info.ip << ", 端口:" << m_info.port << endl;
	int ret = client->connectToHost(m_info.ip, m_info.port);
	if (ret != 0)
	{
		cout << "连接服务器失败..." << endl;
		return false;
	}
	cout << "连接服务器成功..." << endl;
	// 2.1 发送序列化的数据
	client->sendMsg(encstr);
	// 等待服务器回复
	string msg = client->recvMsg();

	// 3.0 解析服务器数据 -> 解码(反序列化)
	// 数据还原到 RespondMsg
	factory = new ResponseFactory(msg);
	c = factory->createCodec();
	RespondMsg* resData = (RespondMsg*)c->decodeMsg();
	// 将得到的密文解密
	string str = rsa.rsaPriKeyDecrypt(resData->data());
	int x = atoi(str.c_str());
	switch (x)
	{
	case 0:
		cout << "密钥注销成功......" << endl;
		res = true;;
	case 1:
		cout << "密钥注销失败，通信端不存在" << endl;
		res = false;
	case 2:
		cout << "密钥注销失败，密钥错误" << endl;
		res = false;
	}
	return res;
	*/
}
