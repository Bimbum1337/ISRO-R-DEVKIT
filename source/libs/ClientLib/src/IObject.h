#pragma once

#include "GFXMainFrame/IEntity.h"

#include <d3d9.h>

#include "GlobalHelpersThatHaveNoHomeYet.h"


class CIObject : public CIEntity {
public:

    virtual void Func_14();

    /// \address 004df110
    virtual void Func_15(int param_1, float *param_2);

    virtual void Func_16();

    virtual void Func_17();



    uregion GetRegion() const;

    D3DVECTOR GetLocation() const;

private:
    char pad_0054[40]; //0x0054
    uregion region; //0x007C
    char pad_007E[2]; //0x007E
    D3DVECTOR location; //0x0080
    float rotation; //0x008C
    char pad_0090[76]; //0x0090

    BEGIN_FIXTURE()
        ENSURE_SIZE(0xdc)
        ENSURE_OFFSET(region, 0x7c)
        ENSURE_OFFSET(location, 0x80)
        ENSURE_OFFSET(rotation, 0x8C)
    END_FIXTURE()

    RUN_FIXTURE(CIObject)
};
