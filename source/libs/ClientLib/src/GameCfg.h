#pragma once

#include "LocalTime.h"
#include <Test/Test.h>

class GameCfg {

public:
    undefined1 pad_0000[0xf8]; //0x000
    CLocalTime m_LocalTime; //0x0f8
    char pad_00f9[0x4F]; //0x0f9
    undefined m_RunMode;
    BEGIN_FIXTURE()
    ENSURE_OFFSET(m_LocalTime, 0xf8)
    END_FIXTURE()

    RUN_FIXTURE(GameCfg)
};
