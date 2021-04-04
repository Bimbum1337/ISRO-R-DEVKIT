#include "hsl.h"
#include <cmath>

HSV::operator D3DCOLOR() const {
    float red, green, blue;

    float local_hue = hue;

    local_hue /= 60.0;

    float fractional = local_hue - std::floor(local_hue);

    float p = value * (1.0f - saturation);
    float q = value * (1.0f - saturation * fractional);
    float t = value * (1.0f - saturation * (1.0f - fractional));


    if (0.0f <= local_hue && local_hue < 1.0f) {
        red = value;
        green = t;
        blue = p;
    } else if (1.0f <= local_hue && local_hue < 2.0f) {
        red = q;
        green = value;
        blue = p;
    } else if (2.0f <= local_hue && local_hue < 3.0f) {
        red = p;
        green = value;
        blue = t;
    } else if (3.0f <= local_hue && local_hue < 4.0f) {
        red = p;
        green = q;
        blue = value;
    } else if (4.0f <= local_hue && local_hue < 5.0f) {
        red = t;
        green = p;
        blue = value;
    } else if (5.0f <= local_hue && local_hue < 6.0f) {
        red = value;
        green = p;
        blue = q;
    } else {
        red = 0.0f;
        green = 0.0f;
        blue = 0.0f;
    }

    return D3DCOLOR_RGBA(
        static_cast<int>(red * 255),
        static_cast<int>(green * 255),
        static_cast<int>(blue * 255),
        255
    );
}

HSV::HSV(float hue, float saturation, float value) :
    hue(hue), saturation(saturation), value(value) {
}
