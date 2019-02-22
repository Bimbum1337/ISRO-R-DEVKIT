#include "StdAfx.h"
#include "PSOuterInterface.h"
//#include "TextStringManager.h"
//#include "Game.h"
//#include "PSRestart.h"
//#include "PSQuit.h"
#include "PSVersionCheck.h"

GFX_IMPLEMENT_RUNTIMECLASS_EXISTING(CPSOuterInterface, 0x00EED954);

#define MSGBOX_WIDTH 300
#define MSGBOX_HEIGHT 144

void CPSOuterInterface::OnTimer(int a1)
{
	reinterpret_cast<void(__thiscall*)(CPSOuterInterface*,int)>(0x00860C60)(this, a1);
}

void CPSOuterInterface::Func_40()
{
#if 1
	reinterpret_cast<void(__thiscall*)(CPSOuterInterface*)>(0x00862450)(this);
#else
	RECT rect;
	rect.left = GetClientDimensionStuff()[2].left / 2 - MSGBOX_WIDTH / 2;
	rect.top = GetClientDimensionStuff()[2].top / 2 - MSGBOX_HEIGHT / 2;
	rect.right = MSGBOX_WIDTH;
	rect.bottom = MSGBOX_HEIGHT;

	if (!this->IsSame(GFX_RUNTIME_CLASS(CPSRestart)))
	{
		if (this->IsSame(GFX_RUNTIME_CLASS(CPSVersionCheck)))
		{
			MessageBoxW(theApp.GetHWnd(), 
				TSM_GETTEXTPTR("UIIT_MSG_MSGBOX_NETOFF"),
				L"NetError", MB_OK);

			theApp.SetNextProcess(GFX_RUNTIME_CLASS(CPSQuit));
		}
		else
		{
			CIFMessageBox *msgbox = (CIFMessageBox*)CGWnd::CreateInstance(theApp.process_current, 
				GFX_RUNTIME_CLASS(CIFMessageBox),
				&rect,
				0,
				0);

			msgbox->MakeMsgBox(MSGBOX_INIF);
			msgbox->SetHandlerMAYBE(1, 0);
		}
	}
#endif
}

void CPSOuterInterface::Handle_0xFFC(CMsgStreamBuffer* p_msg)
{
	reinterpret_cast<void(__thiscall*)(CPSOuterInterface*,CMsgStreamBuffer*)>(0x008611D0)(this, p_msg);
}

void CPSOuterInterface::OnUpdate()
{
	reinterpret_cast<void(__thiscall*)(CPSOuterInterface*)>(0x00860CC0)(this);
}

void CPSOuterInterface::RenderMyself()
{
	reinterpret_cast<void(__thiscall*)(CPSOuterInterface*)>(0x00860ED0)(this);
}
