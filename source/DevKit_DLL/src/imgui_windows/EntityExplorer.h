#pragma once

class EntityExplorer {

    struct EntityListColumnHeader {
        const char *label;
        float size;
    };


public:
    void Render();

    void MenuItem();

private:
    bool bShow;
};
