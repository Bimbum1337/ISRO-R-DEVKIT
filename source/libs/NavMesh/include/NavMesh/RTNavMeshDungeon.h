#pragma once

#pragma once
#include <vector>

class CRTNavMeshDungeon;

#include "RTNavMeshObj.h"
#include "RTNavMesh.h"
#include "IDungeon.h"

// TODO: Move to BSMath.lib
struct BoundingBox // sizeof = 28
{
	D3DVECTOR Min;
	D3DVECTOR Max;
};

struct _SDunColObj //sizeof = 16
{
	D3DVECTOR Position;
	float Radius;
};

struct _SDunBlock
{
	int Index;
	std::string Path;
	std::string Name;
	int IsEntrance; // pDI->m_sEnterPos.find(OEI.m_sDgnEntranceName) == pDI->m_sEnterPos
	D3DVECTOR Position;
	float Yaw;
	BoundingBox BoundingBox;
	D3DMATRIX localToWorld;
	D3DMATRIX worldToLocal; 
	int field_22;
	CRTNavMeshDungeon* pDungeon;
	CRTNavMeshObj* pObject;
	std::vector<_SDunColObj> m_ObjectList; // for navigation
	std::vector<_SDunBlock*> m_WalkableBlocks; // for navigation
	std::vector<_SDunBlock*> m_VisibleBlocks;	// for rendering
	std::vector<_SDunBlock*> m_NeighbourBlocks; // connected outside
};

class CRTNavMeshDungeon : public CRTNavMesh, IDungeon
{
public:
	int m_VoxelCount;
	int m_VoxelsX;
	int m_VoxelsY;
	int m_VoxelsZ;
	char m_VoxelData[40]; // some weird 3 dimensional STL clusterfuck (each voxel has a vector of _SDunBlock)
	std::vector<_SDunBlock*> m_sBlocks;
	WORD m_0x8000; // set to 0x8000u when Reading
	BoundingBox m_BoundingBox;
};

