#include <IFChatViewer.h>
#include <IFMainPopup.h>
#include <IFChatOptionBoard.h>
#include "hooks/Hooks.h"
#include "Util.h"
#include "imgui_windows/ImGui_Windows.h"

#include "IFflorian0.h"
#include "IFflorian0Guide.h"

extern "C" _declspec(dllexport) BOOL WINAPI DllMain(HINSTANCE hModule, DWORD fdwReason, LPVOID lpReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        // Setup all the required hooks
        Setup();

        // Inject all the new objects
        RegisterObject(&GFX_RUNTIME_CLASS(CIFflorian0));
        RegisterObject(&GFX_RUNTIME_CLASS(CIFflorian0Guide));

#ifdef CONFIG_OLD_MAINPOPUP
        OverrideObject<CIFMainPopup, 0x00eea6dc>();
#endif

        OverrideObject<CIFChatOptionBoard, 0x00eec128>();

        // Override existing objects
#ifdef CONFIG_CHATVIEWER
        OverrideObject<CIFChatViewer, 0x00EEC168>();
#endif // CONFIG_CHATVIEWER

#ifdef CONFIG_IMGUI
        OnCreate(ImGui_OnCreate);
        OnEndScene(ImGui_OnEndScene);
        OnWndProc(ImGui_WndProc);

        OnPreSetSize(ImGui_OnPreSetSize);
        OnPostSetSize(ImGui_OnPostSetSize);
#endif // CONFIG_IMGUI

#ifdef CONFIG_OLD_UNDERBAR
        // https://www.elitepvpers.com/forum/sro-pserver-guides-releases/4256375-source-fix-old-exp-bar-writing-code.html
        replaceAddr(0x00D9841C, addr_from_this(&NIFUnderMenuBar::Update));
#endif // CONFIG_OLD_UNDERBAR

        OnPreInitGameAssets(InstallRuntimeClasses);
    }

    return TRUE;
}
