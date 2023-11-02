#include "ResponseCodec.h"

ResponseCodec::ResponseCodec()
{
}

ResponseCodec::ResponseCodec(const string& encstr)
{
	initMessage(encstr);
}

ResponseCodec::ResponseCodec(const ResponseInfo& info)
{
	initMessage(info);
}

ResponseCodec::~ResponseCodec()
{
}

void ResponseCodec::initMessage(const string& encstr)
{
	m_encStr = encstr;
}

void ResponseCodec::initMessage(const ResponseInfo& info)
{
	m_msg.set_status(info.status);
	m_msg.set_seckeyid(info.seckeyID);
	m_msg.set_clientid(info.clientID);
	m_msg.set_serverid(info.serverID);
	m_msg.set_data(info.data);
}

string ResponseCodec::encodeMsg()
{
	string output;
	m_msg.SerializeToString(&output);
	return output;
}

void* ResponseCodec::decodeMsg()
{

	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}
