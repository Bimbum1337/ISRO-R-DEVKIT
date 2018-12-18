#include "StdAfx.h"
#include "IFFrame.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFFrame, 0x00EECB14)

// CIFFrame::CIFFrame(void) .text 008151E0 0000001C 00000004 00000000 R . . . . . .
CIFFrame::CIFFrame(void)
{
	printf("> " __FUNCTION__ "\n");
	// empty
}

// CIFFrame::~CIFFrame(void) .text 00815210 00000015 00000010 00000000 R . . . . . .
CIFFrame::~CIFFrame(void)
{
	printf("> " __FUNCTION__ "\n");
	// empty
}

// CIFFrame::OnCreate(void) .text 00815230 0000001C 00000004 00000004 R . . . . . .
bool CIFFrame::OnCreate(long ln)
{
	assert(FALSE);
	return FALSE;
}

// CIFFrame::RenderMyself(void) .text 00815490 00000EF6 00000264 00000000 R . . . . . .
void CIFFrame::RenderMyself()
{
	reinterpret_cast<void(__thiscall*)(CIFFrame*)>(0x00815490)(this);
}

// CIFFrame::Func_49(void) .text 00815300 00000183 00000040 0000001C R . . . . T .
void CIFFrame::Func_49(std::n_string str)
{
	printf(__FUNCTION__ " (\"%s\")\n", str.c_str());
	reinterpret_cast<void(__thiscall*)(CIFFrame*,std::n_string)>(0x00815300)(this, str);
}
