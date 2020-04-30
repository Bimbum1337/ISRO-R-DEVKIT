#include "GFontTexture.h"

#include <cassert>

// CGFontTexture::CGFontTexture(void) .text 008B4F30 00000061 0000001C 00000000 R . . . . . .
CGFontTexture::CGFontTexture(void)
{
	//assert(FALSE);
	printf("> " __FUNCTION__ "\n");
	reinterpret_cast<void (__thiscall*)(CGFontTexture*)>(0x008B4F30)(this);
}

// CGFontTexture::CGFontTexture(int) .text 008B4FA0 00000067 0000001C 00000004 R . . . . . .
CGFontTexture::CGFontTexture(int a2)
{
	printf("> " __FUNCTION__ "\n");
	assert(FALSE);
}

// CGFontTexture::~CGFontTexture(void) .text 008B3CD0 0000006B 00000018 00000000 R . . . . . .
CGFontTexture::~CGFontTexture(void)
{
	printf("> " __FUNCTION__ "\n");
	// reinterpret_cast<void(__thiscall*)(CGFontTexture*)>(0x008B4FA0)(this);
}

// Non-client function
int CGFontTexture::get_N000007BC()
{
	return N000007BC;
}

// CGFontTexture::SetSomething(int) .text 008B2B50 0000000C 00000000 00000004 R . . . . . .
bool CGFontTexture::SetSomething(void* a2)
{
	// assert(FALSE);
	return reinterpret_cast<bool(__thiscall*)(CGFontTexture*,void*)>(0x008B2B50)(this, a2);
}

// CGFontTexture__SetColor .text 008B2B70 00000016 00000000 00000004 R . . . . . .
void CGFontTexture::SetColor(D3DCOLOR color)
{
	reinterpret_cast<void(__thiscall*)(CGFontTexture*,D3DCOLOR)>(0x008B2B70)(this, color);
}

// CGFontTexture::sub_8B2BA0(int,int) .text 008B2BA0 00000061 00000004 00000008 R . . . . . .
void CGFontTexture::sub_8B2BA0(int a1, D3DCOLOR color)
{
	reinterpret_cast<void(__thiscall*)(CGFontTexture*, int ,D3DCOLOR)>(0x008B2BA0)(this, a1, color);
}

// CGFontTexture::sub_8B3B60(std::n_wstring const *) .text 008B3B60 00000026 00000000 00000004 R . . . . . .
void CGFontTexture::sub_8B3B60(std::n_wstring* str)
{
	// assert(FALSE);
	reinterpret_cast<void(__thiscall*)(CGFontTexture*,std::n_wstring*)>(0x8B3B60)(this, str);
}

// CGFontTexture::sub_8B37A0(void) .text 008B37A0 0000007D 00000008 00000000 R . . . . . .
void CGFontTexture::sub_8B37A0()
{
	// assert(FALSE);
}

void CGFontTexture::sub_8B4400(int a1, int a2) {
    reinterpret_cast<void (__thiscall *)(CGFontTexture *, int, int)>(0x008B4400)(this, a1, a2);
}

void CGFontTexture::sub_8B4750(int a2) {
    reinterpret_cast<void (__thiscall *)(CGFontTexture *, int)>(0x008B4750)(this, a2);
}

std::n_wstring *CGFontTexture::GetText(std::n_wstring *str) const {
    return reinterpret_cast<std::n_wstring *(__thiscall *)(const CGFontTexture *, std::n_wstring *str)>(0x008B3C10)(
            this, str);
}