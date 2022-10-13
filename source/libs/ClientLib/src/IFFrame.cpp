#include "IFFrame.h"
#include <BSLib/Debug.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFFrame, 0x117D944)

bool CIFFrame::OnCreate(long ln) {
    return reinterpret_cast<bool(__thiscall*)(CIFFrame*, long)>(0x0090BDC0)(this, ln);
}

void CIFFrame::RenderMyself() {
    reinterpret_cast<void (__thiscall *)(CIFFrame *)>(0x0090C020)(this);
}

void CIFFrame::Func_49(std::n_string str) {
    BS_DEBUG_LOW("%s (\"%s\")", __FUNCTION__, str.c_str());
    reinterpret_cast<void (__thiscall *)(CIFFrame *, std::n_string)>(0x0090BE90)(this, str);
}
