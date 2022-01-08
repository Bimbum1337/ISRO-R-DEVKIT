#include <BSLib/Debug.h>
#include "IFMainPopup.h"
#include "TextStringManager.h"
#include "GInterface.h"
#include "Game.h"

#include <remodel/MemberFunctionHook.h>

#define GDR_QUEST 76
#define GDR_BTN_APPRENTICE 16
#define GDR_BTN_QUEST 15
#define GDR_BTN_PARTY 14
#define GDR_BTN_ACT 13
#define GDR_BTN_SKILL 12
#define GDR_BTN_INV 11
#define GDR_BTN_CHAR 10
#define GDR_MAINPOPUP_LEFT_DECO_STATIC 4
#define GDR_MAINPOPUP_BG_TILE 3

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFMainPopup, 0x00eea6dc)

GFX_IMPLEMENT_DYNCREATE_FN(CIFMainPopup, CIFMainFrame)

GFX_BEGIN_MESSAGE_MAP(CIFMainPopup, CIFMainFrame)
                    ONG_COMMAND(GDR_BTN_CHAR, &CIFMainPopup::OnClick_BtnChar)
                    ONG_COMMAND(GDR_BTN_INV, &CIFMainPopup::OnClick_BtnInv)
                    ONG_COMMAND(GDR_BTN_SKILL, &CIFMainPopup::OnClick_BtnSkill)
                    ONG_COMMAND(GDR_BTN_ACT, &CIFMainPopup::OnClick_BtnAct)
                    ONG_COMMAND(GDR_BTN_PARTY, &CIFMainPopup::OnClick_BtnParty)
                    ONG_COMMAND(GDR_BTN_QUEST, &CIFMainPopup::OnClick_BtnQuest)
                    ONG_COMMAND(GDR_BTN_APPRENTICE, &CIFMainPopup::OnClick_BtnApprentice)
GFX_END_MESSAGE_MAP()

CIFMainPopup::CIFMainPopup() :
        m_inventoryWindow(NULL),
        m_equipmentWindow(NULL),
        m_skillWindow(NULL),
        m_actionWindow(NULL),
        m_partyWindow(NULL),
        m_apprenticeShipWindow(NULL),
        m_playerInfoWindow(NULL),
        m_questWindow(NULL),
        field_0x7fc(0) {
}

