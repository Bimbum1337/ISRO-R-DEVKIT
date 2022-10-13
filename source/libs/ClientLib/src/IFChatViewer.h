#pragma once

#include <ghidra/undefined.h>
#include "IFWnd.h"
#include "IFChatModeViewer.h"
#include "IFSelectableArea.h"
#include "IFTextBox.h"
#include "IFVerticalScroll.h"
#include "IFButton.h"
#include "IFEdit.h"
#include "unsorted.h"

#include "Test/Test.h"

#define GDR_CHATVIEWER 1

class CIFChatViewer : public CIFWnd {
GFX_DECLARE_DYNAMIC_EXISTING(CIFChatViewer, 0x117CF18)
    GFX_DECLARE_DYNCREATE_FN(CIFChatViewer)

GFX_DECLARE_MESSAGE_MAP(CIFChatViewer)

private:
    // Represents a message to be send
    struct SChatMessage {
        int lengthOfTargetName;
        int lengthOfMessage;
        std::n_wstring strTargetName;
        std::n_wstring strMessage;
    };

    /// Internal constants
    static const int numberOfTabs = 5;
    static const int tabWidth = 70;
    static const int tabHeight = 20;
    static const int tabMarginLeft = 45;
    static const int tabFirstId = 100;
    static const int chatSizeUnit = 56;

    enum eTabPage {
        TAB_ALL = 0,
        TAB_PARTY = 1,
        TAB_GUILD = 2,
        TAB_ALLY = 3,
        TAB_TRAININGCAMP = 4
    };
public:
    /// \address 007A9970
    int Func_4(int a2) override;

    /// This timer func handles the chat ban interval
    /// \address 007A9F70
    void OnTimer(int) override;

    /// Called when this control is created
    /// \address 007AB920
    bool OnCreate(long ln) override;

    /// \address 007A99A0
    void RenderMyself() override;

    /// Show or hide the control
    /// \address 007A9B60
    void ShowGWnd(bool) override;

    /// \address 007A9A00
    int Func_36(int a1, short action, int a3, int a4) override;

    /// Write text to the all-chat window
    /// \address 007AAA50
    virtual void WriteToChatW(const wchar_t *src, int a3, int a4);

    /// Write text to the all-chat window
    /// \address 007AC940
    virtual void WriteToChatA(const char *src, int a3, int a4);

    /// Handles Keyboard-Input to the chat.
    /// When return is pressed, the message is send
    /// \address 007AD400
    int OnChar(UINT, UINT, UINT);

    //
    // Control Handlers
    //

    /// Handler for toggling keeping the chat visible entirely when mouse leaves the control
    /// Usually only the messages stay visible
    /// \address 007A99B0
    void OnToggleHide();

    /// Handler for toggling visibility of the recent whispered names
    void OnWhisperList();

    /// Handler for toggling the height of the chat
    /// \address 007AC2A0
    void OnChatTabSize();

    /// \address 007AC2D0
    void OnUnknownStuff();

    /// Handler for toggling the visibility of the chat command window
    /// \address 007A9F10
    void OnChatMode();

    /// Handler for click events to the chat messages.
    /// Used for extracting the name from the message for whispering
    /// \remark I don't know what to say about this function. It's so bad. Just bad. Let's keep this hilarious piece
    ///         of code for historical reasons ;D
    /// \addres 007AC310
    void OnListChatThing(int, int);

    /// Writes a message with a type to the correct chat tab
    /// \remark This is remarkably inefficient. It constructs about 4 wstrings of the same message and deletes it
    ///         right after the first use.
    /// \address 0x007aca30
    void FUN_007aca30(ChatType chatType, D3DCOLOR color, const wchar_t *message, int param4, int param5);


    /// \brief Hide or show controls aside from the text output
    /// \param bShow true = show controls,
    ///              false = hide controls
    /// \address 007a9bd0
    /// \details This control hides or shows all controls around the text output. It is used to simplify the chat
    ///          window when the chat is not active.
    void ShowHideControls(bool bShow);

protected:
    /// \address 007AAC20
    void UpdateChatSize();

    /// \address 007A9D60
    void sub_7A9D60();

    /// \brief Updates the current selected chat tab
    /// \address 007AA690
    /// \param page Seems to be the ID of the selected tab
    void ActivateTabPage(eTabPage page);

    /// \address 007A9A80
    void sub_7A9A80(int a2);

    /// Unfocus the control
    /// When pressing enter with no message or escape in general
    /// \address 007A9A40
    void Unfocus();

public:
    /// \address 007AD2D0
    CIFChatViewer();

    /// \address 007AA530
    ~CIFChatViewer();

private:
    /// \address 007A9A40
    void sub_7A9A40();

    /// Parse the entered message into a SChatMessage structure
    /// \remark The original implementation was garbage. Sorry, I'm not going to implement that!
    /// \address 007AB230
    /// \example
    ///   SChatMessage msg;
    ///   SeparateWhisperName(msg, "$HansVanYolo Hello World!"
    ///
    ///   // msg.strTargetName, msg.strMessage and both lengths are now set accordingly
    /// \todo Remove the copy of the string when implementing this, its unnecessary
    void SeparateWhisperName(struct SChatMessage &whisperThing, std::n_wstring copyOfMessage);

