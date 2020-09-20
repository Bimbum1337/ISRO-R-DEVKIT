#pragma once

#include <Game.h>

class CGame_Hook : public CGame {
public:
    void LoadGameOption();

    void InitGameAssets_Impl();
};
