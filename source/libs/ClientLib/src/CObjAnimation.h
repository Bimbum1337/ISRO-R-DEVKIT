#pragma once

#include "CompSimple.h"
#include <BSLib/BSLib.h>
#include <Test/Test.h>
#include <d3d9.h>
#include <ghidra/undefined.h>

class CCObjAnimation {
public:
    virtual ~CCObjAnimation();
    virtual void Func_1();
    virtual void Func_2();
    virtual void Func_3(undefined4, undefined4, undefined4, undefined4, float, float);
    virtual void Func_4();
    virtual void Func_5();

public:
    /// \address 00a5b4b0
    void SetResource(const std::n_string &path, undefined4 a2);

    /// \address 00a5a880
    void SetLocation(const D3DVECTOR &position);

    /// \address 00a5a8c0
    void SetRotation(float rotation);

private: /* members vars */
public:
    CCompSimple *m_compound;

private:
    char pad2[40];


private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(48)
    END_FIXTURE()

    RUN_FIXTURE(CCObjAnimation)
};
