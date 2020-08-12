#pragma once

#include <Test/Test.h>
#include <ghidra/undefined.h>

class CLocalTime_Sub {
public:
    CLocalTime_Sub() : field_0(0), field_2(0), field_3(0) {}

private:
    undefined2 field_0;
    undefined1 field_2;
    undefined1 field_3;
    undefined1 field_4;


    BEGIN_FIXTURE()
        ENSURE_OFFSET(field_0, 0)
        ENSURE_OFFSET(field_2, 2)
        ENSURE_OFFSET(field_3, 3)
        ENSURE_OFFSET(field_4, 4)
    END_FIXTURE()

    RUN_FIXTURE(CLocalTime_Sub)
};


class CLocalTime {
public:
    /// \address 008b01b0
    void FUN_008b01b0(CLocalTime_Sub *data);

    /// \address 008b00f0
    undefined4 InitTimer(int dwRealTime, short wDay, unsigned char byHour, unsigned char byMin, unsigned char a6);
};
