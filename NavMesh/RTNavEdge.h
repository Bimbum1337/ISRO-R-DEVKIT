#pragma once

class CRTNavEdge;

#include "NavEdge.h"
#include "RTNavMesh.h"

class CRTNavEdge
{
public:
	virtual ~CRTNavEdge();

	CRTNavMesh *m_mesh;
	CRTNavCellQuad *m_cell_src;
	CRTNavCellQuad *m_cell_dst;
	NavEdge m_edge;
};
