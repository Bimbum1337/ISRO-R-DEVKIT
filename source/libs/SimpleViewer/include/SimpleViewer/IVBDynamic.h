#pragma once

class IVBDynamic {
public:
    virtual ~IVBDynamic();

    virtual void IVBDynamic_Func_1() = 0;

    virtual void IVBDynamic_Func_2() = 0;

    virtual void IVBDynamic_Func_3() = 0;

    virtual void IVBDynamic_Func_4() = 0;

    virtual IDirect3DVertexBuffer9* IVBDynamic_Func_5() = 0;

    virtual undefined4 IVBDynamic_Func_6(void* pData, int iSrcByte, int* param_3) = 0;

private:
    char pad_0000[0x18];
};
