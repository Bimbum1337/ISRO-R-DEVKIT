#include "StdAfx.h"
#include "IFChatViewer.h"
#include <BSLib/Debug.h>

#include "TextStringManager.h"
#include "Game.h"
#include "GInterface.h"
#include "ICPlayer.h"
#include "SRO_MSG_DEF.h"
#include "CharacterDependentData.h"

// CIFChatViewer_Delete                   .text 007A97D0 00000012 00000000 00000004 R . . . . . .
// CIFChatViewer_Create                   .text 007AF5C0 00000067 00000014 00000000 R . . . . . .
// CIFChatViewer::GetParentRuntimeClass() .text 007AA640 00000006                   R . . . . . .
// CIFChatViewer::GetRuntimeClass()       .text 007AA620 00000006                   R . . . . . .
GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFChatViewer, 0x00EEC168)

GFX_IMPLEMENT_DYNCREATE_FN(CIFChatViewer, CIFWnd)

#define GDR_CHAT_BG_UP 5
#define GDR_CHAT_BG_MID 6
#define GDR_CHAT_BG_DOWN 7
#define GDR_CHAT_INPUTBOX 11
#define GDR_BUTTON_CHATTABHIDE 12
#define GDR_CHAT_MODE_BG_DOWN 13
#define GDR_BUTTON_WHISPERLIST 14
#define GDR_BTN_CHAT_SIZE 15
#define GDR_LIST_CHATTING 16
#define GDR_LIST_CHATPARTY 17
#define GDR_LIST_CHATGUILD 18
#define GDR_LIST_CHATALLIACNE 19
#define GDR_STATIC_ALLLAMP 20
#define GDR_STATIC_PARTYLAMP 21
#define GDR_STATIC_GUILDLAMP 22
#define GDR_STATIC_ALLYLAMP 23
#define GDR_CHAT_VSCROLL 24

#define GDR_LIST_APPRENTICE 30
#define GDR_STATIC_APPRENTICE 31

#define GDR_CHAT_MODE_BTN 41
#define GDR_CHAT_MODE_VIEW_WND 42

#define GDR_WHISPERLIST 51
#define GDR_CHAT_STA_PENALTY 52

#define TIMER_CHATBLOCK 82

GFX_BEGIN_MESSAGE_MAP(CIFChatViewer, CIFWnd)

                    ONG_CHAR()
                    ONG_COMMAND(GDR_BUTTON_CHATTABHIDE, &CIFChatViewer::OnToggleHide)
                    ONG_COMMAND(GDR_BUTTON_WHISPERLIST, &CIFChatViewer::OnWhisperList)
                    ONG_COMMAND(GDR_BTN_CHAT_SIZE, &CIFChatViewer::OnChatTabSize)

                    ONG_COMMAND(100, &CIFChatViewer::OnUnknownStuff)

                    ONG_BSSig_u38(2, 0x806D, GDR_LIST_CHATTING, &CIFChatViewer::OnListChatThing)
                    ONG_BSSig_u38(2, 0x806D, GDR_LIST_CHATPARTY, &CIFChatViewer::OnListChatThing)
                    ONG_BSSig_u38(2, 0x806D, GDR_LIST_CHATGUILD, &CIFChatViewer::OnListChatThing)
                    ONG_BSSig_u38(2, 0x806D, GDR_LIST_CHATALLIACNE, &CIFChatViewer::OnListChatThing)
                    ONG_BSSig_u38(2, 0x806D, GDR_LIST_APPRENTICE, &CIFChatViewer::OnListChatThing)

                    ONG_COMMAND(GDR_CHAT_MODE_BTN, &CIFChatViewer::OnChatMode)

GFX_END_MESSAGE_MAP()


// CIFChatViewer::Func_4(void) .text 007A9970 00000023 00000000 00000004 R . . . . . .
int CIFChatViewer::Func_4(int a2) {
    int v1 = 0;
    while (a2 != v1 + 100) {
        if (++v1 >= 5)
            return -1;
    }

    return 100;
}

void CIFChatViewer::OnTimer(int timerId) {
    if (timerId == TIMER_CHATBLOCK) {
        wchar_t buffer[255];
        swprintf_s(buffer, TSM_GETTEXTPTR(L"UIIT_STT_CANT_CHATTING"), m_ChatBlock_SecondsLeft);

        m_ChatBlockLabel->m_FontTexture.sub_8B4400(5, 1);
        m_ChatBlockLabel->SetText(buffer);
        m_ChatBlockLabel->ShowGWnd(true);

        if (m_ChatBlock_SecondsLeft > -1) {
            m_ChatBlock_SecondsLeft--;
        } else {
            CIFWnd *wnd = m_IRM.GetResObj(52, 1);
            wnd->ShowGWnd(false);

            this->KillTimer(TIMER_CHATBLOCK);

            m_bChattingAllowed = true;

            m_InputBox->SetText(L"");

            this->sub_7A9A40();
        }
    }
}

