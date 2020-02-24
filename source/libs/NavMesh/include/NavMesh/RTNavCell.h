#pragma once

class CRTNavCell;

#include "_ICell.h"
#include "RTNavMesh.h"

enum RTNavMeshCellType : byte
{
	RTNavCell = 0,
	RTNavCellTri = 1,
	RTNavCellQuad = 2,
};

class CRTNavCell : public _ICell
{
public:
	virtual int GetIndex(); // { return m_Index; }
	virtual float Func2(); // returns 1.0 for Quad | fUnknown for CellTri
	virtual bool Func3();
	virtual short Func4(void); // returns SNavMeshTile.Flag for CellQuad
	virtual void Func5();
	virtual void Func6();
	virtual RTNavMeshCellType GetType(); // 0 = CRTNavCell, 1 = CRTNavCellTri, 2 = CRTNavCellQuad
	virtual ~CRTNavCell(void);
	virtual int Func9(); // -1 | m_ParentNavMesh for CellTri

	CRTNavMesh* m_NavMesh;
	int m_Index;
};