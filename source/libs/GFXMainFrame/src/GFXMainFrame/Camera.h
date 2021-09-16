#pragma once

#include <d3d9.h>
#include <d3dx9.h>

class CCamera
{
public:
	
	int N00000768; //0x0000
	D3DXVECTOR3 camera; //0x0004
	D3DXVECTOR3 origin; //0x0010
	D3DXVECTOR3 rotation_unknown1; //0x001C
	D3DXVECTOR3 rotation_unknown; //0x0028
	D3DXVECTOR4 rotation_to_world; //0x0034
	// float zoom; //0x0040 // replaced by D3DXVECTOR4
	char N00000757; //0x0044
	char pad_0045[3]; //0x0045
	float plane_near; //0x0048
	float plane_far; //0x004C
	float N0000075A; //0x0050
	D3DMATRIX m_ViewMatrix; //0x0054
	D3DMATRIX m_ProjectionMatrix; //0x0094
	D3DMATRIX m_UnitMatrix; //0x00D4
	D3DMATRIX N0000075E; //0x0114

	CCamera();
};


