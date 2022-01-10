#pragma once

#include <d3d9.h>

class CTextureRuntime {

public:
    virtual ~CTextureRuntime();

    /// \address 00b87eb0
    virtual void Func_1();

    /// \address 00b875c0
    virtual const IDirect3DBaseTexture9 *Func_2();

};
