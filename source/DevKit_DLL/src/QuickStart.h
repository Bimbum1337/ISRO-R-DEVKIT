#pragma once

#include "BSLib/BSLib.h"

class QuickStart {
public:
    void Setup();

    void LoadConfig();

    void PlaceHooks();

    bool IsEnabled() const;

    QuickStart();

private:
    void ConfigReadA(const char *key, char *value, size_t nSize) const;

    void ConfigReadW(const wchar_t *key, wchar_t *value, size_t nSize) const;

private:
    const char *cPath;
    const wchar_t *wPath;

    bool m_enabled;
    wchar_t servername[32];
    wchar_t userid[32];
    wchar_t passwd[32];
};

