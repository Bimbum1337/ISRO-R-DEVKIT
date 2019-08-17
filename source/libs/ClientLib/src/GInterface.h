#pragma once

#include "IFWnd.h"
#include "IFSupporterChatWnd.h"
#include "IFTimerWnd.h"
#include "IFQuickStateWnd.h"
#include "IFQuickStateHalfWnd.h"
#include "NavigationDeadreckon.h"
#include "AlramGuideMgrWnd.h"

#include "IFFade.h"
#include "IFNPCWindow.h"
#include "IFMainPopup.h"
#include "IFSkillPracticeBox.h"
#include "IFHelperBubbleWindow.h"
#include "MessageBoxManager.h"

#define GDR_STORAGEROOM 19
#define GDR_NOTICE 20
#define GDR_MAINPOPUP 25
#define GDR_EXCHANGE 26
#define GDR_NPCWINDOW 30
#define GDR_WARNING_WND 35
#define GDR_UPDATE_QUEST_INFO 42
#define GDR_SYSTEM_MESSAGE_VIEW 68
#define GDR_GUILDSTORAGEROOM 145

enum eLogType : int
{
	NONE = 0,
	GUIDE = 6
};

class CGInterface : public CIFWnd {

public:
	// int OnKeyDown(int keycode, int a3, char a4);

	// void ToggleHudVisibility();

	bool OnCreateIMPL(long ln);

	void BeforeOnCreate();
    void AfterOnCreate();

	// void ShowMessage_Warning(std::wstring &msg);
	// void ShowMessage_Notice(std::wstring &msg);
	// void ShowMessage_Quest(std::wstring &msg);
	// void PrintSystemMessage(eLogType level, wchar_t *str);

    void CreateFlorian0Event();

	CAlramGuideMgrWnd *GetAlarmManager();

	//0x0079D5B0
	void RenderToggle_GDR_ACTION();

	//0x0079B0B0
	void RenderToggle_GDR_APPRENTICESHIP();

	//0x0079ACE0
	void RenderToggle_GDR_PLAYERINFO();

	//0x0079F690
	void RenderToggle_GDR_GAMEGUIDE();

	//0x0079B020
	void RenderToggle_GDR_INVENTORY();

	//0x0079AE90
	void RenderToggle_GDR_PARTY();

	//0x0079AE00
	void RenderToggle_GDR_SKILL();

	//0x0079ABE0
	void RenderToggle_WORLDMAP_GUIDE();

	//0x0079C750
	void Render_GDR_AUTO_POTION(bool visible);

	//0x00778B70
	int Get_SelectedObjectId();

	//0x00777A30
	CIFTimerWnd* Get_TimerWindow();

	//0x00777A50
	CIFQuickStateHalfWnd* Get_QuickStateHalfWnd();

	//0x00798D40
	CIF_NPCWindow* Get_GDR_NPCWINDOW();

	//0x00798D00
	CIFMainPopup* Get_GDR_MAINPOPUP();

	//0x007994C0
	CIFStorageRoom* Get_GDR_STORAGEROOM();

	//0x00799640
	CIFStorageRoom* Get_GDR_GUILDSTORAGEROOM();

	//0x00778190
	void WriteErrorMessage(byte errorType, unsigned __int16 errorCode, int colorARGB, int a5, int a6);

private:
public:
	CIRMManager m_IRM2; //0x036C
	char pad_0x039C[0xC]; //0x039C
	CIFSupporterChatWnd* m_academyChatWindow; //0x03A8 
	CIFTimerWnd* m_timerWindow; //0x03AC 
	CIFQuickStateWnd* N00002636; //0x03B0 
	CIFQuickStateHalfWnd* N00002637; //0x03B4 
	char pad_0x03B8[0xC]; //0x03B8
private:
	int last_mouse_x; //0x03C4 3C4
	int last_mouse_y; //0x03C8
	char pad_03CC[1]; //0x03CC
	char b_blockWASD; //0x03CD
	char b_freeCameraMode; //0x03CE
	char pad_03CF[45]; //0x03CF
	class CCameraWorking* m_pCameraWorking; //0x03FC
	class CIFCameraDataWnd* m_pCameraDataWnd; //0x0400
	class CIFCameraDataMainWnd* m_pCameraDataMainWnd; //0x0404
	char pad_0x0408[0xA4]; //0x0408
	DWORD N00002675; //0x04AC 
	DWORD N00002676; //0x04B0 
	DWORD N00006601; //0x04B4 
	char pad_0x04B8[0x4C]; //0x04B8
	DWORD N0000268B; //0x0504 
	char pad_0x0508[0x120]; //0x0508
	int m_selectedObjectId; //0x0628 
	char pad_0x062C[0x80]; //0x062C
public:
	CNavigationDeadreckon m_Nav; //0x06AC
private:
	class CAutoPotion* m_pCAutoPotion; //0x06FC
	char pad_0x0700[0x20]; //0x0700
	CIFFade* m_screenCover; //0x0720 
	CIF_NPCWindow* m_npcWindow; //0x0724 
	CIFMainPopup* m_mainPopup; //0x0728 
	CIFSkillPracticeBox* m_skillUpWindow; //0x072C 
	CIFHelperBubbleWindow* m_helperWindow; //0x0730 
	CIFHelperBubbleWindow* N00002717; //0x0734 
	char pad_0x0738[0x10]; //0x0738
	CMessageBoxManager m_messageBoxManager; //0x0748 
	class CMessageTipManager* m_pCMessageTipManager; //0x0774 774
	class CSkillCoolTimeManager* m_pCSkillCoolTimeManager; //0x0778
	class CItemReuseDelayManager* m_pCItemReuseDelayManager; //0x077C
	class CSkillRunTimeManager* m_pCSkillRunTimeManager; //0x0780
	char pad_0784[112]; //0x0784
	class CPreUseItem* m_pCPreUseItem; //0x07F4
	char pad_07F8[92]; //0x07F8
};

#define g_pCGInterface (*(CGInterface**)0x0110F80C)
