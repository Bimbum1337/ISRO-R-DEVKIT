#pragma once

#include "IFWnd.h"

class CAlramGuideMgrWnd : public CIFWnd {

GFX_DECLARE_DYNAMIC_EXISTING(CAlramGuideMgrWnd, 0x00ee99a8)

public:
    CAlramGuideMgrWnd();

    CGWnd *GetGuide(int windowId);

    void UpdatePositions();

private:
    unsigned char m_numberOfIcons;
    std::list<CGWnd*> m_list;
};
