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
#include "QuickStart.h"


std::vector<const CGfxRuntimeClass*>* register_objects;

// Locals
#define MAX_LOADSTRING 100
#define szTitle ((LPSTR)0x00EECCB0)
#define szWindowClass ((LPSTR)0x00EECC48)

wchar_t servername[32];
wchar_t userid[32];
wchar_t passwd[32];
char charname[32];
char ibuv_text[32]; // IBUV = Image Code

void FakeWinMain_CPSQuickStart::Setup(std::vector<const CGfxRuntimeClass*>* a)
{
	register_objects = a;

	const char* cPath = ".\\setting\\CPSQuickStart.ini";
	const wchar_t* wPath = L".\\setting\\CPSQuickStart.ini";
	GetPrivateProfileStringW(L"sro_devkit", L"servername", L"", servername, 32, wPath);
	GetPrivateProfileStringW(L"sro_devkit", L"userid", L"", userid, 32, wPath);
	GetPrivateProfileStringW(L"sro_devkit", L"passwd", L"", passwd, 32, wPath);
	GetPrivateProfileStringA("sro_devkit", "charname", "", charname, 32, cPath);
	GetPrivateProfileStringA("sro_devkit", "ibuv_text", "", ibuv_text, 32, cPath);

	// Override credentials & info
	replaceAddr(0x00EC2444, reinterpret_cast<int>(servername));
	replaceAddr(0x00EC2448, reinterpret_cast<int>(userid));
	replaceAddr(0x00EC244C, reinterpret_cast<int>(passwd));

	replaceOffset(0x00B49AE4, (int)&_FakeWinMain_CPSQuickStart);
	replaceAddr(0x00DD868C, addr_from_this(&CPSQuickStart::OnCreate));
	replaceAddr(0x00DD867C, addr_from_this(&CPSQuickStart::OnNetMsg));
}

int APIENTRY FakeWinMain_CPSQuickStart::_FakeWinMain_CPSQuickStart(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);

	printf("florian0's dev-client build on CMake\n");
	printf("WARNING: CPSQuickStart IS enabled!!!\n");
	printf("Servername: %ws, len(%d)\n", servername, wcslen(servername));
	printf("UserID: %ws, len(%d)\n", userid, wcslen(userid));
	//printf("PW: %ws, len(%d)\n", passwd, wcslen(passwd));
	printf("Charname: %s, len(%d)\n", charname, strlen(charname));
	printf("IBUV_TEXT: %s, len(%d)\n", ibuv_text, strlen(ibuv_text));


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

	for (std::vector<const CGfxRuntimeClass*>::const_iterator it = register_objects->begin(); it != register_objects->end(); ++it)
	{
		reinterpret_cast<void(__thiscall*)(const CGfxRuntimeClass*, const char*, void*, void*, const CGfxRuntimeClass*, size_t, int)>(0x00B9C9C0)(*it, (*it)->m_lpszClassName, (*it)->m_pfnCreateObject, (*it)->m_pfnDeleteObject, (*it)->m_pBaseClass, (*it)->m_nObjectSize, 0);
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