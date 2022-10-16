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



    ImGui::End();
}
