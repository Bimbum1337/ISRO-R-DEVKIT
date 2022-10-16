#pragma once

#include "IFWnd.h"

class CIFEquipment : public CIFWnd
{
public:
    bool OnCreateIMPL(long ln);
    void OnUpdateIMPL();
public:
	char pad_0x036C[0x2354]; //0x036C
    bool isSortRequested;
}; //Size=0x26C0