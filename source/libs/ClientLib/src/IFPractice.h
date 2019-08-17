#pragma once

#include "IFFrame.h"
#include "IFStatic.h"
#include "IFDragableArea.h"

class CIFPractice : public CIFFrame
{
public:
	char pad_0x07B0[0x8]; //0x07B0
	CIFStatic* m_windowTitleText; //0x07B8 
	CIFDragableArea* N00002C6E; //0x07BC 

}; //Size=0x07C0