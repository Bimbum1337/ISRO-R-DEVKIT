#pragma once
#include "IFMainFrame.h"


class CIFflorian0 : public CIFMainFrame
{
	GFX_DECLARE_DYNCREATE(CIFflorian0)
	GFX_DECLARE_MESSAGE_MAP(CIFflorian0)

public:
	CIFflorian0(void);
	~CIFflorian0(void);

	bool OnCreate(long ln) override;
	void OnUpdate() override;

private:
	void On_BtnClick();
	void On_BtnExitClick();
	void OnExit() override;

	int On4001(int a1, int a2);
	int On4002(int a1, int a2);
	int On4003(int a1, int a2);
	int OnVisibleStateChange(int a1, int a2);
	int On4005(int a1, int a2);
	int On4006(int a1, int a2);

private:
	CIFButton *m_mybutton;
	CIFStatic* m_time_label;
	CIFStatic* m_custom_label;

};
