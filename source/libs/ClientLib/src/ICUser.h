#pragma once

#include "ICharactor.h"
#include "UserGuildInfo.h"

class CICUser : public CICharactor {
    GFX_DECLARE_DYNAMIC_EXISTING(CICUser, 0x00ef1bc0)
public:

    const std::wstring &GetGuildName() const;

    void Render(void);

    UserGuildInfo *GetGuildInfo() const;
private:
    char pad_078C[56]; //0x078C
    UserGuildInfo *m_pGuildInfo; //0x07C4
    char pad_07C8[28]; //0x07C8
    std::n_wstring m_guildName; //0x07E4
    std::n_wstring m_fortressWarTitle; //0x0800
    char pad_081C[16]; //0x081C

    BEGIN_FIXTURE()
        ENSURE_SIZE(2092)
        ENSURE_OFFSET(m_pGuildInfo, 0x07C4)
        ENSURE_OFFSET(m_guildName, 0x07E4)
        ENSURE_OFFSET(m_fortressWarTitle, 0x0800)
    END_FIXTURE()

    RUN_FIXTURE(CICUser)
};
