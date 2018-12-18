#pragma once

typedef void(* endscene_handler_t)();
typedef void(* create_handler_t)(HWND, void*, int);
typedef void(* setsize_handler_t)(int,int);

void OnEndScene(endscene_handler_t handler);
void OnCreate(create_handler_t handler);
void OnWndProc(WNDPROC handler);
void OnPreSetSize(setsize_handler_t handler);
void OnPostSetSize(setsize_handler_t handler);

void DebugPrintCallback(const char *buffer);