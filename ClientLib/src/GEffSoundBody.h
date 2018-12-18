#pragma once

#include "GEffSound.h"

class CGEffSoundBody : public CGEffSound { // total size 368, local size 336

	char pad[336];
public:
	static CGEffSoundBody* get()
	{
		return *reinterpret_cast<CGEffSoundBody**>(0x0110AAD8);
	}
};

