#pragma once

#include "IFFrame.h"
#include "IFTextBox.h"
#include "IFVerticalScroll.h"

class CIF_NPCTalk : public CIFFrame
{
public:
	CIFTextBox* m_textBox; //0x07B0 
	CIFVerticalScroll* m_verticalScroll; //0x07B4 
	char pad_0x07B8[0xB8]; //0x07B8
	float N000029F6; //0x0870 
	float N000029F7; //0x0874 
	char pad_0x0878[0x70]; //0x0878

}; //Size=0x08E8