#include "CGame_Hook.h"
#include "Hooks.h"
#include <vector>

extern std::vector<void_cgame_handler_t> hooks_lgo_pre;
extern std::vector<void_cgame_handler_t> hooks_lgo_post;

extern std::vector<void_cgame_handler_t> hooks_iga_pre;
extern std::vector<void_cgame_handler_t> hooks_iga_post;

void CGame_Hook::LoadGameOption() {
    for (std::vector<void_cgame_handler_t>::iterator it = hooks_lgo_pre.begin(); it != hooks_lgo_pre.end(); ++it) {
        (*it)(this);
    }

    reinterpret_cast<void (__thiscall *)(CGame_Hook *)>(0x008469c0)(this);

    for (std::vector<void_cgame_handler_t>::iterator it = hooks_lgo_post.begin(); it != hooks_lgo_post.end(); ++it) {
        (*it)(this);
    }
}

void CGame_Hook::InitGameAssets_Impl() {
    for (std::vector<void_cgame_handler_t>::iterator it = hooks_iga_pre.begin(); it != hooks_iga_pre.end(); ++it) {
        (*it)(this);
    }

    CGame::InitGameAssets();

    for (std::vector<void_cgame_handler_t>::iterator it = hooks_iga_post.begin(); it != hooks_iga_post.end(); ++it) {
        (*it)(this);
    }
}
