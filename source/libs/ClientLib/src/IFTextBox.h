#pragma once

#include "IFListCtrl.h"

class CIFTextBox : public CIFListCtrl
{
public:
	char pad_0x03CC[0x14]; //0x03CC

}; //Size=0x03E0