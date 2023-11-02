#ifndef __REQUESTFACTORY__
#define __REQUESTFACTORY__

#pragma once
#include "CodecFactory.h"
#include "RequestCodec.h"
class RequestFactory :
	public CodecFactory
{
public:
	RequestFactory();
	RequestFactory(const string& enc);
	RequestFactory(const RequestInfo& info);
	~RequestFactory();

	Codec* createCodec();
private:
	bool m_flag;    //标记  true : m_info 被初始化     false : m_encStr 被初始化
	string m_encStr;    //解码
	RequestInfo m_info;    //编码
};


#endif // !__REQUESTFACTORY__


