#pragma once

#include <vector>

class CRTNavMeshTerrain;

#include "RTNavMesh.h"
#include "ObjectList.h"

#include "RTNavCellQuad.h"
#include "RTNavEdgeGlobal.h"
#include "RTNavEdgeInternal.h"
#include "CollisionObject.h"

class CRTNavMeshTerrain : public CRTNavMesh, public CObjectList
{
public:

	int FindHeight(D3DVECTOR& vPos) override;

public:
	char gapx[4];
	std::vector<CollisionObject*> m_objectlist; //0x0014
	std::vector<CRTNavEdgeInternal> m_edge_internal; //0x0024
	std::vector<CRTNavEdgeGlobal> N00000024; //0x0034
	char pad_0044[4]; //0x0044
	std::vector<CRTNavCellQuad> m_navcells; //0x0048
	short cellmapper[192*192]; // mapps coordinates to cells ... maybe 192*192+1, dont forget to align bytes afterwards correctly

};

