#include "GlobalDataManager.h"


undefined4 CGlobalDataManager::FUN_008cbac0(int a1) {
    return reinterpret_cast<undefined4 (__thiscall *)(CGlobalDataManager *, int)>(0x008cbac0)(this, a1);
}

const CCharacterData *CGlobalDataManager::GetCharacterData(int id) const {
    return reinterpret_cast<const CCharacterData *(__thiscall *) (const CGlobalDataManager *, int)>(0x0093f370)(this, id);
}
