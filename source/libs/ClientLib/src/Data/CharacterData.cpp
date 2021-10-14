#include "CharacterData.h"

const std::n_wstring &CCharacterData::Codename() const {
    return m_codename;
}

int CCharacterData::Health() const {
    return m_health;
}
