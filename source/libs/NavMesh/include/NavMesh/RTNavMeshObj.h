#pragma once

#include <vector>

class CRTNavMeshObj;

#include "RTNavMesh.h"
#include "RTNavCellTri.h"
#include "PrimNavMesh.h"

#pragma pack(push, 1)
struct NavMeshObjGridTile
{
	CRTNavMeshObj* pOutlineEdge;
	WORD wGlobalEdgeIndex;
};
#pragma pack(pop)

struct NavMeshObjGrid
{
	D3DXVECTOR2 m_Origin;
	int m_Width;
	int m_Height;
	std::vector<NavMeshObjGridTile> m_Tiles;
};


class CRTNavMeshObj : public CRTNavMesh
{
public:	
	std::vector<PrimNavMeshVertex> m_Vertices; //0x0014
	std::vector<PrimNavMeshEdge> m_GlobalEdges; //0x0024
	std::vector<PrimNavMeshEdge> m_InternalEdges; //0x0034
	std::vector<CRTNavCellTri> m_Cells; //0x0044	
	NavMeshObjGrid m_Grid;
	std::vector<std::string> m_NavCallbacks;
	std::vector<std::string> m_Events;
	char field_16; // isEventStruct?
	int m_StructOption;
};
