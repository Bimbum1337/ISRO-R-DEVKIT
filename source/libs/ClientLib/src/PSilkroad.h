#pragma once

#include "IRMManager.h"
#include <GFXMainFrame/Process.h>


class CPSilkroad :
	public CProcess
{ // size 224 bytes | 0xE0
protected:
	CIRMManager m_IRM; //0x00B0
	char pad_00B4[44]; //0x00B4
public:

	virtual void Func_40();

	void ErrorMessage(const wchar_t* message);
	void ErrorMessagePar(const wchar_t* message, char codeletter, int codenumber);
};
