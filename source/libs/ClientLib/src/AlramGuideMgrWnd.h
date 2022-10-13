#pragma once

#include "IFWnd.h"

#define GDR_ALRAM_GUIDE_MGR_WND 158

class CAlramGuideMgrWnd : public CIFWnd {

GFX_DECLARE_DYNAMIC_EXISTING(CAlramGuideMgrWnd, 0x1179BF8)

public:
    CAlramGuideMgrWnd();

    CGWnd *GetGuide(int windowId);

    void UpdatePositions();

private:
    unsigned char m_numberOfIcons; //0x00374
    std::list<CGWnd*> m_list; //0x00375
};
