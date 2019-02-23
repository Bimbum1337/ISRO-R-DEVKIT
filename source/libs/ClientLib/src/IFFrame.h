#pragma once
#include "IFTileWnd.h"

class CIFFrame : public CIFTileWnd
{
	GFX_DECLARE_DYNAMIC_EXISTING(CIFFrame, 0x00EECB14)
public:
	CIFFrame(void);
	~CIFFrame(void);

	bool OnCreate(long ln) override;
	void RenderMyself() override;
	void Func_49(std::n_string str) override;
	
private:
	// No members
};

