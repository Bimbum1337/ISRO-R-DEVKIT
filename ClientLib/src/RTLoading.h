#pragma once
#include "GFXFileManagerLIB/IFileManager.h"


// This name is from an error message of CRTLoading ... 
#define THREADTEXTURE_FMTYPE_NUM 5

class CRTLoading
{
public:
	CRTLoading(void);
	~CRTLoading(void);

	void SetFM(int nFMType, IFileManager* pFM);


	char gap0[0x4C];
	IFileManager *fileManager[THREADTEXTURE_FMTYPE_NUM];



};

