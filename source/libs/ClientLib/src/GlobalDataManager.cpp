#include "GlobalDataManager.h"
#include <BSLib/Debug.h>


undefined4 CGlobalDataManager::FUN_008cbac0(int a1) {
    return reinterpret_cast<undefined4(__thiscall *)(CGlobalDataManager *, int)>(0x008cbac0)(this, a1);
}

const CCharacterData::SData *CGlobalDataManager::GetCharacterData(int id) const {
    return reinterpret_cast<const CCharacterData::SData *(__thiscall *)(const CGlobalDataManager *, int)>(0x0093f370)(
            this, id);
}

const CItemData::SData &CGlobalDataManager::GetItemData(int refObjItemId) const {

    const CItemData *pItem = FUN_00A93B50(refObjItemId);
    if (pItem == NULL) {
        BS_ASSERT_MSG(pItem != NULL, "Item: %d", pItem);
    }
    return pItem->GetData();
}

const CItemData *CGlobalDataManager::FUN_00A93B50(int refObjItemId) const {
    return reinterpret_cast<const CItemData *(__thiscall *)(const CGlobalDataManager *, int)>(0x00A93B50)(this,
                                                                                                          refObjItemId);
}

const CLevelData::SData &CGlobalDataManager::GetLevelData(int level) const {
    return reinterpret_cast<const CLevelData::SData &(__thiscall *)(const CGlobalDataManager *, int)>(0x00937f20)(this,
                                                                                                                  level);
}

undefined CGlobalDataManager::FUN_00939a60(undefined4 param_1) {
    return reinterpret_cast<undefined (__thiscall *)(const CGlobalDataManager *, undefined4)>(0x00939a60)(this,
                                                                                                          param_1);
}

undefined4 CGlobalDataManager::FUN_0093a610(std::n_wstring param_1) {
    return reinterpret_cast<undefined4 (__thiscall *)(const CGlobalDataManager *, std::n_wstring)>(0x0093a610)(this, param_1);
}