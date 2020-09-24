#include "InterfaceDebugger.h"

#include <imgui/imgui.h>
#include <GlobalHelpersThatHaveNoHomeYet.h>
#include <GFXMainFrame/GWndBase.h>
#include <GFX3DFunction/DrawingHelpers.h>

void InterfaceDebugger::Render() {
    if (!bShow)
        return;

    if (!ImGui::Begin("Interface", &bShow)) {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return;
    }

    ImGui::PushItemWidth(-140);

    // ImGui::Text("Cursor: %5d|%-5d", g_Controler->mouse_x, g_Controler->mouse_y);

    CGWndBase::wnd_rect bounds = g_CurrentIfUnderCursor->GetBounds();


    ImGui::Text("@%p", g_CurrentIfUnderCursor);
    ImGui::Text("Class: %s", g_CurrentIfUnderCursor->GetRuntimeClass()->m_lpszClassName);
    ImGui::Text("Id: %d", g_CurrentIfUnderCursor->UniqueID());

    ImGui::Text("%4d|%4d|%4d|%4d",
                bounds.pos.x,
                bounds.pos.y,
                bounds.size.width,
                bounds.size.height
    );

    ImGui::Checkbox("Draw Outline", &interface_draw_outline);
    //ImGui::Checkbox("Draw Marker", &interface_draw_marker);

    if (interface_draw_outline) {

        // Get BoundingBox of element


        // X1|Y1 ----- X2|Y1
        //   |           |
        //   |           |
        //   |           |
        // X1|Y2 ----- X2|Y2

        int x1 = bounds.pos.x;
        int y1 = bounds.pos.y;
        int x2 = bounds.pos.x + bounds.size.width;
        int y2 = bounds.pos.y + bounds.size.height;

        // Draw Top
        DXDrawLine(x1, y1, x2, y1, 0x00FF0000, 1.0);

        // Draw Bot
        DXDrawLine(x1, y2, x2, y2, 0x00FF0000, 1.0);

        // Draw Left
        DXDrawLine(x1, y1, x1, y2, 0x00FF0000, 1.0);

        // Draw Right
        DXDrawLine(x2, y1, x2, y2, 0x00FF0000, 1.0);
    }

    ImGui::End();
}

void InterfaceDebugger::MenuItem() {
    ImGui::MenuItem("Interface Tool", 0, &bShow);
}

InterfaceDebugger::InterfaceDebugger() : bShow(false), interface_draw_marker(false), interface_draw_outline(false) {

}
