#pragma once

#define g_hdc (*((HDC*)0x0110FAB0))
#include "Process.h"

#include <GFX3DFunction/GFXVideo3d.h>

#define ARRAY_SIZE(ar) ((int)(sizeof(ar)/sizeof(*ar)))

// extern GlobalPtr<CGWndBase, 0x0110F60C> g_CurrentIF_UnderCursor;

bool TryCreateCompatibleDC();

bool StartNetEngine();


void DrawRect(int x, int y, int height, int width, int color);
void DrawRect(int x, int y, int height, int width);

CProcess *MakeProcess(const CGfxRuntimeClass &cls);

struct UISize
{
	int width;
	int height;
};

class ClientResolutonData
{
public:
	char pad_0000[36]; //0x0000
	int width; //0x0024
	int height; //0x0028
}; //Size: 0x002C

class ClientRes
{
public:
	char pad_0000[4]; //0x0000
	ClientResolutonData res; //0x0004
}; //Size: 0x0030

ClientResolutonData* sub_4F9CD0();

void sub_BBDA70(int a1);
void PopulateCharPositionsForNameChange(CGFXVideo3d *p);

int GetIDOfInterfaceUnderCursor();

void* Fun_CacheTexture_Create(std::n_string *a2);
void Fun_CacheTexture_Release(std::n_string *a2);

void SendRestartRequest(char type);
