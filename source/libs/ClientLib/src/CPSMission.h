#pragma once
#include "../../../third-party/ghidra/src/ghidra/undefined.h"
#include "PSilkroad.h"

class CPSMission : public CPSilkroad {
public:
    bool OnServerPacketRecv(class CMsgStreamBuffer* MsgBuffer);

public:
    undefined1 pad_e0[68];

    undefined4 m_dwRealTime;
    undefined2 m_wDay;
    undefined1 m_byHour;
    undefined1 m_byMin;

    undefined1 pad_12c[16];

};

