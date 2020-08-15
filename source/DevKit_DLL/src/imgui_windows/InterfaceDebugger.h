#pragma once

class InterfaceDebugger {
public:

    InterfaceDebugger();

    void Render();

    void MenuItem();

private:
    bool bShow;

    bool interface_draw_outline;
    bool interface_draw_marker;
};
