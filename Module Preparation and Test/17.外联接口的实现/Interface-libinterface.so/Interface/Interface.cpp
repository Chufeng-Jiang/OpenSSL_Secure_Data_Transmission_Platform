#include "Interface.h"
#include <json/json.h>
#include <fstream>
#include "SecKeyShm.h"
#include "AesCrypto.h"
using namespace std;

Interface::Interface(string jsonFile)
{
	// 解析json文件
	// 1. 得到流对象 -> 读文件
	ifstream ifs(jsonFile);
	// 2. 创建json Reader 
	Json::Reader rd;
	// 3. 调用Reader对象 parse, 初始化一个Value对象
	Json::Value root;
	rd.parse(ifs, root);
	// 4. 读Value对象中的数据
	cout << "读取ServerID:" << endl;
	string serverID = root["ServerID"].asString();
	cout << serverID << endl;
	cout << "读取ClientID" << endl;
	string clientID = root["ClientID"].asString();
	cout << clientID << endl;
	cout << "读取Shmkey" << endl;
	string shmkey = root["ShmKey"].asString();
	cout << shmkey << endl;
	cout << "读取maxNode" << endl;
	int maxNode = root["ShmMaxNode"].asInt();
	cout << maxNode << endl;

	// 读共享内存，查找对应的秘钥
	SecKeyShm shm(shmkey, maxNode);
	cout << "共享内存对象创建成功" << endl;
	// 得到秘钥
	NodeSecKeyInfo node = shm.shmRead(clientID, serverID);
	m_key = string(node.seckey);
	cout << "得到了共享内存中对称加密的秘钥" << endl;

	//NodeSecKeyInfo node = shm.shmFirstNode();
	//m_secKeyID = node.seckeyID;

}


Interface::~Interface()
{
}

// "hello,world"
string Interface::encryptData(string data)
{
	//data -> 要加密的数据
	//string head = "666 ";
	//string str = head + data;	// 666helloworld
	//给数据添加一个头，存储KeyID，占4个字节
	
	//构造需要的对象
	AesCrypto aes(m_key);
	string ret = aes.aesCBCEncrypt(data);
	return ret;
}

string Interface::decryptData(string data)
{
	//先读接收到的数据的前4个字节

	//根据这个ID读共享内存 -> 秘钥 -> 解密
	AesCrypto aes(m_key);
	return aes.aesCBCDecrypt(data);
}
