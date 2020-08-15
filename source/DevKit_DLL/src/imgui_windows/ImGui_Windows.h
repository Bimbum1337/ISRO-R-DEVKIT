#pragma once
#include <Windows.h>

void ImGui_OnCreate(HWND hWindow, void* msghandler, int a3);
void ImGui_OnPreSetSize(int width, int height);
void ImGui_OnPostSetSize(int width, int height);
void ImGui_OnEndScene();

LRESULT CALLBACK ImGui_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