bool CIFChatViewer::OnCreate(long ln) {
    m_IRM.LoadFromFile("resinfo\\ifchatviewer.txt");

    m_IRM.CreateInterfaceSection("Create", this);

    m_WhisperList = m_IRM.GetResObj(GDR_WHISPERLIST, 1);

    m_pTabs = new CIFSelectableArea *[numberOfTabs];

    for (int i = 0; i < numberOfTabs; i++) {

        m_numberOfLinesPerTab[i] = 1;

        RECT mrect;
        mrect.top = 5;
        mrect.left = 6;
        mrect.right = 0;
        mrect.bottom = 4;

        RECT selectable_area_size;
        selectable_area_size.top = 0;
        selectable_area_size.left = tabMarginLeft + tabWidth * i;
        selectable_area_size.right = tabWidth + 1;
        selectable_area_size.bottom = tabHeight;

        m_pTabs[i] = (CIFSelectableArea *) CGWnd::CreateInstance(this, GFX_RUNTIME_CLASS(CIFSelectableArea),
                                                                 selectable_area_size, tabFirstId + i, 0);

        m_pTabs[i]->SetSomeRect(mrect);
        m_pTabs[i]->SetFont(this->N00009C2F);

        m_pTabs[i]->sub_64CE30("interface\\chattingwnd\\chat_long_tab.ddj",
                               "interface\\chattingwnd\\chat_long_tab.ddj", "");

        if (i) {
            switch (i) {
                case 1:
                    m_pTabs[1]->SetText(TSM_GETTEXTPTR(L"UIIT_CTL_CHATMENU_PARTY"));
                    break;

                case 2:
                    m_pTabs[2]->SetText(TSM_GETTEXTPTR(L"UIIT_CTL_CHATMENU_GUILD"));
                    break;

                case 3:
                    m_pTabs[3]->SetText(TSM_GETTEXTPTR(L"UIIT_CTL_CHATMENU_ALLY"));
                    break;

                case 4:
                    m_pTabs[4]->SetText(TSM_GETTEXTPTR(L"UIIT_CTL_CHATMENU_TRAININGCAMP"));
                    break;
            }
            m_pTabs[i]->sub_64CC30(0);
        } else {
            m_pTabs[0]->SetText(TSM_GETTEXTPTR(L"UIIT_CTL_CHAT_ALL"));
            m_pTabs[i]->sub_64CC30(1);
        }
    }


    m_Button_ChatTabHide = m_IRM.GetResObj<CIFButton>(GDR_BUTTON_CHATTABHIDE, 1);
    m_Button_WhisperList = m_IRM.GetResObj<CIFButton>(GDR_BUTTON_WHISPERLIST, 1);
    m_Button_ChatSize = m_IRM.GetResObj<CIFButton>(GDR_BTN_CHAT_SIZE, 1);
    m_InputBox = m_IRM.GetResObj<CIFEdit>(GDR_CHAT_INPUTBOX, 1);
    m_Button_ChatMode = m_IRM.GetResObj(GDR_CHAT_MODE_BTN, 1);
    m_ChatModeView_Wnd = m_IRM.GetResObj<CIFChatModeViewer>(GDR_CHAT_MODE_VIEW_WND, 1);

    m_ChatModeView_Wnd->BringToFront();

    m_ChatModeView_Wnd->sub_7AA0B0(TSM_GETTEXTPTR(L"UIIT_STT_CHAT_FRIEND_INVITE"));
    m_ChatModeView_Wnd->sub_7AA0B0(TSM_GETTEXTPTR(L"UIIT_STT_CHAT_GUILD_INVITE"));
    m_ChatModeView_Wnd->sub_7AA0B0(TSM_GETTEXTPTR(L"UIIT_STT_CHAT_BLOCK"));
    m_ChatModeView_Wnd->sub_7AA0B0(TSM_GETTEXTPTR(L"UIIT_STT_CHAT_ADMISSION"));
    m_ChatModeView_Wnd->sub_7AA0B0(TSM_GETTEXTPTR(L"UIIT_STT_CHAT_WHISPER_BLOCK"));
    m_ChatModeView_Wnd->sub_7AA0B0(TSM_GETTEXTPTR(L"UIIT_STT_CHAT_WHISPER_ADMISSION"));
    m_ChatModeView_Wnd->sub_7AA0B0(TSM_GETTEXTPTR(L"UIIT_STT_CHAT_COMMAND_WHISPER1"));

    m_ChatLists[0] = m_IRM.GetResObj<CIFTextBox>(GDR_LIST_CHATTING, 1);
    m_ChatLists[1] = m_IRM.GetResObj<CIFTextBox>(GDR_LIST_CHATPARTY, 1);
    m_ChatLists[2] = m_IRM.GetResObj<CIFTextBox>(GDR_LIST_CHATGUILD, 1);
    m_ChatLists[3] = m_IRM.GetResObj<CIFTextBox>(GDR_LIST_CHATALLIACNE, 1);
    m_ChatLists[4] = m_IRM.GetResObj<CIFTextBox>(GDR_LIST_APPRENTICE, 1);

    for (int i = 0; i < 5; i++) {
        m_ChatLists[i]->N00000608 = this;

        if (i == 0) {
            m_ChatLists[i]->ShowGWnd(true);
        } else {
            m_ChatLists[i]->ShowGWnd(false);
        }

        m_ChatLists[i]->m_LinesOfHistory = 100;

        m_ChatLists[i]->m_HeightInLines = 4 * this->m_chatSize;

        m_ChatLists[i]->SetLineHeight(14);
        m_ChatLists[i]->sub_638B50(1);
        m_ChatLists[i]->sub_64E380(1);
        m_ChatLists[i]->sub_638C70(1);
        m_ChatLists[i]->SetHightlineLine(true);
        m_ChatLists[i]->sub_638D50(1);
        m_ChatLists[i]->SetHighlightColor(D3DCOLOR_RGBA(255, 255, 255, 102));
        m_ChatLists[i]->sub_638D40(1);
    }

    m_Scroll = m_IRM.GetResObj<CIFVerticalScroll>(GDR_CHAT_VSCROLL, 1);

    RECT v66;

    v66.bottom = 1;
    v66.right = 0;
    v66.left = 0;
    v66.top = 308;

    m_Scroll->sub_65A390(v66);

    m_Lamp_All = m_IRM.GetResObj(GDR_STATIC_ALLLAMP, 1);
    m_Lamp_Party = m_IRM.GetResObj(GDR_STATIC_PARTYLAMP, 1);
    m_Lamp_Guild = m_IRM.GetResObj(GDR_STATIC_GUILDLAMP, 1);
    m_Lamp_Ally = m_IRM.GetResObj(GDR_STATIC_ALLYLAMP, 1);


    m_Lamp_All->ShowGWnd(true);
    m_Lamp_Party->ShowGWnd(false);
    m_Lamp_Guild->ShowGWnd(false);
    m_Lamp_Ally->ShowGWnd(false);

    m_Lamp_All->BringToFront();
    m_Lamp_Party->BringToFront();
    m_Lamp_Guild->BringToFront();
    m_Lamp_Ally->BringToFront();

    m_Lamp_Apprentice = m_IRM.GetResObj(GDR_STATIC_APPRENTICE, 1);
    m_Lamp_Apprentice->ShowGWnd(false);
    m_Lamp_Apprentice->BringToFront();

    m_ChatLists[4]->Func_01(0);

    int x = GetPos().x + 48;
    int y = GetPos().y + 6;

    m_Lamp_All->MoveGWnd(x, y);
    m_Lamp_Party->MoveGWnd(x + 70 * 1, y);
    m_Lamp_Guild->MoveGWnd(x + 70 * 2, y);
    m_Lamp_Ally->MoveGWnd(x + 70 * 3, y);
    m_Lamp_Apprentice->MoveGWnd(x + 70 * 4, y);


    m_ChatLists[0]->Func_01(0);
    m_ChatLists[1]->Func_01(0);
    m_ChatLists[2]->Func_01(0);
    m_ChatLists[3]->Func_01(0);

    std::n_wstring str = TSM_GETTEXTPTR(L"UIIT_STT_CHATING_VIEW_AUTO_OFF");
    m_Button_ChatTabHide->SetTooltipText(&str);
    m_Button_ChatTabHide->FUN_00652d20(128);

    str = TSM_GETTEXTPTR(L"UIIT_CTL_WHISPER_LIST");
    m_Button_WhisperList->SetTooltipText(&str);
    m_Button_WhisperList->FUN_00652d20(128);

    str = TSM_GETTEXTPTR(L"UIIT_STT_TOGGLE_CHATING_WINDOW_SETING");
    m_Button_ChatSize->SetTooltipText(&str);
    m_Button_ChatSize->FUN_00652d20(128);

    ActivateTabPage(TAB_ALL);

    sub_7A9A80(0);

    m_ChatBlockLabel = m_IRM.GetResObj(GDR_CHAT_STA_PENALTY, 1);

    UpdateChatSize();


    return true;
}

