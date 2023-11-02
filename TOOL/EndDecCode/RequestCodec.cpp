#include "RequestCodec.h"

RequestCodec::RequestCodec()
{
}

RequestCodec::RequestCodec(const string& encstr)
{
	initMessage(encstr);
}

RequestCodec::RequestCodec(const RequestInfo& info)
{
	initMessage(info);
}

RequestCodec::~RequestCodec()
{
}

void RequestCodec::initMessage(const string& encstr)
{
	m_encStr = encstr;
}

void RequestCodec::initMessage(const RequestInfo& info)
{
	m_msg.set_cmdtype(info.cmd);
	m_msg.set_clientid(info.clientID);
	m_msg.set_serverid(info.serverID);
	m_msg.set_sign(info.sign);
	m_msg.set_data(info.data);
}

string RequestCodec::encodeMsg()
{
	string output;
	m_msg.SerializeToString(&output);
	return output;
}

void* RequestCodec::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}
