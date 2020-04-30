#pragma once

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
};