    /// Block the chat from all inputs for the given amount of seconds
    /// The timeout is handled by CIFChatViewer::OnTimer
    /// \address 007a9bb0
    void SetChatBlocked(int timeoutSeconds);

    /// \address 007ADF70
    char sub_7ADF70(const wchar_t *text);

    /// Activate the InputBox
    /// Keystrokes are then registered by the InputBox
    /// \address 007A9A70
    void SetFocusToInputBox();

    /// Sets the targetName-parameter as the Whisper-target
    /// \address 007AB470
    void SetWhisperTarget(std::n_wstring &targetName);

    /// Writes a line to the given textbox
    /// \address 007aab40
    void WriteLineToChatList(CIFTextBox *textbox, const wchar_t *message, int line, D3DCOLOR color1, D3DCOLOR color2,
                             undefined4 param_6);

    /// \brief Block that if messages/interval is exceeded
    /// \param msgLimit Number of messages to limit
    /// \param timeLimitMs Time interval to check against
    /// \param timeoutSec Duration of the applied timeout in seconds
    void inline BlockChatIf(int msgLimit, int timeLimitMs, int timeoutSec);

private:
    std::list<void *> N00009C2C; //0x0374
    char pad_0378[8]; //0x0378
    std::string N00009C32[4]; //0x0380
    char m_ChatHistoryCount; //0x03F0

    int m_ChatBlock_SecondsLeft; //0x03F4
    bool m_bChattingAllowed; //0x03F8

    int m_chatHistoryTimes[7]; /* at 3FC */
    unsigned char m_numberOfLinesPerTab[5];

    eTabPage m_currentTabPage; //0x0420
    unsigned char N00009C5E;
    int m_chatSize; //0x0428 probably the mode, 428
    int N00009C61; //0x042C
    char pad_0430[20]; //0x0430
    CIFButton *m_Button_ChatTabHide; //0x0444
    CIFButton *m_Button_WhisperList; //0x0448
    CIFTextBox *m_CurrentActiveChatlist; //0x044C
    CIFTextBox *m_ChatLists[5]; //0x0450
    CIFButton *m_Button_ChatSize; //0x0464
    CIFWnd *m_ChatBlockLabel; //0x0468
    int N00009C71; //0x046C
    int N00009C72; //0x0470
    int N00009C73; //0x0474
    CIFWnd *m_Lamp_All; //0x0478
    CIFWnd *m_Lamp_Party; //0x047C
    CIFWnd *m_Lamp_Guild; //0x0480
    CIFWnd *m_Lamp_Ally; //0x0484
    CIFWnd *m_Lamp_Apprentice; //0x0488
    bool m_bAutoHide; //0x048C

    CIFWnd *m_Button_ChatMode; //0x0490
    CIFChatModeViewer *m_ChatModeView_Wnd; //0x0494
    CIFWnd *m_WhisperList; //0x0498
    CIFVerticalScroll *m_Scroll; //0x049C
    CIFEdit *m_InputBox; //0x04A0
    CIFSelectableArea **m_pTabs; //0x04A4 is a pointer, type unknown
    int N00009C80; //0x04A8
    char N00009C81; //0x04AC

    std::wstring N00009C82; //0x04B8
    char pad_todo[0x28];

public:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x4FC); // 0x4CC
        ENSURE_OFFSET(m_ChatHistoryCount, 0x03F8);
        ENSURE_OFFSET(m_ChatBlock_SecondsLeft, 0x03FC);
        ENSURE_OFFSET(m_bChattingAllowed, 0x0400);
        ENSURE_OFFSET(m_chatHistoryTimes, 0x0404);
        ENSURE_OFFSET(m_Button_ChatTabHide, 0x044C);
        ENSURE_OFFSET(m_Button_WhisperList, 0x0450);
        ENSURE_OFFSET(m_CurrentActiveChatlist, 0x0454);
        ENSURE_OFFSET(m_ChatLists, 0x0458);
        ENSURE_OFFSET(m_Button_ChatSize, 0x046C);
        ENSURE_OFFSET(m_ChatBlockLabel, 0x0470);
        ENSURE_OFFSET(m_Lamp_All, 0x0480);
        ENSURE_OFFSET(m_Lamp_Party, 0x0484);
        ENSURE_OFFSET(m_Lamp_Guild, 0x0488);
        ENSURE_OFFSET(m_Lamp_Ally, 0x048C);
        ENSURE_OFFSET(m_Lamp_Apprentice, 0x0490);
        ENSURE_OFFSET(m_Button_ChatMode, 0x0498);
        ENSURE_OFFSET(m_ChatModeView_Wnd, 0x049C);
        ENSURE_OFFSET(m_WhisperList, 0x04A0);
        ENSURE_OFFSET(m_Scroll, 0x04A4);
        ENSURE_OFFSET(m_InputBox, 0x04A8);
        ENSURE_OFFSET(m_pTabs, 0x04AC);
    END_FIXTURE()

    RUN_FIXTURE(CIFChatViewer)
};

