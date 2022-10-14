#pragma once
#include "IFStatic.h"

class CIFGauge : public CIFStatic
{
    GFX_DECLARE_DYNAMIC_EXISTING(CIFGauge, 0x11797B0)

public:
	float m_valueFg; //0x0394
	float m_valueBg; //0x0398
    char pad_0x0388[0x4]; //0x039C
    float field_0x38c; // 0x03A0
	char pad_0x0390[0x28]; //0x03A4
private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x3CC)
        ENSURE_OFFSET(m_valueFg, 0x0394)
        ENSURE_OFFSET(m_valueBg, 0x0398)
        ENSURE_OFFSET(field_0x38c, 0x03A0)
        END_FIXTURE()

    RUN_FIXTURE(CIFGauge)

}; //Size=0x03C4