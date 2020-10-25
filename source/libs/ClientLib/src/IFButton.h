#pragma once

#include <ghidra/undefined.h>
#include "IFStatic.h"

class CIFButton : public CIFStatic {
public:
    /// \address 00655fa0
    void FUN_00655fa0(undefined4 a1);

private:
    char pad_0x0380[0x1C]; //0x0380
    char *m_disabledPath; //0x039C
    char pad_0x03A0[0x18]; //0x03A0
    char *m_pressedPath; //0x03B8
    char pad_0x03BC[0x18]; //0x03BC
};