void CIFChatViewer::RenderMyself() {
    CIFWnd::RenderMyself();
}

void CIFChatViewer::ShowGWnd(bool a2) {
    BS_DEBUG_LOW(">" __FUNCTION__ " (%d)", a2);
    m_Button_ChatTabHide->ShowGWnd(a2);
    CIFWnd::ShowGWnd(a2);
}

int CIFChatViewer::Func_36(int a1, short action, int a3, int a4) {
    if (action <= 0) {
        if (action < 0) {
            m_Scroll->sub_65A5C0(0);
        }
    } else {
        m_Scroll->sub_65A5A0(0);
    }

    return 1;
}

void CIFChatViewer::WriteToChatW(const wchar_t *src, int a3, int a4) {
    BS_DEBUG_LOW(">" __FUNCTION__ "(%S, %x, %x)", src, a3, a4);

    std::n_wstring str = src;
    if (m_numberOfLinesPerTab[0]++ > 250) {
        m_numberOfLinesPerTab[0] = 1;
    }

    m_ChatLists[0]->sub_64F8A0(str, 0, a3, a3, a3, 0, a4);

}

void CIFChatViewer::WriteToChatA(const char *src, int a3, int a4) {
    BS_DEBUG_LOW(">" __FUNCTION__ "(%s, %x, %x)", src, a3, a4);

    std::n_string str = src;
    if (m_numberOfLinesPerTab[0]++ > 250) {
        m_numberOfLinesPerTab[0] = 1;
    }

    m_ChatLists[0]->sub_64F660(str, 0, a3, a3, a3, 0, a4);

}

