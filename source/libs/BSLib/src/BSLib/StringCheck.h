#pragma once


#include <BSLib/_internal/custom_stl.h>

class CStringCheck {
public:
    /// \brief Seems to check if given string matches a list of strings
    /// \remark Use for bad word filter in chat
    /// \address 008C4020
    /// \param words The string to check
    char sub_8C4020(const std::n_wstring &words);
};
