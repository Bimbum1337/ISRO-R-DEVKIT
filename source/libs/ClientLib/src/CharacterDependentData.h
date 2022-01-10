#pragma once

#include "CharacterStatistics.h"
#include "PartyData.h"
#include "PartyMemberData.h"
#include <Test/Test.h>
#include <ghidra/undefined.h>

#define g_CCharacterDependentData (*reinterpret_cast<CCharacterDependentData*>(0x00eeebd8))

class CCharacterDependentData {

public:

    /// \address 00987070
    bool IsInParty() const;

    /// \address 009870E0
    bool IsInGuild() const;

    /// \address 00987140
    bool IsInTrainingCamp() const;

    /// \address 00988A50
    bool sub_988A50() const;

    /// \address 00986f50
    const SPartyData &GetPartyData() const;

    /// \address 00992400
    const SPartyMemberData &GetPartyMemberData(int memberId) const;

    /// \address 00987090
    const SCharacterStatistics &FUN_00987090() const;

    /// \address 00993120
    int FUN_00993120(const std::n_wstring &characterName) const;

    /// \address FUN_00998280
    int FUN_00998280(int guildId);

    /// \address 009870d0
    int FUN_009870d0();

    /// \address 00998230
    int FUN_00998230(int* param_1);

    /// \address 00992940
    undefined4 FUN_00992940(std::n_wstring *param_1);

private:

    char pad[0x20];
    SPartyData m_partyData; // 0x0020

private:
    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_partyData, 0x0020)
    END_FIXTURE()

    RUN_FIXTURE(CCharacterDependentData)
};
