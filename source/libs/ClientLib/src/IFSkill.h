#pragma once

#include "IFWnd.h"
#include "IFStatic.h"
#include "IFSkillBoard.h"

class CIFSkill : public CIFWnd
{
public:
    void FUN_006a6e60(undefined4 a1);

private:
	char pad_0x036C[0x24]; //0x0374
	CIFStatic* m_skillPointValueText; //0x0398
	char pad_0x0394[0x4]; //0x039C
	CIFSkillBoard* m_skillBoard; //0x03A0
	char pad_0x039C[0x18]; //0x03A4


    BEGIN_FIXTURE()
        ENSURE_SIZE(0x3BC)
    END_FIXTURE()

    RUN_FIXTURE(CIFSkill)

};
