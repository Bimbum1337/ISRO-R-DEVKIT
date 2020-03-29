#pragma once

#include "IGIDObject.h"

class CICharactor : public CIGIDObject {
private:
    char pad_0254[544]; //0x0254
    CGFontTexture N00009369; //0x0474
    char pad_04DC[688]; //0x04DC
};
