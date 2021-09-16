#pragma once

#include "PSilkroad.h"
#include "CameraWorking.h"

class CPSOuterInterface : public CPSilkroad {
GFX_DECLARE_DYNAMIC_EXISTING(CPSOuterInterface, 0x00EED954);

public:
    /// \address 00860C60
    void OnTimer(int a1) override;

    /// \address 00860CC0
    void OnUpdate() override;

    /// \address 00862450
    void Func_40() override;

    /// \address 00860ED0
    void RenderMyself() override;

    /// \address 008611D0
    void Handle_0xFFC(CMsgStreamBuffer *p_msg);

    /// \address 008629A0
    CPSOuterInterface();

    /// \address 00862410
    void WaitGWnd(bool a1);

protected:
    CCameraWorking *m_cameraworking; //0x00E0
    int current_state; //0x00E4
    int N0000098B; //0x00E8
private:
    char pad_00EC[32]; //0x00EC


    BEGIN_FIXTURE()
        ENSURE_SIZE(0x10c)
        ENSURE_OFFSET(m_cameraworking, 0xe0)
        ENSURE_OFFSET(current_state, 0xe4)
    END_FIXTURE()

    RUN_FIXTURE(CPSOuterInterface)
};

