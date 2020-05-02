#pragma once

#include "ICharactor.h"

class CICUser : public CICharactor {
public:

    const std::wstring &GetGuildName() const;

    void Render(void);

private:
    // 2092 - 1932 = 160
    char _gap_cicuser[160 - 8]; // <- why -8 ??


    BEGIN_FIXTURE()
        ENSURE_SIZE(2092)
    END_FIXTURE()

    RUN_FIXTURE(CICUser)
};
