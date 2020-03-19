#include "StdAfx.h"
#include "GWnd.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CGWnd, 0x0110F94C)

void CGWnd::F24(int a1, int a2)
{
	reinterpret_cast<void(__thiscall*)(CGWnd*,int,int)>(0x00B9D810)(this, a1, a2);
}

bool CGWnd::F25(int a1)
{
	return true;
}

void CGWnd::F26(int a1)
{
}

bool CGWnd::F27()
{
	return true;
}

bool CGWnd::F28(int a1, int a2, int a3)
{
	return false;
}

int CGWnd::OnClickEvent(int a1, int x, int y)
{
	return 0;
}

int CGWnd::F30(int a1, int a2, int a3)
{
	return 0;
}

int CGWnd::F31(int a1, int a2, int a3)
{
	return 0;
}

int CGWnd::F32(int a1, int a2, int a3)
{
	return 0;
}

int CGWnd::F33(int a1, int a2, int a3)
{
	return 0;
}

int CGWnd::F34(int a1, int a2, int a3)
{
	return 0;
}

int CGWnd::F35(int a1, int a2, int a3)
{
	return 0;
}

int CGWnd::F36(int a1, int a2, int a3, int a4)
{
	return 0;
}

void CGWnd::Func_37()
{
	return;
}

CGWnd::CGWnd()
{
	m_bVisible = true;
	m_bClickable = true;
	N0000074F = true;
	N00000702 = false;

	sub_B9DA70(false);
}

void CGWnd::OnUpdate()
{
	// empty
}

void CGWnd::RenderMyself()
{
	if (!m_bVisible)
		return;
	// NOTE: This can trigger an endless recursion if RenderMyself is not properly overwritten
	CGWnd::Render();
}

void CGWnd::RenderMyChildren()
{
	reinterpret_cast<void(__thiscall*)(CGWnd*)>(0x00BA0300)(this);
}

void CGWnd::Render()
{
	RenderMyself();
	RenderMyChildren();
	Func_15();
}

void CGWnd::Func_15()
{
	// empty
}

bool CGWnd::On3DEvent_MAYBE(Event3D* a2)
{
	return false;
}

