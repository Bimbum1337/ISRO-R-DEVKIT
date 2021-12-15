#pragma once
#include "IFStatic.h"

class CIFGauge : public CIFStatic
{
public:
	float m_valueFg; //0x0380
	float m_valueBg; //0x0384
    char pad_0x0388[0x4]; //0x0388
    float field_0x38c; // 0x038c
	char pad_0x0390[0x34]; //0x0390



private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x03C4)
        ENSURE_OFFSET(m_valueFg, 0x0380)
        ENSURE_OFFSET(m_valueBg, 0x0384)
        ENSURE_OFFSET(field_0x38c, 0x038c)
        END_FIXTURE()

    RUN_FIXTURE(CIFGauge)

}; //Size=0x03C4