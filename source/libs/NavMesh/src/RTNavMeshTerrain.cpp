#include "RTNavMeshTerrain.h"

int CRTNavMeshTerrain::FindHeight(const D3DVECTOR& vPos) const
{
	return reinterpret_cast<int (__thiscall*)(const CRTNavMeshTerrain*,const D3DVECTOR*)>(0x004051B0)(this, &vPos);
}

short CRTNavMeshTerrain::GetTileFlag(D3DVECTOR& vPos)
{
	return reinterpret_cast<short (__thiscall*)(CRTNavMeshTerrain*,D3DVECTOR*)>(0x00403940)(this, &vPos);
}