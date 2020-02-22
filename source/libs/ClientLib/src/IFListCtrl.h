#pragma once

#include "IFWnd.h"
#include "IFVerticalScroll.h"

class CIFListCtrl : public CIFWnd
{
public:
	char pad_0x036C[0x4]; //0x036C
	CIFVerticalScroll* m_verticalScroll; //0x0370 
	char pad_0x0374[0x58]; //0x0374

}; //Size=0x03CC