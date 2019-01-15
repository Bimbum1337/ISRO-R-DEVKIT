#pragma once
#include <d3dx9.h>
#include <vector>

class CRTNavCellTri;

#include "navmesh/RTNavCell.h"

class CRTNavCellTri : public CRTNavCell
{
public:
	std::vector<void*> N0000098F; //0x0008
	char pad_0018[12]; //0x0018
	std::vector<void*> N00000993; //0x0024
	D3DXVECTOR3 vP1; //0x0034
	D3DXVECTOR3 vP2; //0x0040
	D3DXVECTOR3 vP3; //0x004C
	char pad_0058[52]; //0x0058
};
