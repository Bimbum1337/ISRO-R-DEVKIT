#pragma once

#include "ICharactor.h"

class CICUser : public CICharactor {
    GFX_DECLARE_DYNAMIC_EXISTING(CICUser, 0x00ef1bc0)
public:

    const std::wstring &GetGuildName() const;

    void Render(void);

private:
    char _gap_cicuser[160];

    BEGIN_FIXTURE()
        ENSURE_SIZE(2092)
    END_FIXTURE()

    RUN_FIXTURE(CICUser)
};
