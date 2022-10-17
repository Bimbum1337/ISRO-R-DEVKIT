#pragma once
#include "IFTileWnd.h"
class CIFMessageBox : public CIFTileWnd {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFMessageBox, 0x11797F0)

private:
    char pad_7b8[0x518];
};