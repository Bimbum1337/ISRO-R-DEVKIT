#pragma once

#include "ICUser.h"
#include "SOItem.h"

class CICPlayer : public CICUser {
    GFX_DECLARE_DYNAMIC_EXISTING(CICPlayer, 0x119B66C)
public:

    /// \address 009d49c0
    void Func_15(int param_1, float *param_2) override;
    void Func_15_impl(int param_1, float *param_2);

    bool IsGameMaster();

    std::n_wstring *sub_9D6580(std::n_wstring *str);

    /// \address 009d6580
    std::n_wstring GetCharName() const;

    unsigned char GetCurrentLevel() const;

    long long int GetCurrentExp() const;

    short GetStatPointAvailable() const;

    short GetStrength() const;

    short GetIntelligence() const;

    /// \address 009d65c0
    /// \remark Optimized to return const reference instead of object
    const std::n_wstring &GetJobAlias() const;

    /// \address 009d4d20
    int GetCurrentJobExperiencePoints() const;

    /// \address 009d68f0
    undefined4 FUN_009d68f0();

private:
    char pad_09F0[32]; //0x09F0
    std::n_wstring m_charname; //0x0A10
public:
    unsigned char m_level; //0x0A2C level of your character, crashes when set too high
private:
    char pad_0A2D[7]; //0x0A2D
public:
    long long int m_exp_current; //0x0A38
    int m_skillpoint_progress; //0x0A40
private:
    short m_str_stat; //0x0A44
    short m_int_stat; //0x0A46
public:
    int m_skillpoint; //0x0A48
private:
    short m_statpoint_available; //0x0A4C
    char pad_0A4E[0x2FAE]; //0x0A4E
    char m_gamemaster_bit; //0x39FC
    char pad_039FD[0x7]; //0x39FD
    std::n_wstring m_jobAlias; //0x3A04
    char pad_03A20[0x78]; //0x3A20

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x3A98)

        ENSURE_OFFSET(m_charname, 0x0A10)
        ENSURE_OFFSET(m_level, 0x0A2C)
        ENSURE_OFFSET(m_exp_current, 0x0A38)
        ENSURE_OFFSET(m_skillpoint_progress, 0x0A40)
        ENSURE_OFFSET(m_str_stat, 0x0A44)
        ENSURE_OFFSET(m_int_stat, 0x0A46)
        ENSURE_OFFSET(m_skillpoint, 0x0A48)
        ENSURE_OFFSET(m_statpoint_available, 0x0A4C)
        ENSURE_OFFSET(m_gamemaster_bit, 0x39FC)
        ENSURE_OFFSET(m_jobAlias, 0x3A04)
        END_FIXTURE()

    RUN_FIXTURE(CICPlayer)
};

#define g_pCICPlayer (*((CICPlayer**)0x01199114))
