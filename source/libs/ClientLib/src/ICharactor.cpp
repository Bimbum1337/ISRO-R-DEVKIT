#include "ICharactor.h"

CLASSLINK_STATIC_IMPL(CICharactor)

void CICharactor::ShowMessageAboveEntity(const std::n_wstring &message, D3DCOLOR color) {
    reinterpret_cast<void(__thiscall*)(CICharactor*, const std::n_wstring *, D3DCOLOR)>(0x009c77c0)(this, &message, color);
}

unsigned int CICharactor::GetMaxHp() const {
    return m_hpMax;
}

unsigned int CICharactor::FUN_009c7880() const {
    return reinterpret_cast<unsigned int(__thiscall *)(const CICharactor *)>(0x009c7880)(this);
}

unsigned int CICharactor::GetCurrentMp() const {
    return m_mpCurrent;
}

unsigned int CICharactor::GetMaxMp() const {
    return m_mpMax;
}
