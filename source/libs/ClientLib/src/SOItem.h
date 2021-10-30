#pragma once

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
    char pad_0000[0xc4]; //0x0000

    std::n_map<Blue, int> bluemap;

    char pad_00cc[464 - (0xc4 + 0xc)];

    BEGIN_FIXTURE()
        ENSURE_SIZE(464) // approved by CIFExchange::ctor
        ENSURE_OFFSET(bluemap, 0xc4)
    END_FIXTURE()

    RUN_FIXTURE(CSOItem)
};
