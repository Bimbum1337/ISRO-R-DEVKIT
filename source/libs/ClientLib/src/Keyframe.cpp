#include "Keyframe.h"

Keyframe::Keyframe(float x, float y, float z, float rx, float ry, float rz, float fov) :
        position(x, y, z), rotation(rx, ry, rz, fov){
}
