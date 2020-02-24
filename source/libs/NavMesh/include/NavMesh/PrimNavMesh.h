#pragma once
#include <d3dx9.h>
#include "RTNavMesh.h"
#include "RTNavCellTri.h"
#include "NavEdge.h"

struct PrimNavMeshVertex
{
	D3DXVECTOR3 Position;
    struct sSlopePair {
        float fCos;
        float fSin;
    } m_Slope;
};

struct PrimNavMeshEdge
{
	EDGE_FLAG btFlag;
	PrimNavMeshVertex* AssocVertex[2];
	CRTNavCellTri* AssocCell[2];
	CRTNavMesh* NavMesh;
	bool bHasData;
	NavEdgeLine sData;
	char btEventZone;
};