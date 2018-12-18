#pragma once

#include <d3d9.h>
#include <string>
#include <BSLib/BSLib.h>

class CGFontTexture
{
public:
	CGFontTexture();
	CGFontTexture(int a2);
	virtual ~CGFontTexture();


	int get_N000007BC();

	bool SetSomething(void* a2);

	void SetColor(D3DCOLOR color);

	// Set some texture
	void sub_8B3B60(std::n_wstring *str);
	// Clear some texture
	void sub_8B37A0();

private:
	char pad_0004[12-4]; //0x0004
	D3DCOLOR m_color_bg; //0x000C
	D3DCOLOR m_color_fg; //0x0010
	char pad_0014[24]; //0x0014
	int m_textmode; //0x002C
	int m_textspacing; //0x0030
	char pad_0034[8]; //0x0034
	float m_scaling; //0x003C
	char pad_0040[8]; //0x0040
	int N000007BC; //0x0048
	char pad_004C[28]; //0x004C
};

