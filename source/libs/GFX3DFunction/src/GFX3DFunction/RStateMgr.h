#pragma once

#include "d3d9.h"
#include "ghidra/undefined.h"

#define g_RStateMgr (*reinterpret_cast<CRStateMgr*>(0x01112428))

class CRStateMgr {

public:
    /// \address 00471360
    void FUN_00471360(int param_1, int param_2);

    /// \address 00478500
    void FUN_00478500(undefined4 param_1, pointer param_2);

    /// \address 004702d0
    undefined4 SetTextureForStage(int param_1, const IDirect3DBaseTexture9* param_2);

    /// \address 00470060
    void FUN_00470060(undefined4 param_1, int param_2, int param_3);

    /// \address 00470310
    undefined4 FUN_00470310(int param_1);

    template<DWORD Stage, D3DTEXTURESTAGESTATETYPE Type>
    static inline void SetStageOperator(DWORD value) {
        static DWORD currentValue = 0;

        if (value != currentValue) {
            currentValue = value;
            g_RStateMgr.m_pDevice->SetTextureStageState(Stage, Type, value);
        }
    }

public:
    IDirect3DDevice9* m_pDevice; // 0x0000

};
