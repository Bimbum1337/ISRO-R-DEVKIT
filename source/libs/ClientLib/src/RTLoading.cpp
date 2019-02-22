#include "StdAfx.h"
#include "RTLoading.h"


CRTLoading::CRTLoading(void)
{
}


CRTLoading::~CRTLoading(void)
{
}

void CRTLoading::SetFM(int nFMType, IFileManager* pFM)
{
	reinterpret_cast<void(__thiscall*)(CRTLoading*, int, IFileManager*)>(0x00B876B0)(this, nFMType, pFM);
}
