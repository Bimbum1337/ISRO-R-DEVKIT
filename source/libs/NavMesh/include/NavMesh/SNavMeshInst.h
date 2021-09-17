#pragma once

struct SNavMeshInst;

#include <d3dx9.h>
#include "RTNavMeshObj.h"

struct LinkEdge
{
	WORD m_wLinkedObjID;
	WORD m_wLinkedObjEdgeID;
	WORD m_wEdgeID;
};

struct SNavMeshInst
{
	char gap0[2]; // eh?
#pragma pack(push,1)
	struct SMapObjInfo
	{
		int Index;
		D3DXVECTOR3 Offset;
		short Type;
		float Yaw;
		short ID;
		short Short0; // padding?
		bool IsBig;
		bool IsStruct;
		short RegionID;
	} m_sObj;
#pragma pack(pop)

	_D3DMATRIX m_WorldToLocal;
	_D3DMATRIX m_LocalToWorld;
	std::vector<LinkEdge> m_LinkEdges;
	CRTNavMesh* m_pParent;
	CRTNavMeshObj* m_pObject;
	void* m_ObjExtInfo; // data from objext.ifo (object extensions?) -> dungeons?
};