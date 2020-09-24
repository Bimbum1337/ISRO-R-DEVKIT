#include "MathUtil.h"

D3DXVECTOR2 ToVector2(D3DXVECTOR3 &v) {
    return D3DXVECTOR2(v.x, v.z);
};

D3DXVECTOR3 ToVector3(D3DXVECTOR2 &v) {
    return D3DXVECTOR3(v.x, 0, v.y);

};

D3DXVECTOR3 Flatten(D3DXVECTOR3 &v) {
    return D3DXVECTOR3(v.x, 0, v.z);
};

D3DCOLOR GetColorFromEdgeFlag(EDGE_FLAG flag) {
    D3DCOLOR color = D3DCOLOR_ARGB(0, 0, 255, 0); // GREEN

    if (flag & EDGE_FLAG_BLOCKED)
        color = D3DCOLOR_ARGB(0, 255, 0, 0); // RED

    if (flag & EDGE_FLAG_BRIDGE)
        color = D3DCOLOR_ARGB(0, 255, 255, 0); // YELLOW

    return color;
}
