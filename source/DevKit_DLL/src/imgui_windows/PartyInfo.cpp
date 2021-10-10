#include "PartyInfo.h"

#include <BSLib/multibyte.h>
#include <CharacterDependentData.h>
#include <GInterface.h>
#include <IFSystemMessage.h>
#include <imgui/imgui.h>

PartyInfo::PartyInfo()
    : bShow(false) {
}

void PartyInfo::MenuItem() {
    ImGui::MenuItem("PartyInfo", 0, &bShow);
}

void PartyInfo::Render() {
    if (!bShow)
        return;

    if (!ImGui::Begin("PartyInfo", &bShow)) {
        ImGui::End();
        return;
    }

    const SPartyData &partyData = g_CCharacterDependentData.GetPartyData();

    ImGui::LabelText("Number of Party Members", "%d", partyData.NumberOfMembers);

    if (partyData.NumberOfMembers > 0) {
        ListColumnHeader headers[] = {
                {"Id", 40},
                {"Name", 120},
                {"Guild", 120},
                {"Level", 70},
                {"HP", 70},
                {"MP", 70},
                {"Position", 120},
        };

        ImGui::Columns(IM_ARRAYSIZE(headers), "TableTextureColumns", true);
        ImGui::Separator();

        float offset = 0.0f;
        for (int i = 0; i < IM_ARRAYSIZE(headers); i++) {
            ListColumnHeader *header = &headers[i];
            ImGui::Text(header->label);
            ImGui::SetColumnOffset(-1, offset);
            offset += header->size;
            ImGui::NextColumn();
        }

        ImGui::Separator();

        for (int i = 0; i < partyData.NumberOfMembers; ++i) {

            const SPartyMemberData &memberData = g_CCharacterDependentData.GetPartyMemberData(i);

            ImGui::Text("%d", i); ImGui::NextColumn();
            ImGui::Text("%ls", memberData.m_charactername.c_str()); ImGui::NextColumn();
            ImGui::Text("%ls", memberData.m_guildname.c_str()); ImGui::NextColumn();
            ImGui::Text("Lv. %d", memberData.currentLevel); ImGui::NextColumn();
            ImGui::Text("%d / %d", memberData.currentHP, memberData.maxHP); ImGui::NextColumn();
            ImGui::Text("%d / %d", memberData.currentMP, memberData.maxMP); ImGui::NextColumn();

            uregion region = memberData.region;
            D3DVECTOR location = memberData.position;

            ImGui::Text("(%d,%d) (%.2f, %.2f, %.2f)",
                        region.single.x,
                        region.single.y,
                        location.x,
                        location.y,
                        location.z);

            ImGui::NextColumn();

            ImGui::Separator();
        }
    }

    ImGui::End();
}
