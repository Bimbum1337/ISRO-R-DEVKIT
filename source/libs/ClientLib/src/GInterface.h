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
#include "NIFCommunityWnd.h"
#include "unsorted.h"
#include "IFSystemMessage.h"

#define GDR_CHAT_BOARD 1
#define GDR_STORAGEROOM 19
#define GDR_NOTICE 20
#define GDR_MAINPOPUP 25
#define GDR_EXCHANGE 26
#define GDR_NPCWINDOW 30
#define GDR_WARNING_WND 35
#define GDR_UPDATE_QUEST_INFO 42
#define GDR_SYSTEM_MESSAGE_VIEW 68
#define GDR_GUILDSTORAGEROOM 145

#define g_pCGInterface (*(CGInterface**)0x0110F80C)

enum eLogType : int {
    SYSLOG_NONE = 0,
    SYSLOG_ERR = 4,
    SYSLOG_GUIDE = 6
};

struct SChatMetaData {

    SChatMetaData() {
        chatIndex = -1;
        chatType = 0;
        strRecipient = L"";
        strMessage = L"";
    }

    char chatIndex;
    char chatType;
    // Name of the receiving character, in case of PM, string is empty otherwise.
    std::n_wstring strRecipient;
    // Always the message
    std::n_wstring strMessage;
};

class CGInterface : public CIFWnd {

public:
    // int OnKeyDown(int keycode, int a3, char a4);

    // void ToggleHudVisibility();

    bool OnCreateIMPL(long ln);

    void BeforeOnCreate();

    void AfterOnCreate();


    /// \brief Show a message in the warning area (green)
    ///
    /// \details Show a message in the green area in the center of the client.
    /// The message fades out after a certain amount of time.
    ///
    /// \address 0077b580
    ///
    /// \param msg The message to be displayed
    ///
    /// Example:
    /// \code
    /// g_pCGInterface->ShowMessage_Warning(L"Hello World");
    /// \endcode
    void ShowMessage_Warning(const std::n_wstring &msg);

    /// \brief Show a message in the notice area (red)
    ///
    /// \details Show a message in the red area in the center of the client.
    /// The message fades out after a certain amount of time.
    ///
    /// \address 00777bf0
    ///
    /// \param msg The message to be displayed
    ///
    /// Example:
    /// \code
    /// g_pCGInterface->ShowMessage_Notice(L"Hello World");
    /// \endcode
    void ShowMessage_Notice(const std::n_wstring &msg);

    /// \brief Show a message in the quest area (blue)
    ///
    /// \details Show a message in the blue area in the center of the client.
    /// The message fades out after a certain amount of time.
    ///
    /// \address 0077b5b0
    ///
    /// \param msg The message to be displayed
    ///
    /// Example:
    /// \code
    /// g_pCGInterface->ShowMessage_Quest(L"Hello World");
    /// \endcode
    void ShowMessage_Quest(const std::n_wstring &msg);

    /// \address 007781B0
    void WriteSystemMessage(eLogType level, const wchar_t *str);

    /// \brief Send given message as global by using item at given slot
    /// \address 007901c0
    /// \todo Make message parameter a const reference once caller is under our control
    void WriteGlobalMessage(unsigned char nSlot, std::n_wstring message);

    void CreateFlorian0Event();

    CAlramGuideMgrWnd *GetAlarmManager();

    /// \address 0079D5B0
    void ToggleActionWnd();

    /// \address 0079B0B0
    void ToggleApprenticeshipWnd();

    /// \address 0079ACE0
    void TogglePlayerInfoWnd();

    /// \address 0079F690
    void RenderToggle_GDR_GAMEGUIDE();

    /// \address 0079B020
    void ToggleInventoryWnd();

    /// \address 0079ad70
    void ToggleEquipmentWnd();

    /// \address 0079AE90
    void TogglePartyWnd();

    /// \address 0079AE00
    void ToggleSkillWnd();

    /// \address 0079af20
    void ShowInventoryWnd();

    /// \address 0079af70
    void ShowApprenticeshipWnd();

    /// \address 0079afd0
    void ToggleMainPopup();

    /// \address 0079ABE0
    void RenderToggle_WORLDMAP_GUIDE();

    /// \address 0079C750
    void Render_GDR_AUTO_POTION(bool visible);

