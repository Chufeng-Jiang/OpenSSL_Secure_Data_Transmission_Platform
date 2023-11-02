#ifndef __CODEC__
#define __CODEC__
#pragma once
#include<iostream>

using std::string;

class Codec
{
public:
	Codec();
	virtual string encodeMsg();	//编码
	virtual void* decodeMsg();	//解码
	//虚析构-->多态-->Big Three-->可以通过父类指针释放子类对象
	virtual ~Codec();

};


#endif // !__CODEC__


