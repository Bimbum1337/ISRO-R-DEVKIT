#pragma once

#include "ICharactor.h"
#include "UserGuildInfo.h"

class CICUser : public CICharactor {
    GFX_DECLARE_DYNAMIC_EXISTING(CICUser, 0x00ef1bc0)
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
    char pad_078C[56]; //0x078C
    UserGuildInfo *m_pGuildInfo; //0x07C4
    std::n_wstring m_grantName; //0x07C8
    std::n_wstring m_guildName; //0x07E4
    std::n_wstring m_fortressWarTitle; //0x0800
    undefined1 field_81c; //0x081C
    char pad_081D[15]; //0x081D

    BEGIN_FIXTURE()
        ENSURE_SIZE(2092)
        ENSURE_OFFSET(m_pGuildInfo, 0x07C4)
        ENSURE_OFFSET(m_grantName, 0x07C8)
        ENSURE_OFFSET(m_guildName, 0x07E4)
        ENSURE_OFFSET(m_fortressWarTitle, 0x0800)
    END_FIXTURE()

    RUN_FIXTURE(CICUser)
};