int CIFChatViewer::OnChar(UINT nChar, UINT a2, UINT a3) {
    // Print error message to system log when chatting is blocked
    if (!m_bChattingAllowed) {
        m_InputBox->SetText(L"");
        wchar_t buffer[64];
        swprintf_s(buffer, TSM_GETTEXTPTR(L"UIIT_MSG_CANT_CHATTING"));
        g_pCGInterface->WriteSystemMessage(SYSLOG_ERR, buffer);
        return 0;
    }

    // Ignore input if input box is not selected
    if (!m_InputBox->HasFocus()) {
        return 0;
    }

    // Ignore input if we don't have a player object (when does this happen???)
    if (!g_pCICPlayer) {
        return 0;
    }

    switch (nChar) {
        case VK_ESCAPE:
            // Release focus when escape is pressed
            Unfocus();
            return 1;

        case VK_TAB:
            return 1;

        case VK_RETURN: {
            std::n_wstring input_text = m_InputBox->GetText();

            // Just unfocus if we don't have any text
            if (input_text.empty()) {
                Unfocus();
                return 1;
            }

            switch (input_text[0]) {
                case '$': // Whisper
                    N00009C5E = CHAT_PM;
                    break;
                case '#':
                    N00009C5E = CHAT_Party;
                    break;
                case '@':
                    N00009C5E = CHAT_Guild;
                    break;
                case '/':
                    N00009C5E = 254;
                    break;
                case '%':
                    N00009C5E = CHAT_Union;
                    break;
                case '&':
                    N00009C5E = CHAT_Academy;
                    break;
                default:
                    if (g_pCICPlayer->IsGameMaster()) {
                        N00009C5E = CHAT_AllGM; // GM Chat

                    } else {
                        N00009C5E = CHAT_All; // All Chat
                    }

                    // Move all timings up one slot
                    for (int i = 5; i >= 0; --i) {
                        m_chatHistoryTimes[i] = m_chatHistoryTimes[i - 1];
                    }

                    // Clamp number of history values
                    if (++m_ChatHistoryCount > 6) {
                        m_ChatHistoryCount = 6;
                    }

                    // Insert current time
                    m_chatHistoryTimes[0] = g_currentTime;

                    // Block for 10 seconds if more than 4 msg / 4 seconds
                    BlockChatIf(4, 4000, 10);

                    // Block for 10 seconds if more than 6 msg / 10 seconds
                    BlockChatIf(6, 10000, 10);
            }

            const wchar_t *pMessage = input_text.c_str();

            std::vector<void *> param2;
            RECT param1;
            if (dword_EECC18 && g_pCGInterface->TryParseChatCommands(input_text.c_str(), param1, param2)) {
                m_InputBox->SetText(L"");
                return 1;
            }


            SChatMessage chatMessage;

            if (!sub_4F9C50()) {
                std::n_wstring strMessage;
                std::n_wstring strRecipient;

                if (N00009C5E == CHAT_PM) {
                    // BAD: This constructs a new n_wstring from the PTR ... LOL
                    SeparateWhisperName(chatMessage, pMessage);

                    // TODO: This was a call in the original code, maybe use that?
                    strMessage = chatMessage.strMessage;
                    strRecipient = chatMessage.strTargetName;

                    if (chatMessage.lengthOfMessage == 0) {
                        Unfocus();
                        return 1;
                    }

                } else {
                    if (N00009C5E == 254) {

                        if (sub_7ADF70(input_text.c_str())) {
                            return 1;
                        }
                        m_InputBox->SetText(L"");
                        return 1;
                    } else {
                        if (N00009C5E != CHAT_All && N00009C5E != CHAT_AllGM && N00009C5E != CHAT_Global) {
                            pMessage++;

                            if (input_text.length() == 1) {
                                Unfocus();
                                return 1;
                            }

                            if (N00009C5E == CHAT_Party && !g_CCharacterDependentData.IsInParty()) {
                                g_pCGInterface->WriteSystemMessage(
                                        SYSLOG_ERR,
                                        TSM_GETTEXTPTR(L"UIIT_MSG_PARTYERR_CANT_FIND_PARTY")
                                );

                                m_InputBox->SetText(L"");
                                return 1;
                            }

                            if (N00009C5E == CHAT_Guild && !g_CCharacterDependentData.IsInGuild()) {
                                g_pCGInterface->WriteSystemMessage(
                                        SYSLOG_ERR,
                                        TSM_GETTEXTPTR(L"UIIT_MSG_GUILD_NON_EXISTING")
                                );

                                m_InputBox->SetText(L"");
                                return 1;
                            }

                            if (N00009C5E == CHAT_Academy && !g_CCharacterDependentData.IsInTrainingCamp()) {
                                g_pCGInterface->WriteSystemMessage(
                                        SYSLOG_ERR,
                                        TSM_GETTEXTPTR(L"UIIT_MSG_TC_ERROR_NOT_POSITION")
                                );

                                m_InputBox->SetText(L"");
                                return 1;
                            }
                        }
                    }
                }

                if (strMessage.empty()) {
                    strMessage = pMessage;
                }

#ifdef CONFIG_CHATVIEWER_BADWORDFILTER
                if (CGame::GetBadwordFilter()->sub_8C4020(input_text.c_str())) {
                    WriteToChatW(TSM_GETTEXTPTR(L"UIIT_MSG_CHATWND_MESSAGE_FILTER"), D3DCOLOR_RGBA(255, 0, 0, 0), 1);
                    return 1;
                }
#endif // CONFIG_CHATVIEWER_BADWORDFILTER

                SChatMetaData metadata;

                metadata.chatType = N00009C5E;
                metadata.strRecipient = strRecipient;
                metadata.strMessage = strMessage;

                std::n_wstring chatMessageToBeSend(L"");

                if (N00009C5E == CHAT_Union && g_pCICPlayer && g_CCharacterDependentData.sub_988A50()) {
                    wchar_t buffer[256];
                    swprintf_s(buffer, L"-%s): ", g_pCICPlayer->GetGuildName().c_str());

                    chatMessageToBeSend = buffer;
                }

                chatMessageToBeSend += metadata.strMessage;
                metadata.strMessage = chatMessageToBeSend;

                g_pCGInterface->sub_787C10(metadata);

                NEWMSG(SR_CHAT_REQ)
                    pReq << metadata.chatType << metadata.chatIndex;


                    std::n_string nChatMessageToBeSend = TO_NSTRING(chatMessageToBeSend);


                    switch (N00009C5E) {
                        case CHAT_All:
                        case CHAT_AllGM:
                        case CHAT_Party:
                        case CHAT_Guild:
                        case CHAT_Global:
                        case CHAT_Union:
                        case CHAT_Academy:
                            pReq << nChatMessageToBeSend;
                            break;

                        case CHAT_PM:
                            std::n_string strRecipient;
                            strRecipient = TO_NSTRING(metadata.strRecipient);

                            pReq << strRecipient << nChatMessageToBeSend;
                            break;
                    }
                SENDMSG()

                // Recent Commands maybe?
#if 0
                if (sub_4F9C50()) {

                    this->WriteToChatW();

                    sub_7AD290(str);
                }
#endif

                if (N00009C5E == CHAT_AllGM)
                {
                    if (input_text[0] == ';') {
                        m_InputBox->SetText(L";");
                    }
                    else {
                        m_InputBox->SetText(L"");
                    }
                }
                else if (m_currentTabPage == TAB_ALL && (N00009C5E == CHAT_All || N00009C5E == CHAT_Global))
                {
                    m_InputBox->SetText(L""); //Probably should leave this use case for the Else statement...
                }
                else if (m_currentTabPage == TAB_ALL && N00009C5E == CHAT_PM)
                {
                    // Insert name of dude
                    std::n_wstring newTbText = L"$";
                    newTbText += chatMessage.strTargetName;
                    newTbText += L" ";

                    m_InputBox->SetText(newTbText.c_str());
                }
                else if (m_currentTabPage == TAB_PARTY || (N00009C5E == CHAT_Party && m_currentTabPage == TAB_ALL))
                {
                    m_InputBox->SetText(L"#");
                }
                else if (m_currentTabPage == TAB_GUILD || (N00009C5E == CHAT_Guild && m_currentTabPage == TAB_ALL))
                {
                    m_InputBox->SetText(L"@");
                }
                else if (m_currentTabPage == TAB_ALLY || (N00009C5E == CHAT_Union && m_currentTabPage == TAB_ALL))
                {
                    m_InputBox->SetText(L"%");
                }
                else if (m_currentTabPage == TAB_TRAININGCAMP || (N00009C5E == CHAT_Academy && m_currentTabPage == TAB_ALL))
                {
                    m_InputBox->SetText(L"&");
                }
                else
                {
                    m_InputBox->SetText(L"");
                }
                
            }
        }
    }

    Unfocus();

    return 0;
}

