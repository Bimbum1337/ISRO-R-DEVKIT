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

        if (item == NULL) {
            ImGui::Text("Item %d: NONE", i);
            return;
        }

    }

    ImGui::End();
}
