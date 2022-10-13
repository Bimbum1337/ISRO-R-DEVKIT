#pragma once

#include "GEffSound.h"
#include <Test/Test.h>

class CGEffSoundBody : public CGEffSound // total size 368, local size 336
{
	
public:
	void PlaySound(const wchar_t* sndFile) override;

	void PlaySoundInner(std::n_wstring* str, int a2, float a3);

public:
	static CGEffSoundBody* get();

private:
public:
    char pad_000[0x28];
	std::n_hash_map<std::n_wstring, int> m_sounds;
private:
	char pad_0048[0x108]; //0x0048


    BEGIN_FIXTURE()
        ENSURE_SIZE(0x178);
    END_FIXTURE()
    RUN_FIXTURE(CGEffSoundBody)
};