bool CIFMainPopup::OnCreate(long ln) {
    CIFMainFrame::OnCreate(ln);

    m_IRM.LoadFromFile("resinfo\\ifmainpopup.txt");

    m_IRM.CreateInterfaceSection("Create", this);

    m_inventoryWindow = m_IRM.GetResObj<CIFInventory>(GDR_INVENTORY, 1);
    m_equipmentWindow = m_IRM.GetResObj<CIFEquipment>(GDR_EQUIPMENT, 1);
    m_skillWindow = m_IRM.GetResObj<CIFSkill>(GDR_SKILL, 1);
    m_actionWindow = m_IRM.GetResObj<CIFAction>(GDR_ACTION, 1);
    m_partyWindow = m_IRM.GetResObj<CIFParty>(GDR_PARTY, 1);
    m_playerInfoWindow = m_IRM.GetResObj<CIFPlayerInfo>(GDR_PLAYERINFO, 1);
    m_questWindow = m_IRM.GetResObj<CIFQuest>(GDR_QUEST, 1);
    m_apprenticeShipWindow = m_IRM.GetResObj<CIFApprenticeShip>(GDR_APPRENTICESHIP, 1);

    m_btnInventory = m_IRM.GetResObj<CIFButton>(GDR_BTN_INV, 1);
    m_btnSkill = m_IRM.GetResObj<CIFButton>(GDR_BTN_SKILL, 1);
    m_btnAction = m_IRM.GetResObj<CIFButton>(GDR_BTN_ACT, 1);
    m_btnParty = m_IRM.GetResObj<CIFButton>(GDR_BTN_PARTY, 1);
    m_btnCharacter = m_IRM.GetResObj<CIFButton>(GDR_BTN_CHAR, 1);
    m_btnQuest = m_IRM.GetResObj<CIFButton>(GDR_BTN_QUEST, 1);
    m_btnApprentice = m_IRM.GetResObj<CIFButton>(GDR_BTN_APPRENTICE, 1);

    m_background = m_IRM.GetResObj<CIFStatic>(GDR_MAINPOPUP_BG_TILE, 1);

    m_btnCharacter->FUN_00655fa0(8);
    m_btnInventory->FUN_00655fa0(8);
    m_btnSkill->FUN_00655fa0(8);
    m_btnAction->FUN_00655fa0(8);
    m_btnParty->FUN_00655fa0(8);
    m_btnQuest->FUN_00655fa0(8);
    m_skillWindow->FUN_006a6e60(1);


    m_btnInventory->SetTooltipText(TSM_GETTEXT(L"UIIT_STT_TOGGLE_INVENTORY"));
    m_btnInventory->FUN_00652d20(0x80);

    m_btnCharacter->SetTooltipText(TSM_GETTEXT(L"UIIT_STT_TOGGLE_CHARACTER"));
    m_btnCharacter->FUN_00652d20(0x80);

    m_btnSkill->SetTooltipText(TSM_GETTEXT(L"UIIT_STT_TOGGLE_SKILL"));
    m_btnSkill->FUN_00652d20(0x80);

    m_btnAction->SetTooltipText(TSM_GETTEXT(L"UIIT_STT_TOGGLE_ACTION"));
    m_btnAction->FUN_00652d20(0x80);

    m_btnParty->SetTooltipText(TSM_GETTEXT(L"UIIT_STT_TOGGLE_PARTY"));
    m_btnParty->FUN_00652d20(0x80);

    m_btnQuest->SetTooltipText(TSM_GETTEXT(L"UIIT_STT_TOGGLE_QUEST"));
    m_btnQuest->FUN_00652d20(0x80);

    m_btnApprentice->SetTooltipText(TSM_GETTEXT(L"UIIT_CTL_TC_SHORTKEY_L"));
    m_btnApprentice->FUN_00652d20(0x80);


#ifndef CONFIG_OLD_MAINPOPUP
    m_btnInventory->ShowGWnd(false);
    m_btnSkill->ShowGWnd(false);
    m_btnAction->ShowGWnd(false);
    m_btnParty->ShowGWnd(false);
    m_btnCharacter->ShowGWnd(false);
    m_btnQuest->ShowGWnd(false);
    m_btnApprentice->ShowGWnd(false);

    m_IRM.GetResObj(GDR_MAINPOPUP_LEFT_DECO_STATIC, 1)->ShowGWnd(false);
#endif

    m_inventoryWindow->BringToFront();

    return true;
}

void CIFMainPopup::OnUpdate() {
    CIFWnd::OnUpdate();
}

void CIFMainPopup::HideAll() {
    m_inventoryWindow->ShowGWnd(false);
    m_equipmentWindow->ShowGWnd(false);
    m_skillWindow->ShowGWnd(false);
    m_actionWindow->ShowGWnd(false);
    m_partyWindow->ShowGWnd(false);
    m_playerInfoWindow->ShowGWnd(false);
    m_questWindow->ShowGWnd(false);
    m_apprenticeShipWindow->ShowGWnd(false);
}

