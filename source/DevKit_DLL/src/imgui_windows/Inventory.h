#pragma once

class Inventory {
public:
    Inventory();

    /// \brief Create the window
    void Render();

    /// \brief Create the menu item for this window
    void MenuItem();

private:
    bool bShow;
};
