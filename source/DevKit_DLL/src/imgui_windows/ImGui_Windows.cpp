#include "ImGui_Windows.h"
#include <Windows.h>
#include "imgui/imgui.h"
#include "imgui/examples/imgui_impl_dx9.h"
#include "imgui/examples/imgui_impl_win32.h"

#include <GFX3DFunction/GFXVideo3d.h>
#include <GFX3DFunction/DrawingHelpers.h>

#include <GInterface.h>
#include "unsorted.h"

#include "../MathUtil.h"
#include "../hooks/Hooks.h"
#include "About.h"
#include "EntityExplorer.h"
#include "ErrorMessageTool.h"
#include "IFSystemMessage.h"
#include "InterfaceDebugger.h"
#include "InterfaceTree.h"
#include "NavMeshTool.h"
#include "NotificationTool.h"
#include "PartyInfo.h"
#include "ProcessViewer.h"
#include "SoundTool.h"
#include "NotificationTool.h"
#include "About.h"
#include "SystemMessage.h"
#include "CharacterData.h"
#include "Inventory.h"
#include <BSLib/Debug.h>
#include <BSLib/multibyte.h>


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

InterfaceDebugger interfaceDebugger;
NavMeshTool navmeshExplorer;
EntityExplorer entityExplorer;
SoundTool soundTool;
NotificationTool notificationTool;
About aboutWnd;
SystemMessage systemMessage;
ErrorMessageTool errorMessageTool;
InterfaceTree interfaceTree;
ProcessViewer processViewer;
Inventory inventory;
PartyInfo partyInfo;
CharacterData characterData;

void ImGui_OnCreate(HWND hWindow, void *msghandler, int a3) {
    BS_DEBUG("ImGui_OnCreate");
    ImGui::CreateContext();

    ImGui_ImplWin32_Init(hWindow);
    ImGui_ImplDX9_Init(g_CD3DApplication->m_pd3dDevice);

}

void ImGui_OnEndScene() {
    BS_DEBUG_LOW("ImGui_OnEndScene %d", g_CD3DApplication->IsLost());

    if (g_CD3DApplication->IsLost()) {
        return;
    }

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    // Menu
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            ImGui::MenuItem("Debug Mode", NULL, reinterpret_cast<bool *>(0x00EED6A7));

            ImGui::Separator();

            if (ImGui::MenuItem("Restart"))
                SendRestartRequest(2);

            if (ImGui::MenuItem("Exit"))
                SendRestartRequest(1);

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit")) {
            ImGui::MenuItem("Cut", 0, false, false);
            ImGui::MenuItem("Copy", 0, false, false);
            ImGui::MenuItem("Paste", 0, false, false);
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Options")) {
            ImGui::MenuItem("Fullscreen", 0, false, false);

            if (ImGui::BeginMenu("Resolution")) {
                ImGui::MenuItem("640x480 (4:3)", 0, false, false);
                ImGui::MenuItem("800x600 (4:3)", 0, false, false);
                ImGui::Separator();
                ImGui::MenuItem("Enter custom resolution", 0, false, false);

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Camera")) {
                ImGui::MenuItem("Fixed behind character", 0, false, false);
                ImGui::MenuItem("Fixed height", 0, false, false);
                ImGui::MenuItem("Free visual point", 0, false, false);
                ImGui::MenuItem("Free (Fly)", 0, false, false);

                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Tools")) {
            interfaceDebugger.MenuItem();
            interfaceTree.MenuItem();
            navmeshExplorer.MenuItem();
            entityExplorer.MenuItem();
            ImGui::MenuItem("Keyframe Editor", 0, false, false);
            ImGui::MenuItem("Script Editor", 0, false, false);
            soundTool.MenuItem();
            notificationTool.MenuItem();
            systemMessage.MenuItem();
            errorMessageTool.MenuItem();
            processViewer.MenuItem();

            inventory.MenuItem();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Data")) {
            partyInfo.MenuItem();
            characterData.MenuItem();
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Windows")) {
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Help")) {
            aboutWnd.MenuItem();
            if (ImGui::MenuItem("Online Help")) {
                ShellExecute(NULL,
                             TEXT("open"),
                             TEXT("https://florian0.gitlab.io/sro_devkit/"),
                             NULL, NULL, SW_SHOWNORMAL);
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    interfaceDebugger.Render();
    entityExplorer.Render();
    soundTool.Render();
    notificationTool.Render();
    navmeshExplorer.Render();
    aboutWnd.Render();
    systemMessage.Render();
    errorMessageTool.Render();
    interfaceTree.Render();
    processViewer.Render();
    inventory.Render();
    partyInfo.Render();
    characterData.Render();

    ImGui::EndFrame();

    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

LRESULT CALLBACK ImGui_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    BS_DEBUG_LOW("ImGui_WndProc");

    // Check if context is already created
    if (!ImGui::GetCurrentContext())
        return RESULT_PASS;

    ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam);

    // Only pass events if imgui wants it
    if (ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard)
        return RESULT_DISCARD;

    return RESULT_PASS;
}

void ImGui_OnPreSetSize(int width, int height) {
    BS_DEBUG_LOW("ImGui_OnPreSetSize");
    ImGui_ImplDX9_InvalidateDeviceObjects();
}

void ImGui_OnPostSetSize(int width, int height) {
    BS_DEBUG_LOW("ImGui_OnPostSetSize");
    //ImGui_ImplDX9_CreateDeviceObjects();
    ImGui_ImplDX9_Init(g_CD3DApplication->m_pd3dDevice);
}
