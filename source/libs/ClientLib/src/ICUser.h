#pragma once

#include "ICharactor.h"
#include "UserGuildInfo.h"

class CICUser : public CICharactor {
    GFX_DECLARE_DYNAMIC_EXISTING(CICUser, 0x119B6F0)
public:

    /// \address 009dea30
    void Func_15(int param_1, float *param_2) override;
    void Func_15_impl(int param_1, float *param_2);

    const std::wstring &GetGuildName() const;

    void Render(void);

    UserGuildInfo *GetGuildInfo() const;

    /// \address 009db0e0
    unsigned char GetJobLevel() const;

    /// \address 009db0d0
    undefined1 FUN_009db0d0() const;

    /// \address 009dad40
    bool GetBeginnerState() const;

private:
    void RenderFortressIcons(D3DVECTOR *dataOut, float *param_2);

private:
    char pad_08BC[56]; //0x08BC
    UserGuildInfo *m_pGuildInfo; //0x08F4
    std::n_wstring m_grantName; //0x08F8
    std::n_wstring m_guildName; //0x0914
    std::n_wstring m_fortressWarTitle; //0x0930
    undefined1 field_94c; //0x094c
    char pad_094D[0xA3]; //0x094D

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x9F0)
        ENSURE_OFFSET(m_pGuildInfo, 0x08F4)
        ENSURE_OFFSET(m_grantName, 0x08F8)
        ENSURE_OFFSET(m_guildName, 0x0914)
        ENSURE_OFFSET(m_fortressWarTitle, 0x0930)
    END_FIXTURE()

    RUN_FIXTURE(CICUser)
};
