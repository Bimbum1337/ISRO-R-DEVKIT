#pragma once

#include "BSLib/BSLib.h"

void Setup(void);

bool DoesFileExists(const std::string& name);

void RegisterObject(const CGfxRuntimeClass*);

typedef void(*overrideFnPtr)();
extern std::vector<overrideFnPtr> override_objects;

template<typename T, int address>
void OverrideRtClassAt() {
    CGfxRuntimeClass* rt = (CGfxRuntimeClass*)address;

    rt->m_pfnCreateObject = T::CreateObject;
    rt->m_pfnDeleteObject = T::DeleteObject;
}

template<typename T, int address>
void OverrideObject() {
    override_objects.push_back(&OverrideRtClassAt<T, address>);
}
