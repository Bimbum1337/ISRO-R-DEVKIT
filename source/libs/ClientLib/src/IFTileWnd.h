#pragma once
#include "ifwnd.h"
class CIFTileWnd : public CIFWnd
{
	GFX_DECLARE_DYNAMIC_EXISTING(CIFTileWnd, 0x117DA04)

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

	void sub_911AE0();

private:
	bool N00009B9D; //0x0374
	char pad_0375[35]; //0x0375
	std::n_string N00009BAF[4]; //0x0398
	std::n_string N00009BB0[4]; //0x0408
	char pad_0478[832]; //0x0478

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x7B8)
    END_FIXTURE()

    RUN_FIXTURE(CIFTileWnd)
};

