#pragma once

#include <d3d9.h>

// Credits: @florian0 https://florian0.wordpress.com/2017/12/14/silkroad-online-reconstructing-ui-access-for-the-sake-of-colors/

class CIFSystemMessage {
public:
    /// \address 007B89E0
    void WriteMessage(int a1, D3DCOLOR color, const wchar_t *msg, int a2, int a3);
};
