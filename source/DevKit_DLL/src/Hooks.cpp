#include "StdAfx.h"
#include "hooks.h"

std::vector<endscene_handler_t> hooks_endscene;
std::vector<create_handler_t> hooks_create;
std::vector<WNDPROC> hooks_wndproc;
std::vector<setsize_handler_t> hooks_setsize_pre;
std::vector<setsize_handler_t> hooks_setsize_post;
std::vector<void_cgame_handler_t> hooks_lgo_pre;
std::vector<void_cgame_handler_t> hooks_lgo_post;

void OnEndScene(endscene_handler_t handler)
{
	hooks_endscene.push_back(handler);
}

void OnCreate(create_handler_t handler)
{
	hooks_create.push_back(handler);
}

void OnWndProc(WNDPROC handler)
{
	hooks_wndproc.push_back(handler);
}

void OnPreSetSize(setsize_handler_t handler)
{
	hooks_setsize_pre.push_back(handler);
}

void OnPostSetSize(setsize_handler_t handler)
{
	hooks_setsize_post.push_back(handler);
}

void OnPreLoadGameOption(void_cgame_handler_t handler) {
    hooks_lgo_pre.push_back(handler);
}

void OnPostLoadGameOption(void_cgame_handler_t handler) {
    hooks_lgo_post.push_back(handler);
}

void DebugPrintCallback(const char* buffer)
{
	printf(buffer);
}
