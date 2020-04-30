#pragma once

#include <Windows.h>
#include <ClientNet/MsgStreamBuffer.h>

#define MSG_FLAG_IDFIELD_DUMMYMASK 0x3000u
#define MSG_FLAG_IDFIELD_REQMSG 0x7000u
#define MSG_FLAG_IDFIELD_ACKMSG 0xB000u

// This is not as safe as the name tells ... hmm
// TODO: Figure out how this macro looked. Maybe ask Megamax.
#define SAFE_DEFINE_MSGID(name, id, type) \
    static const WORD name = id ##u | type;

SAFE_DEFINE_MSGID(SR_CHAT_REQ, 0x0025, MSG_FLAG_IDFIELD_REQMSG)
SAFE_DEFINE_MSGID(SR_CHAT_ACK, 0x0025, MSG_FLAG_IDFIELD_ACKMSG)
