#pragma once

#include "IFStatic.h"

class CIFButton : public CIFStatic {
public:

    /// \brief Maybe sets the hover text
    /// \address 00653DC0
    void sub_653DC0(std::n_wstring *str);

    /// \address 00652D20
    /// \remark Related to setting the hover text
    void sub_652D20(int a2);

private:
    char pad_0x0380[0x1C]; //0x0380
    char *m_disabledPath; //0x039C
    char pad_0x03A0[0x18]; //0x03A0
    char *m_pressedPath; //0x03B8
    char pad_0x03BC[0x18]; //0x03BC
};

