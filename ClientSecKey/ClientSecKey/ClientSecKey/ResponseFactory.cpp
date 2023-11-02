#include "ResponseFactory.h"

ResponseFactory::ResponseFactory() : CodecFactory()
{
}

ResponseFactory::ResponseFactory(const string& enc) : CodecFactory()
{
	m_flag = false;
	m_encStr = enc;
}

ResponseFactory::ResponseFactory(const ResponseInfo& info) : CodecFactory()
{
	m_flag = true;
	m_info = info;
}

ResponseFactory::~ResponseFactory()
{
}

Codec* ResponseFactory::createCodec()
{
	Codec* codec = nullptr;
	if (m_flag)
	{
		codec = new ResponseCodec(m_info);
	}
	else
	{
		codec = new ResponseCodec(m_encStr);
	}
	return codec;
}
