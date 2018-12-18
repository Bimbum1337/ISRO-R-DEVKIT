#pragma once

#define _CRT_SECURE_NO_DEPRECATE

// Please not that precompiled headers are completely disabled in DevKit_DLL to due linking conflicts

#include <Windows.h>

#include <vector>

#include <cstdio>

#include <BSLib/BSLib.h>

// Linking files
#pragma comment(lib, "BSLib.lib")
#pragma comment(lib, "ClientLib.lib")
#pragma comment(lib, "GFX3DFunction.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "memory.lib")
#pragma comment(lib, "imgui-1.66.lib")
