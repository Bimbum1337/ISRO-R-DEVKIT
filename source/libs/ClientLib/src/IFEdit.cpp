#include "IFEdit.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFEdit, 0x00ee9540)

bool CIFEdit::HasFocus() const {
    return reinterpret_cast<bool (__thiscall *)(const CIFEdit *)>(0x00634EA0)(this);
}

