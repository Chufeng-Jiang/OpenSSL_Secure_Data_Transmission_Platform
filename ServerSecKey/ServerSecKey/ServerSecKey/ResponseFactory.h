#ifndef __RESPONSEFACTORY__
#define __RESPONSEFACTORY__


#pragma once
#include "CodecFactory.h"
#include "ResponseCodec.h"
class ResponseFactory :
	public CodecFactory
{
public:
	ResponseFactory();
	ResponseFactory(const string& enc);
	ResponseFactory(const ResponseInfo& info);
	~ResponseFactory();

	Codec* createCodec();
private:
	bool m_flag;   //标记   true : m_info 被初始化     false : m_encStr 被初始化
	string m_encStr;   //解码
	ResponseInfo m_info;   //编码    
};

#endif // !__RESPONSEFACTORY__



