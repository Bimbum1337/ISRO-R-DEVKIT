#pragma once

#include "ICNonuser.h"
#include <ghidra/undefined.h>

class CICMonster : public CICNonuser {

public:
    /// \address 009d3e70
    void Func_15(int param_1, float *param_2) override;
    void Func_15_impl(int param_1, float *param_2);

    /// \address 009d3c90
    void Func_19() override;

    /// \address 009d2f90
    void Func_22() override;

    /// \address 009d3850
    void Func_25() override;

    /// \address 009d3010
    void Func_41() override;

    /// \address 009d3020
    void  Func_42() override;

    /// \address 00534b50
    void  Func_51() override;

    /// \address 009d3160
    bool IsHostile();

private:
    char pad_79C[0x1C];

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x7b8)
    END_FIXTURE()

    RUN_FIXTURE(CICMonster)
};


