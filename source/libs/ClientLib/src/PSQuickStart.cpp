#include "PSQuickStart.h"

#include <BSLib/Debug.h>

#include "unsorted.h"
#include "GlobalHelpersThatHaveNoHomeYet.h"
#include "ClientNet/ClientNet.h"
#include "Game.h"

GlobalVar<bool, 0x00EED310> CPSQuickStart::m_ready;

char CPSQuickStart::charname[32];
char CPSQuickStart::ibuv_text[32];

char CPSQuickStart::OnCreate(int a1)
{
	BS_DEBUG_LOW("> " __FUNCTION__ "(%d)", a1);

	if (!StartNetEngine())
	{
		CGFXMainFrame::SetNextProcessSTAT(reinterpret_cast<CGfxRuntimeClass*>(0x0EED894));
		return false;
	}

	g_CGame->LoadTextfiles();
	m_ready = true;

	ShowWindow(g_CGame->GetHWnd(), SW_SHOWNORMAL);
	UpdateWindow(g_CGame->GetHWnd());

	g_CGame->ResizeMainWindow();

	return true;
}

int CPSQuickStart::OnNetMsg(CMsgStreamBuffer* pMsg)
{
	BS_DEBUG_LOW("> " __FUNCTION__ " ~ Got Msg %04x", pMsg->msgid());
	if (pMsg->msgid() == 0x1002)
	{
		int unk1, unk2;
		*pMsg >> unk1 >> unk2;

		CClientNet::get()->IBUV_confirm(ibuv_text); // Confirm IBVU
		BS_INFO("Send IBUV confirmation with text \"%s\"", ibuv_text);

		return 0;
	}

	if (pMsg->msgid() == 0x1003)
	{
		int unk1, unk2;
		*pMsg >> unk1 >> unk2;

		BS_INFO("IBUV_Response [%d][%d]", unk1, unk2);
		return 0;
	}

	if (pMsg->msgid() == 0xB007)
	{
		pMsg->FlushRemaining();

		CMsgStreamBuffer buf(0x7001);

		buf << std::string(charname); // Character Name
		BS_INFO("Sent charname: \"%s\"", charname);

		SendMsg(buf);

		return 0;
	}

	return reinterpret_cast<int(__thiscall*)(CPSQuickStart*,CMsgStreamBuffer*)>(0x00863AD0)(this, pMsg);
}
