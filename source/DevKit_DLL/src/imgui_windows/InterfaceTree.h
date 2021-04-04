#pragma once

#include <GFXMainFrame/GWndBase.h>

/// \brief Tree-view representation of all UI elements in the current process
class InterfaceTree {
public:
    InterfaceTree();

    /// \brief Create the window
    void Render();

    /// \brief Create the menu item for this window
    void MenuItem();

private:
    /// \brief Creates an ImGui Tree Node for the given element and recurses it's children
    /// \details Children are only recursed if the tree node is not collapsed.
    void RecurseElement(const CGWndBase *element);

    /// \brief Draw a colored outline of given elements proportions
    void DrawOutline(const CGWndBase *element);

    /// \brief Calculates the color for the outline dependend on the number of draws
    /// \details Creates an evenly spaced map of colors based on the numbers of the last draw and
    ///          returns the color at the position of the current draw.
    int GetOutlineColor() const;

private:
    bool bShow;
    bool drawOutline;
    bool showOnlyVisible;
    int lastNumberOfDraws;
    int currentNumberOfDraws;
};

