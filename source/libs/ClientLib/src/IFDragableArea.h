#pragma once

#include "IFWnd.h"

class CIFDragableArea : public CIFWnd {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFDragableArea, 0x117B37C)

    GFX_DECLARE_DYNCREATE_FN(CIFDragableArea)

private: /* members */
    undefined pad[16];

private: /* test fixture */
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x384)
    END_FIXTURE()

    RUN_FIXTURE(CIFDragableArea)
};

