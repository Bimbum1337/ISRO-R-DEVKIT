#pragma once

#include "IFStretchWnd.h"

class CIFNotify : public CIFStretchWnd {
public:
    /// Show the notification message
    /// \address 007b3eb0
    /// \param msg Message to be shown
    void ShowMessage(const std::n_wstring &msg);

    /// \brief Set the Y position of this element
    /// \details This value is used for auto-positioning.
    /// \address 007b3d40
    void SetYPosition(int yposition);

    /// \brief Sets the background color
    /// \address 007b3d10
    void SetColor(unsigned char red, unsigned char green, unsigned char blue);

private:
    char pad7c8[16]; // 0x7CC
    int m_yposition; // 0x07dc
    unsigned char m_red; // 0x7e0
    unsigned char m_green; // 0x7e1
    unsigned char m_blue; // 0x7e2

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x7E4)
        ENSURE_OFFSET(m_yposition, 0x7dc)
        ENSURE_OFFSET(m_red, 0x7e0)
        ENSURE_OFFSET(m_green, 0x7e1)
        ENSURE_OFFSET(m_blue, 0x7e2)
    END_FIXTURE()

    RUN_FIXTURE(CIFNotify)
};
