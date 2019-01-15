#pragma once

class CRTNavCellQuad;

#include "navmesh/RTNavCell.h"
#include "navmesh/ObjectList.h"

class CRTNavCellQuad : public CRTNavCell, public CObjectList
{
public:
	char pad_0000[32-4-8]; //0x0000
	int id;
	float Center_X; //0x0020
	float Center_Z; //0x0024
	float vMin_X; //0x0028
	float vMin_Z; //0x002C
	float vMax_X; //0x0030
	float vMax_Z; //0x0034
	char pad_0038[64]; //0x0038
};

