#pragma once
#include "Codec.h"

// 工厂类的基类
class CodecFactory
{
public:

	// 构造函数
	CodecFactory();

	// 创建对象的方法
	virtual Codec* createCodec();

	virtual ~CodecFactory();
};

