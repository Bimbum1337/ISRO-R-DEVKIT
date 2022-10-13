#include "IFInventory.h"

CSOItem *CIFInventory::GetItemBySlot(int slotId) {
    return reinterpret_cast<CSOItem *(__thiscall *)(CIFInventory *, int)>(0x7944D0)(this, slotId);
}
