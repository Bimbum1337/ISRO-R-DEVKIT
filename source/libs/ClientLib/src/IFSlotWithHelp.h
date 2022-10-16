#pragma once

#include "IFWnd.h"
#include "SOItem.h"

class CIFSlotWithHelp : public CIFWnd
{
public:
    int Type;//36C
    char pad_0x0370[0x20];//370
    CSOItem* ItemInfo;
    char pad_0x036C[0x35C-4-0x28];

}; //Size=0x06C8