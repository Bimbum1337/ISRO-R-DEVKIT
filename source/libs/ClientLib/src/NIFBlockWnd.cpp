#include "NIFBlockWnd.h"

// 005871d0
bool CNIFBlockWnd::IsOnBlockList(std::n_wstring &name) {
    return reinterpret_cast<bool(__thiscall*)(CNIFBlockWnd*, std::n_wstring*)>(0x005871d0)(this, &name);
}
