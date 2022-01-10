#include <cstdio>
#include "RStateMgr.h"

void CRStateMgr::FUN_00471360(int param_1, int param_2) {
    reinterpret_cast<void (__thiscall *)(CRStateMgr *, int, int)>(0x00471360)(this, param_1, param_2);
}

void CRStateMgr::FUN_00478500(undefined4 param_1, pointer param_2) {
    reinterpret_cast<void (__thiscall *)(CRStateMgr *, undefined4, pointer)>(0x00478500)(this, param_1, param_2);
}

undefined4 CRStateMgr::SetTextureForStage(int param_1, const IDirect3DBaseTexture9* param_2 ) {
    return reinterpret_cast<undefined4 (__thiscall *)(CRStateMgr *, int, const IDirect3DBaseTexture9*)>(0x004702d0)(this, param_1, param_2);
}

void CRStateMgr::FUN_00470060(undefined4 param_1, int param_2, int param_3) {
    reinterpret_cast<void (__thiscall *)(CRStateMgr *, undefined4, int, int)>(0x00470060)(this, param_1, param_2, param_3);
}

undefined4 CRStateMgr::FUN_00470310(int param_1) {
    return reinterpret_cast<undefined4 (__thiscall *)(CRStateMgr *, int)>(0x00470310)(this, param_1);
}
