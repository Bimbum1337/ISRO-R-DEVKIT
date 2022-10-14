#pragma once

#include "PSOuterInterface.h"

class CPSVersionCheck : public CPSOuterInterface
{
public:
    bool OnCreate(int ln);
private:
    bool m_ready;
    char pad_010D[0x3];
};
