#pragma once

#include "IFStatic.h"

class CIFDecoratedStatic : public CIFStatic
{
	GFX_DECLARE_DYNAMIC_EXISTING(CIFDecoratedStatic, 0x1179748)

public:
	bool OnCreate(long ln) override;
	void OnUpdate() override;
	void OnTimer(int) override;

	void RenderMyself() override;

	void OnCIFReady() override;

	virtual bool Func_52();

public:
	CIFDecoratedStatic();
	virtual ~CIFDecoratedStatic();

private:
	void set_N00009BDD(char a1);
	void set_N00009C18(char a1);
protected:
	void set_N00009BD4(char a1);
	void set_N00009BD3(int a1);
	void sub_634470(std::n_string a1);
	void sub_633990();
    void sub_72F670(int a1);
private:
	char N00009BD2; //0x0394
	char N00009C1D; //0x0395
	char N00009C20; //0x0396
	char pad_0383[1]; //0x0397
	int N00009BD3; //0x0398
	char N00009BD4; //0x039C
	char pad_0389[3]; //0x039D
	int N00009BD5; //0x03A0
	int N00009BD8; //0x03A4
	char pad_0394[4]; //0x03A8
	int N00009BDC; //0x03AC
	char N00009BDD; //0x03B0
	char N00009C18; //0x03B1
	char pad_039E[98]; //0x03B2
	int N00009BFC; //0x0414
    char pad_0000[0x1C];
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x434)
    END_FIXTURE()
    RUN_FIXTURE(CIFDecoratedStatic)
};
