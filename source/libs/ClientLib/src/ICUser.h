#pragma once

#include "ICharactor.h"

class CICUser : public CICharactor {
public:
    // 2092 - 1932 = 160
    char _gap_cicuser[160];

    const std::wstring &GetGuildName() const;

    void Render(void);
};
