#pragma once

class CollisionObject;

#include <d3dx9.h>
#include "RTNavMeshObj.h"
#include "RTNavMeshTerrain.h"

class CollisionObject
{
public:
	char pad_0000[20]; //0x0000
	float yaw; //0x0014
	char pad_0018[56]; //0x0018
	D3DXVECTOR3 origin; //0x0050
	char pad_005C[84]; //0x005C
	class CRTNavMeshTerrain* m_nvm_terrain; //0x00B0
	class CRTNavMeshObj* m_nvm_obj; //0x00B4
	char pad_00B8[12]; //0x00B8
};
