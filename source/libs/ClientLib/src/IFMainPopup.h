#pragma once

#include "IFMainFrame.h"
#include "IFInventory.h"
#include "IFEquipment.h"
#include "IFSkill.h"
#include "IFAction.h"
#include "IFParty.h"
#include "IFPlayerInfo.h"
#include "IFQuest.h"
#include "IFApprenticeShip.h"
#include "IFButton.h"
#include "IFStatic.h"

#define GDR_APPRENTICESHIP 77
#define GDR_PLAYERINFO 75
#define GDR_ACTION 74
#define GDR_SKILL 73
#define GDR_PARTY 72
#define GDR_EQUIPMENT 71
#define GDR_INVENTORY 70

class CIFMainPopup : public CIFMainFrame {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFMainPopup, 0x00eea6dc)
    GFX_DECLARE_MESSAGE_MAP(CIFMainPopup)
public:
    GFX_DECLARE_DYNCREATE_FN(CIFMainPopup)

public:

    CIFMainPopup();

    bool OnCreate(long ln) override;

    /// \address 006a1c50
    void OnUpdate() override;

    /// \address 006a1c60
    void RenderMyself() override;

    /// \address 006a2390
    void ShowGWnd(bool bVisible) override;

    /// \address 006a1d20
    CIFInventory *GetInventory() const;

    /// \address 006a1d80
    CIFSkill *GetSkill() const;

    /// \address 006a1db0
    CIFAction *GetAction() const;

    /// \address 006a1de0
    CIFParty *GetParty() const;

    /// \address 06a1e10
    CIFPlayerInfo *GetPlayerInfo() const;

    /// \address 006a1e40
    CIFQuest *GetQuest() const;

    /// \address 006a1e70
    CIFApprenticeShip *GetApprenticeShip() const;

    /// \address 006a1d50
    CIFEquipment *GetEquipment() const;

    /// \address 006a1cf0
    bool IsSubPageActive(int page);

    /// \address 006a1c70
    void HideAll();

    /// \address 006a1f70
    void ShowSubPage(int page);

private:

    /// \address 006a24f0
    void OnClick_BtnChar();

    /// \address 006a2500
    void OnClick_BtnInv();

    /// \address 006a2510
    void OnClick_BtnSkill();

    /// \address 006a2520
    void OnClick_BtnAct();

    /// \address 006a2530
    void OnClick_BtnParty();

    /// \address 006a2540
    void OnClick_BtnQuest();

    /// \address 006a2550
    void OnClick_BtnApprentice();

private:
    CIFInventory *m_inventoryWindow; //0x07BC
    CIFEquipment *m_equipmentWindow; //0x07C0
    CIFSkill *m_skillWindow; //0x07C4
    CIFAction *m_actionWindow; //0x07C8
    CIFParty *m_partyWindow; //0x07CC
    CIFPlayerInfo *m_playerInfoWindow; //0x07D0
    CIFQuest *m_questWindow; //0x07D4
    CIFApprenticeShip *m_apprenticeShipWindow; //0x07D8

    CIFButton *m_btnInventory; //0x07DC
    CIFButton *m_btnSkill; //0x07E0
    CIFButton *m_btnAction; //0x07E4
    CIFButton *m_btnParty; //0x07E8
    CIFButton *m_btnCharacter; //0x07EC
    CIFButton *m_btnQuest; //0x07F0
    CIFButton *m_btnApprentice; //0x07F4
    CIFStatic *m_background; //0x07F8
    undefined4 field_0x7fc; //0x07FC


BEGIN_FIXTURE()
        ENSURE_SIZE(0x800)

        ENSURE_OFFSET(m_inventoryWindow, 0x07BC)
        ENSURE_OFFSET(m_equipmentWindow, 0x07C0)
        ENSURE_OFFSET(m_skillWindow, 0x07C4)
        ENSURE_OFFSET(m_actionWindow, 0x07C8)
        ENSURE_OFFSET(m_partyWindow, 0x07CC)
        ENSURE_OFFSET(m_playerInfoWindow, 0x07D0)
        ENSURE_OFFSET(m_questWindow, 0x07D4)
        ENSURE_OFFSET(m_apprenticeShipWindow, 0x07D8)
        ENSURE_OFFSET(m_btnInventory, 0x07DC)
        ENSURE_OFFSET(m_btnSkill, 0x07E0)
        ENSURE_OFFSET(m_btnAction, 0x07E4)
        ENSURE_OFFSET(m_btnParty, 0x07E8)
        ENSURE_OFFSET(m_btnCharacter, 0x07EC)
        ENSURE_OFFSET(m_btnQuest, 0x07F0)
        ENSURE_OFFSET(m_btnApprentice, 0x07F4)
        ENSURE_OFFSET(m_background, 0x07F8)
        ENSURE_OFFSET(field_0x7fc, 0x07FC)
    END_FIXTURE()

    RUN_FIXTURE(CIFMainPopup)
};
