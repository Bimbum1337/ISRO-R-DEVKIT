#pragma once

#include "IFDecoratedStatic.h"

class CIFFacebookLinkAlram : public CIFDecoratedStatic {

    GFX_DECLARE_DYNAMIC_EXISTING(CIFFacebookLinkAlram, 0x1177054)

    void OnFacebookNavigate(CIFWnd* p_wnd,int confirmed);

    bool OnCreateIMPL(long ln);
};
