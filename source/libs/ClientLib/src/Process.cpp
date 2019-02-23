#include "StdAfx.h"
#include "Process.h"

#include "unsorted.h"


GlobalVar<bool, 0x00EED310> CProcess::m_bProcessNetMsg;

GFX_IMPLEMENT_RUNTIMECLASS_EXISTING(CProcess, 0x0110FA70);

void CProcess::Func_38()
{
	
}

int CProcess::Func_39()
{
	return 1;
}

bool CProcess::On3DEvent_MAYBE(Event3D* a2)
{
	return true;
}


CProcess* CProcess::GetChildProcess()
{
	return m_pProcessChild;
}

CProcess* CProcess::sub_BA7B90(CGfxRuntimeClass* cls, int bSomething)
{
	assert(!m_pProcessChild);

	this->m_pProcessChild = MakeProcess(cls);
	
	if (bSomething)
	{
		sub_BA7620(m_pProcessChild);
	}

	return this->m_pProcessChild;
}


void CProcess::sub_BA7620(CProcess* pProcess)
{
	assert(pProcess);
	assert(m_blRun == FALSE);

	assert(pProcess->m_blProcessRunTerminate == FALSE);

	m_blRun = TRUE;
	pProcess->Func_38();
	m_blRun = FALSE;
	pProcess->m_blProcessRunTerminate = TRUE;

}

void CProcess::SetProcessNetMsg(bool state)
{
	m_bProcessNetMsg = state;
}

