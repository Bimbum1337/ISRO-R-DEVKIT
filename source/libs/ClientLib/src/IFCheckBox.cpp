#include "IFCheckBox.h"

bool CIFCheckBox::GetCheckedState_MAYBE() const {
    return reinterpret_cast<bool (__thiscall *)(const CIFCheckBox *)>(0x00656db0)(this);
}

void CIFCheckBox::FUN_00656d50(bool state) {
    reinterpret_cast<void (__thiscall *)(CIFCheckBox *, bool)>(0x00656d50)(this, state);
}
