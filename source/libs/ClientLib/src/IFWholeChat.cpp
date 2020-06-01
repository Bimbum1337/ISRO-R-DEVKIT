#include "IFWholeChat.h"
#include "GInterface.h"
#include "Game.h"
#include "IFButton.h"
#include "TextStringManager.h"
#include <remodel/MemberFunctionHook.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFWholeChat, 0x00eec7a8)
GFX_IMPLEMENT_DYNCREATE_FN(CIFWholeChat, CIFWnd)


enum {
    GDR_WHOLE_CHAT_EDITBOX_INPUT = 36,
    GDR_WHOLE_CHAT_ODDITEM = 35,
    GDR_WHOLE_CHAT_STA_ODDITEM = 34,
    GDR_WHOLE_CHAT_STA_INPUTMSG = 33,
    GDR_WHOLE_CHAT_BTN_CANCEL = 32,
    GDR_WHOLE_CHAT_BTN_OK = 31,
    GDR_WHOLE_CHAT_EDITBOX_BG = 23,
    GDR_WHOLE_CHAT_EDITBOX_BLACKSQUARE = 22,
    GDR_WHOLE_CHAT_EDITBOX_FRAME = 21,
    GDR_WHOLE_CHAT_ICON = 11,
    GDR_WHOLE_CHAT_BG = 1,
};

GFX_BEGIN_MESSAGE_MAP(CIFWholeChat, CIFWnd)
    ONG_KEYUP()
    ONG_COMMAND(GDR_WHOLE_CHAT_BTN_OK, &CIFWholeChat::SendGlobalMessage)
    ONG_COMMAND(GDR_WHOLE_CHAT_BTN_CANCEL, &CIFWholeChat::FUN_007ef490)
GFX_END_MESSAGE_MAP()


bool CIFWholeChat::OnCreate(long ln) {
    CIFFrame::OnCreate(ln);

    m_IRM.LoadFromFile("resinfo\\ifwholechat.txt");
    m_IRM.CreateInterfaceSection("Create", this);


    wnd_rect rect = GetBounds();

    wnd_rect rect2;
    rect2.pos.x = 10;
    rect2.pos.y = 12;
    rect2.size.height = 12;
    rect2.size.width = rect.size.width - 21;

    this->m_pCreatedStatic = static_cast<CIFStatic *>(CreateInstance(this, GFX_RUNTIME_CLASS(CIFStatic), rect2, 201, 0));

    RECT someRect = {0, 0, 0, 0};
    m_pCreatedStatic->SetSomeRect(someRect);
    m_pCreatedStatic->SetFont(theApp.GetFont(0));
    m_pCreatedStatic->TB_Func_5(1);
    m_pCreatedStatic->TB_Func_6(0);
    m_pCreatedStatic->SetText(TSM_GETTEXTPTR("UIIT_STT_WHOLECHAT"));

    wnd_rect rect3 = rect2;

    m_pDragableArea = static_cast<CIFDragableArea *>(CreateInstance(this, GFX_RUNTIME_CLASS(CIFDragableArea), rect3, 202, 0));

    m_pDragableArea->SetSomeRect(someRect);
    m_pDragableArea->SetFont(theApp.GetFont(0));
    m_pDragableArea->TB_Func_5(1);
    m_pDragableArea->TB_Func_6(0);

    m_pEdit = m_IRM.GetResObj<CIFEdit>(GDR_WHOLE_CHAT_EDITBOX_INPUT, 1);
    m_pEdit->AddValue_404(2);
    m_pEdit->FUN_00634f80(100);

    wnd_rect bounds = m_pEdit->GetBounds();

    m_pEdit->SetTextmode(bounds.size.width);

    m_pEdit->SetFocus_MAYBE();

    return true;
}

void CIFWholeChat::FUN_007ef400(int numberOfItemsLeft) {
    if (numberOfItemsLeft < 0) {
        CSOItem *pItem = g_pCGInterface->GetMainPopup()->GetInventory()->GetItemBySlot(m_SlotOfChattingItem);
        numberOfItemsLeft = pItem->GetQuantity();
    }

    m_NumberOfItemsLeft = numberOfItemsLeft;
    m_IRM.GetResObj<CIFButton>(0x1f, 1)->SetEnabledState(numberOfItemsLeft != 0);

    CIFStatic *sta = m_IRM.GetResObj<CIFStatic>(0x23, 1);
    sta->Func_49(sta, L"%d", numberOfItemsLeft);
}

int CIFWholeChat::OnKeyUp(UINT a1, UINT a2, UINT a3) {
    return reinterpret_cast<int(__thiscall *)(CIFWholeChat *, UINT, UINT, UINT)>(0x007ef900)(this, a1, a2, a3);
}

void CIFWholeChat::SendGlobalMessage() {
    reinterpret_cast<void(__thiscall *)(CIFWholeChat *)>(0x007ef550)(this);
}

void CIFWholeChat::FUN_007ef490() {
    reinterpret_cast<void(__thiscall *)(CIFWholeChat *)>(0x007ef490)(this);
}

void CIFWholeChat::RenderMyself() {
    reinterpret_cast<void(__thiscall *)(CIFWholeChat *)>(0x00815490)(this);
}

void CIFWholeChat::OnCloseWnd() {
    reinterpret_cast<void(__thiscall *)(CIFWholeChat *)>(0x007ef3c0)(this);
}

void CIFWholeChat::SetGWndSize(int width, int height) {
    reinterpret_cast<void(__thiscall *)(CIFWholeChat *, int, int)>(0x007ef3a0)(this, width, height);
}
