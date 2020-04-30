#include "IFListCtrl.h"

void CIFListCtrl::SetHighlightColor(D3DCOLOR color) {
    m_BackgroundColor = color;
}

void CIFListCtrl::SetHightlineLine(bool a2) {
    m_bHighlighLine = a2;
}

bool CIFListCtrl::OnCreate(long ln) {
    return true;
}

CIFListCtrl::SLineOfText* CIFListCtrl::sub_63A940() {
    return reinterpret_cast<CIFListCtrl::SLineOfText*(__thiscall*)(CIFListCtrl*)>(0x63A940)(this);
}

void CIFListCtrl::SetLineHeight(int height) {
    m_LineHeight = height;
}
