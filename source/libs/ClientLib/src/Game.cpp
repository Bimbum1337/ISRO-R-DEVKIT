#include "StdAfx.h"

#include "Game.h"

// CGame::GetFont(int) .text 00BA5460 00000022 00000000 00000004 R . . . . . .
void* CGame::GetFont(int a2)
{
	// assert(FALSE);
	return reinterpret_cast<void*(__thiscall*)(CGame*,int)>(0x00BA5460)(this, a2);
}
