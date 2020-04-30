#pragma once

#include "NIFBlockWnd.h"

class CNIFCommunityWnd {

public:
    /// \brief Get a pointer to the chat block window
    /// \address 0058eeb0
    /// \return Pointer to the chat block window
    CNIFBlockWnd *GetBlockWnd();
};
