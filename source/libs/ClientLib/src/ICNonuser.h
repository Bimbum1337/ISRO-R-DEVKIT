#pragma once

#include "ICharactor.h"


class CICNonuser : public CICharactor {
    GFX_DECLARE_DYNAMIC_EXISTING(CICNonuser, 0x119B5CC)


private:
    CClassLink<CICNonuser> m_classlink; //0x08BC

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x8CC)
    END_FIXTURE()
    RUN_FIXTURE(CICNonuser)
}; //Size: 0x079C
