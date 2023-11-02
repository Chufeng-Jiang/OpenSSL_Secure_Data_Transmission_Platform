#include "MysqlOP.h"

MysqlOP::MysqlOP()
{
	sql = nullptr;
	pthread_mutex_init(&m_mutex, NULL);
};

MysqlOP::~MysqlOP()
{

	close();
};

// 初始化环境连接数据库
bool MysqlOP::connectDB(string user, string passwd, string db)
{

	// 1. 初始化环境
	sql = mysql_init(sql); // 创建数据库
	if (sql == nullptr)
	{
		std::cout << "Error:" << mysql_error(sql);
	}


	// 2. 创建连接
	sql = mysql_real_connect(sql, "localhost", user.c_str(), passwd.c_str(), db.c_str(), 3306, NULL, 0);
	if (sql == nullptr)
	{
		std::cout << "Error:" << mysql_error(sql);
	}

	cout << "数据库连接成功..." << endl;
	return true;
}

int MysqlOP::writeSecKey(NodeSHMInfo* pNode)
{


	char sql_insert[1024] = { 0 };
	// keyid是自动增加的2022-09-28 13:54:20
	sprintf(sql_insert, "INSERT INTO SECKEYINFO(clientid, serverid, createtime, state, seckey)	VALUES('%s','%s','%s',%d,'%s')",
		pNode->clientID, pNode->serverID,
		getCurTime().data(), 1, pNode->seckey);
	cout << "insert sql: " << sql_insert << endl;
	int x;

	pthread_mutex_lock(&m_mutex);
	int res = mysql_query(sql, sql_insert);
	//cout << __FUNCTION__ << ":" << __LINE__ << endl;
	if (res == 0)  // 查询成功返回0
	{
		//cout << __FUNCTION__ << ":" << __LINE__ << endl;
		memset(sql_insert, 0, 1024);
		sprintf(sql_insert, "SELECT keyid FROM SECKEYINFO WHERE clientid = '%s' AND serverid ='%s'", pNode->clientID, pNode->serverID);
		res = mysql_query(sql, sql_insert);
		//cout << __FUNCTION__ << ":" << __LINE__ << res << endl;
		if (res == 0)
		{

			MYSQL_RES* result = mysql_store_result(sql);
			//cout << __FUNCTION__ << ":" << __LINE__ << endl;
			if (NULL == result)
			{
				printf("error(%d):%s\n", mysql_errno(sql), mysql_error(sql));
				x = -1;
			}
			else
			{
				MYSQL_ROW row = mysql_fetch_row(result);
				char* filed = row[0];
				string str = filed;
				x = atoi(filed);
				//cout << __FUNCTION__ << ":" << __LINE__ << ":key :" << x << endl;
			}
		}
		else
		{
			//cout << __FUNCTION__ << ":" << __LINE__ << endl;
			printf("error(%d):%s\n", mysql_errno(sql), mysql_error(sql));

			x = -1;
		}
	}
	else
	{
		//cout << __FUNCTION__ << ":" << __LINE__ << endl;
		printf("error(%d):%s\n", mysql_errno(sql), mysql_error(sql));

		x = -1;
	}
	pthread_mutex_unlock(&m_mutex);
	//cout << __FUNCTION__ << ":" << __LINE__ << endl;
	return x;
}



string  MysqlOP::selectSecKey(NodeSHMInfo* pNode)
{
	int res;
	string str;
	char sql_select[1024] = { 0 };
	sprintf(sql_select, "SELECT seckey FROM SECKEYINFO WHERE clientid = '%s' AND serverid ='%s'", pNode->clientID, pNode->serverID);
	res = mysql_query(sql, sql_select);
	//cout << __FUNCTION__ << ":" << __LINE__ << res << endl;
	if (res == 0)
	{

		MYSQL_RES* result = mysql_store_result(sql);
		//cout << __FUNCTION__ << ":" << __LINE__ << endl;
		if (NULL == result)
		{
			printf("error(%d):%s\n", mysql_errno(sql), mysql_error(sql));
		}
		else
		{
			MYSQL_ROW row = mysql_fetch_row(result);
			char* filed = row[0];
			str = filed;
			//cout << __FUNCTION__ << ":" << __LINE__ << ":key :" << x << endl;
		}
	}
	else
	{
		//cout << __FUNCTION__ << ":" << __LINE__ << endl;
		printf("error(%d):%s\n", mysql_errno(sql), mysql_error(sql));
	}
	return str;
}


void MysqlOP::close()
{
	//销毁sql
	mysql_close(sql);
}
string MysqlOP::getCurTime()
{
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}