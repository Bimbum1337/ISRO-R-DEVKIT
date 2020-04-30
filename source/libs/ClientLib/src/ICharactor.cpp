#include "ICharactor.h"

CLASSLINK_STATIC_IMPL(CICharactor)

void CICharactor::ShowMessageAboveEntity(const std::n_wstring &message, D3DCOLOR color) {
    reinterpret_cast<void(__thiscall*)(CICharactor*, const std::n_wstring *, D3DCOLOR)>(0x009c77c0)(this, &message, color);
}
