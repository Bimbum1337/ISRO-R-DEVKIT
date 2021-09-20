#pragma once

#include <BSLib/BSLib.h>
#include <GFX3DFunction/GFontTexture.h>

class UserGuildInfo {
public:
    const std::n_wstring &GetName() const;

    CGFontTexture *GetTexture() const;

private:
    char pad_0000[4];             //0x0000
    std::n_wstring m_name;        //0x0004
    CGFontTexture *m_pFontTexture;//0x0020

private:
    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_name, 0x0004)
        ENSURE_OFFSET(m_pFontTexture, 0x0020)
    END_FIXTURE()

    RUN_FIXTURE(UserGuildInfo)
};
