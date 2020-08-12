#include "LocalTime.h"

void CLocalTime::FUN_008b01b0(CLocalTime_Sub *data) {
    reinterpret_cast<void (__thiscall *)(CLocalTime *, CLocalTime_Sub *)>(0x008b01b0)(this, data);
}

undefined4 CLocalTime::InitTimer(int dwRealTime, short wDay, unsigned char byHour, unsigned char byMin, unsigned char a6) {
    return reinterpret_cast<undefined4(__thiscall *)(CLocalTime *, int, short, unsigned char, unsigned char, unsigned char)>(0x008b00f0)(this, dwRealTime, wDay, byHour, byMin, a6);
}
