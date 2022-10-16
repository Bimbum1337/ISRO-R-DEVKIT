#pragma once

#include "IFWnd.h"
#include "IFStoreForPackage.h"
#include "IFStorageRoom.h"
#include "SOItem.h"

class CIFInventory : public CIFWnd
{

public:
    /// \address 0006b3e50
    CSOItem* GetItemBySlot(int slotId);

public:
	CIFStoreForPackage* m_storeWindow; //0x036C 
	CIFStorageRoom* m_storageWindow; //0x0370 
	char pad_0x0374[0xC]; //0x0374
	__int32 N00000183; //0x0380 
	char pad_0x0384[0x4]; //0x0384
	CIFStatic* m_goldAmtText; //0x0388 
	char pad_0x038C[0xC]; //0x038C
	CIFButton* m_moneyDropButton; //0x0398 
    char pad_0x039C[0x14]; //0x039C
    unsigned int pSlots; // 0x03B0
    char pad_0x03B4[0x3C]; //0x03B4
};//Size=0x03F0