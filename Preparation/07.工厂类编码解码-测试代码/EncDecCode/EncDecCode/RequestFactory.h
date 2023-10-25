#pragma once
#include "CodecFactory.h"
#include "Codec.h"
#include "Request.h"
#include <iostream>

// 客户端子工厂类
class RequestFactory :
	public CodecFactory
{
public:

	// 客户端工厂类构造函数，设置解码字符串
	RequestFactory(std::string enc);

	// 客户端工厂类构造函数，设置编码对象
	RequestFactory(RequestInfo *info);

	// 继承自父类工厂的函数，用于创建工厂子类
	Codec* createCodec();

	~RequestFactory();

private:

	// 标记用于判断是编码/解码对象
	bool m_flag;

	// 保存要解码的字符串
	std::string m_encStr;

	// 要序列化的数据在这个类中，通过这个类进行序列化操作
	RequestInfo* m_info;
};

