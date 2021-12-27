#pragma once

#include "IFWnd.h"

class CIFTargetWindowJobPlayer : public CIFWnd {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFTargetWindowJobPlayer, 0x00eea5bc)

    GFX_DECLARE_DYNCREATE_FN(CIFTargetWindowJobPlayer)

    GFX_DECLARE_MESSAGE_MAP(CIFTargetWindowJobPlayer)

public:

    /// \address 0069ac40
    bool OnCreate(long ln) override;

    /// \address 0069ac90
    void FUN_0069ac90(int objectId);

private:
    int m_objectId;

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x370)
        ENSURE_OFFSET(m_objectId, 0x036C)
    END_FIXTURE()

    RUN_FIXTURE(CIFTargetWindowJobPlayer)
};
