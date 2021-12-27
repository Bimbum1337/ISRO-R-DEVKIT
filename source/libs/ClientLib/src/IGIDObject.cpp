#include "IGIDObject.h"

const std::n_wstring &CIGIDObject::GetName() const {
    return m_name;
}

const CCharacterData::SData *CIGIDObject::GetSData() const {
    return m_characterData;
}

const int CIGIDObject::GetUniqueId() const {
    return m_uniqueId;
}
