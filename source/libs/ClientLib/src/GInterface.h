#pragma once

#include "IFWnd.h"
#include "NavigationDeadreckon.h"

#define GDR_NOTICE 20
#define GDR_WARNING_WND 35
#define GDR_UPDATE_QUEST_INFO 42
#define GDR_SYSTEM_MESSAGE_VIEW 68

enum eLogType : int
{
	NONE = 0,
	GUIDE = 6
};

class CGInterface : public CIFWnd {

public:
	// int OnKeyDown(int keycode, int a3, char a4);

	// void ToggleHudVisibility();


	// void ShowMessage_Warning(std::wstring &msg);
	// void ShowMessage_Notice(std::wstring &msg);
	// void ShowMessage_Quest(std::wstring &msg);
	// void PrintSystemMessage(eLogType level, wchar_t *str);

	void RenderToggle_GDR_ACTION();
	void RenderToggle_GDR_APPRENTICESHIP();
	void RenderToggle_GDR_PLAYERINFO();
	void RenderToggle_GDR_GAMEGUIDE();
	void RenderToggle_GDR_INVENTORY();
	void RenderToggle_GDR_PARTY();
	void RenderToggle_GDR_SKILL();
	void RenderToggle_WORLDMAP_GUIDE();
	void Render_GDR_AUTO_POTION(bool visible);

	

private:
public:
	CIRMManager m_IRM; //0x036C
private:
	char pad_039C[40]; //0x039C
	int last_mouse_x; //0x03C4 3C4
	int last_mouse_y; //0x03C8
	char pad_03CC[1]; //0x03CC
	char b_blockWASD; //0x03CD
	char b_freeCameraMode; //0x03CE
	char pad_03CF[45]; //0x03CF
	class CCameraWorking* m_pCameraWorking; //0x03FC
	class CIFCameraDataWnd* m_pCameraDataWnd; //0x0400
	class CIFCameraDataMainWnd* m_pCameraDataMainWnd; //0x0404
	char pad_0408[676]; //0x0408
public:
	CNavigationDeadreckon m_Nav; //0x06AC
private:
	class CAutoPotion* m_pCAutoPotion; //0x06FC
	char pad_0700[116]; //0x0700
	class CMessageTipManager* m_pCMessageTipManager; //0x0774 774
	class CSkillCoolTimeManager* m_pCSkillCoolTimeManager; //0x0778
	class CItemReuseDelayManager* m_pCItemReuseDelayManager; //0x077C
	class CSkillRunTimeManager* m_pCSkillRunTimeManager; //0x0780
	char pad_0784[112]; //0x0784
	class CPreUseItem* m_pCPreUseItem; //0x07F4
	char pad_07F8[92]; //0x07F8
};

#define g_pCGInterface (*(CGInterface**)0x0110F80C)
