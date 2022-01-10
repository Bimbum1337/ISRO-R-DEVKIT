#pragma once

#include <BSLib/BSLib.h>
#include <GFX3DFunction/GFontTexture.h>
#include <GFX3DFunction/TextureRuntime.h>

class UserGuildInfo {
public:
    const std::n_wstring &GetName() const;

    CGFontTexture *GetTexture() const;

private:
    char pad_0000[4];             //0x0000
public:
    std::n_wstring m_name;        //0x0004
    CGFontTexture *m_pFontTexture;//0x0020
private:
    char pad_0024[0xC]; // 0x0024
public:
    int m_guildId; // 0x0030
    CTextureRuntime* m_runtimeTexture; // 0x0034
    CTextureRuntime* m_anotherRuntimeTexture; // 0x0038
public:
    undefined4 field_003C; // 0x003C
    undefined4 field_0040; // 0x0040
    undefined4 field_0044;

private:
    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_name, 0x0004)
        ENSURE_OFFSET(m_pFontTexture, 0x0020)
        ENSURE_OFFSET(m_guildId, 0x0030)
        ENSURE_OFFSET(m_runtimeTexture, 0x0034)
        ENSURE_OFFSET(m_anotherRuntimeTexture, 0x0038)
    END_FIXTURE()

    RUN_FIXTURE(UserGuildInfo)
};
