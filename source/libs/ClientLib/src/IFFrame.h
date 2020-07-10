#pragma once

#include "IFTileWnd.h"

class CIFFrame : public CIFTileWnd {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFFrame, 0x00EECB14)

public:
    // Constructor is trivial
    // \address 008151E0
    // CIFFrame();

    // Destructor is trivial
    // \address 00815210
    // ~CIFFrame();

    /// \address 00815230
    bool OnCreate(long ln) override;

    /// \address 00815490
    void RenderMyself() override;

    /// \address 00815300
    void Func_49(std::n_string str) override;

private:
    // No members


    BEGIN_FIXTURE()
        ENSURE_SIZE(0x7b0)
    END_FIXTURE()
    RUN_FIXTURE(CIFFrame)


};

