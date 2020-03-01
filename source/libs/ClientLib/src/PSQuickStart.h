#pragma once

#include "ClientNet/MsgStreamBuffer.h"
#include "remodel/GlobalVar.h"


class CPSQuickStart {
public:
    static char charname[32];
    static char ibuv_text[32];

public:
	int OnNetMsg(CMsgStreamBuffer* pMsg);
	char OnCreate(int a1);

	static GlobalVar<bool, 0x00EED310> m_ready;
};

