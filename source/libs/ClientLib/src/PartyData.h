#pragma once

struct SPartyData
{
private:
    char pad_0000[16]; //0x0000
public:
    int NumberOfMembers; //0x0010

private:
    BEGIN_FIXTURE()
        ENSURE_OFFSET(NumberOfMembers, 0x0010)
    END_FIXTURE()

    RUN_FIXTURE(SPartyData)
};
