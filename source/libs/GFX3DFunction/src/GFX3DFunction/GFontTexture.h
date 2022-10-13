#pragma once

#include <d3d9.h>
#include <string>
#include <BSLib/BSLib.h>
#include "ghidra/undefined.h"

class CGFontTexture
{
public:
    struct TextureDimensions {
        short width;
        short height;
    };

public:
	CGFontTexture();
	CGFontTexture(int a2);
	virtual ~CGFontTexture();


	int get_N000007BC();

	bool SetSomething(void* a2);

	void SetColor(D3DCOLOR color);
	void sub_8B2BA0(int a1, D3DCOLOR color);

	// Set some texture
	void sub_B1D410(std::n_wstring *str);
	// Clear some texture
	void sub_B1BEE0();

	/// \address 008B4400
	void sub_8B4400(int a1, int a2);

	/// \address 008B4750
	void sub_8B4750(int a2);

	/// \address 008B3C10
    std::n_wstring *GetText(std::n_wstring *) const;

    /// \address 008b2d30
    void FUN_008b2d30(float* param_1, D3DVECTOR * dataOut);

    /// \address 008b2f20
    TextureDimensions GetDimensions() const;

    /// \address 008b3bd0
    void FUN_008b3bd0(std::n_wstring* param_1);

    /// \address 008b4d90
    void FUN_008b4d90(float* param_1, undefined4 param_2);

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
    TextureDimensions m_dimensions; //0x004C
    char pad_0050[24]; //0x0050
    char pad_todo[8];
};

