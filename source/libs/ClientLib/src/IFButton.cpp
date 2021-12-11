#include "IFButton.h"

void CIFButton::FUN_00655fa0(undefined4 a1) {
    reinterpret_cast<void (__thiscall *)(CIFButton *, undefined4)>(0x00655fa0)(this, a1);
}

void CIFButton::SetEnabledState(bool state) {
    reinterpret_cast<void(__thiscall *)(CIFButton *, bool)>(0x00655ec0)(this, state);
}
