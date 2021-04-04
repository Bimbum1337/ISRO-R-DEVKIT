#include "InterfaceTree.h"
#include <cstdio>
#include <imgui/imgui.h>
#include <Game.h>
#include <GFX3DFunction/DrawingHelpers.h>
#include <MathHelpers/hsl.h>

InterfaceTree::InterfaceTree()
    : bShow(false), lastNumberOfDraws(0), currentNumberOfDraws(0) {
}

void InterfaceTree::MenuItem() {
    ImGui::MenuItem("Interface Tree", 0, &bShow);
}

void InterfaceTree::Render() {
    if (!bShow)
        return;

    if (!ImGui::Begin("Interface Tree", &bShow)) {
        ImGui::End();
        return;
    }

    ImGui::Checkbox("Only visible", &showOnlyVisible);
    ImGui::Checkbox("Draw Outline", &drawOutline);

    CProcess *process = theApp.GetCurrentProcess();
    if (process != NULL) {
        RecurseElement(process);
    }
    ImGui::End();

    lastNumberOfDraws = currentNumberOfDraws;
    currentNumberOfDraws = 0;
}

void InterfaceTree::RecurseElement(const CGWndBase *element) {
    for (std::n_list<CGWndBase *>::const_iterator it = element->N00000707.begin();
         it != element->N00000707.end();
         ++it) {

        CGWndBase *elem = *it;

        if (showOnlyVisible && !elem->IsVisible())
            continue;

        char buffer[64] = {0};
        _snprintf(buffer, sizeof(buffer), "%s [%d] [+%d children]",
                  elem->GetRuntimeClass()->m_lpszClassName,
                  elem->UniqueID(),
                  elem->N00000707.size());

        if (drawOutline) {
            DrawOutline(elem);
        }

        currentNumberOfDraws++;

        // Things only visible when the item is expanded
        if (ImGui::TreeNodeEx(buffer)) {
            ImGui::Text("@%p", elem);

            RecurseElement(elem);
            ImGui::TreePop();
        }
    }
}

void InterfaceTree::DrawOutline(const CGWndBase *element) {

    // X1|Y1 ----- X2|Y1
    //   |           |
    //   |           |
    //   |           |
    // X1|Y2 ----- X2|Y2

    CGWnd::wnd_rect bounds = element->GetBounds();

    int x1 = bounds.pos.x;
    int y1 = bounds.pos.y;
    int x2 = bounds.pos.x + bounds.size.width;
    int y2 = bounds.pos.y + bounds.size.height;

    int color = GetOutlineColor();

    // Draw Top
    DXDrawLine(x1, y1, x2, y1, color, 1.0);

    // Draw Bot
    DXDrawLine(x1, y2, x2, y2, color, 1.0);

    // Draw Left
    DXDrawLine(x1, y1, x1, y2, color, 1.0);

    // Draw Right
    DXDrawLine(x2, y1, x2, y2, color, 1.0);

}

int InterfaceTree::GetOutlineColor() const {
    float h = (float) currentNumberOfDraws / lastNumberOfDraws * 360.0f;

    HSV hsv(h, 1.0, 1.0);

    return hsv;
}
