#pragma once

#include "BSLib/BSLib.h"

class QuickStart {
public:
    void Setup();
    void LoadConfig();
    void PlaceHooks();

    bool IsEnabled();

    void PreWinMain();

private:
    wchar_t servername[32];
    wchar_t userid[32];
    wchar_t passwd[32];
    char CPSQuickStartEnabled[2];
};

