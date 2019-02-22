#pragma once

class CRTNavCell;

#include "navmesh/_ICell.h"
#include "navmesh/RTNavMesh.h"


class CRTNavCell : public _ICell
{
public:
	virtual ~CRTNavCell(void);


	CRTNavMesh* m_related_mesh;
};

