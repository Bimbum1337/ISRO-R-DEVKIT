#pragma once

#include "BSLib/BSLib.h"

void Setup(void);

bool DoesFileExists(const std::string& name);

void RegisterObject(const CGfxRuntimeClass*);

// Overriding is currently not supported
#if 0
void OverrideObject(const CGfxRuntimeClass&);
#endif
