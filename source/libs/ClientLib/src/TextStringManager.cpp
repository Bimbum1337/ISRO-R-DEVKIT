#include "TextStringManager.h"

#include <set>
#include <algorithm>

#ifdef CONFIG_TRANSLATIONS_DEBUG

#endif

const std::n_wstring *CTextStringManager::GetString(const wchar_t *identifier) {
#ifdef CONFIG_TRANSLATIONS_DEBUG
    static std::set<std::n_wstring> strings;
    std::pair<std::set<std::n_wstring>::iterator, bool> ret = strings.insert(identifier);
    return &(*ret.first);
#else
    return reinterpret_cast<const std::n_wstring*(__thiscall*)(CTextStringManager*, const wchar_t*identifier)>(0x008C9C30)(this, identifier);
#endif
}
