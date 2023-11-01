#include "CodecFactory.h"



CodecFactory::CodecFactory()
{
}

Codec * CodecFactory::createCodec()
{
	return NULL; // 由子类重写覆盖
}


CodecFactory::~CodecFactory()
{
}
