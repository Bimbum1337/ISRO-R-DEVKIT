#pragma once

#include "IFFrame.h"
#include "IFStatic.h"
#include "IFCloseButton.h"
#include "IFDragableArea.h"

class CIFMainFrame : public CIFFrame
{
	GFX_DECLARE_DYNAMIC_EXISTING(CIFMainFrame, 0x00EECB54)
	GFX_DECLARE_MESSAGE_MAP(CIFMainFrame)
public:
	CIFMainFrame();
	~CIFMainFrame();


	bool OnCreate(long ln) override;
	void SetGWndSize(int width, int height) override;
	bool SetText(const wchar_t* src) override;
	virtual void OnExit();

private:
	CIFStatic* m_title; //0x07B0
	CIFDragableArea* m_handleBar; //0x07B4
	CIFCloseButton* m_close; //0x07B8
};
