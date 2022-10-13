#pragma once

#include "ifwnd.h"

class CIFStatic : public CIFWnd
{
	GFX_DECLARE_DYNAMIC_EXISTING(CIFStatic, 0x1179970)

public:
	CIFStatic(void);
	~CIFStatic(void);

	bool OnCreate(long ln) override;

	bool SetText(const wchar_t* src) override;
	void OnWndMessage(int a1) override;

	void RenderMyself() override;

	void Func_42() override;

	virtual bool SetTextFormatted(const wchar_t *format, ...);
	virtual bool Func_50(const wchar_t *format, ...);
	virtual bool Func_51(const wchar_t *src);

private:
	int N000096E4; //0x0374
	char pad_0370[0x1C]; //0x0378
};
