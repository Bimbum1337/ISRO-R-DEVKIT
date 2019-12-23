#pragma once
#include "GFXMainFrame/GWnd.h"
#include "TextBoard.h"
#include "IRMManager.h"
#include <Test/Test.h>


class CIFWnd : public CGWnd, public CTextBoard
{
	GFX_DECLARE_DYNAMIC_EXISTING(CIFWnd, 0x00EE9808)
	GFX_DECLARE_MESSAGE_MAP(CIFWnd)
public:
	CIFWnd(void);
	~CIFWnd(void);


	void OnTimer(int) override;
	
	bool OnCreate(long ln) override;
	bool OnRelease() override;

	bool Func_18(int a1) override;
	bool On3DEvent_MAYBE(Event3D* a2) override;
	
	void Func_20() override;
	void SetGWndSize(int width, int height) override;
	void Func_22(int x, int y) override;

	void Func_37() override;

	void TB_Func_7() override;
	char TB_Func_8() override;
	void TB_Func_11() override;

	void OnUpdate() override;

	
	void ShowGWnd(bool bVisible) override;


	void OnWndMessage(int a1) override;

	void RenderMyself() override;

	virtual void MoveGWnd(int x, int y);
	virtual void MoveGWnd2(int x, int y);
	virtual void Func_40();
	virtual void Func_41();
	virtual void Func_42();
	virtual void Func_43();
	virtual bool IsInside(int x, int y);
	virtual bool SetText(const wchar_t* src);
	virtual const wchar_t* GetText();
	virtual void Func_47(int);
	virtual void Func_48();


private:
	int On4001(int, int);
	int On4006(int, int);

	void sub_652B00();
	void sub_653060();

	void Set_N00000687(char a2);

private:
	int N000005A9; //0x0184
	int N000005BB; //0x0188
	int N000005CD; //0x018C
	int N000005FB; //0x0190
	int N000005FD; //0x0194
	int N00009BFC; //0x0198
	std::n_wstring m_innerText; //0x019C
	char N00009BFD; //0x01B8
	char N00009C1B; //0x01B9
	char pad_01BA[2]; //0x01BA
protected:
	CIRMManager m_IRM; //0x01BC m_IRM at 1BC
private:
	int N00000608; //0x01EC
protected:
	int N00000609; //0x01F0
private:
	int N0000060A; //0x01F4
	int N0000060B; //0x01F8
	float N00000615; //0x01FC
	float N00000617; //0x0200
	int N00000618; //0x0204
	char N0000061A; //0x0208
	char pad_0209[3]; //0x0209
	int N0000061B; //0x020C
	std::n_wstring N0000061C; //0x0210
	float N0000061D; //0x022C
	float N0000061E; //0x0230
	float N00000627; //0x0234
	float N00000628; //0x0238
	float N00000629; //0x023C
	float N0000062A; //0x0240
	float N0000062B; //0x0244
	float N0000062C; //0x0248
	char pad_024C[8]; //0x024C
	float N0000062F; //0x0254
	float N00009C60; //0x0258
	float N00009C61; //0x025C
	float N00000632; //0x0260
	char pad_0264[8]; //0x0264
	float N00000635; //0x026C
	float N00000637; //0x0270
	float N00009C69; //0x0274
	float N00009C6A; //0x0278
	char pad_027C[8]; //0x027C
	float N0000063A; //0x0284
	float N00009C70; //0x0288
	float N00009C71; //0x028C
	float N0000063B; //0x0290
	char pad_0294[8]; //0x0294
	float N00009C5A; //0x029C
	float N0000065D; //0x02A0
	float N00009C79; //0x02A4
	float N00009C7A; //0x02A8
	char pad_02AC[8]; //0x02AC
	float N00000662; //0x02B4
	float N00009C80; //0x02B8
	float N00009C81; //0x02BC
	float N00000668; //0x02C0
	char pad_02C4[8]; //0x02C4
	float N0000066B; //0x02CC 2CC
	float N0000066C; //0x02D0
	char pad_02D4[16]; //0x02D4
	float N00000671; //0x02E4
	float N00000672; //0x02E8
	char pad_02EC[16]; //0x02EC
	float N00000677; //0x02FC
	float N00000678; //0x0300
	char pad_0304[16]; //0x0304
	float N0000067D; //0x0314
	float N0000067E; //0x0318
	char pad_031C[16]; //0x031C
	float N00000683; //0x032C
	float N00000684; //0x0330
	char pad_0334[8]; //0x0334
	char N00000687; //0x033C 33C
	char N00009C2C; //0x033D
	char pad_033E[2]; //0x033E
	int N00000688; //0x0340
	int N00000689; //0x0344
	int N0000068A; //0x0348
	int N0000068B; //0x034C
	int N0000068C; //0x0350
	int N0000068D; //0x0354
	int N0000068E; //0x0358
	char pad_035C[4]; //0x035C
	int N000006A1; //0x0360
	int N00009C01; //0x0364
	int N00009C02; //0x0368

    BEGIN_FIXTURE()
        ENSURE_SIZE(876)
    END_FIXTURE()
    RUN_FIXTURE(CIFWnd)
};

