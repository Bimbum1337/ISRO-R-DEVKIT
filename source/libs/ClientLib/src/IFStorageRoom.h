#pragma once

#include "IFMainFrame.h"
#include "IFSpinButtonCtrl.h"


class CIFStorageRoom : public CIFMainFrame
{
public:
	char pad_0x07BC[0x10]; //0x07BC
	CIFSpinButtonCtrl* N0000056D; //0x07CC 
	char pad_0x07D0[0x4]; //0x07D0
	CIFStatic* N0000056F; //0x07D4 
	CIFButton* N00000570; //0x07D8 
	char pad_0x07DC[0x2C]; //0x07DC

}; //Size=0x0808