void CIFChatViewer::OnToggleHide() {
    m_bAutoHide = !m_bAutoHide;
}

void CIFChatViewer::OnWhisperList() {
    m_WhisperList->ShowGWnd(!m_WhisperList->IsVisible());
}

void CIFChatViewer::OnChatTabSize() {
    if (m_chatSize++ > 6) {
        m_chatSize = 0;
    }

    UpdateChatSize();
    sub_7A9D60();
}

void CIFChatViewer::OnUnknownStuff() {
    int id = GetIDOfInterfaceUnderCursor();
    int i = 0;

    for (int i = 0; i < numberOfTabs; ++i) {
        if (id == m_pTabs[i]->UniqueID()) {
            ActivateTabPage((eTabPage) i);
            return;
        }
    }

    SetFocusToInputBox();
}

void CIFChatViewer::OnChatMode() {
    // Toggle Chat Command Window
    m_ChatModeView_Wnd->ShowGWnd(m_ChatModeView_Wnd->IsVisible() == 0);

    return sub_7A9D60();
}

void CIFChatViewer::OnListChatThing(int a1, int a2) {
    BS_DEBUG_LOW("%s(%d, %d)", __FUNCTION__, a1, a2 );

    int id = GetIDOfInterfaceUnderCursor();
    CIFListCtrl *pList;

    if (id == m_ChatLists[0]->UniqueID()) {
        pList = m_ChatLists[0];
    } else if (id == m_ChatLists[1]->UniqueID()) {
        pList = m_ChatLists[1];

    } else if (id == m_ChatLists[2]->UniqueID()) {
        pList = m_ChatLists[2];

    } else if (id == m_ChatLists[3]->UniqueID()) {
        pList = m_ChatLists[3];

    } else if (id == m_ChatLists[4]->UniqueID()) {
        pList = m_ChatLists[4];
    } else {
        // Joymax was using this here ... why ... how ... ???
        assert(FALSE);
    }

    CIFListCtrl::SLineOfText *line = pList->sub_63A940();

    std::n_wstring str;
    line->m_font->GetText(&str);

    if (str.empty())
        return;

    // If message doesn't have a sender, ignore it
    if (str.find(':') == std::n_wstring::npos)
        return;

    // Extract senders name
    // Remark: I think the original code was overriding str instead of storing the sender
    //         in it's own variable
    std::n_wstring sender = str.substr(0, str.find(':'));

    // Check origin information (Party, Guild, Union, Training Camp)
    // Remark: This code is completely garbage
    if (sender.find('(') != std::n_wstring::npos) {

        std::n_wstring origin = sender.substr(sender.find('('), sender.length());

        if (origin.find('-') < origin.find(')')) {
            origin = origin.substr(0, origin.find('-'));
            origin += L")";
        }

        std::n_wstring tc = L"(";
        tc += TSM_GETTEXTPTR(L"UIIT_CTL_TC_TRAININGCAMP");
        tc += L")";

        std::n_wstring whisper_from = L"(";
        whisper_from += TSM_GETTEXTPTR(L"UIIT_CHATERR_WHISPER_FROM_MESSAGE");
        whisper_from += L")";

        std::n_wstring whisper_to = L"(";
        whisper_to += TSM_GETTEXTPTR(L"UIIT_CHATERR_WHISPER_TO_MESSAGE");
        whisper_to += L")";

        std::n_wstring guild = L"(";
        guild += TSM_GETTEXTPTR(L"UIIT_CTL_GUILD");
        guild += L")";

        std::n_wstring party = L"(";
        party += TSM_GETTEXTPTR(L"UIIT_CTL_PARTY");
        party += L")";

        std::n_wstring ally = L"(";
        ally += TSM_GETTEXTPTR(L"UIIT_STT_GUILD_RESPECT_ALLY");
        ally += L")";


        if ((origin == tc) ||
            (origin == whisper_from) ||
            (origin == whisper_to) ||
            (origin == guild) ||
            (origin == party) ||
            (origin == ally)) {
            sender = sender.substr(0, sender.find('('));
        }
    }

    if (sender.length() - 2 <= 10) {
        SetWhisperTarget(sender);
        SetFocusToInputBox();
    }
}