    /// \address 00778B70
    int Get_SelectedObjectId();

    /// \address 00777A30
    CIFTimerWnd *Get_TimerWindow();

    /// \address 00777A50
    CIFQuickStateHalfWnd *Get_QuickStateHalfWnd();

    /// \address 00798D40
    CIF_NPCWindow *Get_GDR_NPCWINDOW();

    /// \address 00798D00
    CIFMainPopup *GetMainPopup();

    /// \address 007994C0
    CIFStorageRoom *Get_GDR_STORAGEROOM();

    /// \address 00799640
    CIFStorageRoom *Get_GDR_GUILDSTORAGEROOM();

    /// \address 007990e0
    void ToggleQuestNew();

    /// \address 007994f0
    CNIFCommunityWnd *GetCommunityWnd();

    CIFSystemMessage *GetSystemMessageView();

    /// \address 00777c30
    void FUN_00777c30(ChatType type, const wchar_t *message, D3DCOLOR color, int a5);

    /// \address 00778a10
    void FUN_00778a10(int a2, const wchar_t *message, D3DCOLOR color);

    /// \address 00777cf0
    void FUN_00777cf0(const std::n_wstring &recipient);

    /// \address 00778190
    void WriteErrorMessage(byte errorType, unsigned __int16 errorCode, int colorARGB, int a5, int a6);

    /// \address 0078BEA0
    int TryParseChatCommands(const wchar_t *text, RECT &r, std::vector<void *> &v);

    /// \address 00787C10
    void sub_787C10(SChatMetaData &meta);


private:
    /// \address 0079a7e0
    void FUN_0079a7e0(CGWndBase *pGWnd) const;

private:
public:
    CIRMManager m_IRM; //0x036C
    char pad_0x039C[0xC]; //0x039C
    CIFSupporterChatWnd *m_academyChatWindow; //0x03A8
    CIFTimerWnd *m_timerWindow; //0x03AC
    CIFQuickStateWnd *N00002636; //0x03B0
    CIFQuickStateHalfWnd *N00002637; //0x03B4
    char pad_0x03B8[0xC]; //0x03B8
private:
    int last_mouse_x; //0x03C4 3C4
    int last_mouse_y; //0x03C8
    char pad_03CC[1]; //0x03CC
    char b_blockWASD; //0x03CD
    char b_freeCameraMode; //0x03CE
    char pad_03CF[45]; //0x03CF
    class CCameraWorking *m_pCameraWorking; //0x03FC
    class CIFCameraDataWnd *m_pCameraDataWnd; //0x0400
    class CIFCameraDataMainWnd *m_pCameraDataMainWnd; //0x0404
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
    class CAutoPotion *m_pCAutoPotion; //0x06FC
    char pad_0x0700[0x20]; //0x0700
    CIFFade *m_screenCover; //0x0720
    CIF_NPCWindow *m_npcWindow; //0x0724
    CIFMainPopup *m_mainPopup; //0x0728
    CIFSkillPracticeBox *m_skillUpWindow; //0x072C
    CIFHelperBubbleWindow *m_helperWindow; //0x0730
    CIFHelperBubbleWindow *N00002717; //0x0734
    char pad_0x0738[0x10]; //0x0738
    CMessageBoxManager m_messageBoxManager; //0x0748
    class CMessageTipManager *m_pCMessageTipManager; //0x0774 774
    class CSkillCoolTimeManager *m_pCSkillCoolTimeManager; //0x0778
    class CItemReuseDelayManager *m_pCItemReuseDelayManager; //0x077C
    class CSkillRunTimeManager *m_pCSkillRunTimeManager; //0x0780
    char pad_0784[0x48]; //0x0784
    char pad_07cc[1]; // 0x7cc
public:
    undefined1 field_0x7cd;
private:
    char pad_07d0[0x24];

    class CPreUseItem *m_pCPreUseItem; //0x07F4
    char pad_07F8[92]; //0x07F8


    BEGIN_FIXTURE()
        ENSURE_SIZE(0x854)
        ENSURE_OFFSET(m_pCSkillRunTimeManager, 0x780)
        ENSURE_OFFSET(field_0x7cd, 0x7cd)
        ENSURE_OFFSET(m_pCPreUseItem, 0x7f4)
    END_FIXTURE()

    RUN_FIXTURE(CGInterface)
};
