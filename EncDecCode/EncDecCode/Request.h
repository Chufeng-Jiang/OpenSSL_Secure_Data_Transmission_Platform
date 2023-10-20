#pragma once
#include "Codec.h"
#include "msg.pb.h"
#include <iostream>
using namespace std;

struct RequestInfo 
{
	int cmd;
	string clientID;
	string serverID;
	string sign;
	string data;
};

class RequestCodec :
	public Codec
{
public:
	// 空对象
	RequestCodec();
	// 构造出的对象用于解码场景
	RequestCodec(string encstr);
	// 构造出的对象用于编码场景
	RequestCodec(RequestInfo *info);
	// init函数给空构造准备的
	// 解码使用
	void initMessage(string encstr);
	// 编码使用
	void initMessage(RequestInfo *info);
	// 重写的父类函数 -> 序列化函数，返回序列化字符串
	string encodeMsg();
	// 重写的父类函数 -> 反序列化函数，返回结构体/类对象
	void* decodeMsg();

	~RequestCodec();

private:
	//保存要解码的字符串
	string m_encStr;

	//要序列化的数据在这个类中，通过这个类进行序列化操作
	//RequestMsg定义在msg.ph.h中，由protobuf根据定义的结构体自动生成相应的类
	RequestMsg m_msg;
};

