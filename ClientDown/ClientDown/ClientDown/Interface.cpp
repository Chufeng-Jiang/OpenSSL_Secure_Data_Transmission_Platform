#include "Interface.h"

Interface::Interface(string json)
{
	// 解析json文件
	// 1. 得到流对象 -> 读文件
	ifstream ifs(json);
	// 2. 创建json Reader 
	Json::Reader rd;
	// 3. 调用Reader对象 parse, 初始化一个Value对象
	Json::Value root;
	rd.parse(ifs, root);
	// 4. 对Value对象中的数据
	string shmkey = root["ShmKey"].asString();
	string serverID = root["ServerID"].asString();
	string clientID = root["ClientID"].asString();
	int maxNode = root["ShmMaxNode"].asInt();

	// 读共享内存
	SecKeyShm shm(shmkey, maxNode);
	// 得到秘钥
	NodeSHMInfo node = shm.shmRead(clientID, serverID);
	m_key = string(node.seckey);
}


Interface::~Interface()
{
}

// "hello,world"
string Interface::encryptData(string data)
{
	// data -> 要加密的数据
	AesCrypto aes(m_key);
	string ret = aes.aesCBCEncrypt(data);
	return ret;
}

string Interface::decryptData(string data)
{
	AesCrypto aes(m_key);
	return aes.aesCBCDecrypt(data);
}
