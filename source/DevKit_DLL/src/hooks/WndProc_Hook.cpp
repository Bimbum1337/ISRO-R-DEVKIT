#include "WndProc_Hook.h"
#include "Hooks.h"

extern std::vector<WNDPROC> hooks_wndproc;

LRESULT CALLBACK WndProcHook(HWND hwnd, UINT msg, LPARAM lParam, WPARAM wParam)
{
	for (std::vector<WNDPROC>::iterator it = hooks_wndproc.begin();
		it != hooks_wndproc.end();
		++it)
	{
		if ((*it)(hwnd, msg, lParam, wParam) == RESULT_DISCARD)
		{
			// Call default window proc because nothing happens otherwise ...
			return DefWindowProc(hwnd, msg, lParam, wParam);
		}
	}

	return reinterpret_cast<WNDPROC>(0x008311C0)(hwnd, msg, lParam, wParam);
}
