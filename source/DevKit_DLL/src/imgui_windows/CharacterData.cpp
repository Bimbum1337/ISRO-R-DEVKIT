#include "CharacterData.h"

#include <Data/CharacterData.h>
#include <GlobalDataManager.h>
#include <imgui/imgui.h>

void CharacterData::MenuItem() {
    ImGui::MenuItem("Character Data", 0, &bShow);
}

void CharacterData::Render() {

    if (!bShow) return;

    if (!ImGui::Begin("Character Data", &bShow)) {
        ImGui::End();
        return;
    }

    static int id = 0;
    static const CCharacterData::SData *data = NULL;

    if (ImGui::InputInt("ID", &id)) {
        // Update
        data = g_CGlobalDataManager->GetCharacterData(id);
    }

    if (data != NULL) {
        ImGui::LabelText("CodeName", "%ls", data->m_codename.c_str());
        ImGui::LabelText("Health", "%d", data->m_health);
    }

    ImGui::End();
}
