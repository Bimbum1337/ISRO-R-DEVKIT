#pragma once

#include "IClientNet.h"

class CClientNet : public IClientNet
{
	public:
	static CClientNet* get()
	{
		return *reinterpret_cast<CClientNet**>(0x0115B0C0);
	}

	 

};

