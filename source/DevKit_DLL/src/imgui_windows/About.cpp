#include "About.h"

#include <imgui/imgui.h>
#include <GInterface.h>

void About::MenuItem() {
    ImGui::MenuItem("About", 0, &bShow);
}

About::About() : bShow(true), m_bButtonNotFound(false) {
}

void About::Render() {

    const ImVec2 vec(370.0f, 270.0f);

    if (!bShow)
        return;

    if (!ImGui::Begin("About", &bShow, vec)) {
        ImGui::End();
        return;
    }

    ImGui::TextWrapped("Welcome to SRO_DevKit, \n"
                       "\n"
                       "SRO_DevKit is a C++ framework for creating and extending "
                       "the game Silkroad Online. It aims to be binary compatible to "
                       "the original game client allowing the entire codebase to work "
                       "without assembly code. The framework can easily be extended "
                       "with interfaces for existing classes in the game.\n"
                       "\n"
                       "SRO_DevKit is free, open-source.");

    if (g_pCGInterface == NULL) {
        ImGui::TextWrapped("Log in to show the demo window.");
    } else {
        ImGui::TextWrapped("If you imported the files for the demo window correctly, "
                           "you can go ahead and press the button below to show it.");

        if (ImGui::Button("Show Demo Window")) {
            CIFWnd *demoWnd = g_pCGInterface->m_IRM.GetResObj(1338, 1);
            m_bButtonNotFound = demoWnd == 0;

            if (demoWnd != NULL) {
                demoWnd->ShowGWnd(true);
            }
        }

        if (m_bButtonNotFound) {
            ImGui::TextColored(ImColor(255, 0, 0), "Error: Window could not be found.");
        }
    }

    ImGui::End();
}
