#pragma once

#include <d3dx9.h>
#include <NavMesh/RTNavEdge.h>

D3DXVECTOR2 ToVector2(D3DXVECTOR3 &v);

D3DXVECTOR3 ToVector3(D3DXVECTOR2 &v);

D3DXVECTOR3 Flatten(D3DXVECTOR3 &v);

D3DCOLOR GetColorFromEdgeFlag(EDGE_FLAG flag);
