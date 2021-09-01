#pragma once

#include "ghidra/undefined.h"
#include <d3d9.h>

class SWorld *GETMAP();

class SWorld {
public:
    virtual void Func_0(undefined2, const D3DVECTOR &);
    virtual undefined1 Func_1(undefined2);
};
