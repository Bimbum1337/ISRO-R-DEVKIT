#pragma once

#include "ICharactor.h"


class CICNonuser : public CICharactor {

private:
    char pad_78C[0x10];

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x79c)
    END_FIXTURE()

    RUN_FIXTURE(CICNonuser)
};


