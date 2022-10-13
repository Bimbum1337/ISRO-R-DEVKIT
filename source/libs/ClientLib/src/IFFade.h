#pragma once

#include "IFWnd.h"
#include <d3d9.h>

class CIFFade : public CIFWnd
{
public:
    void SetColor(D3DCOLOR color);

private:
	D3DCOLOR m_color; //0x0374

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x378)
        ENSURE_OFFSET(m_color, 0x374)
    END_FIXTURE()

    RUN_FIXTURE(CIFFade)
}; //Size=0x0370