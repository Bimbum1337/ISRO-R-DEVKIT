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

        for (std::n_map<short, int>::iterator it = item->bluemap.begin(); it != item->bluemap.end(); ++it) {
            switch (it->first) {

                case 0x0005:
                    ImGui::Text("Int %d Increase", it->second);
                    break;

                case 0x000b:
                    ImGui::Text("Str %d Increase", it->second);
                    break;

                case 0x0050:
                    ImGui::Text("Durability %d%% Increase", it->second);
                    break;

                case 0x003d:
                    ImGui::Text("Lucky (%d %s)", it->second, (it->second == 1) ? "Time": "Times");
                    break;

                case 0x0098:
                    ImGui::Text("MP %d Increase", it->second);
                    break;

                case 0x008C:
                    ImGui::Text("HP %d Increase", it->second);
                    break;

                case 0x0080:
                    ImGui::Text("Parry rate %d%% Increase", it->second);
                    break;

                case 0x0041:
                    ImGui::Text("Repair invalid (%d)", it->second);
                    break;

                default:
                    ImGui::Text("%d (%x): %d", it->first, it->first, it->second);
                    break;
            }
        }
    }

    ImGui::End();
}
