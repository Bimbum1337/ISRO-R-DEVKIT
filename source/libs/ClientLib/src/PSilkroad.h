#pragma once

#include <GFXMainFrame/Process.h>
#include "IRMManager.h"

class CPSilkroad : public CProcess {
public:

    /// \address 00849c20
    virtual void Func_40();

    /// \address 00861850
    void ErrorMessage(const wchar_t *message);

    /// \address 00861890
    void ErrorMessagePar(const wchar_t *message, char codeletter, int codenumber);


private: /* members */

protected:
    CIRMManager m_IRM; //0x00B0

    BEGIN_FIXTURE()
        ENSURE_SIZE(0xe0)
        ENSURE_OFFSET(m_IRM, 0xB0)
    END_FIXTURE()

    RUN_FIXTURE(CPSilkroad)
};
