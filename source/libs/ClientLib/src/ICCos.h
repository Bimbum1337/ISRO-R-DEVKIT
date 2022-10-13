#pragma once

#include "ICNonuser.h"


class CICCos : public CICNonuser {
    GFX_DECLARE_DYNAMIC_EXISTING(CICCos, 0x1199218)

public:
private:
    CClassLink<CICCos> m_classlink; //0x08CC
    char pad_08DC[8]; //0x08DC
private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x8E4)
        END_FIXTURE()
        RUN_FIXTURE(CICCos)
};