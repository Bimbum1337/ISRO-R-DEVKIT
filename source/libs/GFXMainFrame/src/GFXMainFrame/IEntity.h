#pragma once

#include <BSLib/BSLib.h>
#include "Test/Test.h"

class CIEntity : public CObjChild {

public:
    virtual void Func_7();

    virtual void Func_8();

    virtual void Func_9();

    virtual void Func_10();

    virtual void Func_11();

    virtual void Func_12();

    virtual void Func_13();

private: /* members */
    char pad_0020[52]; //0x0020

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x54)
    END_FIXTURE()

    RUN_FIXTURE(CIEntity)
};
