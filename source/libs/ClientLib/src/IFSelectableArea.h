#pragma once

#include "IFStatic.h"

class CIFSelectableArea : public CIFStatic {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFSelectableArea, 0x00EE96C0)

public:
    /// \address 0064CE30
    void sub_64CE30(std::n_string a, std::n_string b, std::n_string c);

    /// \address 0064CC30
    void sub_64CC30(char a2);

private:
    char pad_0x0380[0x70]; //0x0380
};
