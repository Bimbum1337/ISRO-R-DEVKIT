#pragma once

#include "ICharactor.h"

class CICUser : public CICharactor {
public:

    const std::wstring &GetGuildName() const;

    void Render(void);

private:
	// 2092 - 1932 = 160
	char _gap_cicuser[160];
};
