#pragma once

#include <BSLib/BSLib.h>
#include "Test/Test.h"

class CIEntity : public CObjChild {
public:
    char pad_0020[52]; //0x0020

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x54)
    END_FIXTURE()

    RUN_FIXTURE(CIEntity)
};