void CIFChatViewer::UpdateChatSize() {
    BS_DEBUG_LOW(">" __FUNCTION__);

    int v5; // edi@1

    int chat_base_pos_y = CGame::GetClientDimensionStuff().height - 467;
    int v3 = CGame::GetClientDimensionStuff().height;
    v5 = v3 - 68;
    N00009C61 = 4 * m_chatSize;
    if (m_chatSize) {
        m_Button_WhisperList->ShowGWnd(true);
        m_Button_ChatTabHide->ShowGWnd(true);
        int chat_pos_y = chat_base_pos_y + chatSizeUnit * (6 - m_chatSize);
        MoveGWnd(2, chat_pos_y);
        SetGWndSize(GetSize().width, v5 - chat_pos_y);

        m_Scroll->ShowGWnd(true);
        m_Scroll->sub_65A500(chatSizeUnit * m_chatSize - 28);
        m_Scroll->SetGWndSize(m_Scroll->GetBounds().size.width, chatSizeUnit * m_chatSize - 28);
        wnd_rect a2 = m_ChatLists[0]->GetBounds();

        for (int i = 0; i < numberOfTabs; ++i) {
            m_ChatLists[i]->SetGWndSize(a2.size.width, chatSizeUnit * m_chatSize + 7);
            m_ChatLists[i]->m_HeightInLines = N00009C61;
        }

        CIFWnd *pChatBgUp = m_IRM.GetResObj(GDR_CHAT_BG_UP, 1);
        pChatBgUp->ShowGWnd(true);

        CIFWnd *pChatBgMid = m_IRM.GetResObj(GDR_CHAT_BG_MID, 1);
        pChatBgMid->ShowGWnd(true);
        pChatBgMid->SetGWndSize(pChatBgMid->GetBounds().size.width, chatSizeUnit * m_chatSize + 12);

        CIFWnd *pChatBgDown = m_IRM.GetResObj(GDR_CHAT_BG_DOWN, 1);
        pChatBgDown->ShowGWnd(true);
        pChatBgDown->MoveGWnd(pChatBgDown->GetPos().x, pChatBgMid->GetBounds().bottom());

        m_Button_ChatSize->MoveGWnd(m_Button_ChatSize->GetPos().x, pChatBgDown->GetBounds().bottom() + 1);
        m_InputBox->MoveGWnd(m_InputBox->GetPos().x, m_Button_ChatSize->GetPos().y);
        m_ChatBlockLabel->MoveGWnd(m_ChatBlockLabel->GetPos().x, m_Button_ChatSize->GetPos().y + 3);
        m_Button_ChatMode->MoveGWnd(m_Button_ChatMode->GetPos().x, m_Button_ChatSize->GetPos().y);
        sub_7A9A80(0);
    } else {
        MoveGWnd(2, v5 - 21);
        SetGWndSize(GetSize().width, 21);

        m_Button_ChatSize->MoveGWnd2(GetPos());
        m_InputBox->MoveGWnd(m_InputBox->GetPos().x, GetPos().y);
        m_ChatBlockLabel->MoveGWnd(m_ChatBlockLabel->GetPos().x, GetPos().y + 3);
        m_Button_ChatMode->MoveGWnd(m_Button_ChatMode->GetPos().x, GetPos().y);
        sub_7A9A80(1);
        m_Lamp_All->ShowGWnd(false);
        m_Lamp_Party->ShowGWnd(false);
        m_Lamp_Guild->ShowGWnd(false);
        m_Lamp_Ally->ShowGWnd(false);

        for (int i = 0; i < (numberOfTabs - 1); ++i) {
            m_ChatLists[i]->ShowGWnd(false);
        }

        m_Scroll->ShowGWnd(false);
        m_Button_WhisperList->ShowGWnd(false);
        m_Button_ChatTabHide->ShowGWnd(false);
        m_WhisperList->ShowGWnd(false);

        m_IRM.GetResObj(5, 1)->ShowGWnd(false);
        m_IRM.GetResObj(6, 1)->ShowGWnd(false);
        m_IRM.GetResObj(7, 1)->ShowGWnd(false);
    }
    CIFChatViewer::ActivateTabPage(m_currentTabPage);
}

void CIFChatViewer::sub_7A9D60() {
    BS_DEBUG_LOW(">" __FUNCTION__);
    wnd_pos pos = m_IRM.GetResObj(7, 1)->GetPos();
    pos.x += 4;
    wnd_size size = m_ChatModeView_Wnd->GetSize();
    m_ChatModeView_Wnd->MoveGWnd(pos.x, -4 - size.height + pos.y);
}

CIFChatViewer::CIFChatViewer() {
    BS_DEBUG_LOW(">" __FUNCTION__);
    m_pTabs = 0;
    m_Button_ChatSize = 0;
    N00009C71 = 0;
    N00009C72 = 0;
    N00009C73 = 0;
    m_chatSize = 2;
    N00009C61 = 8;
    N00009C80 = 0;
    N00000609 = 0;


    m_ChatBlock_SecondsLeft = 10;
    m_bChattingAllowed = 1;
    m_ChatHistoryCount = 0;
    m_bAutoHide = 0;
    N00009C82 = L"";
}

CIFChatViewer::~CIFChatViewer() {
    if (m_pTabs) {
        free(m_pTabs);
        m_pTabs = 0;
    }
}

void CIFChatViewer::sub_7A9A40() {
    BS_DEBUG_LOW(">" __FUNCTION__);

    SetFocus(g_CGame->GetHWnd());
    GetParentControl()->SetFocus_MAYBE();
}

