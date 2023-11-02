#ifndef __REQUESTCODEC__
#define __REQUESTCODEC__
#pragma once
#include <iostream>
#include "Codec.h"
#include "Message.pb.h"


using namespace std;
struct RequestInfo
{
	int cmd;                // 命令
	string clientID;        // 客户端号
	string serverID;        // 服务器号
	string sign;            // 标记
	string data;            // 数据
};

class RequestCodec :
	public Codec
{
private:
	string m_encStr;
	//要序列化的数据在RequestMsg类中，需要通过RequestMsg类进行序列化操作 
	RequestMsg m_msg;
public:
	//空对象
	RequestCodec();
	//构造出的对象用于 解码
	RequestCodec(const string& encstr);
	//构造出的对象用于 编码
	RequestCodec(const RequestInfo& info);
	//析构函数
	~RequestCodec();


	//init函数是给构造函数准备的
	void initMessage(const string& encstr);//解码时使用
	void initMessage(const RequestInfo& info);//编码时使用
	//重写父类函数
	string encodeMsg() override;//编码 序列化函数，返回序列化的字符串
	void* decodeMsg()override; //解码 反序列化函数，返回的是一个类对象
};

#endif // !__REQUESTCODEC__


