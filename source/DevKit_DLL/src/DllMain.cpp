#include <IFChatViewer.h>
#include <IFMainPopup.h>
#include <IFChatOptionBoard.h>
#include "hooks/Hooks.h"
#include "Util.h"
#include "imgui_windows/ImGui_Windows.h"
#include <IFWholeChat.h>

#include "IFflorian0.h"
#include "IFflorian0Guide.h"

extern "C" _declspec(dllexport) BOOL WINAPI DllMain(HINSTANCE hModule, DWORD fdwReason, LPVOID lpReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        // Setup all the required hooks
        Setup();

        // Inject all the new objects
        //RegisterObject(&GFX_RUNTIME_CLASS(CIFflorian0));
       // RegisterObject(&GFX_RUNTIME_CLASS(CIFflorian0Guide));

#ifdef CONFIG_IMGUI
        OnCreate(ImGui_OnCreate);
        OnEndScene(ImGui_OnEndScene);
        OnWndProc(ImGui_WndProc);

        OnPreSetSize(ImGui_OnPreSetSize);
        OnPostSetSize(ImGui_OnPostSetSize);
#endif // CONFIG_IMGUI

        OnPreInitGameAssets(InstallRuntimeClasses);
    }

    return TRUE;
}
