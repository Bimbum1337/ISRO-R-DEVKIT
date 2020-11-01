#include "StdAfx.h"
#include "IFFrame.h"
#include <BSLib/Debug.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFFrame, 0x00EECB14)

bool CIFFrame::OnCreate(long ln) {
    return reinterpret_cast<bool(__thiscall*)(CIFFrame*, long)>(0x00815230)(this, ln);
}

void CIFFrame::RenderMyself() {
    reinterpret_cast<void (__thiscall *)(CIFFrame *)>(0x00815490)(this);
}

void CIFFrame::Func_49(std::n_string str) {
    BS_DEBUG_LOW("%s (\"%s\")", __FUNCTION__, str.c_str());
    reinterpret_cast<void (__thiscall *)(CIFFrame *, std::n_string)>(0x00815300)(this, str);
}
