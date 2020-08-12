#pragma once

#include "IRMManager.h"
#include <GFXMainFrame/Process.h>


class CPSilkroad : public CProcess {
public:

    virtual void Func_40();

    void ErrorMessage(const wchar_t *message);

    void ErrorMessagePar(const wchar_t *message, char codeletter, int codenumber);


private: /* members */

protected:
    CIRMManager m_IRM; //0x00B0

    BEGIN_FIXTURE()
        ENSURE_SIZE(0xe0)
    END_FIXTURE()

    RUN_FIXTURE(CPSilkroad)
};
