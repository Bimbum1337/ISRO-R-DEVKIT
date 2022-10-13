#include "IFNotify.h"

void CIFNotify::ShowMessage(const std::n_wstring &msg) {
    reinterpret_cast<void(__thiscall*)(CIFNotify*,const std::n_wstring*)>(0x008A0C60)(this, &msg);
}

void CIFNotify::SetYPosition(int yposition) {
    m_yposition = yposition;
}

void CIFNotify::SetColor(unsigned char red, unsigned char green, unsigned char blue) {
    m_red = red;
    m_green = green;
    m_blue = blue;
}
