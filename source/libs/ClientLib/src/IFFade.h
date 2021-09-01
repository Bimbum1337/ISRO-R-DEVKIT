#pragma once

#include "IFWnd.h"
#include <d3d9.h>

class CIFFade : public CIFWnd
{
public:
    void SetColor(D3DCOLOR color);

private:
	D3DCOLOR m_color; //0x036C


    BEGIN_FIXTURE()
        ENSURE_SIZE(0x370)
        ENSURE_OFFSET(m_color, 0x36C)
    END_FIXTURE()

    RUN_FIXTURE(CIFFade)
}; //Size=0x0370