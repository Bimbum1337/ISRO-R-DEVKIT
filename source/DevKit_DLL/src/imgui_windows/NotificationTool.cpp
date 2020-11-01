#include "NotificationTool.h"

#include <imgui/imgui.h>
#include <cstdio>
#include <BSLib/BSLib.h>
#include <BSLib/Debug.h>
#include <BSLib/multibyte.h>
#include <GInterface.h>

void NotificationTool::MenuItem() {
    ImGui::MenuItem("Notification Tool", 0, &bShow);
}

void NotificationTool::Render() {

    if (!bShow) return;

    if (!ImGui::Begin("Notification Tool", &bShow)) {
        ImGui::End();
        return;
    }

    // Make a combo box for the three notice types
    // Based on this example: https://github.com/ocornut/imgui/issues/1658
    const char *items[] = {"Quest", "Warning", "Notice"};
    static const char *current_item = NULL;

    // The second parameter is the label previewed before opening the combo.
    if (ImGui::BeginCombo("##combo", current_item)) {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++) {
            // You can store your selection however you want, outside or inside your objects
            bool is_selected = (current_item == items[n]);
            if (ImGui::Selectable(items[n], is_selected))
                current_item = items[n];

            // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }

    // Create the input box for the message
    // The message input can be 255 characters for now
    static char messageBuffer[256] = {0};
    ImGui::InputText("Message", messageBuffer, IM_ARRAYSIZE(messageBuffer));

    // Create the send button and send the message, if pressed
    if (ImGui::Button("Send")) {
        // We don't want to send empty messages
        if (messageBuffer[0] == '\0') {
            ImGui::End();
            return;
        }

        // We can't send if there is no item selected
        if (current_item == NULL) {
            ImGui::End();
            return;
        }

        // We need the message to be an n_wstring
        std::n_wstring wstr = acp_n_decode(messageBuffer, strlen(messageBuffer));

        // Dispatch the message to the correct function
        if (strcmp(current_item, items[0]) == 0) {
            g_pCGInterface->ShowMessage_Quest(wstr);
        } else if (strcmp(current_item, items[1]) == 0) {
            g_pCGInterface->ShowMessage_Warning(wstr);
        } else if (strcmp(current_item, items[2]) == 0) {
            g_pCGInterface->ShowMessage_Notice(wstr);
        } else {
            // Somehow we don't know what the selection is
            BS_INFO("Unknown selection when sending notification");
        }
    }

    ImGui::End();
}
