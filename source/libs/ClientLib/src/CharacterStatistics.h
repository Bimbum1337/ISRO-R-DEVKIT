#pragma once

#include "ghidra/undefined.h"
#include <Test/Test.h>

struct SCharacterStatistics {
    undefined4 field_0;
    undefined4 field_4;
    undefined4 field_8;
    undefined4 field_C;
    undefined2 field_10;
    undefined2 field_12;
    undefined2 field_14;
    undefined2 field_16;

    BEGIN_FIXTURE()
        ENSURE_OFFSET(field_0, 0x0000)
        ENSURE_OFFSET(field_4, 0x0004)
        ENSURE_OFFSET(field_8, 0x0008)
        ENSURE_OFFSET(field_C, 0x000C)
        ENSURE_OFFSET(field_10, 0x0010)
        ENSURE_OFFSET(field_12, 0x0012)
        ENSURE_OFFSET(field_14, 0x0014)
        ENSURE_OFFSET(field_16, 0x0016)
    END_FIXTURE()

    RUN_FIXTURE(SCharacterStatistics)
};
