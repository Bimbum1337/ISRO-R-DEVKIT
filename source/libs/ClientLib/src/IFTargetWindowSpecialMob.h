#pragma once

#include "IFWnd.h"
#include "IFStatic.h"
#include "IFGauge.h"

class CIFTargetWindowSpecialMob : public CIFWnd {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFTargetWindowSpecialMob, 0x00eea5fc)

    GFX_DECLARE_DYNCREATE_FN(CIFTargetWindowSpecialMob)

    GFX_DECLARE_MESSAGE_MAP(CIFTargetWindowSpecialMob)

public:
    /// \address 0069b410
    bool OnCreate(long ln) override;

    /// \address 0069b240
    void OnUpdate() override;

private:
    char pad_0x0374[0x4];
    CIFStatic* m_pGDR_TWSM_TEXT_LEV; // 0x378
    CIFGauge* m_pGDR_TWSM_GAUGE_HPGAUGE; // 0x37C
    CIFStatic* m_pGDR_TWSM_TEXT_ID; // 0x380

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x384)
        ENSURE_OFFSET(m_pGDR_TWSM_TEXT_LEV, 0x378)
        ENSURE_OFFSET(m_pGDR_TWSM_GAUGE_HPGAUGE, 0x37C)
        ENSURE_OFFSET(m_pGDR_TWSM_TEXT_ID, 0x380)
    END_FIXTURE()

    RUN_FIXTURE(CIFTargetWindowSpecialMob)
};