void CIFChatViewer::ActivateTabPage(eTabPage page) {

    // Hide all lamps
    m_Lamp_All->ShowGWnd(false);
    m_Lamp_Party->ShowGWnd(false);
    m_Lamp_Guild->ShowGWnd(false);
    m_Lamp_Ally->ShowGWnd(false);
    m_Lamp_Apprentice->ShowGWnd(false);

    // Hide all chatlists and unlink the scrollbar
    for (int i = 0; i < 5; i++) {
        m_ChatLists[i]->ShowGWnd(false);
        m_ChatLists[i]->LinkScrollbar(0);
    }

    m_currentTabPage = page;
    m_CurrentActiveChatlist = m_ChatLists[page];
    m_ChatLists[page]->LinkScrollbar(m_Scroll);

    m_Scroll->sub_65A5C0(999);

    for (int i = 0; i < numberOfTabs; i++) {
        if (i == page)
            continue;

        m_pTabs[i]->sub_64CC30(0);
        m_pTabs[i]->m_FontTexture.sub_8B4750(3);
    }

    std::n_wstring text = m_InputBox->GetText();

    bool v8 = false;

    if (text.length() != 0) {
        if (text.length() == 1) {
            switch (text[0]) {
                case '#':
                case '$':
                case '%':
                case '&':
                case '/':
                case '@':
                case '^':
                case '~':
                    v8 = true;
                    break;
                default:
                    break;
            }
        }
    } else {
        v8 = true;
    }

    m_pTabs[page]->sub_64CC30(1);

    switch (page) {
        case TAB_ALL:
            if (!N00009C81)
                m_Lamp_All->ShowGWnd(true);

            if (m_chatSize)
                m_ChatLists[TAB_ALL]->ShowGWnd(true);

            if (v8)
                m_InputBox->SetText(L"");

            break;
        case TAB_PARTY:
            if (!N00009C81)
                m_Lamp_Party->ShowGWnd(true);

            if (m_chatSize)
                m_ChatLists[TAB_PARTY]->ShowGWnd(true);

            if (v8)
                m_InputBox->SetText(L"#");

            break;
        case TAB_GUILD:
            if (!N00009C81)
                m_Lamp_Guild->ShowGWnd(true);

            if (m_chatSize)
                m_ChatLists[TAB_GUILD]->ShowGWnd(true);

            if (v8)
                m_InputBox->SetText(L"@");

            break;
        case TAB_ALLY:
            if (!N00009C81)
                m_Lamp_Ally->ShowGWnd(true);

            if (m_chatSize)
                m_ChatLists[TAB_ALLY]->ShowGWnd(true);

            if (v8)
                m_InputBox->SetText(L"%");

            break;
        case TAB_TRAININGCAMP:
            if (!N00009C81)
                m_Lamp_Apprentice->ShowGWnd(true);

            if (m_chatSize)
                m_ChatLists[TAB_TRAININGCAMP]->ShowGWnd(true);

            if (v8)
                m_InputBox->SetText(L"&");

            break;
    }
}

void CIFChatViewer::sub_7A9A80(int a2) {

    for (int i = 0; i < 5; i++) {
        m_pTabs[i]->ShowGWnd(a2 == 0);
    }

    m_Lamp_All->ShowGWnd(false);
    m_Lamp_Party->ShowGWnd(false);
    m_Lamp_Guild->ShowGWnd(false);
    m_Lamp_Ally->ShowGWnd(false);
    m_Lamp_Apprentice->ShowGWnd(false);

    if (a2 == false) {
        switch (m_currentTabPage) {
            case 0:
                m_Lamp_All->ShowGWnd(true);
                break;
            case 1:
                m_Lamp_Party->ShowGWnd(true);
                break;
            case 2:
                m_Lamp_Guild->ShowGWnd(true);
                break;
            case 3:
                m_Lamp_Ally->ShowGWnd(true);
                break;
            case 4:
                m_Lamp_Apprentice->ShowGWnd(true);
                break;
        }
    }

    N00009C81 = a2;
}

void CIFChatViewer::SetChatBlocked(int timeoutSeconds) {
    this->m_bChattingAllowed = false;
    this->m_ChatBlock_SecondsLeft = timeoutSeconds;
    StartTimer(TIMER_CHATBLOCK, 1000);
}

char CIFChatViewer::sub_7ADF70(const wchar_t *text) {
    return reinterpret_cast<char (__thiscall *)(CIFChatViewer *, const wchar_t *)>(0x7ADF70)(this, text);
}

void CIFChatViewer::SetFocusToInputBox() {
    m_InputBox->SetFocus_MAYBE();
}

void CIFChatViewer::SetWhisperTarget(std::n_wstring &targetName) {
    if (!g_pCICPlayer) {
        return;
    }

    std::n_wstring name;
    g_pCICPlayer->sub_9D6580(&name);

    if (name == targetName) {
        // Cannot whisper to myself
        return;
    }

    // Prepend the $ sign
    std::n_wstring textForBox = L"$";
    textForBox += targetName;
    textForBox += L" ";

    m_InputBox->SetText(textForBox.c_str());
}

