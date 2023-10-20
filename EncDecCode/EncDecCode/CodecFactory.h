#pragma once
#include "Codec.h"

//工厂类的基类
class CodecFactory
{
public:
	CodecFactory();

	//创建对象的方法
	virtual Codec* createCodec();
	virtual ~CodecFactory();
};

