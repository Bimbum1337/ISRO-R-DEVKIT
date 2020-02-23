#pragma once
#include <d3dx9.h>
#include <vector>

class CRTNavCellTri;

#include "RTNavCell.h"
#include "PrimNavMesh.h"

class CRTNavCellTri : public CRTNavCell
{
public:
	virtual void Func10();

	PrimNavMeshVertex* AssocVertex[3];
	D3DXVECTOR2 vCenter;
	short Flag;
	int m_EdgeCount;
	PrimNavMeshEdge* m_Edges[3];

	struct TriangleF
	{
		D3DXVECTOR3 m_VertexA;
		D3DXVECTOR3 m_VertexB;
		D3DXVECTOR3 m_VertexC;
		D3DXVECTOR3 m_Normalized;
		D3DXVECTOR3 m_VertexE;
		float m_fUnknown;
	} m_Triangle;

	struct TriangleThingy
	{
		D3DXVECTOR3 vNormalized;
		float fThingy;
	} m_TriangleThingy;

	float Float0; // calculated in sub_45DE00
	bool hasTriangle;
	bool hasTriangleThingy;
	bool hasFloat0;
	char EventZone;
};
