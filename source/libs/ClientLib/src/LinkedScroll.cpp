#include "LinkedScroll.h"

// CLinkedScroll::LinkScrollbar(void) .text 0065A600 0000002D 00000008 00000004 R . . . . . .
void CLinkedScroll::LinkScrollbar(void *a1) {
    reinterpret_cast<void (__thiscall *)(CLinkedScroll *, void *)>(0x0065A600)(this, a1);
}

CLinkedScroll::CLinkedScroll()
    : m_Scrollbar(0) {

}
