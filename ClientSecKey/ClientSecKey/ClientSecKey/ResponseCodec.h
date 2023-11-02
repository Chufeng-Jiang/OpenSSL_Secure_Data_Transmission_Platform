#ifndef __RESPONSECODEC__
#define __RESPONSECODEC__
#pragma once

#include <iostream>
#include "Codec.h"
#include "Message.pb.h"

using namespace std;

struct ResponseInfo
{
	bool status;        // 状态
	int seckeyID;       // 密钥
	string clientID;    // 客户端号
	string serverID;    // 服务器号
	string data;        // 数据
};

class ResponseCodec :
	public Codec
{
private:
	string m_encStr;
	RespondMsg m_msg;
public:
	//空构造
	ResponseCodec();
	//用于 解码
	ResponseCodec(const string& encstr);
	//用于 编码
	ResponseCodec(const ResponseInfo& info);
	//析构函数
	~ResponseCodec();

	//初始化函数
	void initMessage(const string& encstr);    //用于解码
	void initMessage(const ResponseInfo& info);//用于编码 
	//重写父类函数
	string encodeMsg()override;//编码 序列化函数，返回序列化的字符串
	void* decodeMsg()override; //解码 反序列化函数，返回的是一个类对象

};


#endif // !__RESPONSECODEC__

