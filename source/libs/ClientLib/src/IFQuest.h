#pragma once

#include "IFWnd.h"
#include "IFScrollManager.h"

class CIFQuest : public CIFWnd
{
public:
	char pad_0x036C[0x24]; //0x036C
	CIFScrollManager* m_scrollManager; //0x0390 
	char pad_0x0394[0x8]; //0x0394

}; //Size=0x039C