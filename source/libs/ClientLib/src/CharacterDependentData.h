#pragma once

#include <ghidra/undefined.h>
#include <Test/Test.h>
#include "PartyData.h"

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


private:

    char pad[0x20];
    SPartyData m_partyData; // 0x0020

private:
    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_partyData, 0x0020)
    END_FIXTURE()

    RUN_FIXTURE(CCharacterDependentData)
};
