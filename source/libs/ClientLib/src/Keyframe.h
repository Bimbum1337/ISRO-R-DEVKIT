#pragma once

#include <d3d9.h>
#include <d3dx9.h>

// It is unclear if this struct ever existed in the original game.
// For now, we just use it as a helper to keep the keyframes nice and tidy.
struct Keyframe
{
    Keyframe(float x, float y, float z, float rx, float ry, float rz, float fov);

    D3DXVECTOR3 position;
    D3DXVECTOR4 rotation;
};
