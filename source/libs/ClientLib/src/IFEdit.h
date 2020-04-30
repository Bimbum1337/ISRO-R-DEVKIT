#pragma once

#include "IFStatic.h"

class CIFEdit : public CIFStatic {
GFX_DECLARE_DYNAMIC_EXISTING(CIFEdit, 0x00ee9540)

public:
    /// \address 00634EA0
    bool HasFocus() const;

private:
    char pad_0x0380[0xB100]; //0x0380 ????
};
