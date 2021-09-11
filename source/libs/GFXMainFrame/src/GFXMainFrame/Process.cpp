#include "Process.h"

GlobalVar<bool, 0x00EED310> CProcess::m_bProcessNetMsg;

GFX_IMPLEMENT_RUNTIMECLASS_EXISTING(CProcess, 0x0110FA70);

void CProcess::Func_38() {
    // empty
}

int CProcess::Func_39() {
    return 1;
}

bool CProcess::On3DEvent_MAYBE(Event3D *a2) {
    return true;
}


CProcess *CProcess::GetChildProcess() const {
    return m_pProcessChild;
}

CProcess *CProcess::sub_BA7B90(const CGfxRuntimeClass &cls, int bSomething) {
    assert(!m_pProcessChild);

    this->m_pProcessChild = MakeProcess(cls);

    if (bSomething) {
        sub_BA7620(m_pProcessChild);
    }

    return this->m_pProcessChild;
}


void CProcess::sub_BA7620(CProcess *pProcess) {
    assert(pProcess);
    assert(m_blRun == FALSE);

    assert(pProcess->m_blProcessRunTerminate == FALSE);

    m_blRun = TRUE;
    pProcess->Func_38();
    m_blRun = FALSE;
    pProcess->m_blProcessRunTerminate = TRUE;
}

void CProcess::SetProcessNetMsg(bool state) {
    m_bProcessNetMsg = state;
}

CProcess *CProcess::MakeProcess(const CGfxRuntimeClass &cls) {
    if (!cls.IsDerivedFrom(GFX_RUNTIME_CLASS(CProcess))) {
        return 0;
    }

    RECT rect;
    rect.top = 0;
    rect.left = 0;
    rect.bottom = 100000;
    rect.right = 100000;

    return (CProcess *) CGWnd::CreateInstance((CProcess *) -1, cls, rect, 0, 0);
}

