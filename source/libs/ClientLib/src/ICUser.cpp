#include "ICUser.h"

// CICUser::GetGuildName() .text 009DB100 00000007   R . . . . . .
const std::wstring &CICUser::GetGuildName() const {
    return reinterpret_cast<const std::wstring &(__thiscall*)(const CICUser*)>(0x009DB100)(this);
}
