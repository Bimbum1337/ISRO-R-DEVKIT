#pragma once

class CRTNavMesh;

#include <d3d9.h>

class CRTNavMesh
{
public:
	CRTNavMesh();
	
	virtual ~CRTNavMesh();
	virtual int FindHeight(D3DVECTOR &vPos);
	virtual void RelatedToMoving();
	virtual void RelatedToLoading(int);
	virtual int F05();
	virtual int F06(int, int);

public:
	int N000009F1; // set this to 1 for quick exit Kappa
	short region;
	int N000009F3;

};

#define g_CurrentNavMesh (*reinterpret_cast<CRTNavMeshTerrain**>(0x0115B1CC))
