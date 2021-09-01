#include "StdAfx.h"

#include "Game.h"

// CGame::GetFont(int) .text 00BA5460 00000022 00000000 00000004 R . . . . . .
void* CGame::GetFont(int a2)
{
	// assert(FALSE);
	return reinterpret_cast<void*(__thiscall*)(CGame*,int)>(0x00BA5460)(this, a2);
}

void CGame::InitGameAssets() {

	reinterpret_cast<void(__thiscall*)(CGame * pthis)>(0x849110)(this);
}

void CGame::LoadTextfiles()
{
	// TODO:: Implement me
	reinterpret_cast<void(__thiscall*)(CGame*)>(0x00844CD0)(this);
}

void CGame::ResizeMainWindow()
{
	reinterpret_cast<void(__thiscall*)(CGame*)>(0x00840E90)(this);
}

const ClientRes &CGame::GetRes() const {
    return N00000888;
}

const ClientResolutonData &CGame::GetClientDimensionStuff() {
    const ClientRes &res = theApp.GetRes();
    return res.res[res.index];
}

CStringCheck *CGame::GetBadwordFilter() {
    return theApp.m_badWordFilter;
}

WhatIsThis &CGame::STA_FUN_004f9d00() {
    WhatIsThis* ptr = reinterpret_cast<WhatIsThis*(*)()>(0x004f9d00)();
    return *ptr;
}

void CGame::sub_8371D0() {
    reinterpret_cast<void(__thiscall*)(CGame*)>(0x008371D0)(this);
}
