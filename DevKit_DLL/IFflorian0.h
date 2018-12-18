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

private:
	CIFButton *m_mybutton;
	//CIFStatic *m_my_label;
};

 