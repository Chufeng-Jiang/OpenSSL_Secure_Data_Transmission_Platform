#pragma once
#include "CodecFactory.h"
#include "Response.h"
#include <iostream>

class RespondFactory :
	public CodecFactory
{
public:

	// 服务端工厂类构造函数，设置解码字符串
	RespondFactory(std::string enc);

	// 服务端工厂类构造函数，设置编码对象
	RespondFactory(RespondInfo* info);

	// 继承自父类工厂的函数，用于创建工厂子类
	Codec* createCodec();

	~RespondFactory();

private:

	// 标记用于判断是编码/解码对象
	bool m_flag;

	// 保存要解码的字符串
	std::string m_encStr;

	// 要序列化的数据在这个类中，通过这个类进行序列化操作
	RespondInfo* m_info;
};

