#pragma once

#include <vector>

class CRTNavMeshObj;

#include "RTNavMesh.h"
#include "RTNavCellTri.h"

class CRTNavMeshObj : public CRTNavMesh
{
public:
	class BsrThing* m_resource; //0x0010 seems pretty much unimportant
	std::vector<void*> N00000A21; //0x0014
	std::vector<void*> N00000A22; //0x0024
	std::vector<void*> N00000A23; //0x0034
	std::vector<CRTNavCellTri> m_cells; //0x0044
	char pad_0054[92]; //0x0054

};
