#pragma once
#include "ifwnd.h"
class CIFTileWnd : public CIFWnd
{
	GFX_DECLARE_DYNAMIC_EXISTING(CIFTileWnd, 0x00EECBD4)

public:
	CIFTileWnd(void);
	
	~CIFTileWnd(void);

	void TB_Func_13(std::n_string str, int a3, int a4) override;

	bool OnCreate(long ln) override;
	void RenderMyself() override;
	void SetGWndSize(int width, int height) override;
	void Func_40() override;
	void OnCIFReady() override;

	virtual void Func_49(std::n_string str);

protected:
	void set_N00009B9D(bool a2);

	void sub_81AE00();

private:
	bool N00009B9D; //0x036C
	char pad_036D[35]; //0x036D
	std::n_string N00009BAF[4]; //0x0390
	std::n_string N00009BB0[4]; //0x0400
	char pad_0470[832]; //0x0470
};

