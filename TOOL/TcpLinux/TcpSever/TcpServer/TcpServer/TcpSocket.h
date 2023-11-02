#ifndef __TCPSOCKET__
#define __TCPSOCKET__
#pragma once
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
/*用于通信的套接字类*/
// 超时的时间
static const int TIMEOUT = 8192;
class TcpSocket
{
	///////操作////////
public:
	TcpSocket() = default;
	TcpSocket(int connect);
	~TcpSocket() = default;

	// 连接服务器
	int connectToHost(string ip, unsigned short port, int timeout = TIMEOUT);
	// 发送数据
	int sendMsg(string sendData, int timeout = TIMEOUT);
	// 接收数据
	string recvMsg(int timeout = TIMEOUT);
	// 断开连接
	void disconnect();
private:
	// 设置I/O非阻塞
	int setNoBlock(int fd);
	// 设置I/O阻塞
	int setBlock(int fd);
	// 读超时检测函数，不包含读操作
	int readTimeout(unsigned int wait_seconds);
	// 写超时检测函数，不包含写操作
	int writeTimeout(unsigned int wait_seconds);
	// 带连接超时的connect函数
	int connectTimeout(struct sockaddr_in* addr, unsigned int wait_seconds);
	// 每次从缓冲区中读取n个字符
	int readn(void* buffer,int count);
	// 每次往缓冲区写入n个字符
	int writen(const void* buffer, int count);
	 
	
	///////数据////////
public:
	enum ErrorType
	{
		ParamError = 3001,
		TimeoutError,
		PeerCloseError,
		MallocError
	};
private:
	int m_socket;	//通信的文件描述符
};

#endif // ! __TCPSOCKET__



