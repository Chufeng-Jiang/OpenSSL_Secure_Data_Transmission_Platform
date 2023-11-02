#pragma once
#include "BaseShm.h"

class NodeSHMInfo
{
public:
	NodeSHMInfo() : status(0), seckeyID(0)
	{
		bzero(clientID, sizeof(clientID));
		bzero(serverID, sizeof(serverID));
		bzero(seckey, sizeof(seckey));
	}
	int status;		// 秘钥状态: 1可用, 0:不可用
	int seckeyID;	// 秘钥的编号
	char clientID[12];	// 客户端ID, 客户端的标识
	char serverID[12];	// 服务器ID, 服务器标识
	char seckey[128];	// 对称加密的秘钥
};

class SecKeyShm : public BaseShm
{
public:
	//  通过 key 构建共享内存
	SecKeyShm(int key, int maxNode);
	// 通过 path 构建共享内存
	SecKeyShm(string pathName, int maxNode);
	// 析构
	~SecKeyShm()  = default;

	// 共享内存初始化
	void shmInit();

	// 写入共享内存   把传入的 对象写入共享内存
	int shmWrite(NodeSHMInfo* pNodeInfo);

	// 读取共享内存   把共享内存内的 对象读出来  查找和  clientID都serverID  相同的节点
	NodeSHMInfo shmRead(string clientID, string serverID);

private:

	// 共享内存 可以存 NodeSHMInfo 的 最大个数
	int m_maxNode;
};

