#include "CharacterDependentData.h"

bool CCharacterDependentData::sub_988A50() const {
    return reinterpret_cast<bool (__thiscall *)(const CCharacterDependentData *)>(0x988A50)(this);
}

bool CCharacterDependentData::IsInParty() const {
    return reinterpret_cast<bool (__thiscall *)(const CCharacterDependentData *)>(0x00987070)(this);
}

bool CCharacterDependentData::IsInGuild() const {
    return reinterpret_cast<bool (__thiscall *)(const CCharacterDependentData *)>(0x009870E0)(this);
}

bool CCharacterDependentData::IsInTrainingCamp() const {
    return reinterpret_cast<bool (__thiscall *)(const CCharacterDependentData *)>(0x00987140)(this);
}