// Credits: @florian0 https://florian0.wordpress.com/2017/12/14/silkroad-online-reconstructing-ui-access-for-the-sake-of-colors/
#include "IFSystemMessage.h"

// CIFSystemMessage::write(int a1, int color, wchar_t* msg, int a2, int a3) .text:007B89E0 sro_client_dev.exe:$3B89E0 #3B89E0 <sub_7B89E0>
void IFSystemMessage::write(int a1, int color, wchar_t* msg, int a2, int a3)
{
    // Redirection to original client code
    reinterpret_cast<void(__thiscall*)(IFSystemMessage*, int, int, wchar_t, int, int)>(0x007B89E0)(this, a1, color, reinterpret_cast<wchar_t>(msg), a2, a3);
}