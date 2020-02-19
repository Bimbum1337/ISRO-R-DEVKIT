#include "StdAfx.h"


//#include <IFUnderbar.h>
#include "IFflorian0.h"
#include "IFflorian0Guide.h"
//#include <PSQuickStart.h>

//#include <PSVersionCheck.h>

#include "Util.h"

#include "ImGui_Windows.h"
#include "Hooks.h"



BOOL WINAPI DllMain(HINSTANCE hModule, DWORD fdwReason, LPVOID lpReserved) 
{
	if (fdwReason == DLL_PROCESS_ATTACH) 
	{
		// Setup all the required hooks
		Setup();

		// Inject all the new objects
		//RegisterObject(&GFX_RUNTIME_CLASS(CIFflorian0));
		RegisterObject(&GFX_RUNTIME_CLASS(CIFflorian0Guide));

		// Override existing objects
		//OverrideObject(GFX_RUNTIME_CLASS(CIFUnderbar));
		//OverrideObject(GFX_RUNTIME_CLASS(CPSQuickStart));

		// OverrideObject(GFX_RUNTIME_CLASS(CPSVersionCheck));

		OnCreate(ImGui_OnCreate);
		OnEndScene(ImGui_OnEndScene);
		OnWndProc(ImGui_WndProc);

		OnPreSetSize(ImGui_OnPreSetSize);
		OnPostSetSize(ImGui_OnPostSetSize);
	}
	

	return TRUE;
}
