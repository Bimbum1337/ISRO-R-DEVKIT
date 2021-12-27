#pragma once

#include "IFWnd.h"
#include "IFStatic.h"
#include "IFGauge.h"
#include "IFButton.h"

class CIFTargetWindowFortressStructure : public CIFWnd {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFTargetWindowFortressStructure, 0x00ee7b00)

    GFX_DECLARE_DYNCREATE_FN(CIFTargetWindowFortressStructure)

    GFX_DECLARE_MESSAGE_MAP(CIFTargetWindowFortressStructure)

public:
    /// \address 00565480
    bool OnCreate(long ln) override;

    /// \address 00564890
    void OnUpdate() override;

private:
    char pad_0x036C[0x4];
    CIFStatic* m_pGDR_TWFS_TEXT_ID; // 0x0370
    CIFGauge* m_pGDR_TWFS_GAUGE_HPGAUGE; // 0x0374
    CIFButton* m_pGDR_TWFS_D_BUTTON; // 0x0378
    char pad_0x037C[0xC];

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x388)
        ENSURE_OFFSET(m_pGDR_TWFS_TEXT_ID, 0x0370)
        ENSURE_OFFSET(m_pGDR_TWFS_GAUGE_HPGAUGE, 0x0374)
        ENSURE_OFFSET(m_pGDR_TWFS_D_BUTTON, 0x0378)
    END_FIXTURE()

    RUN_FIXTURE(CIFTargetWindowFortressStructure)
};
