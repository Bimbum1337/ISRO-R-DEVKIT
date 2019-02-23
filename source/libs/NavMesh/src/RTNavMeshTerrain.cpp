#include "RTNavMeshTerrain.h"

int CRTNavMeshTerrain::FindHeight(D3DVECTOR& vPos)
{
	return reinterpret_cast<int (__thiscall*)(CRTNavMeshTerrain*,D3DVECTOR*)>(0x004051B0)(this, &vPos);
}
