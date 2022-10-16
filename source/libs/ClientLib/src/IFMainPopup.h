#pragma once

#include "IFAction.h"
#include "IFApprenticeShip.h"
#include "IFCloseButton.h"
#include "IFDragableArea.h"
#include "IFEquipment.h"
#include "IFFrame.h"
#include "IFInventory.h"
#include "IFParty.h"
#include "IFPlayerInfo.h"
#include "IFQuest.h"
#include "IFSkill.h"
#include "IFStatic.h"

class CIFMainPopup : public CIFMainFrame {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFMainPopup, 0x117B39C)
public:
    CIFInventory *m_inventoryWindow; //0x07BC
    CIFEquipment *m_equipmentWindow; //0x07C0
    CIFSkill *m_skillWindow; //0x07C4
    CIFAction *m_actionWindow; //0x07C8
#ifndef party
    CIFParty *m_partyWindow; //0x07CC
#endif
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
};