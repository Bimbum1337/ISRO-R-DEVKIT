#pragma once
#include <d3d9.h>

struct HSV {

    HSV(float hue, float saturation, float value);

    /// \brief Transform this HSV color into a D3DCOLOR RGBA
    operator D3DCOLOR() const;

public:
    float hue;
    float saturation;
    float value;
};
