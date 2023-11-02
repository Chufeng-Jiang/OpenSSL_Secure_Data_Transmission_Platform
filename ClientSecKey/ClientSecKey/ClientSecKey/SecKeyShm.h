#pragma once
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
	~SecKeyShm() = default; // 析构时不delshm，只能在使用对象时，主动标记删除

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

