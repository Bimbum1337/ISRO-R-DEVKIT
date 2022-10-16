#include "CPSMission.h"

bool CPSMission::OnServerPacketRecv(CMsgStreamBuffer* msg) {
    printf("Received Packet: 0x%X\n\r",msg->msgid());
    return reinterpret_cast<bool(__thiscall*)(CPSMission*, CMsgStreamBuffer*)>(0x0094D910)(this, msg);
}

