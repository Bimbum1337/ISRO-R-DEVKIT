#pragma once

#include "ICNonuser.h"


class CICCos : public CICNonuser {
	GFX_DECLARE_DYNAMIC_EXISTING(CICCos, 0x00EEF6F0)

public:
private:
	char pad_079C[24]; //0x079C
	std::n_wstring m_playername; //0x07B4
	CGFontTexture fonttexture_playername; //0x07D0
private:
	BEGIN_FIXTURE()
		ENSURE_SIZE(0x838)
		ENSURE_OFFSET(m_playername, 0x7B4)
		ENSURE_OFFSET(fonttexture_playername, 0x7D0)
		END_FIXTURE()
		RUN_FIXTURE(CICCos)
};