void CIFMainPopup::ShowSubPage(int page) {
    HideAll();

    wnd_rect rect = GetBounds();

    const ClientResolutonData &res = CGame::GetClientDimensionStuff();

    switch (page) {
        case GDR_INVENTORY: {
            field_0x7fc = 1;
            SetText(TSM_GETTEXTPTR(L"UIIT_STT_INVENTORY"));

            m_inventoryWindow->ShowGWnd(true);
            m_equipmentWindow->ShowGWnd(true);

            m_background->ShowGWnd(true);
            m_background->MoveGWnd(rect.pos.x + 189, rect.pos.y + 68);
            m_background->SetGWndSize(9, 292);

            MoveGWnd(((res.width - GetSize().width) - 80), GetPos().y);
            BringToFront();
            break;
        }

        case GDR_PARTY: {
            field_0x7fc = 4;
            SetText(TSM_GETTEXTPTR(L"UIIT_STT_PARTY"));

            m_partyWindow->ShowGWnd(true);
            m_background->ShowGWnd(false);

            MoveGWnd(((res.width - GetSize().width) - 80), GetPos().y);
            BringToFront();
            break;
        }

        case GDR_SKILL: {
            field_0x7fc = 2;
            SetText(TSM_GETTEXTPTR(L"UIIT_STT_SKILL"));

            m_skillWindow->ShowGWnd(true);
            m_background->ShowGWnd(false);

            MoveGWnd(((res.width - GetSize().width) - 80), GetPos().y);
            BringToFront();
            break;
        }

        case GDR_ACTION: {
            field_0x7fc = 3;
            SetText(TSM_GETTEXTPTR(L"UIIT_STT_ACTION"));

            m_actionWindow->ShowGWnd(true);
            m_background->MoveGWnd(rect.pos.x + 40, rect.pos.y + 154);
            m_background->SetGWndSize(308, 124);

            MoveGWnd(((res.width - GetSize().width) - 80), GetPos().y);
            BringToFront();
            break;
        }

        case GDR_PLAYERINFO: {
            field_0x7fc = 0;
            SetText(TSM_GETTEXTPTR(L"UIIT_STT_ACTION"));

            m_playerInfoWindow->ShowGWnd(true);
            m_background->ShowGWnd(false);

            MoveGWnd(80, GetPos().y);
            BringToFront();
            break;
        }

        case GDR_QUEST: {
            field_0x7fc = 5;
            SetText(TSM_GETTEXTPTR(L"UIIT_STT_QUEST"));

            m_questWindow->ShowGWnd(true);
            m_background->ShowGWnd(false);

            MoveGWnd(80, GetPos().y);
            BringToFront();
            break;
        }

        case GDR_APPRENTICESHIP: {
            field_0x7fc = 5;
            SetText(TSM_GETTEXTPTR(L"UIIT_CTL_TC_TRAININGCAMP"));

            m_apprenticeShipWindow->ShowGWnd(true);
            m_background->ShowGWnd(true);
            m_background->ShowGWnd(false);

            MoveGWnd(80, GetPos().y);
            BringToFront();
            break;
        }
    }
}

void CIFMainPopup::OnClick_BtnChar() {
    ShowSubPage(GDR_PLAYERINFO);
}

void CIFMainPopup::OnClick_BtnInv() {
    ShowSubPage(GDR_INVENTORY);
}

void CIFMainPopup::OnClick_BtnSkill() {
    ShowSubPage(GDR_SKILL);
}

void CIFMainPopup::OnClick_BtnAct() {
    ShowSubPage(GDR_ACTION);
}

void CIFMainPopup::OnClick_BtnParty() {
    ShowSubPage(GDR_PARTY);
}

void CIFMainPopup::OnClick_BtnQuest() {
#ifdef CONFIG_OLD_MAINPOPUP
    g_pCGInterface->ToggleQuestNew();
#else
    ShowSubPage(GDR_QUEST);
#endif
}

void CIFMainPopup::OnClick_BtnApprentice() {
    ShowSubPage(GDR_APPRENTICESHIP);
}

void CIFMainPopup::RenderMyself() {
    CIFFrame::RenderMyself();
}

