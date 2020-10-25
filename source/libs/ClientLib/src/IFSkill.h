#pragma once

#include "IFWnd.h"
#include "IFStatic.h"
#include "IFSkillBoard.h"

class CIFSkill : public CIFWnd
{
public:
    void FUN_006a6e60(undefined4 a1);

private:
	char pad_0x036C[0x24]; //0x036C
	CIFStatic* m_skillPointValueText; //0x0390 
	char pad_0x0394[0x4]; //0x0394
	CIFSkillBoard* m_skillBoard; //0x0398 
	char pad_0x039C[0x18]; //0x039C


    BEGIN_FIXTURE()
        ENSURE_SIZE(0x03B4)

    END_FIXTURE()

    RUN_FIXTURE(CIFSkill)

};
