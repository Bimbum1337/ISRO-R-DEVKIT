#include "EntityExplorer.h"

#include <imgui/imgui.h>
#include <EntityManagerClient.h>
#include <GFX3DFunction/GFXVideo3d.h>
#include <Game.h>
#include <GFX3DFunction/DrawingHelpers.h>
#include <GInterface.h>

void EntityExplorer::Render() {

    if (!bShow) return;

    if (!ImGui::Begin("EntityManager", &bShow)) {
        ImGui::End();
        return;
    }

    EntityListColumnHeader headers[] = {
            {"ID",       40},
            {"Address",  70},
            {"Type",     120},
            {"Position", 500}
    };

    ImGui::Columns(IM_ARRAYSIZE(headers), "TableTextureColumns", true);
    ImGui::Separator();

    float offset = 0.0f;
    for (int i = 0; i < IM_ARRAYSIZE(headers); i++) {
        EntityListColumnHeader *header = &headers[i];
        ImGui::Text(header->label);
        ImGui::SetColumnOffset(-1, offset);
        offset += header->size;
        ImGui::NextColumn();
    }

    ImGui::Separator();

    static int selected = -1;

    for (std::map<int, CIObject *>::iterator it = g_pGfxEttManager->entities.begin();
         it != g_pGfxEttManager->entities.end(); ++it) {
        char label[32];
        sprintf(label, "%d", it->first);

        if (ImGui::Selectable(label, selected == it->first, ImGuiSelectableFlags_SpanAllColumns))
            selected = it->first;

        ImGui::NextColumn();

        ImGui::Text("%p", it->second);
        ImGui::NextColumn();
        ImGui::Text("%s", it->second->GetRuntimeClass()->m_lpszClassName);
        ImGui::NextColumn();

        uregion region = it->second->GetRegion();
        D3DVECTOR location = it->second->GetLocation();

        ImGui::Text("(%d,%d) (%.2f, %.2f, %.2f)",
                    region.single.x,
                    region.single.y,
                    location.x,
                    location.y,
                    location.z
        );
        ImGui::NextColumn();

        ImGui::Separator();

    }

    ImGui::Columns(1);

    ImGui::Text("Number of Entites: %d", g_pGfxEttManager->entities.size());

    char label[32];
    sprintf(label, "Move to Entity #%d", selected);

    static bool b_checked = false;
    ImGui::Checkbox("Highlight selected", &b_checked);

    if (b_checked && selected != -1) {
        // ESP ON

        std::map<int, CIObject *>::iterator elem = g_pGfxEttManager->entities.find(selected);
        if (elem != g_pGfxEttManager->entities.end()) {

            D3DVECTOR d2dpos, d2dpos_up, d2dpos_own;
            D3DVECTOR d3dpos = elem->second->GetLocation();
            D3DVECTOR d3dpos_up = d3dpos;

            d3dpos_up.y += 18.0;

            if (CGFXVideo3d::get()->Project(d3dpos, d2dpos) > 0) {
                DrawRect((int)d2dpos.x - 5, (int)d2dpos.y - 5, 10, 10);

                if (CGFXVideo3d::get()->Project(theApp.camera.origin, d2dpos_own) > 0) {
                    DXDrawLine((int)d2dpos_own.x, (int)d2dpos_own.y, (int)d2dpos.x, (int)d2dpos.y, D3DCOLOR_ARGB(0, 255, 255, 0), 1.0);
                }
            }

            if (CGFXVideo3d::get()->Project(d3dpos_up, d2dpos_up) > 0) {
                DXDrawLine((int)d2dpos.x, (int)d2dpos.y, (int)d2dpos_up.x, (int)d2dpos_up.y, D3DCOLOR_ARGB(0, 0, 255, 0), 1.0);
            }
        }
    }

    if (ImGui::Button(label)) {
        std::map<int, CIObject *>::iterator elem = g_pGfxEttManager->entities.find(selected);
        if (elem != g_pGfxEttManager->entities.end()) {
            g_pCGInterface->m_Nav.MoveTo(elem->second->GetRegion(), elem->second->GetLocation());
        }
    }

    ImGui::End();
}

void EntityExplorer::MenuItem() {
    ImGui::MenuItem("Entity Explorer", 0, &bShow);
}
