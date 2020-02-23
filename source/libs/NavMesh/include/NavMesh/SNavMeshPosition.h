#pragma once
#include <d3dx9.h>

struct SNavMeshPosition;

#include "RTNavCell.h"
#include "SNavMeshInst.h"

struct SNavMeshPosition // sizeof = 24
{
	CRTNavCell *m_pCell;
	SNavMeshInst *m_pInst;
	short m_Region;
	D3DXVECTOR3 m_Offset;
};