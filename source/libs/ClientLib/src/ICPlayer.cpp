#include "ICPlayer.h"

// CICPlayer::IsGameMasterMAYBE(void) .text 009D4C40 00000009   R . . . . T .
bool CICPlayer::IsGameMaster() {
    return N000094A7 & 1;
}

// sub_9D6580 .text 009D6580 00000032 00000008 00000004 R . . . . T .
// I am pretty sure this func simply returned a copy of the players name ... ridiculous!
std::n_wstring *CICPlayer::sub_9D6580(std::n_wstring *str) {
    return reinterpret_cast<std::n_wstring*(__thiscall*)(CICPlayer*, std::n_wstring*)>(0x9D6580)(this, str);
}
