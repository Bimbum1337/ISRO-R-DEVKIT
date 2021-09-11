#pragma once

#include <GFXMainFrame/Process.h>

class ProcessViewer {
    struct ColumnHeader {
        const char *label;
        float width;
    };

public:
    void Render();

    void MenuItem();

private:
    void RenderThreadlist(const CProcess *proc) const;

    void RenderSomeMap(const CProcess *proc) const;

private:
    bool bShow;
};
