#include "StdAfx.h"
#include "Util.h"
#include <memory/hook.h>
#include "GFXVideo3D_Hook.h"
#include "WndProc.h"
#include "hooks.h"

std::vector<const CGfxRuntimeClass*> register_objects;
std::vector<const CGfxRuntimeClass*> override_objects;


// Locals
int APIENTRY _FakeWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow);


void Setup()
{
	replaceOffset(0x00B49AE4, (int)&_FakeWinMain);

	// vftableHook(0x00E0963C, 25, addr_from_this(&CGFXVideo3d::BeginSceneIMPL));

	vftableHook(0x00E0963C, 17, addr_from_this(&CGFXVideo3D_Hook::CreateThingsHook));
	vftableHook(0x00E0963C, 26, addr_from_this(&CGFXVideo3D_Hook::EndSceneHook));
	vftableHook(0x00E0963C, 20, addr_from_this(&CGFXVideo3D_Hook::SetSizeHook));

	replaceAddr(0x00831337+4, (int)&WndProcHook);

	replaceAddr(0x00832927+1, (int)&DebugPrintCallback);
}

void RegisterObject(const CGfxRuntimeClass* obj)
{
	register_objects.push_back(obj);
}

void OverrideObject(const CGfxRuntimeClass& obj)
{
	override_objects.push_back(&obj);
}

int APIENTRY _FakeWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
					 int       nCmdShow)
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);

	printf("florian0's dev-client\n");

	// Replace Create & Delete for existing classes
	// Note: We can't just inject existing objects like we would do with new objects.
	//       Joymax uses == on GFX_RUNTIME_CLASS(), so we would end up breaking this comparison
	for (std::vector<const CGfxRuntimeClass*>::const_iterator it = override_objects.begin(); it != override_objects.end(); ++it)
	{
		
	}

	for (std::vector<const CGfxRuntimeClass*>::const_iterator it = register_objects.begin(); it != register_objects.end(); ++it)
	{
		reinterpret_cast<void (__thiscall*)(const CGfxRuntimeClass*, const char *, void*, void*, const CGfxRuntimeClass*, size_t, int)>(0x00B9C9C0)(*it, (*it)->m_lpszClassName, (*it)->m_pfnCreateObject, (*it)->m_pfnDeleteObject, (*it)->m_pBaseClass, (*it)->m_nObjectSize, 0);
	}

	return reinterpret_cast<int (APIENTRY*)(HINSTANCE, HINSTANCE, LPTSTR, int)>(0x008328C0)(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}
