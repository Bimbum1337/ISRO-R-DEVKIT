#include "IFStatic.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFStatic, 0x1179970)

// CIFStatic::CIFStatic(void) .text 0064D5F0 00000081 0000001C 00000000 R . . . . T .
CIFStatic::CIFStatic(void)
{
	N00000609 = 0;
	N000096E4 = 0;

	m_FontTexture.SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	m_FontTexture.sub_8B2BA0(3, D3DCOLOR_RGBA(0xB4, 0xB4, 0xB4, 255));
}

// CIFStatic::~CIFStatic(void) .text 0064D690 00000015 00000010 00000000 R . . . . . .
CIFStatic::~CIFStatic(void)
{
	// empty
}

// CIFStatic::OnCreate(int) .text 0064D6B0 00000005 00000000 00000000 R . L . . . .
bool CIFStatic::OnCreate(long ln)
{
	return true;
}

// CIFStatic::SetText(void *) .text 0064D810 00000029 00000004 00000004 R . . . . . .
bool CIFStatic::SetText(const wchar_t* src)
{
	if (src)
	{
		CIFWnd::SetText(src);
		Func_42();
        return true;
	}

	return false;
}

// CIFStatic::OnWndMessage .text 0064D850 00000037 00000004 00000004 R . . . . . .
void CIFStatic::OnWndMessage(int a1)
{
	reinterpret_cast<void(__thiscall*)(CIFStatic*,int)>(0x007297C0)(this, a1);
}

// CIFStatic::RenderMyself(void) .text 0064D940 00000065 00000004 00000000 R . . . . . .
void CIFStatic::RenderMyself()
{
	reinterpret_cast<void(__thiscall*)(CIFStatic*)>(0x00729180)(this);
}

// CIFStatic::Func_42(void) .text 0064D9B0 0000019B 00000018 00000000 R . . . . . .
void CIFStatic::Func_42()
{
	reinterpret_cast<void(__thiscall*)(CIFStatic*)>(0x00729600)(this);
}

// CIFStatic::Func_49(void) .text 0064D780 0000008E 00002008 00000009 R . . . . T .
bool CIFStatic::SetTextFormatted(const wchar_t* format, ...)
{
	assert(FALSE);
	return false;
}

// CIFStatic::Func_50(void) .text 0064D6C0 0000008E 00002008 00000009 R . . . . T .
bool CIFStatic::Func_50(const wchar_t* format, ...)
{
	assert(FALSE);
	return false;
}

// CIFStatic::Func_51(void) .text 0064D750 00000029 00000004 00000004 R . . . . T .
bool CIFStatic::Func_51(const wchar_t* src)
{
	assert(FALSE);
	return false;
}
