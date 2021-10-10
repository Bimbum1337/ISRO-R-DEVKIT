#pragma once

#include "GlobalHelpersThatHaveNoHomeYet.h"
#include <BSLib/BSLib.h>
#include <d3d9.h>

struct SPartyMemberData
{
public:
    std::n_wstring m_charactername; //0x0000
    std::n_wstring m_guildname; //0x001C
private:
    char pad_0038[8]; //0x0038
public:
    int currentLevel; //0x0040
    int currentHP; //0x0044 HP in Percent/10
    int maxHP; //0x0048
    int currentMP; //0x004C MP in Percent/10
    int maxMP; //0x0050
private:
    char pad_0054[6]; //0x0054
public:
    uregion region; //0x005A
    D3DVECTOR position; //0x005C
private:
    char pad_0068[16]; //0x0068

private:
    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_charactername, 0x0000)
        ENSURE_OFFSET(m_guildname, 0x001C)
        ENSURE_OFFSET(currentLevel, 0x0040)
        ENSURE_OFFSET(currentHP, 0x0044)
        ENSURE_OFFSET(maxHP, 0x0048)
        ENSURE_OFFSET(currentMP, 0x004C)
        ENSURE_OFFSET(maxMP, 0x0050)
        ENSURE_OFFSET(region, 0x005A)
        ENSURE_OFFSET(position, 0x005C)
    END_FIXTURE()

    RUN_FIXTURE(SPartyMemberData)
};
