#include "CPSVersionCheck.h"
#include "Game.h"
#include "IFGauge.h"
#include <BSLib/Debug.h>
#include <BSLib/multibyte.h>
#include <GFXMainFrame/Controler.h>

#define g_unknown (*(int*)((int)0x1145F48))

bool CPSVersionCheck::OnCreate(int ln)
{
    PutDump("CPSVersionCheck::OnCreate (%d)\n", ln);

    if(StartNetEngine())
    {
        if(!g_pCFileManager->FileExists("jmxdebug._m_",0))
            Fun_GetCfgGame()->m_RunMode = 1;

        long hWndState = GetWindowLongA(g_CGame->GetHWnd(), GWL_STYLE);

        static int hWndwidth = 600;
        static int hWndheight = 400;

        RECT hWndRect = {0,0,hWndwidth,hWndheight};
        AdjustWindowRect(&hWndRect,hWndState,0);

        HWND hDesktopWnd = GetDesktopWindow();
        RECT hDesktopWndRECT;
        GetClientRect(hDesktopWnd, &hDesktopWndRECT);


        hDesktopWndRECT.left = (hDesktopWndRECT.right - hWndwidth) / 2;
        hDesktopWndRECT.top = (hDesktopWndRECT.bottom - hWndheight) / 2;

        SetWindowPos(g_CGame->GetHWnd(),(HWND)0xFFFFFFFE,hDesktopWndRECT.left,hDesktopWndRECT.top ,hWndwidth,hWndheight ,SWP_SHOWWINDOW);
        ShowWindow(g_CGame->GetHWnd(),1);
        UpdateWindow(g_CGame->GetHWnd());

        RECT m_mainWndRect = {0,0,1024,768};
        CIFWnd* m_mainWnd = (CIFWnd*)CreateInstance(this, GFX_RUNTIME_CLASS(CIFWnd),m_mainWndRect,1,0);

        wchar_t buffer[256];
        std::n_wstring m_ddjImg;

        int m_ddjId = rand() % ((10 - 1) + 1) + 1;
        swprintf(buffer, L"interface\\loading\\start_loading_0%d.ddj", m_ddjId);
        m_ddjImg.assign(buffer);

        m_mainWnd->TB_Func_13(TO_STRING(m_ddjImg).c_str(),0,0);

        g_unknown = 0;
        return true;
    }
    else
    {
        CGFXMainFrame::SetNextProcessSTAT(reinterpret_cast<CGfxRuntimeClass*>(0x0117E7DC));
        return false;
    }

    //int result = reinterpret_cast<char (__thiscall *)(CPSVersionCheck *,int)>(0x0086D370)(this,a2);
}

