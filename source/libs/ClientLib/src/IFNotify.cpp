#include "IFNotify.h"

void CIFNotify::ShowMessage(const std::n_wstring &msg) {
    reinterpret_cast<void(__thiscall*)(CIFNotify*,const std::n_wstring*)>(0x007b3eb0)(this, &msg);
}
