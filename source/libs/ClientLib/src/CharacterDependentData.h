#pragma once

#include <ghidra/undefined.h>

#define g_CCharacterDependentData (*reinterpret_cast<CCharacterDependentData*>(0x00eeebd8))

class CCharacterDependentData {
public:
    struct SubData {

        undefined1 FUN_00986f40() const;

    private:
        char pad[8];
        undefined1 field_c;
    };
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
    SubData *FUN_00986f50();


private:

    char pad[0x20];
    SubData data;

};
