#pragma once

#include "IFMainFrame.h"
#include "IFInventory.h"
#include "IFEquipment.h"
#include "IFSKill.h"
#include "IFAction.h"
#include "IFParty.h"
#include "IFPlayerInfo.h"
#include "IFQuest.h"

class CIFMainPopup : public CIFMainFrame
{
public:
	CIFInventory* m_inventoryArea; //0x07BC 
	CIFEquipment* m_equipmentArea; //0x07C0 
	CIFSKill* m_skillsWindow; //0x07C4 
	CIFAction* m_actionWindow; //0x07C8 
	CIFParty* m_partyWindow; //0x07CC 
	CIFPlayerInfo* m_playerInfoWindow; //0x07D0 
	CIFQuest* m_questWindow; //0x07D4 
	CIFApprenticeShip* m_academyWindow; //0x07D8 
	CIFButton* m_inventoryButton; //0x07DC 
	CIFButton* m_skillsButton; //0x07E0 
	CIFButton* m_actionButton; //0x07E4 
	CIFButton* m_partyButton; //0x07E8 
	CIFButton* m_playerInfoButton; //0x07EC 
	CIFButton* m_questButton; //0x07F0 
	CIFButton* m_academyButton; //0x07F4 
	CIFStatic* m_background; //0x07F8 
	char pad_0x07FC[0x4]; //0x07FC

}; //Size=0x0800