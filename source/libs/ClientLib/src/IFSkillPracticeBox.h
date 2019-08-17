#pragma once

#include "IFPractice.h"
#include "IFStatic.h"
#include "IFSlotWithHelp.h"
#include "IFEdit.h"
#include "IFButton.h"

class CIFSkillPracticeBox : public CIFPractice
{
public:
	char pad_0x07C0[0x4]; //0x07C0
	CIFStatic* m_skillIconFrame; //0x07C4 
	CIFSlotWithHelp* m_skillIcon; //0x07C8 
	CIFStatic* m_skillNameValueText; //0x07CC 
	CIFStatic* m_skillLevelValueText; //0x07D0 
	CIFStatic* m_someFrame_not_visible; //0x07D4 
	CIFStatic* N00002C85; //0x07D8 
	CIFEdit* m_skillDescription; //0x07DC 
	CIFButton* m_confirmButton; //0x07E0 
	CIFButton* m_cancelButton; //0x07E4 
	CIFStatic* m_skillLevelInfoText; //0x07E8 
	CIFStatic* m_skillPointNeededLabel; //0x07EC 
	CIFStatic* m_skillPointNeededValueText; //0x07F0 

}; //Size=0x07F4