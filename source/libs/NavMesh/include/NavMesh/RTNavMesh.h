#pragma once

class CRTNavMesh;

#include <d3d9.h>
#include <string>

enum RTNavMeshType : int
{
	None = 0,
	Terrain = 1,
	Object = 2,
	Dungeon = 3,
};

class CRTNavMesh
{
public:
	CRTNavMesh();
	
	virtual ~CRTNavMesh();
	virtual int FindHeight(const D3DVECTOR &vPos) const;
	virtual void Move(); // int a2, int a3, SNavMeshPosition* pSrc, SNavMeshPosition* pDst, pRaycastContext* pContext
	virtual void ResolveCellAndHeight(void* position); //SNavMeshPosition* but the linking is killing me...
	virtual int F05();
	virtual int F06(int, int);

public:
	CRTNavMesh* m_ParentMesh;
	short m_Region;
	RTNavMeshType m_Type;
	std::string *m_File;

};

#define g_CurrentNavMesh (*reinterpret_cast<CRTNavMeshTerrain**>(0x0115B1CC))