void CIFChatViewer::SeparateWhisperName(CIFChatViewer::SChatMessage &whisperThing, std::n_wstring copyOfMessage) {
    // Example string passed in copyOfMessage
    // $florian0 Hello World

    // It isn't Whisper, but tried to separate name
    assert(copyOfMessage[0] == '$');

    // Get the position of the space separating the name and the message
    int pos = copyOfMessage.find_first_of(' ');

    // space character not found. Can not separate name from message
    assert(pos != std::n_wstring::npos);

    // Space can not be second character in the string
    assert(pos == 1);

    if(pos != -1)
    { 
        // Split off the name
        // We start at 1 to skip the $
        whisperThing.strTargetName = copyOfMessage.substr(1, pos - 1);
        whisperThing.lengthOfTargetName = whisperThing.strTargetName.length();

        // Split off the message
        // We start with pos+1 to skip the space
        whisperThing.strMessage = copyOfMessage.substr(pos + 1);
        whisperThing.lengthOfMessage = whisperThing.strMessage.length();
    }
    else
    {
        //There is no space, so there is no message to send
        whisperThing.strTargetName = copyOfMessage.substr(1, copyOfMessage.length());
        whisperThing.lengthOfTargetName = whisperThing.strTargetName.length();

        whisperThing.strMessage = L"";
        whisperThing.lengthOfMessage = 0;
    }
}

void CIFChatViewer::Unfocus() {
    SetFocus(theApp.GetHWnd());
    GetParentControl()->SetFocus_MAYBE();
}

void CIFChatViewer::FUN_007aca30(ChatType chatType, D3DCOLOR color, const wchar_t *message, int param4, int param5) {

    CIFTextBox *pChatList = 0;
    int index = -1;

    switch (chatType) {
        case CHAT_All:
        case CHAT_PM:
        case CHAT_AllGM:
        case CHAT_Global:
        case CHAT_Ask:
        case CHAT_NPC:
        case 255:
            // All of these types only go to the 'All Chat'-tab, so we can exit here
            break;

        case CHAT_Party:
            pChatList = this->m_ChatLists[1];
            index = 1;
            break;

        case CHAT_Guild:
            pChatList = this->m_ChatLists[2];
            index = 2;
            break;

        case CHAT_Union:
            pChatList = this->m_ChatLists[3];
        case 8: /// TODO: Figure out why this case 8 is here. It makes no sense.
            index = 3;
            break;

        case CHAT_Academy:
            pChatList = this->m_ChatLists[4];
            index = 4;
            break;

        default:
            // sorry :/
            // i don't know any other logic that would result in a code like this ...
            goto theend;
    }

    if (m_ChatLists[0] != 0) {

        std::n_wstring strmsg(message);

        if (m_numberOfLinesPerTab[0]++ > 250)
            m_numberOfLinesPerTab[0] = 1;

        int lineNumber;
        if (chatType == 0xff) {
            lineNumber = 0;
        } else {
            lineNumber = this->m_numberOfLinesPerTab[0];
        }

        m_ChatLists[0]->sub_64F8A0(strmsg, lineNumber, color, color, -1, 0, param5);
    }

    if (pChatList) {
        std::n_wstring strmsg(message);

        if (m_numberOfLinesPerTab[index]++ > 250)
            m_numberOfLinesPerTab[index] = 1;

        int lineNumber;
        if (chatType == 0xff) {
            lineNumber = 0;
        } else {
            lineNumber = this->m_numberOfLinesPerTab[index];
        }

        m_ChatLists[index]->sub_64F8A0(strmsg, lineNumber, color, color, -1, 0, param5);
    }

    theend:
    if ((((chatType == 2) || (chatType == 0xff)) || (chatType == 10)) || (chatType == 3)) {

        for (int i = 1; i < numberOfTabs; ++i) {
            if (m_numberOfLinesPerTab[i]++ > 250)
                this->m_numberOfLinesPerTab[i] = 1;
        }


        for (int i = 1; i < numberOfTabs; ++i) {
            WriteLineToChatList(
                    m_ChatLists[i],
                    message,
                    (chatType == 0xff) ? 0 : m_numberOfLinesPerTab[i],
                    color,
                    color,
                    1);
        }
    }
}

void CIFChatViewer::ShowHideControls(bool bShow) {

    m_IRM.GetResObj(GDR_BUTTON_CHATTABHIDE,1)->ShowGWnd(bShow);
    m_IRM.GetResObj(GDR_BUTTON_WHISPERLIST,1)->ShowGWnd(bShow);

    m_Button_ChatSize->ShowGWnd(bShow);
    m_InputBox->ShowGWnd(bShow);
    m_Button_ChatMode->ShowGWnd(bShow);

    if (!bShow) {
        m_WhisperList->ShowGWnd(0);
        m_ChatModeView_Wnd->ShowGWnd(0);
    }

    if (this->m_chatSize == 0) {
        m_Button_ChatTabHide->ShowGWnd(false);
        m_Button_WhisperList->ShowGWnd(false);
        m_ChatModeView_Wnd->ShowGWnd(false);
    } else {
        m_IRM.GetResObj(5, 1)->ShowGWnd(bShow);
        m_IRM.GetResObj(6, 1)->ShowGWnd(bShow);
        m_IRM.GetResObj(7, 1)->ShowGWnd(bShow);

        m_Scroll->ShowGWnd(bShow);

        sub_7A9A80(bShow == false);
    }
}

void CIFChatViewer::WriteLineToChatList(CIFTextBox *textbox, const wchar_t *message,
        int line, D3DCOLOR color1, D3DCOLOR color2, undefined4 param_6) {

    if (textbox == 0)
        return;

    std::n_wstring strmsg(message);
    textbox->sub_64F8A0(strmsg, line, color1, color2, -1, 0, param_6);
}

void inline CIFChatViewer::BlockChatIf(int msgLimit, int timeLimitMs, int timeoutSec) {
    assert(msgLimit > 0);
    if (m_ChatHistoryCount >= msgLimit) {
        if (g_currentTime - m_chatHistoryTimes[msgLimit-1] < timeLimitMs) {
            SetChatBlocked(timeoutSec);
        }
    }
}
