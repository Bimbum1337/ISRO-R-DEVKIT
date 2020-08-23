#include "SystemMessage.h"

#include <imgui/imgui.h>
#include <IFSystemMessage.h>
#include <GInterface.h>
#include <BSLib/multibyte.h>

SystemMessage::SystemMessage()
        : bShow(false) {
    m_color[0] = 0.0f;
    m_color[1] = 1.0f;
    m_color[2] = 0.0f;

    strcpy(m_buffer, "Hello World");
}

void SystemMessage::MenuItem() {
    ImGui::MenuItem("SystemMessage Tool", 0, &bShow);
}

void SystemMessage::Render() {
    if (!bShow)
        return;

    if (!ImGui::Begin("SystemMessage Tool", &bShow)) {
        ImGui::End();
        return;
    }

    ImGui::TextWrapped("This tool writes a colored message to the system log of the game.");

    ImGui::ColorPicker3("Color", m_color, ImGuiColorEditFlags_None);

    ImGui::InputText("Message", m_buffer, sizeof(m_buffer));

    if (ImGui::Button("Send Message")) {
        int red = static_cast<int>(m_color[0] * 255.0f);
        int green = static_cast<int>(m_color[1] * 255.0f);
        int blue = static_cast<int>(m_color[2] * 255.0f);

        D3DCOLOR color = D3DCOLOR_ARGB(255, red, green, blue);

        // text needs to be a wide string, imgui has no wide string input
        std::wstring message = acp_decode(m_buffer, strlen(m_buffer));

        CIFSystemMessage *systemmessage = g_pCGInterface->GetSystemMessageView();
        systemmessage->WriteMessage(255, color, message.c_str(), 0, 1);
    }

    ImGui::End();
}
