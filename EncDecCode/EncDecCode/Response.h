#pragma once
#include "Codec.h"
#include <iostream>
#include "msg.pb.h"
using namespace std;

// 服务端传输次那次的结构体/类对象
struct RespondInfo
{
	int status;
	int seckeyID;
	string clientID;
	string serverID;
	string data;
};

// 服务端编码解码类
class RespondCodec :
	public Codec
{
public:

	// 空对象，构造函数
	RespondCodec();

	// 构造出的对象用于解码场景，参数是要解码的字符串
	RespondCodec(string enc);

	// 构造出的对象用于编码场景，参数是传入的客户端信息
	RespondCodec(RespondInfo *info);

	// init函数给空构造准备的
	// 解码使用，参数是要解码的字符串
	void initMessage(string enc);

	// 编码使用，参数是传入的客户端信息
	void initMessage(RespondInfo *info);

	// 重写的父类函数 -> 序列化函数，返回序列化字符串
	string encodeMsg();

	// 重写的父类函数 -> 反序列化函数，返回结构体/类对象
	void* decodeMsg();

	~RespondCodec();

private:

	// 保存要解码的字符串
	string m_encstr;

	// RequestMsg定义在msg.ph.h中，由protobuf根据定义的结构体自动生成相应的类
	// 要序列化的数据在这个类中，通过这个类进行序列化操作
	RespondMsg m_msg;
};

