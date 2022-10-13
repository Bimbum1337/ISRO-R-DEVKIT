#include "GFontTexture.h"
#include <BSLib/Debug.h>
#include <cassert>

// CGFontTexture::CGFontTexture(void) .text 0x00B1E180 00000061 0000001C 00000000 R . . . . . .
CGFontTexture::CGFontTexture(void)
{
	//assert(FALSE);
	BS_DEBUG_LOW("> " __FUNCTION__);
	reinterpret_cast<void (__thiscall*)(CGFontTexture*)>(0x00B1E180)(this);
}

// CGFontTexture::CGFontTexture(int) .text 00B1E1E0 00000067 0000001C 00000004 R . . . . . .
CGFontTexture::CGFontTexture(int a2)
{
	BS_DEBUG_LOW("> " __FUNCTION__);
	assert(FALSE);
}

// CGFontTexture::~CGFontTexture(void) .text 008B3CD0 0000006B 00000018 00000000 R . . . . . .
CGFontTexture::~CGFontTexture(void)
{
	BS_DEBUG_LOW("> " __FUNCTION__);
	// reinterpret_cast<void(__thiscall*)(CGFontTexture*)>(0x008B4FA0)(this);
}

// Non-client function
int CGFontTexture::get_N000007BC()
{
	return N000007BC;
}

// CGFontTexture::SetSomething(int) .text 00B13610 0000000C 00000000 00000004 R . . . . . .
bool CGFontTexture::SetSomething(void* a2)
{
	// assert(FALSE);
	return reinterpret_cast<bool(__thiscall*)(CGFontTexture*,void*)>(0x00B134F0)(this, a2);
}

// CGFontTexture__SetColor .text 008B2B70 00000016 00000000 00000004 R . . . . . .
void CGFontTexture::SetColor(D3DCOLOR color)
{
	reinterpret_cast<void(__thiscall*)(CGFontTexture*,D3DCOLOR)>(0x00B13510)(this, color);
}

// CGFontTexture::sub_8B2BA0(int,int) .text 008B2BA0 00000061 00000004 00000008 R . . . . . .
void CGFontTexture::sub_8B2BA0(int a1, D3DCOLOR color)
{
	reinterpret_cast<void(__thiscall*)(CGFontTexture*, int ,D3DCOLOR)>(0x00B13540)(this, a1, color);
}

// CGFontTexture::sub_8B3B60(std::n_wstring const *) .text 008B3B60 00000026 00000000 00000004 R . . . . . .
void CGFontTexture::sub_B1D410(std::n_wstring* str)
{
	// assert(FALSE);
	reinterpret_cast<void(__thiscall*)(CGFontTexture*,std::n_wstring*)>(0x00B1D2F0)(this, str);
}

// CGFontTexture::sub_8B37A0(void) .text 008B37A0 0000007D 00000008 00000000 R . . . . . .
void CGFontTexture::sub_B1BEE0()
{
	// assert(FALSE);
}

void CGFontTexture::sub_8B4400(int a1, int a2) {
    reinterpret_cast<void (__thiscall *)(CGFontTexture *, int, int)>(0x00B1DD50)(this, a1, a2);
}

void CGFontTexture::sub_8B4750(int a2) {
    reinterpret_cast<void (__thiscall *)(CGFontTexture *, int)>(0x00B1DF20)(this, a2);
}

std::n_wstring *CGFontTexture::GetText(std::n_wstring *str) const {
    return reinterpret_cast<std::n_wstring *(__thiscall *)(const CGFontTexture *, std::n_wstring *str)>(0x00B17780)(
            this, str);
}

void CGFontTexture::FUN_008b2d30(float*  param_1, D3DVECTOR * dataOut) {
    reinterpret_cast<void (__thiscall *)(CGFontTexture *, float*, D3DVECTOR *)>(0x00B13670)(this, param_1, dataOut);
}

CGFontTexture::TextureDimensions CGFontTexture::GetDimensions() const{
    return m_dimensions;
}

void CGFontTexture::FUN_008b3bd0(std::n_wstring *param_1) {
    return reinterpret_cast<void (__thiscall *)(CGFontTexture *, std::n_wstring *)>(0xB1D340)(this, param_1);
}

void CGFontTexture::FUN_008b4d90(float* param_1, undefined4 param_2) {
    return reinterpret_cast<void (__thiscall *)(CGFontTexture *, float*, undefined4)>(0x00B19690)(this, param_1, param_2);
}
