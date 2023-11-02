#include "RequestFactory.h"

RequestFactory::RequestFactory() :CodecFactory()
{
}

RequestFactory::RequestFactory(const string& enc) : CodecFactory()
{
	m_flag = false;
	m_encStr = enc;
}

RequestFactory::RequestFactory(const RequestInfo& info) : CodecFactory()
{
	m_flag = true;
	m_info = info;
}

RequestFactory::~RequestFactory()
{
}

Codec* RequestFactory::createCodec()
{
	Codec* codec = nullptr;
	if (m_flag)
	{
		codec = new RequestCodec(m_info);
	}
	else
	{
		codec = new RequestCodec(m_encStr);
	}
	return codec;
}
