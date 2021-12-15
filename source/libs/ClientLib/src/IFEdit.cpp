#include "IFEdit.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFEdit, 0x00ee9540)

bool CIFEdit::HasFocus() const {
    return reinterpret_cast<bool (__thiscall *)(const CIFEdit *)>(0x00634EA0)(this);
}

void CIFEdit::AddValue_404(undefined4 value) {
    reinterpret_cast<void(__thiscall *)(CIFEdit *, undefined4)>(0x00635150)(this, value);
}

void CIFEdit::SetValue_404(undefined4 value) {
    reinterpret_cast<void(__thiscall *)(CIFEdit *, undefined4)>(0x00635070)(this, value);
}

undefined4 CIFEdit::GetValue_404() const {
    return reinterpret_cast<undefined4(__thiscall *)(const CIFEdit *)>(00635060)(this);
}

bool CIFEdit::IsSetValue_404(undefined4 value) const {
    return reinterpret_cast<bool(__thiscall *)(const CIFEdit *, undefined4)>(0x00635170)(this, value);
}

void CIFEdit::FUN_00634f80(unsigned int a1) {
    reinterpret_cast<void(__thiscall *)(CIFEdit *, unsigned int)>(0x00634f80)(this, a1);
}

void CIFEdit::SetTextmode(undefined4 mode) {
    reinterpret_cast<void(__thiscall *)(CIFEdit *, undefined4)>(0x006351b0)(this, mode);
}
const std::n_wstring &CIFEdit::GetCurrentText() const {
    return m_texturestr_font;
}
