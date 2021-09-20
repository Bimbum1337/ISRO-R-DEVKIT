#include "UserGuildInfo.h"

const std::n_wstring &UserGuildInfo::GetName() const {
    return m_name;
}

CGFontTexture *UserGuildInfo::GetTexture() const {
    return m_pFontTexture;
}