void CIFMainPopup::ShowGWnd(bool bVisible) {
    if (bVisible) {
        switch (this->field_0x7fc) {
            case 0:
                ShowSubPage(GDR_PLAYERINFO);
                break;
            case 1:
                ShowSubPage(GDR_INVENTORY);
                break;
            case 2:
                ShowSubPage(GDR_SKILL);
                break;
            case 3:
                ShowSubPage(GDR_ACTION);
                break;
            case 4:
                ShowSubPage(GDR_PARTY);
                break;
            case 5:
                ShowSubPage(GDR_QUEST);
                break;
            case 6:
                ShowSubPage(GDR_APPRENTICESHIP);
                break;
        }
    } else {
        m_inventoryWindow->ShowGWnd(false);
        m_equipmentWindow->ShowGWnd(false);
        m_skillWindow->ShowGWnd(false);
        m_actionWindow->ShowGWnd(false);
        m_partyWindow->ShowGWnd(false);
        m_playerInfoWindow->ShowGWnd(false);
        m_questWindow->ShowGWnd(false);
        m_apprenticeShipWindow->ShowGWnd(false);
    }

    CIFMainFrame::ShowGWnd(bVisible);
}


HOOK_ORIGINAL_MEMBER(0x006a1d20, &CIFMainPopup::GetInventory);
CIFInventory *CIFMainPopup::GetInventory() const {
    BS_ASSERT_MSG(m_inventoryWindow, "Mainpop에 세팅된 Inventory가 이상하다");
    return m_inventoryWindow;
}

HOOK_ORIGINAL_MEMBER(0x006a1d80, &CIFMainPopup::GetSkill);
CIFSkill *CIFMainPopup::GetSkill() const {
    BS_ASSERT_MSG(m_skillWindow, "Mainpop에 세팅된 Skill이 이상하다");
    return m_skillWindow;
}

HOOK_ORIGINAL_MEMBER(0x006a1db0, &CIFMainPopup::GetAction);
CIFAction *CIFMainPopup::GetAction() const {
    BS_ASSERT_MSG(m_actionWindow, "Mainpop에 세팅된 Action이 이상하다");
    return m_actionWindow;
}

HOOK_ORIGINAL_MEMBER(0x006a1de0, &CIFMainPopup::GetParty);
CIFParty *CIFMainPopup::GetParty() const {
    BS_ASSERT_MSG(m_partyWindow, "Mainpop에 세팅된 Party가 이상하다");
    return m_partyWindow;
}

HOOK_ORIGINAL_MEMBER(0x06a1e10, &CIFMainPopup::GetPlayerInfo);
CIFPlayerInfo *CIFMainPopup::GetPlayerInfo() const {
    BS_ASSERT_MSG(m_playerInfoWindow, "Mainpop에 세팅된 PlayerInfo가 이상하다");
    return m_playerInfoWindow;
}

HOOK_ORIGINAL_MEMBER(0x006a1e40, &CIFMainPopup::GetQuest);
CIFQuest *CIFMainPopup::GetQuest() const {
    BS_ASSERT_MSG(m_questWindow, "Mainpop에 세팅된 Quest가 이상하다");
    return m_questWindow;
}

HOOK_ORIGINAL_MEMBER(0x006a1e70, &CIFMainPopup::GetApprenticeShip);
CIFApprenticeShip *CIFMainPopup::GetApprenticeShip() const {
    BS_ASSERT_MSG(m_apprenticeShipWindow, "Mainpop에 세팅된 ApprenticeShip이 이상하다");
    return m_apprenticeShipWindow;
}

HOOK_ORIGINAL_MEMBER(0x006a1d50, &CIFMainPopup::GetEquipment);
CIFEquipment *CIFMainPopup::GetEquipment() const {
    BS_ASSERT_MSG(m_equipmentWindow, "Mainpop에 세팅된 Equipment가 이상하다");
    return m_equipmentWindow;
}

HOOK_ORIGINAL_MEMBER(0x006a1cf0, &CIFMainPopup::IsSubPageActive);
bool CIFMainPopup::IsSubPageActive(int page) {
    return m_IRM.GetResObj<CIFWnd>(page, 1)->IsVisible();
}
