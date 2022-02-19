#pragma once

#include "Data/ItemData.h"
#include <BSLib/BSLib.h>
#include <ghidra/undefined.h>

enum Blue : short {
    BLUE_INT = 0x0005,
    BLUE_STR = 0x000b,
    BLUE_DURABILITY = 0x0050,
    BLUE_LUCKY = 0x003d,
    BLUE_LUCKY2 = 0x003b,
    BLUE_MP = 0x0098,
    BLUE_HP = 0x008C,
    BLUE_PARRY = 0x0080,
    BLUE_REPAIR_INVALID = 0x0041,
    BLUE_STEADY = 0x0035
};

class CSOItem {
public:
    /// \address 008ba440
    const CItemData::SData *GetItemData() const;

    /// \address 008ba460
    int GetQuantity() const;

public:
    char pad_0000[0x28];//0x0000
    undefined1 field_28;//0x0028
    char pad_0029[0xB];//0x0025
    int m_refObjItemId;//0x0034
    char pad_0038[0x54]; //0x0038
    BYTE m_OptLevel; //0x008C
    char pad_008D[0xB]; //0x008D
    int m_CurrDurability; //0x0098
    int m_quantity; // 0x009c
    char pad_00A0[0x24]; //0x00A0
    std::n_map<Blue, int> bluemap;//0x00c4
    char pad_00D0[0x10]; //0x00D0
    int m_PhyAtkPwrMax; //0x00E0
    int m_PhyAtkPwrMin; //0x00E4
    int m_MagAtkPwrMax; //0x00E8
    int m_MagAtkPwrMin; //0x00EC
    int m_BlockingRateValue; //0x00F0
    int m_MaxDurability; //0x00F4
    float m_PhyDefPwrValue; //0x00F8
    int m_ParryRateValue; //0x00FC
    float m_PhyAbsorption; //0x0100
    char pad_0104[4]; //0x0104
    int m_CriticalValue; //0x0108
    float m_MagDefPwrValue; //0x010C
    float m_MagAbsorption; //0x0110
    float m_PhyReinforcementMin; //0x0114
    float m_PhyReinforcementMax; //0x0118
    float m_MagReinforcementMin; //0x011C
    float m_MagReinforcementMax; //0x0120
    float m_PhyReinforcementValue; //0x0124
    float m_MagReinforcementValue; //0x0128
    char pad_012C[4]; //0x012C
    int m_AttackRateValue; //0x0130
    char pad_0134[0x9C]; //0x0134

    BEGIN_FIXTURE()
        ENSURE_SIZE(464)// approved by CIFExchange::ctor
        ENSURE_OFFSET(field_28, 0x28)
        ENSURE_OFFSET(m_refObjItemId, 0x34)
        ENSURE_OFFSET(m_OptLevel, 0x008C)
        ENSURE_OFFSET(m_CurrDurability, 0x0098)
        ENSURE_OFFSET(m_quantity, 0x9c)
        ENSURE_OFFSET(bluemap, 0xc4)
        ENSURE_OFFSET(m_PhyAtkPwrMax, 0x00E0)
        ENSURE_OFFSET(m_PhyAtkPwrMin, 0x00E4)
        ENSURE_OFFSET(m_MagAtkPwrMax, 0x00E8)
        ENSURE_OFFSET(m_MagAtkPwrMin, 0x00EC)
        ENSURE_OFFSET(m_BlockingRateValue, 0x00F0)
        ENSURE_OFFSET(m_MaxDurability, 0x00F4)
        ENSURE_OFFSET(m_PhyDefPwrValue, 0x00F8)
        ENSURE_OFFSET(m_ParryRateValue, 0x00FC)
        ENSURE_OFFSET(m_PhyAbsorption, 0x0100)
        ENSURE_OFFSET(m_CriticalValue, 0x0108)
        ENSURE_OFFSET(m_MagDefPwrValue, 0x010C)
        ENSURE_OFFSET(m_MagAbsorption, 0x0110)
        ENSURE_OFFSET(m_PhyReinforcementMin, 0x0114)
        ENSURE_OFFSET(m_PhyReinforcementMax, 0x0118)
        ENSURE_OFFSET(m_MagReinforcementMin, 0x011C)
        ENSURE_OFFSET(m_MagReinforcementMax, 0x0120)
        ENSURE_OFFSET(m_PhyReinforcementValue, 0x0124)
        ENSURE_OFFSET(m_MagReinforcementValue, 0x0128)
        ENSURE_OFFSET(m_AttackRateValue, 0x0130)
    END_FIXTURE()

    RUN_FIXTURE(CSOItem)
};
