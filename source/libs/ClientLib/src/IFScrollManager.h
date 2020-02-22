#pragma once

#include "IFFrame.h"
#include "IFVerticalScroll.h"

class CIFScrollManager : public CIFFrame
{
public:
	char pad_0x07B0[0x24]; //0x07B0
	CIFVerticalScroll* m_verticalScroll; //0x07D4 
	char pad_0x07D8[0xC]; //0x07D8

}; //Size=0x07E4