#include "IFMainFrame.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFMainFrame, 0x00EECB54)

GFX_BEGIN_MESSAGE_MAP(CIFMainFrame, CIFWnd)
    ONG_COMMAND(2, &OnClick_Exit)
GFX_END_MESSAGE_MAP()


CIFMainFrame::CIFMainFrame()
        : m_title(NULL), m_handleBar(NULL), m_close(NULL) {
}

bool CIFMainFrame::OnCreate(long ln) {
    return reinterpret_cast<bool (__thiscall *)(CIFMainFrame *, long)>(0x00816F80)(this, ln);
}

void CIFMainFrame::SetGWndSize(int width, int height) {
    assert(FALSE);
}

bool CIFMainFrame::SetText(const wchar_t *Src) {
    return reinterpret_cast<bool (__thiscall *)(CIFMainFrame *, const wchar_t *)>(0x00817230)(this, Src);
}

void CIFMainFrame::OnClick_Exit() {
    this->OnCloseWnd();
}