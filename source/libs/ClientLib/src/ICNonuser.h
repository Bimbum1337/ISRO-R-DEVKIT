#pragma once

#include "ICharactor.h"


class CICNonuser : public CICharactor {
    GFX_DECLARE_DYNAMIC_EXISTING(CICNonuser, 0x00EF1AA4)


private:
    CClassLink<CICNonuser> m_classlink; //0x078C

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x79C)
    END_FIXTURE()
    RUN_FIXTURE(CICNonuser)
}; //Size: 0x079C
