#pragma once

#include "ClientNet/MsgStreamBuffer.h"
#include "remodel/GlobalVar.h"


class CPSQuickStart {
public:
	int OnPacket_MAYBE_IMPL(CMsgStreamBuffer* pMsg);
	char OnCreate_IMPL(int a1);

	static GlobalVar<bool, 0x00EED310> m_ready;
};

