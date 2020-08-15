#include "StdAfx.h"
#include "NavigationDeadreckon.h"


CNavigationDeadreckon::CNavigationDeadreckon(void) {
}


CNavigationDeadreckon::~CNavigationDeadreckon(void) {
}

void CNavigationDeadreckon::MoveTo(uregion &region, D3DVECTOR &coord) {
    reinterpret_cast<void (__thiscall *)(CNavigationDeadreckon *, uregion *, D3DVECTOR *)>(0x009EC570)(this, &region,
                                                                                                       &coord);
}

void CNavigationDeadreckon::MoveTo(uregion region, D3DVECTOR coord) {
    reinterpret_cast<void (__thiscall *)(CNavigationDeadreckon *, uregion *, D3DVECTOR *)>(0x009EC570)(this, &region,
                                                                                                       &coord);
}
