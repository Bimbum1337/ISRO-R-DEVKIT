#pragma once

#include "IFFrame.h"
#include "IFScrollManager.h"
#include "IFSlotWithHelp.h"

class CIFSkillBoard : public CIFFrame
{
public:
	char pad_0x07B0[0x14]; //0x07B0
	CIFScrollManager* m_scrollManager; //0x07C4 
	CIFSlotWithHelp* m_masteryIcon; //0x07C8 
	CIFStatic* m_masteryNameText; //0x07CC 
	CIFStatic* m_masteryLevelText; //0x07D0 
	CIFButton* m_mastetyLevelUpButton; //0x07D4 

}; //Size=0x07D8