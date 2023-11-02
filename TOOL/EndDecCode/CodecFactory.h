#ifndef __CODECFACTORY__
#define __CODECFACTORY__

#pragma once
#include "Codec.h"

class CodecFactory
{
public:
	CodecFactory() = default;
	virtual ~CodecFactory() = default;
	virtual Codec* createCodec();
};

#endif // !__CODECFACTORY__



