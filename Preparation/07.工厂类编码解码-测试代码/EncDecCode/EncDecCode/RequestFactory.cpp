#include "RequestFactory.h"

RequestFactory::RequestFactory(std::string enc) : CodecFactory()
{
	m_flag = false;
	m_encStr = enc;
}

RequestFactory::RequestFactory(RequestInfo * info) : CodecFactory()
{
	m_flag = true;
	m_info = info;
}

//多态的应用，父类指针指向子类对象
Codec * RequestFactory::createCodec()
{
	Codec* codec = NULL;

	//两个工厂对象用if-else，但是如果有很多工厂子类对象就使用switch
	if (m_flag) //m_flag = true;，则就是编码对象
	{
		codec = new RequestCodec(m_info);  
	}
	else
	{
		codec = new RequestCodec(m_encStr);
	}
	return codec;
}


RequestFactory::~RequestFactory()
{
}
