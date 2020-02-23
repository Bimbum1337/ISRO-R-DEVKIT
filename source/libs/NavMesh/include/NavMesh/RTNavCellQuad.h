#pragma once

class CRTNavCellQuad;

#include <vector>

#include "RTNavCell.h"
#include "ObjectList.h"
#include "RTNavEdge.h"

class CRTNavCellQuad : public CRTNavCell, public CObjectList
{
public:
	int m_dwEdgeCount;
	D3DXVECTOR2 m_Center;
	D3DXVECTOR2 m_vMin;
	D3DXVECTOR2 m_vMax;
	std::vector<CRTNavEdge*> m_sEdges[4];
};

