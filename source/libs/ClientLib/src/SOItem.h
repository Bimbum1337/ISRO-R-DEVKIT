#pragma once

class CSOItem {
public:
    char pad_0000[0xc4]; //0x0000

    std::n_map<short, int> bluemap;

    char pad_00cc[464 - (0xc4 + 0xc)];

    BEGIN_FIXTURE()
        ENSURE_SIZE(464) // approved by CIFExchange::ctor
        ENSURE_OFFSET(bluemap, 0xc4)
    END_FIXTURE()

    RUN_FIXTURE(CSOItem)
};
