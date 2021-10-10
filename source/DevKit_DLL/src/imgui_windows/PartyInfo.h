#pragma once

class PartyInfo {
    struct ListColumnHeader {
        const char *label;
        float size;
    };

public:
    PartyInfo();

    void MenuItem();

    void Render();

private:
    bool bShow;
};
