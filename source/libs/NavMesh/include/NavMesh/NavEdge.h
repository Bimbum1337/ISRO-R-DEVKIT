#pragma once

#include <d3dx9.h>

struct LineF
{
	D3DXVECTOR2 Min;
	D3DXVECTOR2 Max;
};

struct NavEdgeLine
{
	//LineF m_Data;
	D3DXVECTOR2 Min;
	D3DXVECTOR2 Max;
	D3DXVECTOR2 Normalized;
	char IsNormalized;
};

enum EDGE_FLAG : byte
{
	EDGE_FLAG_NONE = 0,
	EDGE_FLAG_BLOCKED_DST_2_SRC = 1,
	EDGE_FLAG_BLOCKED_SRC_2_DST = 2,
	EDGE_FLAG_BLOCKED = EDGE_FLAG_BLOCKED_DST_2_SRC | EDGE_FLAG_BLOCKED_SRC_2_DST,
	EDGE_FLAG_INTERNAL = 4,
	EDGE_FLAG_GLOBAL = 8,
	EDGE_FLAG_BRIDGE = 16,
	EDGE_FLAG_ENTRANCE = 32,
	EDGE_FLAG_6 = 64,
	EDGE_FLAG_SIEGE = 128,
};

class NavEdge
{
public:
	//virtual bool IsGlobalLinker() { return false; }
	//virtual bool IsLocalLinker() { return true; }
	//virtual void Write(CJArchiveFm* pArchiveFm);
	//virtual void Read(CJArchiveFm* pArchiveFm);
	virtual ~NavEdge() { }

	NavEdgeLine sLine;
	EDGE_FLAG btFlag;
	char btAssocDirection[2];
	short wAssocCell[2];
};

class NavEdgeGlobal : public NavEdge
{
public:	
	//virtual bool IsGlobalLinker() override { return true; }
	//virtual bool IsLocalLinker() override { return false; }
	//virtual void Write(CJArchiveFm* pArchiveFm) override;
	//virtual void Read(CJArchiveFm* pArchiveFm) override;

	short wAssocRgn[2];
};