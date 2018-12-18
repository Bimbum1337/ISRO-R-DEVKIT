#pragma once

union uregion {
	struct {
		char y;
		char x;
	} single;
	short r;
};

#define g_CurrentIfUnderCursor (*(CGWndBase**)0x0110F608)
#define g_Controler (*(CControler**)0x0110F7D4)

#define g_Region (*(uregion*)0xEEF68C)

#define DXDrawLine ((void (__cdecl *)(int, int, int, int, int, float))0x00841F30)

#define SendMsg(x) reinterpret_cast<void (__cdecl *)(CMsgStreamBuffer&)>(0x008418D0)(x)

