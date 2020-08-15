#pragma once

#include <vector>

class CRTNavMeshTerrain;

#include "RTNavMesh.h"
#include "ObjectList.h"

#include "RTNavCellQuad.h"
#include "RTNavEdgeGlobal.h"
#include "RTNavEdgeInternal.h"
#include "SNavMeshInst.h"

class CRTNavMeshTerrain : public CRTNavMesh, public CObjectList
{
public:

	int FindHeight(const D3DVECTOR& vPos) const override;
	short GetTileFlag(D3DVECTOR& vPos);

public:		
	std::vector<CRTNavEdgeInternal> m_InternalEdges;
	std::vector<CRTNavEdgeGlobal> m_GlobalEdges;
	SNavMeshInst* field_5; // temporary variable when performaing movement ?!
	std::vector<CRTNavCellQuad> m_Cells;

	struct SNavMeshTile
	{
		int m_CellID; // RTNavCellQuad ID
		short m_Flag; // Tile based navigation flags (Bit0 = BlockedTile)
		short m_TextureID; // Used with tile2d.ifo to figure which foot-step sound to play.
	} m_TileMap[96*96]; //0x0058

	int m_OpenCellCount;
	float m_HeightMap[97*97];
	char m_SurfaceFlagMap[6*6];
	float m_SurfaceHeightMap[6*6];
	int field3;
	int field4;
	int field5;
	int field6;
};

