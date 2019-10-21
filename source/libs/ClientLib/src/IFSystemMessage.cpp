// Credits: @florian0 https://florian0.wordpress.com/2017/12/14/silkroad-online-reconstructing-ui-access-for-the-sake-of-colors/
#include "IFSystemMessage.h"


void CIFSystemMessage::write(int a1, int color, wchar_t* msg, int a2, int a3)
{
    reinterpret_cast<void(__thiscall*)(CIFSystemMessage*, int, int, wchar_t, int, int)>(0x007B89E0)(this, a1, color, reinterpret_cast<wchar_t>(msg), a2, a3);
}