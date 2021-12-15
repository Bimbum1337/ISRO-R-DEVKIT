#include "ICPlayer.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CICPlayer, 0x00ef1b44)


// CICPlayer::IsGameMasterMAYBE(void) .text 009D4C40 00000009   R . . . . T .
bool CICPlayer::IsGameMaster() {
    return N000094A7 & 1;
}

// sub_9D6580 .text 009D6580 00000032 00000008 00000004 R . . . . T .
// I am pretty sure this func simply returned a copy of the players name ... ridiculous!
std::n_wstring *CICPlayer::sub_9D6580(std::n_wstring *str) {
    return reinterpret_cast<std::n_wstring*(__thiscall*)(CICPlayer*, std::n_wstring*)>(0x9D6580)(this, str);
}

std::n_wstring CICPlayer::GetCharName() const {
    return m_charname;
}

unsigned char CICPlayer::GetCurrentLevel() const {
    return m_level;
}

long long int CICPlayer::GetCurrentExp() const {
    return m_exp_current;
}

short CICPlayer::GetStatPointAvailable() const {
    return m_statpoint_available;
}

short CICPlayer::GetStrength() const {
    return m_str_stat;
}

short CICPlayer::GetIntelligence() const {
    return m_int_stat;
}

const std::n_wstring &CICPlayer::GetJobAlias() const {
    return m_jobAlias;
}

int CICPlayer::GetCurrentJobExperiencePoints() const {
    return reinterpret_cast<int (__thiscall *)(const CICPlayer *)>(0x009d4d20)(this);
}
