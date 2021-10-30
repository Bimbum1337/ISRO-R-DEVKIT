#include "Inventory.h"

#include "imgui/imgui.h"

#include <GInterface.h>

Inventory::Inventory() : bShow(false) {

}

void Inventory::MenuItem() {
    ImGui::MenuItem("Inventory", 0, &bShow);
}

void Inventory::Render() {

    if (!bShow)
        return;


    if (!ImGui::Begin("Inventory", &bShow)) {
        ImGui::End();
        return;
    }

    CIFInventory *inventory = g_pCGInterface->GetMainPopup()->GetInventory();

    for (int i = 0; i < 20; i++) {
        CSOItem *item = inventory->GetItemBySlot(i);

        if (item == NULL)
        {
            ImGui::Text("Item %d: NONE", i);
            return;
        }

        ImGui::Text("Item %d: %p [%d]", i, item, item->bluemap.size());

        if (item->bluemap.size() == 0)
            continue;

        for (std::n_map<Blue, int>::iterator it = item->bluemap.begin(); it != item->bluemap.end(); ++it) {
            const ImColor colorBlue(0, 255, 255);
            const ImColor colorRed(255, 0, 0);
            const ImColor colorNotFound(255, 0, 255);

            switch (it->first) {
                case BLUE_INT:
                    ImGui::TextColored(colorBlue, "Int %d Increase", it->second);
                    break;

                case BLUE_STR:
                    ImGui::TextColored(colorBlue, "Str %d Increase", it->second);
                    break;

                case BLUE_DURABILITY:
                    ImGui::TextColored(colorBlue, "Durability %d%% Increase", it->second);
                    break;

                case BLUE_LUCKY:
                case BLUE_LUCKY2:
                    ImGui::TextColored(colorBlue, "Lucky (%d %s)", it->second, (it->second == 1) ? "Time": "Times");
                    break;

                case BLUE_MP:
                    ImGui::TextColored(colorBlue, "MP %d Increase", it->second);
                    break;

                case BLUE_HP:
                    ImGui::TextColored(colorBlue, "HP %d Increase", it->second);
                    break;

                case BLUE_PARRY:
                    ImGui::TextColored(colorBlue, "Parry rate %d%% Increase", it->second);
                    break;

                case BLUE_REPAIR_INVALID:
                    ImGui::TextColored(colorRed, "Repair invalid (%d)", it->second);
                    break;

                case BLUE_STEADY:
                    ImGui::TextColored(colorBlue,"Steady (%d %s)", it->second, (it->second == 1) ? "Time" : "Times");
                    break;

                default:
                    ImGui::TextColored(colorNotFound, "%d (%x): %d", it->first, it->first, it->second);
                    break;
            }
        }
    }

    ImGui::End();
}
