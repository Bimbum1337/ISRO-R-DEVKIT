#include "StdAfx.h"
#include "IFDecoratedStatic.h"
#include <BSLib/Debug.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFDecoratedStatic, 0x00EE94F8)

// CIFDecoratedStatic::OnCreate(int) .text 00633C80 00000017 00000004 00000000 R . . . . . .
bool CIFDecoratedStatic::OnCreate(long ln)
{
	BS_DEBUG_LOW("> " __FUNCTION__ "(%d)", ln);

	sub_633990();
	set_N00009BD4(0);

	return true;
}

// CIFDecoratedStatic::OnUpdate() .text 00633920 00000005   R . . . . . .
void CIFDecoratedStatic::OnUpdate()
{
	CIFWnd::OnUpdate();
}

// CIFDecoratedStatic::OnTimer(void) .text 00633930 00000003 00000000 00000000 R . . . . . .
void CIFDecoratedStatic::OnTimer(int)
{
	// empty
}

// CIFDecoratedStatic::RenderMyself(void) .text 00634640 00000334 00000024 00000000 R . . . . . .
void CIFDecoratedStatic::RenderMyself()
{
	reinterpret_cast<void(__thiscall*)(CIFDecoratedStatic*)>(0x00634640)(this);
}

// CIFDecoratedStatic::OnCIFReady(void) .text 00633BD0 0000009F 00000004 00000000 R . . . . . .
void CIFDecoratedStatic::OnCIFReady()
{
	reinterpret_cast<void(__thiscall*)(CIFDecoratedStatic*)>(0x00633BD0)(this);
}

// CIFDecoratedStatic::Func_52(void) .text 00633BB0 00000003   R . . . . . .
bool CIFDecoratedStatic::Func_52()
{
	return false;
}

// CIFDecoratedStatic::CIFDecoratedStatic(void) .text 00634350 00000080 00000004 00000000 R . . . . T .
CIFDecoratedStatic::CIFDecoratedStatic()
{
	this->set_N00009BDD(0);
	this->set_N00009C18(0);

	this->N00009BD5 = 32;
	this->N00009BD8 = 32;
	this->N00009C20 = 1;
	this->N00000609 = 1;
	this->N00009BFC = 0;
	this->N00009BDC = -1;
	this->N00009BD2 = 0;
	this->N00009C1D = 0;
}

// CIFDecoratedStatic::~CIFDecoratedStatic(void) .text 00634550 000000C2 0000003C 00000000 R . . . . . .
CIFDecoratedStatic::~CIFDecoratedStatic()
{
	this->sub_634470("");
}

// CIFDecoratedStatic::set_N00009BDD(char) .text 00633950 0000000D 00000000 00000001 R . . . . T .
void CIFDecoratedStatic::set_N00009BDD(char a1)
{
	N00009BDD = a1;
}

// CIFDecoratedStatic::set_N00009C18(char) .text 00633960 0000000D 00000000 00000001 R . . . . T .
void CIFDecoratedStatic::set_N00009C18(char a1)
{
	N00009C18 = a1;
}

// CIFDecoratedStatic::set_N00009BD4(char) .text 00633910 0000000D 00000000 00000001 R . . . . . .
void CIFDecoratedStatic::set_N00009BD4(char a1)
{
	N00009BD4 = a1;
}

// CIFDecoratedStatic::set_N00009BD3(int) .text 00633BC0 0000000D 00000000 00000004 R . . . . . .
void CIFDecoratedStatic::set_N00009BD3(int a1)
{
	N00009BD3 = a1;
}

// CIFDecoratedStatic::sub_634470(std::n_string) .text 00634470 000000D2 00000014 0000001C R . . . . T .
void CIFDecoratedStatic::sub_634470(std::n_string a1)
{
	reinterpret_cast<void(__thiscall*)(CIFDecoratedStatic*, std::n_string)>(0x634470)(this ,a1);
}

// CIFDecoratedStatic::sub_633990(void) .text 00633990 0000010B   R . . . . . .
void CIFDecoratedStatic::sub_633990()
{
	reinterpret_cast<void(__thiscall*)(CIFDecoratedStatic*)>(0x00633990)(this);
}
