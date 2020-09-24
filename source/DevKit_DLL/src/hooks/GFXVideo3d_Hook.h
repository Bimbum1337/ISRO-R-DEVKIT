#pragma once
#include <GFX3DFunction/GFXVideo3d.h>

class CGFXVideo3D_Hook : public CGFXVideo3d
{
public:
	bool CreateThingsHook(HWND hWindow, void* msghandler, int a3);
	bool EndSceneHook();

	bool SetSizeHook(int width, int height);
};

