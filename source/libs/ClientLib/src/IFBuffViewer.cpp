#include "IFBuffViewer.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFBuffViewer, 0x00eec908)

GFX_IMPLEMENT_DYNCREATE_FN(CIFBuffViewer, CIFWnd)

GFX_BEGIN_MESSAGE_MAP(CIFBuffViewer, CIFWnd)

GFX_END_MESSAGE_MAP()

bool CIFBuffViewer::OnCreate(long ln) {
    //printf("%s\n", __FUNCTION__);
    //return reinterpret_cast<bool (__thiscall *)(const CIFBuffViewer *, long)>(0x007fab80)(this, ln);

    return true;
}

CIFBuffViewer::CIFBuffViewer()
        : field4_0x378(0x15),
          field5_0x37c(0x15),
          field6_0x380(0x14),
          field7_0x384(0x14),
          field1_0x36c(0),
          field2_0x370(0),
          field3_0x374(8),
          field10_0x3a0(0),
          field11_0x3a4(0) {

}
