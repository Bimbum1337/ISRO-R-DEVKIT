#include "ICUser.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CICUser, 0x00ef1bc0)

// CICUser::GetGuildName() .text 009DB100 00000007   R . . . . . .
const std::wstring &CICUser::GetGuildName() const {
    return reinterpret_cast<const std::wstring &(__thiscall*)(const CICUser*)>(0x009DB100)(this);
}

UserGuildInfo *CICUser::GetGuildInfo() const {
    return m_pGuildInfo;
}

unsigned char CICUser::GetJobLevel() const {
    return reinterpret_cast<unsigned char (__thiscall *)(const CICUser *)>(0x009db0e0)(this);
}

undefined1 CICUser::FUN_009db0d0() const {
    return reinterpret_cast<undefined1 (__thiscall *)(const CICUser *)>(0x009db0d0)(this);
}
