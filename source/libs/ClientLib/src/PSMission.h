#pragma once

#include "PSilkroad.h"
#include <Test/Test.h>
#include <ghidra/undefined.h>

class CNetProcessIn;

class CPSMission : public CPSilkroad {
    friend CNetProcessIn;


private:
    undefined1 pad_e0[68];

    undefined4 m_dwRealTime;
    undefined2 m_wDay;
    undefined1 m_byHour;
    undefined1 m_byMin;

    undefined1 pad_12c[16];

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x13c)
        ENSURE_OFFSET(m_dwRealTime, 0x124)
        ENSURE_OFFSET(m_wDay, 0x128)
        ENSURE_OFFSET(m_byHour, 0x12a)
        ENSURE_OFFSET(m_byMin, 0x12b)
    END_FIXTURE()

    RUN_FIXTURE(CPSMission)
};
