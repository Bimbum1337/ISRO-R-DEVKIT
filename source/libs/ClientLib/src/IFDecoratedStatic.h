#pragma once

#include "IFStatic.h"

class CIFDecoratedStatic : public CIFStatic
{
	GFX_DECLARE_DYNAMIC_EXISTING(CIFDecoratedStatic, 0x00EE94F8)

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

private:
	char N00009BD2; //0x0380
	char N00009C1D; //0x0381
	char N00009C20; //0x0382
	char pad_0383[1]; //0x0383
	int N00009BD3; //0x0384
	char N00009BD4; //0x0388
	char pad_0389[3]; //0x0389
	int N00009BD5; //0x038C
	int N00009BD8; //0x0390
	char pad_0394[4]; //0x0394
	int N00009BDC; //0x0398
	char N00009BDD; //0x039C
	char N00009C18; //0x039D
	char pad_039E[98]; //0x039E
	int N00009BFC; //0x0400
	std::n_string N00009BFD; //0x0404

    BEGIN_FIXTURE()
        ENSURE_SIZE(1056)
    END_FIXTURE()
    RUN_FIXTURE(CIFDecoratedStatic)
};
