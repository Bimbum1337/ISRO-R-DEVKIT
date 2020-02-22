#include "StdAfx.h"
#include "Util.h"
#include <memory/hook.h>
#include <AlramGuideMgrWnd.h>
#include "GFXVideo3D_Hook.h"
#include "WndProc.h"
#include "hooks.h"
#include "GInterface.h"
#include "PSQuickStart.h"
#include "Game.h"


std::vector<const CGfxRuntimeClass*> register_objects;

#if 0
std::vector<const CGfxRuntimeClass*> override_objects;
#endif

// Locals
int APIENTRY _FakeWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow);
#define MAX_LOADSTRING 100
HINSTANCE hInst;
#define szTitle ((LPSTR)0x00EECCB0)
#define szWindowClass ((LPSTR)0x00EECC48)

wchar_t* servername = L"serv";
wchar_t* userid = L"sur";
wchar_t* passwd = L"pw";
char* charname = "char";
char* ibuv_text = "7"; // IBUV = Image Code


void Setup()
{
	replaceOffset(0x00B49AE4, (int)&_FakeWinMain);

	// vftableHook(0x00E0963C, 25, addr_from_this(&CGFXVideo3d::BeginSceneIMPL));

	vftableHook(0x00E0963C, 17, addr_from_this(&CGFXVideo3D_Hook::CreateThingsHook));
	vftableHook(0x00E0963C, 26, addr_from_this(&CGFXVideo3D_Hook::EndSceneHook));
	vftableHook(0x00E0963C, 20, addr_from_this(&CGFXVideo3D_Hook::SetSizeHook));

	vftableHook(0x00db95a4, 10, addr_from_this(&CGInterface::OnCreateIMPL));

	replaceAddr(0x00831337+4, (int)&WndProcHook);

	replaceAddr(0x00832927+1, (int)&DebugPrintCallback);

    placeHook(0x0065c6f0, addr_from_this(&CAlramGuideMgrWnd::GetGuide));



	// Override credentials & info
	replaceAddr(0x00EC2444, reinterpret_cast<int>(servername));
	replaceAddr(0x00EC2448, reinterpret_cast<int>(userid));
	replaceAddr(0x00EC244C, reinterpret_cast<int>(passwd));


	replaceAddr(0x00DD868C, addr_from_this(&CPSQuickStart::OnCreate_IMPL));
	replaceAddr(0x00DD867C, addr_from_this(&CPSQuickStart::OnPacket_MAYBE_IMPL));


}

void RegisterObject(const CGfxRuntimeClass* obj)
{
	register_objects.push_back(obj);
}
#if 0
void OverrideObject(const CGfxRuntimeClass& obj)
{
	override_objects.push_back(&obj);
}
#endif

int APIENTRY _FakeWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
					 int       nCmdShow)
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);

	printf("florian0's dev-client build on CMake\n");

	MSG msg;
	HACCEL hAccelTable;

	// Replace Create & Delete for existing classes
	// Note: We can't just inject existing objects like we would do with new objects.
	//       Joymax uses == on GFX_RUNTIME_CLASS(), so we would end up breaking this comparison
#if 0
	for (std::vector<const CGfxRuntimeClass*>::const_iterator it = override_objects.begin(); it != override_objects.end(); ++it)
	{
		
	}
#endif

	for (std::vector<const CGfxRuntimeClass*>::const_iterator it = register_objects.begin(); it != register_objects.end(); ++it)
	{
		reinterpret_cast<void (__thiscall*)(const CGfxRuntimeClass*, const char *, void*, void*, const CGfxRuntimeClass*, size_t, int)>(0x00B9C9C0)(*it, (*it)->m_lpszClassName, (*it)->m_pfnCreateObject, (*it)->m_pfnDeleteObject, (*it)->m_pBaseClass, (*it)->m_nObjectSize, 0);
	}



	if (*(int*)0xEECC14)
		reinterpret_cast<void (*)(int, int)>(0x49E450)(0x512, 0x52A);
	else
		reinterpret_cast<void (*)(int, int)>(0x49E450)(0x512, 0x501);

	LoadString(hInstance, 0x67, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, 0x6D, szWindowClass, MAX_LOADSTRING);

	// Show the client, if its already open
	CreateMutex(0, 0, "Silkroad Client");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		HWND hwnd = FindWindow(szWindowClass, szTitle);
		if (hwnd)
			SetForegroundWindow(hwnd);

		return 0;
	}

	// Setup random
	srand(timeGetTime());

	// CheckLauncherMutex(); // obsolete

	g_CGame->InitGameAssets();

	// sub_56E040(); returns 1

	//if ( g_CMsgHooker )
	//	g_CMsgHooker->field_0();


	reinterpret_cast<void (*)(HINSTANCE)>(0x00831310)(hInstance);
	//MyRegisterClass(hInstance);


	//if (!InitInstance(hInstance, nCmdShow)) {
	if (!reinterpret_cast<int (*)(HINSTANCE, int)>(0x00831060)(hInstance, nCmdShow)) {
		return FALSE;
	}

	// Enable Quickstart
	g_CGame->m_runtimeClass = reinterpret_cast<CGfxRuntimeClass*>(0x00EED974);

	g_CGame->LoadAndInitStuff(0);

	// Locale Change required for InPanic SRO
	// CClientConfig::get()->N000013F7 = 5;

	// Register Hotkeys
	if (!(*((int*)0xEECC18)))
	{
		RegisterHotKey(g_CGame->GetHWnd(), 0, 1, VK_RETURN);
		RegisterHotKey(g_CGame->GetHWnd(), 2, 1, VK_F4);
	}

	//ImGui_ImplDX9_Init(g_CGame->GetHWnd(), CGFXVideo3d::get()->m_pd3dDevice);

	// Main message loop:
	while (true) {
		while (!PeekMessage(&msg, NULL, 0, 0, 0)) {
			g_CGame->Cycle();
		}

		if (!GetMessage(&msg, NULL, 0, 0))
			break;

		//// Pass event to ImGui
		//ImGui_ImplDX9_WndProcHandler(g_CGame->hwnd(), msg.message, msg.wParam, msg.lParam);

		//// Block input if window is active
		//if (ImGui::IsMouseHoveringAnyWindow())
		//	continue;

		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			if ((*((int*)0xEECC14)) || GetKeyState(VK_MENU) >= 0 || msg.wParam != 9) // TODO: What is 9 ??
			{
				if (msg.wParam != 18) { // TODO: What is 18 ?
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}

			if (msg.message != WM_KEYFIRST && msg.message != WM_KEYUP && msg.message != WM_CHAR && msg.message != WM_SYSKEYDOWN && msg.message != WM_SYSKEYUP)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

	// TODO: Cleanup
	g_CGame->SetNextProcess(NULL);
	// g_CMemPoolManager->Cleanup();

	getchar();

	return (int)msg.wParam;





	return reinterpret_cast<int (APIENTRY*)(HINSTANCE, HINSTANCE, LPTSTR, int)>(0x008328C0)(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}
