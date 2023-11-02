#pragma once
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
using namespace std;

class BaseShm
{
public:
	// 通过key打开共享内存
	BaseShm(int key);
	// 通过传递进来的key创建/打开共享内存
	BaseShm(int key, int size);
	// 通过路径打开共享内存
	BaseShm(string name);
	// 通过路径创建/打开共享内存
	BaseShm(string name, int size);
	// 析构
	~BaseShm() = default;
	// 关联
	void* mapShm();
	// 取消关联
	int unmapShm();
	// 标记删除
	int delShm();
	

private:
	// shmget
	int getShmID(key_t key, int shmSize, int flag);

private:
	// 共享内存号
	int m_shmID;
protected:
	// 共享内存的地址
	void* m_shmAddr = NULL;
};

