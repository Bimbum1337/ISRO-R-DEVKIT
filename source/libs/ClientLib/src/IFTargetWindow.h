#pragma once

#include "IFWnd.h"
#include "IFTargetWindowPlayer.h"
#include "IFTargetWindowCommonEnemy.h"
#include "IFTargetWindowSpecialMob.h"
#include "IFTargetWindowJobPlayer.h"
#include "IFBuffViewer.h"
#include "IFTargetWindowFortressStructure.h"

class CIFTargetWindow : public CIFWnd {
GFX_DECLARE_DYNAMIC_EXISTING(CIFTargetWindow, 0x00eea57c)

    GFX_DECLARE_DYNCREATE_FN(CIFTargetWindow)

GFX_DECLARE_MESSAGE_MAP(CIFTargetWindow)

public:

    /// \address 006993a0
    void OnTimer(int timerId) override;

    /// \address 00699080
    bool OnCreate(long ln) override;

    /// \address 00698ae0
    void OnUpdate() override;

    /// \address 00698b50
    void ShowGWnd(bool bVisible) override;

    /// \address 0069a300
    undefined1 OnCloseWnd() override;

    /// \address 00698be0
    void OnClick_11();

private:
    char pad_0x0374[0x8];
    CIFTargetWindowCommonEnemy* m_pGDR_TW_COMMONENEMY; //0x37C
    CIFTargetWindowPlayer* m_pGDR_TW_PLAYERWND; //0x380
    CIFTargetWindowJobPlayer* m_pGDR_TW_JOB_PLAYERWND; //0x384
    CIFTargetWindowSpecialMob* m_pGDR_TW_SPECIALMOBWND; //0x388
    CIFTargetWindowFortressStructure* m_pGDR_TW_FORTRESSSTRUCTER; // 0x38C
    CIFBuffViewer* m_pCIFBuffViewer; //0x390

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x394)
        ENSURE_OFFSET(m_pGDR_TW_COMMONENEMY, 0x37C)
        ENSURE_OFFSET(m_pGDR_TW_PLAYERWND, 0x380)
        ENSURE_OFFSET(m_pGDR_TW_JOB_PLAYERWND, 0x384)
        ENSURE_OFFSET(m_pGDR_TW_SPECIALMOBWND, 0x388)
        ENSURE_OFFSET(m_pGDR_TW_FORTRESSSTRUCTER, 0x38C)
        ENSURE_OFFSET(m_pCIFBuffViewer, 0x390)
    END_FIXTURE()

    RUN_FIXTURE(CIFTargetWindow)
};