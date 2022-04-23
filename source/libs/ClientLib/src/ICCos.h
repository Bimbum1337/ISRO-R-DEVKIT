#pragma once

#include "ICNonuser.h"


class CICCos : public CICNonuser {
    GFX_DECLARE_DYNAMIC_EXISTING(CICCos, 0x00EEF6F0)

public:
private:
    CClassLink<CICCos> m_classlink; //0x079C
    char pad_07AC[8]; //0x07AC
    std::n_wstring m_ownername; //0x07B4
    CGFontTexture fonttexture_ownername; //0x07D0
private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x838)
        ENSURE_OFFSET(m_ownername, 0x7B4)
        ENSURE_OFFSET(fonttexture_ownername, 0x7D0)
        END_FIXTURE()
        RUN_FIXTURE(CICCos)
};