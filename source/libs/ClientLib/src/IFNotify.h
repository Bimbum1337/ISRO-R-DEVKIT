#pragma once

#include "IFStretchWnd.h"

class CIFNotify : public CIFStretchWnd {
public:
    /// Show the notification message
    /// \address 007b3eb0
    /// \param msg Message to be shown
    void ShowMessage(const std::n_wstring &msg);

private:
    char _pad[0x18];

private:
BEGIN_FIXTURE()
        ENSURE_SIZE(0x7dc)
    END_FIXTURE()

    RUN_FIXTURE(CIFNotify)
};
