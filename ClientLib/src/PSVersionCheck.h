#pragma once

#include "PSOuterInterface.h"

class CPSVersionCheck : public CPSOuterInterface
{
	GFX_DECLARE_DYNCREATE(CPSVersionCheck);

public:
	CPSVersionCheck();
	~CPSVersionCheck();

	BOOL OnNetMsg(CMsgStreamBuffer* pMsg) override; // @0086D2A0
	bool OnCreate(long ln) override; // @0086D370

	bool OnRelease() override; // named F11 in base, jtfr

	void OnUpdate() override;

public:
	bool state; //0x010C
}; //Size: 0x0110
