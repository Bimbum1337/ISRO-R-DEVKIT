#include "GlobalDataManager.h"
#include <BSLib/Debug.h>


undefined4 CGlobalDataManager::FUN_008cbac0(int a1) {
    return reinterpret_cast<undefined4(__thiscall *)(CGlobalDataManager *, int)>(0x008cbac0)(this, a1);
}

const CCharacterData *CGlobalDataManager::GetCharacterData(int id) const {
    return reinterpret_cast<const CCharacterData *(__thiscall *) (const CGlobalDataManager *, int)>(0x0093f370)(this, id);
}

const CItemData::SData &CGlobalDataManager::GetItemData(int refObjItemId) const {

    const CItemData *pItem = FUN_0093f2f0(refObjItemId);
    if (pItem == NULL) {
        BS_ASSERT_MSG(pItem != NULL, "Item: %d", pItem);
    }
    return pItem->GetData();
}

const CItemData *CGlobalDataManager::FUN_0093f2f0(int refObjItemId) const
{
    return reinterpret_cast<const CItemData*(__thiscall*)(const CGlobalDataManager *, int)>(0x0093f2f0)(this, refObjItemId);
}
