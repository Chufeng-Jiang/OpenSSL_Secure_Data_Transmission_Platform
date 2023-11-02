#pragma once
#include <string.h>
#include <iostream>
#include "BaseShm.h"
#include "NodeSHMInfo.h"


class SecKeyShm : public BaseShm
{
public:
	//  通过 key 构建共享内存
	SecKeyShm(int key, int maxNode);
	// 通过 path 构建共享内存
	SecKeyShm(string pathName, int maxNode);
	// 析构
	~SecKeyShm() = default;

	// 共享内存初始化
	void shmInit();

	// 写入共享内存   把传入的 对象写入共享内存
	int shmWrite(NodeSHMInfo* pNodeInfo);

	// 服务端客户端都可以使用  读取共享内存   把共享内存内的 对象读出来  查找和  clientID都serverID  相同的节点
	NodeSHMInfo shmRead(string clientID, string serverID);

	// 给服务端使用   读取共享内存   把共享内存内的 对象读出来  查找和 keyID  相同的节点 
	NodeSHMInfo shmRead(int keyID);

	// 给客户端使用
	NodeSHMInfo shmFirstRead();

private:

	// 共享内存 可以存 NodeSHMInfo 的 最大个数
	int m_maxNode;
};

