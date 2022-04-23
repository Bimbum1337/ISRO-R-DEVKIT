#pragma once

#include "IVBDynamic.h"
#include "IVertexBuffer.h"

#define g_pDynamicVertexBuffer (*reinterpret_cast<CVBDynamic**>(0x00eecd74))

class CVBDynamic : public IVBDynamic, public IVertexBuffer {

    // 0x0000 IVBDynamic
    // 0x0018 IVertexBuffer
    // 0x???? CVBDynamic



public:

};
