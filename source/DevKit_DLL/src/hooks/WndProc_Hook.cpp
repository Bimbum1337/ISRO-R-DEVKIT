#include "WndProc_Hook.h"
#include "GInterface.h"
#include "Hooks.h"
#include "IFButton.h"

extern std::vector<WNDPROC> hooks_wndproc;
bool upClick = false;

LRESULT CALLBACK WndProcHook(HWND hwnd, UINT msg, LPARAM lParam, WPARAM wParam)
{
    //todo replace the cifequipment
    if (GetAsyncKeyState(VK_LBUTTON) < 0 && upClick == false)
    {
        upClick = true;
    }
    if (GetAsyncKeyState(VK_LBUTTON) == 0 && upClick == true)
    {
        upClick = false;
        if (g_CurrentIfUnderCursor && !strcmp(g_CurrentIfUnderCursor->GetRuntimeClass()->m_lpszClassName, "CIFButton")) {
            CIFButton *CurBtn = (CIFButton *) g_CurrentIfUnderCursor;
            int id = CurBtn->UniqueID();
            if(id == 15779)
                g_pCGInterface->m_IRM.GetResObj<CIFWnd>(25, 1)->m_IRM.GetResObj<CIFEquipment>(71,1)->isSortRequested = true;
        }
    }
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

	return reinterpret_cast<WNDPROC>(0x92D2E0)(hwnd, msg, lParam, wParam);
}
