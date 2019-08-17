#pragma once

#include "IFScrollBar.h"
#include "IFButton.h"

class CIFVerticalScroll : public CIFScrollBar
{
public:
	CIFButton* m_arrowUpButton; //0x03AC 
	CIFButton* m_arrowDownButton; //0x03B0 
	CIFButton* m_scrollButton; //0x03B4 
	char pad_0x03B8[0x4]; //0x03B8

}; //Size=0x03BC