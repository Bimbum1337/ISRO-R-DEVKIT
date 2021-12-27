#pragma once
#include "GFX3DFunction/GFontTexture.h"
#include <BSLib/BSLib.h>

class CTextBoard
{
public:
	CTextBoard(void);
	virtual ~CTextBoard(void);

	virtual void TB_Func_1(float a2);
	virtual void TB_Func_2();
	virtual void TB_Func_3();
	virtual void TB_Func_4();
	virtual void TB_Func_5(int a2);
	virtual void TB_Func_6(int a2);
	virtual void TB_Func_7();
	virtual char TB_Func_8();
	virtual void TB_Func_9(char a2);
	virtual void TB_Func_10();
	virtual void TB_Func_11();
	virtual void TB_Func_12(const char * str, int a3, int a4);
	virtual void TB_Func_13(std::n_string str, int a3, int a4);
	virtual void TB_Func_14(std::string str, int a3, int a4);
	virtual void TB_Func_15(int a2);
	virtual void TB_Func_16();


	/// \address 00655270
	void SetFont(void* a2);

	char GetN00009BB9() const;

protected:
	void sub_655B00(const wchar_t *str);

	bool sub_655420(int a2);
	void sub_655770(std::n_string);

	void sub_655CA0(int a2);
	void sub_6553A0(float a2);
	void sub_6554C0();

private:
	char N000096C1; //0x0004
	char pad_0005[3]; //0x0005
	int N000096C2; //0x0008
public: /* see usage of 8B4400, public seems correct */
	CGFontTexture m_FontTexture; //0x000C
protected:
	std::n_wstring m_texturestr_font; //0x0074
private:
	int N00009C2D; //0x0090
	int N00009C2E; //0x0094
protected:
	void* N00009C2F; //0x0098, set to protected as seen at SetFont in 007ABA44
private:
	int N00009C30; //0x009C
	char pad_00A0[9]; //0x00A0
	char N00009BB9; //0x00A9
	char pad_00AA[2]; //0x00AA
	float N0000974B; //0x00AC
	float N0000974C; //0x00B0
	float N0000974D; //0x00B4
	void* m_texture_un2; //0x00B8
	std::n_string m_str_un2; //0x00BC
	int N00009757; //0x00D8
	std::n_string bg_filename_maybe; //0x00DC
	int N00009768; //0x00F8
	char N00009769; //0x00FC
	char pad_00FD[3]; //0x00FD

};

