#pragma once
#include <mysql/mysql.h>
#include <unistd.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include "NodeSHMInfo.h"
using namespace std;


class MysqlOP
{
private:
	MYSQL* sql;
	pthread_mutex_t m_mutex;
public:
	MysqlOP();
	~MysqlOP();

	// 初始化环境连接数据库
	bool connectDB(string user, string passwd, string db);
	int writeSecKey(NodeSHMInfo* pNode);
	string selectSecKey(NodeSHMInfo* pNode);
	void close();

private:
	// 获取当前时间, 并格式化为字符串
	string getCurTime();

};
