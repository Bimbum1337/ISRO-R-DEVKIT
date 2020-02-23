#pragma once
#include <d3dx9.h>

class CRTNavEdge;

#include "NavEdge.h"
#include "RTNavMesh.h"
#include "RTNavCell.h"

class CRTNavEdge
{
public:	
	virtual EDGE_FLAG GetFlag();
	virtual NavEdgeLine* GetLine();
	virtual void SetFlag(EDGE_FLAG flag);
	virtual int GetPointRelation(D3DXVECTOR2* vPos, float fTolerance);
	virtual bool IsBlocked();
	virtual bool IsGlobalLinker();
	virtual bool IsLocalLinker();
	virtual void Link();
	virtual void Read(void* pArchiveFm); //CJArchiveFm*
	virtual ~CRTNavEdge();

	CRTNavMesh* m_NavMesh;
	CRTNavCell* m_AssocCell[2];
};