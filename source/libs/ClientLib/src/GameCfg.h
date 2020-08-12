#pragma once

#include <Test/Test.h>
#include "LocalTime.h"

class GameCfg {

public:
    undefined1 pad_0000[0xf8];
    CLocalTime m_LocalTime;





    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_LocalTime, 0xf8)
    END_FIXTURE()

    RUN_FIXTURE(GameCfg)
};
