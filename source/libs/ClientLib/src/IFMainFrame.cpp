#include "StdAfx.h"
#include "IFMainFrame.h"

// CIFMainFrame_Create                       .text 00817270 00000067 00000014 00000000 R . . . . . .
// CIFMainFrame_Delete                       .text 00816EF0 00000012 00000000 00000004 R . . . . . .
// CIFMainFrame::GetRuntimeClass(void)       .text 00816F50 00000006                   R . . . . . .
// CIFMainFrame::GetParentRuntimeClass(void) .text 00817260 00000006                   R . . . . . .
GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFMainFrame, 0x00EECB54)

GFX_BEGIN_MESSAGE_MAP(CIFMainFrame, CIFWnd)

ONG_COMMAND(2, &OnClick_Exit)

GFX_END_MESSAGE_MAP()


// CIFMainFrame::CIFMainFrame(void) .text 00816F20 00000030 00000004 00000000 R . . . . . .
CIFMainFrame::CIFMainFrame(void)
{
	printf("> %s\n", __FUNCTION__);

	m_title = NULL;
	m_handleBar = NULL;
	m_close = NULL;
}

// CIFMainFrame::~CIFMainFrame(void) .text 00816F60 00000015   R . . . . . .
CIFMainFrame::~CIFMainFrame(void)
{
	// empty
}

// CIFMainFrame::OnCreate(void) .text 00816F80 000001EF 00000038 00000004 R . . . . . .
bool CIFMainFrame::OnCreate(long ln)
{
	return reinterpret_cast<bool(__thiscall*)(CIFMainFrame*,long)>(0x00816F80)(this, ln);
}

// CIFMainFrame::SetGWndSize(int,int) .text 00817210 0000001F 00000004 00000008 R . . . . . .
void CIFMainFrame::SetGWndSize(int width, int height)
{
	assert(FALSE);
}

// CIFMainFrame::SetText(void) .text 00817230 00000010   R . . . . . .
bool CIFMainFrame::SetText(const wchar_t* Src)
{
	return reinterpret_cast<bool(__thiscall*)(CIFMainFrame*,const wchar_t*)>(0x00817230)(this, Src);
}

void CIFMainFrame::OnClick_Exit()
{
	this->OnCloseWnd();
}