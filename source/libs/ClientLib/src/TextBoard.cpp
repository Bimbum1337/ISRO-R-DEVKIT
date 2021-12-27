#include "StdAfx.h"
#include "TextBoard.h"
#include "GFX3DFunction/GFXVideo3d.h"

#include "Client.h"


CTextBoard::CTextBoard(void)
	: m_FontTexture()
{
  this->N0000974C = 0.0;
  this->N00009BB9 = -1;
  this->N0000974B = 0.0;
  this->N00009C30 = 0;

  void* v3 = theApp.GetFont(0);
  this->N00009C2F = v3;
  m_FontTexture.SetSomething(v3);
  this->N00009C2D = -1;
  this->N00009C2E = 0;

  this->sub_655B00(L"");

  this->N000096C1 = 1;
  TB_Func_3();

  this->N000096C2 = 1;
  TB_Func_3();
  this->N00009757 = 0;
  this->N00009768 = 0;
  this->m_texture_un2 = 0;
  this->N0000974D = 0;
  this->N00009769 = 0;
}


// CTextBoard::~CTextBoard(void) .text 00655900 000001C5 00000060 00000000 R . . . . . .
CTextBoard::~CTextBoard(void)
{
	if (this->sub_655420(1))
	{
		CTextBoard::TB_Func_13("", 0, 0);
	}

	this->sub_655770("");
}

// CTextBoard::Func_1(float) .text 00655470 0000004F 00000008 00000004 R . . . . . .
void CTextBoard::TB_Func_1(float a2)
{
	if ( this->N0000974B == 0.0 )
	{
		return;
	}

	this->sub_6553A0(a2);
	
	if ( this->N0000974B <= this->N0000974C )
	{
		this->N0000974C = 0.0;
		this->N0000974B = 0.0;
		TB_Func_7();
	}
}

// CTextBoard::Func_2(void) .text 00655D50 0000010B 00000004 00000000 R . . . . . .
void CTextBoard::TB_Func_2()
{
	this->sub_655CA0(this->N00009C30);

	if ( this->N00009769 )
	{
		if ( this->N00009C30 )
		{
			CGFXVideo3d::UpdateTextureStageState<D3DTSS_COLOROP>(4);
			CGFXVideo3d::UpdateTextureStageState<D3DTSS_COLORARG1>(2);
			CGFXVideo3d::UpdateTextureStageState<D3DTSS_COLORARG2>(3);
		}

		this->TB_Func_11();

		if ( this->N00009C30 )
		{
			CGFXVideo3d::UpdateTextureStageState<D3DTSS_COLOROP>(2);
			CGFXVideo3d::UpdateTextureStageState<D3DTSS_COLORARG1>(2);
		}
	}
	if ( this->m_FontTexture.get_N000007BC() )
		TB_Func_4();

	this->sub_6554C0();
}

// CTextBoard::Func_3(void) .text 004F4CC0 00000001   R . . . . . .
void CTextBoard::TB_Func_3()
{
	return; // empty
}

// CTextBoard::Func_4(void) .text 004F4CD0 00000001   R . . . . . .
void CTextBoard::TB_Func_4()
{
	return; // empty
}

// CTextBoard::Func_5(void) .text 004F4CE0 00000011 00000000 00000004 R . . . . . .
void CTextBoard::TB_Func_5(int a2)
{
	this->N000096C1 = a2;
	TB_Func_3();
}

// CTextBoard::Func_6(void) .text 004F4D00 00000011 00000000 00000004 R . . . . . .
void CTextBoard::TB_Func_6(int a2)
{
	this->N000096C2 = a2;
	TB_Func_3();
}

// CTextBoard::Func_7(void) .text 00655AD0 00000001   R . . . . . .
void CTextBoard::TB_Func_7()
{
	return; // emtpy
}

// CTextBoard::AddControlToList(void) .text 00655AE0 00000007   R . . . . . .
char CTextBoard::TB_Func_8()
{
	return N00009BB9;
}

