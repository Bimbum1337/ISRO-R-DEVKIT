#include "StringCheck.h"

char CStringCheck::sub_8C4020(const std::n_wstring &str) {
    return reinterpret_cast<char(__thiscall*)(CStringCheck*, const std::n_wstring*)>(0x8C4020)(this, &str);
}
