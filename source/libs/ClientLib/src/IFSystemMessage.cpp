// Credits: @florian0 https://florian0.wordpress.com/2017/12/14/silkroad-online-reconstructing-ui-access-for-the-sake-of-colors/
#include "IFSystemMessage.h"

void CIFSystemMessage::WriteMessage(int a1, D3DCOLOR color, const wchar_t *msg, int a2, int a3) {
    // Redirection to original client code
    reinterpret_cast<void (__thiscall *)(CIFSystemMessage *, int, int, const wchar_t*, int, int)>(0x007B89E0)(this, a1, color, msg, a2, a3);
}