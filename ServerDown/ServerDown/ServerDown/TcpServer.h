#ifndef __TCPSERVER__
#define __TCPSERVER__
#pragma once
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "TcpSocket.h"

class TcpServer
{
	///////操作////////
public:
	TcpServer() = default;
	~TcpServer() = default;

	//服务器设置监听
	int setListen(const unsigned short port);
	//等待并接受客户端连接请求，默认连接超时时间为8192s
	TcpSocket* acceptConnet(int wait_seconds = 8192);

	void closeFd();
	///////数据////////
private:
	int m_lfd;	//监听的文件描述符
};


#endif // !__TCPSERVER__

