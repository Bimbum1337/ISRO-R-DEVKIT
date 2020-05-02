#pragma once

#include "GFXMainFrame/IEntity.h"

#include <d3d9.h>

#include "GlobalHelpersThatHaveNoHomeYet.h"


class CIObject : public CIEntity {
public:
    char pad_0054[40]; //0x0054
    uregion region; //0x007C
    char pad_007E[2]; //0x007E
    D3DVECTOR location; //0x0080
    float rotation; //0x008C
    char pad_0090[76]; //0x0090
}; //Size: 0x00DC
