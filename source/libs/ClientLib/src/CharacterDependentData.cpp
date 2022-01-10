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

const SPartyData &CCharacterDependentData::GetPartyData() const {
    return m_partyData;
}

const SPartyMemberData &CCharacterDependentData::GetPartyMemberData(int memberId) const {
    return reinterpret_cast<const SPartyMemberData &(__thiscall *) (const CCharacterDependentData *, int)>(0x00992400)(this, memberId);
}

const SCharacterStatistics &CCharacterDependentData::FUN_00987090() const {
    return reinterpret_cast<const SCharacterStatistics &(__thiscall *)(const CCharacterDependentData *)>(0x00987090)(this);
}

int CCharacterDependentData::FUN_00993120(const std::n_wstring &characterName) const {
    return reinterpret_cast<int(__thiscall *)(const CCharacterDependentData *, const std::n_wstring &)>(0x00993120)(this, characterName);
}

int CCharacterDependentData::FUN_00998280(int guildId) {
    return reinterpret_cast<int(__thiscall *)(const CCharacterDependentData *, int)>(0x00998280)(this, guildId);
}

int CCharacterDependentData::FUN_009870d0() {
    return reinterpret_cast<int(__thiscall *)(const CCharacterDependentData *)>(0x009870d0)(this);
}

int CCharacterDependentData::FUN_00998230(int* param_1) {
    return reinterpret_cast<int(__thiscall *)(const CCharacterDependentData *, int *)>(0x00998230)(this, param_1);
}

undefined4 CCharacterDependentData::FUN_00992940(std::n_wstring *param_1) {
    return reinterpret_cast<undefined4(__thiscall *)(const CCharacterDependentData *, std::n_wstring*)>(0x00992940)(this, param_1);
}
