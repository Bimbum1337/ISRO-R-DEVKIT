#include "StdAfx.h"
#include "unsorted.h"

#include "GlobalHelpersThatHaveNoHomeYet.h"
#include "GWndBase.h"
#include "Process.h"
#include <BSLib/BSLib.h>
#include <GFX3DFunction/DrawingHelpers.h>

GlobalPtr<CGWndBase, 0x0110F60C> g_CurrentIF_UnderCursor;

bool TryCreateCompatibleDC()
{
  g_hdc = CreateCompatibleDC(0);
  return g_hdc != 0;
}

bool StartNetEngine()
{
	return reinterpret_cast<bool(*)()>(0x008449F0)();
}

void DrawRect(int x, int y, int height, int width, int color)
{
	/* 
	 * x1|y1        x2|y1
	 * --------------
	 * |            |
	 * |            |
	 * --------------
	 * x1|y2        x2|y2
	*/

	int x1 = x;
	int x2 = x + width;
	int y1 = y;
	int y2 = y + height;

	// Draw vertical Left
	DXDrawLine(x1, y1, x2, y1, color, 1.0);
	DXDrawLine(x2, y1, x2, y2, color, 1.0);
	DXDrawLine(x2, y2, x1, y2, color, 1.0);
	DXDrawLine(x1, y2, x1, y1, color, 1.0);
}

void DrawRect(int x, int y, int height, int width)
{
	DrawRect(x, y, height, width, 0x00FF0000);
}

CProcess* MakeProcess(CGfxRuntimeClass* cls)
{
	if (!cls->IsDerivedFrom(GFX_RUNTIME_CLASS(CProcess)))
	{
		return 0;
	}

	RECT rect;
	rect.top = 0;
	rect.left = 0;
	rect.bottom = 100000;
	rect.right = 100000;

	return (CProcess*)CGWnd::CreateInstance((CProcess*)-1, cls, rect, 0, 0);
}

ClientResolutonData* sub_4F9CD0()
{
	return reinterpret_cast<ClientResolutonData*(*)()>(0x4F9CD0)();
}

void sub_BBDA70(int a1)
{
	reinterpret_cast<void(*)(int)>(0xBBDA70)(a1);
}

void PopulateCharPositionsForNameChange(CGFXVideo3d* p)
{
	reinterpret_cast<void(__cdecl*)(CGFXVideo3d*)>(0x85AFF0)(p);
}

int GetIDOfInterfaceUnderCursor()
{
	if (g_CurrentIF_UnderCursor)
	{
		return g_CurrentIF_UnderCursor->UniqueID();
	} 
	else
	{
		return -1;
	}
}

// Fun_CacheTexture_Create .text 005008F0 00000010 00000000 00000004 R . . . . . .
void* Fun_CacheTexture_Create(std::n_string* a2)
{
	assert(FALSE);
	return NULL;
}

// Fun_CacheTexture_Release .text 00500460 00000010 00000000 00000004 R . . . . . .
void Fun_CacheTexture_Release(std::n_string* a2)
{
	assert(FALSE);
}

void SendRestartRequest(char type)
{
	reinterpret_cast<void(__stdcall*)(char)>(0x0081F030)(type);
}
