#pragma once
#include "IFDecoratedStatic.h"

#define GUIDE_FLORIAN0 13378

class CIFflorian0Guide : public CIFDecoratedStatic
{
	GFX_DECLARE_DYNCREATE(CIFflorian0Guide)

public:
	bool OnCreate(long ln) override;
	int OnClickEvent(int a1, int x, int y) override;
	void Func_41() override;
};