// CTextBoard::RemoveControlFromList(void) .text 00655460 0000000D 00000000 00000001 R . . . . . .
void CTextBoard::TB_Func_9(char a2)
{
	N00009BB9 = a2;
}

// CTextBoard::Func_10(void) .text 004F4D20 00000001   R . . . . . .
void CTextBoard::TB_Func_10()
{
	return; // empty
}

// CTextBoard::Func_11(void) .text 00655AF0 00000001   R . . . . . .
void CTextBoard::TB_Func_11()
{
	return; // empty
}

// CTextBoard::Func_12(void) .text 00655590 000000E5 0000004C 0000000C R . . . . . .
void CTextBoard::TB_Func_12(const char* str, int a3, int a4)
{
	TB_Func_13(str, a3, a4);
}

// CTextBoard::Func_13(std::string const *,int,int) .text 00655680 000000E6 00000014 00000024 R . . . . T .
void CTextBoard::TB_Func_13(const std::n_string str, int a3, int a4)
{
	reinterpret_cast<void(__thiscall*)(CTextBoard*, const std::n_string, int, int)>(0x00655680)(this, str, a3, a4);
}

// CTextBoard::Func_14(void) .text 00655820 000000E0 00000014 00000024 R . . . . T .
void CTextBoard::TB_Func_14(const std::string str, int a3, int a4)
{
	reinterpret_cast<void(__thiscall*)(CTextBoard*, const std::string, int, int)>(0x00655820)(this, str, a3, a4);
}

// CTextBoard::Func_15(void) .text 00655510 00000058 00000004 00000004 R . . . . . .
void CTextBoard::TB_Func_15(int a2)
{
	assert(FALSE);
}

// CTextBoard::Func_16(void) .text 00655570 0000001E 00000004 00000000 R . . . . . .
void CTextBoard::TB_Func_16()
{
	bg_filename_maybe.clear();
	N00009757 = 0;
	N00009769 = 0;
}

// CTextBoard::sub_655B00(wchar_t const *) .text 00655B00 0000004E 00000004 00000004 R . . . . . .
void CTextBoard::sub_655B00(const wchar_t* str)
{
	if (str)
	{
		m_texturestr_font = str;
		m_FontTexture.sub_8B3B60(&m_texturestr_font);
	}
	else
	{
		m_texturestr_font.clear();
		m_FontTexture.sub_8B37A0();
	}
}

// CTextBoard::sub_655420(int) .text 00655420 00000010 00000000 00000004 R . . . . T .
bool CTextBoard::sub_655420(int a2)
{
	return (a2 & this->N00009768) != 0;
}

// CTextBoard::sub_655770(std::string) .text 00655770 000000AA 00000014 0000001C R . . . . . .
void CTextBoard::sub_655770(std::n_string a2)
{
	if (m_texture_un2)
		Fun_CacheTexture_Release(&m_str_un2);

	if (a2.length())
	{
		m_texture_un2 = Fun_CacheTexture_Create(a2);
		m_str_un2 = a2;
	}
	else
	{
		m_texture_un2 = 0;
	}
}

// CTextBoard__sub_655CA0 .text 00655CA0 000000A4 0000002C 00000004 R . . . . . .
void CTextBoard::sub_655CA0(int a2)
{
	reinterpret_cast<void(__thiscall*)(CTextBoard*,int)>(0x00655CA0)(this, a2);
}

// CTextBoard__sub_6553A0 .text 006553A0 0000001E 00000004 00000004 R . . . . T .
void CTextBoard::sub_6553A0(float a2)
{
	reinterpret_cast<void(__thiscall*)(CTextBoard*)>(0x006553A0)(this);
}

// CTextBoard__sub_6554C0 .text 006554C0 0000004E 00000004 00000000 R . . . . . .
void CTextBoard::sub_6554C0()
{
	reinterpret_cast<void(__thiscall*)(CTextBoard*)>(0x006554C0)(this);
}

void CTextBoard::SetFont(void *a2) {
    reinterpret_cast<void (__thiscall *)(CTextBoard *, void *)>(0x00655270)(this, a2);
}

char CTextBoard::GetN00009BB9() const {
    return N00009BB9;
}