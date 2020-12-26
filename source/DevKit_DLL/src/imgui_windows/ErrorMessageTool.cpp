#include "ErrorMessageTool.h"

#include <cstdio>
#include <imgui/imgui.h>
#include <Game.h>
#include <PSilkroad.h>
#include <BSLib/multibyte.h>

void ErrorMessageTool::Render() {

    if (!bShow) return;

    if (!ImGui::Begin("Error Message Tool", &bShow)) {
        ImGui::End();
        return;
    }

    static char buffer[128] = {0};
    ImGui::InputText("Message", buffer, IM_ARRAYSIZE(buffer));

    if (ImGui::Button("Show")) {
        std::wstring str = acp_decode(buffer, strlen(buffer));

        CProcess *process = theApp.GetCurrentProcess();
        if (process->IsKindOf(GFX_RUNTIME_CLASS(CPSilkroad))) {
            reinterpret_cast<CPSilkroad*>(process)->ShowMessage(str.c_str(), D3DCOLOR_RGBA(255, 0, 0, 0));
        }
    }

    ImGui::End();
}

void ErrorMessageTool::MenuItem() {
    ImGui::MenuItem("Error Message Tool", 0, &bShow);
}
