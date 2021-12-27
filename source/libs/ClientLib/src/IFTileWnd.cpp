#include "StdAfx.h"
#include "IFTileWnd.h"
#include <BSLib/Debug.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFTileWnd, 0x00EECBD4)

// CIFTileWnd::CIFTileWnd(void) .text 0081AB10 0000009A 00000018 00000000 R . . . . . .
CIFTileWnd::CIFTileWnd(void)
{
	BS_DEBUG_LOW(">" __FUNCTION__);
	this->set_N00009B9D(1);
}

// CIFTileWnd::~CIFTileWnd(void) .text 0081B490 00000099 00000018 00000000 R . . . . . .
CIFTileWnd::~CIFTileWnd(void)
{
	sub_81AE00();
}

// CIFTileWnd::CTextBoard_Func_13 .text 0081AC50 0000008E 00000034 00000001 R . . . . . .
void CIFTileWnd::TB_Func_13(std::n_string str, int a3, int a4)
{
	BS_DEBUG_LOW(__FUNCTION__ " (\"%s\", %d, %d)", str.c_str(), a3, a4);
	reinterpret_cast<void(__thiscall*)(CTextBoard*,std::n_string,int,int)>(0x0081AC50)(this, str, a3, a4);
}

// CIFTileWnd::OnCreate(void) .text 0081B530 0000000A 00000000 00000000 R . . . . . .
bool CIFTileWnd::OnCreate(long ln)
{
	assert(FALSE);
	return false;
}

// CIFTileWnd::RenderMyself(void) .text 0081A730 00000005 00000004 00000000 R . . . . . .
void CIFTileWnd::RenderMyself()
{
	CIFWnd::RenderMyself();
}

// CIFTileWnd::SetGWndSize(void) .text 0081A920 00000005 00000004 00000000 R . . . . . .
void CIFTileWnd::SetGWndSize(int width, int height)
{
	assert(FALSE);
}

// CIFTileWnd::Func_40(void) .text 0081A720 0000000A   R . . . . . .
void CIFTileWnd::Func_40()
{
	OnCIFReady();
}

// CIFTileWnd::OnCIFReady(void) .text 0081A740 000001C8 00000024 00000000 R . . . . . .
void CIFTileWnd::OnCIFReady()
{
	reinterpret_cast<void(__thiscall*)(CIFTileWnd*)>(0x0081A740)(this);
}

// CIFTileWnd::Func_49(void) .text 0081B540 000001A1 00000048 0000001C R . . . . T .
void CIFTileWnd::Func_49(std::n_string str)
{
	assert(FALSE);
}

// CIFTileWnd::set_N00009B9D(int) .text 0081A910 0000000D 00000000 00000001 R . . . . . .
void CIFTileWnd::set_N00009B9D(bool a2)
{
	N00009B9D = a2;
}

// CIFTileWnd__sub_81AE00 .text 0081AE00 0000007D 00000010 00000000 R . . . . . .
void CIFTileWnd::sub_81AE00()
{
	reinterpret_cast<void(__thiscall*)(CIFTileWnd*)>(0x0081AE00)(this);
}
