#pragma once

class CIFScrollbar;

class CLinkedScroll {

    struct CPMLLayer {
        // TODO: Reverse me
    };

public:
    virtual void LinkScrollbar(void *a1);

    virtual void Func_01(int a2) = 0;

    /// \brief Get number of items currently stored in this control
    /// \returns Number of items in this control
    virtual int GetNumberOfItems() const = 0;

    virtual void Func_03() = 0;


    CLinkedScroll();


private:
    CIFScrollbar *m_Scrollbar;
    CPMLLayer *m_PMLLayer;
    bool N00009699;
    void *unknown;
    bool N0000969B;
};
