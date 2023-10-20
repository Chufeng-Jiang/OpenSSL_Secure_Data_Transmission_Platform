#pragma once
#include <iostream>

class Codec
{
public:
	Codec();
	virtual std::string encodeMsg();
	virtual void* decodeMsg();

	//虚析构 --要实现多态的时候才使用虚析构
	//实现多态的时候使用虚函数，C++会给用户维护一个虚函数表，如果不涉及多态也使用虚函数，没有什么意义
	virtual ~Codec();
};

