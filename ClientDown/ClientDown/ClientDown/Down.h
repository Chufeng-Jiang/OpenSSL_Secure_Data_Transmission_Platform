#pragma once
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>//exit函数
#include <sys/stat.h>//stat系统调用获取文件大小
#include <sys/time.h>//获取下载时间
#include <cstdio>
#include <fstream>
#include <sys/socket.h>//套接字
#include <arpa/inet.h>//ip地址处理
#include <fcntl.h>//open系统调用
#include "SocketPool.h"

using namespace std;
class Down
{
private:

	long m_fileLength;//本次需下载文件的大小
	long m_hadDown;//已下载文件大小 
	long m_altFileLength;//文件总大小 

	string m_fileName; //下载文件名
	string m_dirName;//文件保存地址  

	TcpSocket m_socket;

	vector<string> pathName;


public:
	Down(string filePath);
	~Down();
	long  downLoad(long& FileLength);//开始下载
	long merge();
private:
	void GetFileSize();		// 获取文件大小
	long GetFileSize(string dirName);

};

