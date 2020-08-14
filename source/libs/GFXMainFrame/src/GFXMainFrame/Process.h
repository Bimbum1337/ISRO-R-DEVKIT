#pragma once

#include "GWnd.h"
#include <remodel/GlobalVar.h>

class CProcess : public CGWnd {
GFX_DECLARE_DYNAMIC_EXISTING(CProcess, 0x0110FA70);

public:
    /// \address 0084a190
    virtual void Func_38();

    /// \address 0084a1a0
    virtual int Func_39();

    /// \address 0084a180
    bool On3DEvent_MAYBE(Event3D *a2) override;

    CProcess *GetChildProcess();

    /// \address 00BA7B90
    CProcess *sub_BA7B90(const CGfxRuntimeClass &cls, int bSomething);

    /// \address 00BA7620
    void sub_BA7620(CProcess *pProcess);

    void SetProcessNetMsg(bool state);

public: /* statics */
    static CProcess *MakeProcess(const CGfxRuntimeClass &cls);

private: /* members */
    static GlobalVar<bool, 0x00EED310> m_bProcessNetMsg;

public:
    int N000006AB; //0x0084
    char pad_0088[20 - 4]; //0x0088
    int m_blProcessRunTerminate; //0x0098
    int m_blRun; //0x009C
private:
    CProcess *m_pProcessChild; //0x00A0, was not public
    char pad_00A4[12]; //0x00A4

    BEGIN_FIXTURE()
        ENSURE_SIZE(176)
        ENSURE_OFFSET(m_blProcessRunTerminate, 0x98)
        ENSURE_OFFSET(m_blRun, 0x9c)
        ENSURE_OFFSET(m_pProcessChild, 0xa0)
    END_FIXTURE()

    RUN_FIXTURE(CProcess)
};
