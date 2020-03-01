#include "StdAfx.h"
#include "QuickStart.h"
#include "Game.h"
#include "Util.h"
#include <memory/hook.h>
#include "PSQuickStart.h"
#include "Hooks.h"

void setQuickStartProcess(CGame *game);


void setQuickStartProcess(CGame *game) {
    // Enable Quickstart
    printf("Enabling quickstart\n");
    game->m_runtimeClass = reinterpret_cast<CGfxRuntimeClass*>(0x00EED974);
}

void QuickStart::Setup() {
    const char* cPath = ".\\setting\\CPSQuickStart.ini";
    if (!DoesFileExists(cPath))
        return;

    GetPrivateProfileStringA("sro_devkit", "enabled", "", CPSQuickStartEnabled, 2, cPath);

    if (!IsEnabled())
        return;

    LoadConfig();
    PlaceHooks();
    OnPostLoadGameOption(setQuickStartProcess);
}

void QuickStart::LoadConfig() {

    char charname[32];
    char ibuv_text[32]; // IBUV = Image Code


    const char* cPath = ".\\setting\\CPSQuickStart.ini";
    const wchar_t* wPath = L".\\setting\\CPSQuickStart.ini";
    GetPrivateProfileStringW(L"sro_devkit", L"servername", L"", servername, 32, wPath);
    GetPrivateProfileStringW(L"sro_devkit", L"userid", L"", userid, 32, wPath);
    GetPrivateProfileStringW(L"sro_devkit", L"passwd", L"", passwd, 32, wPath);
    GetPrivateProfileStringA("sro_devkit", "charname", "", charname, 32, cPath);
    GetPrivateProfileStringA("sro_devkit", "ibuv_text", "", ibuv_text, 32, cPath);

    strncpy(CPSQuickStart::charname, charname, sizeof(CPSQuickStart::charname));
    strncpy(CPSQuickStart::ibuv_text, ibuv_text, sizeof(CPSQuickStart::ibuv_text));

}

void QuickStart::PlaceHooks() {
    // Override credentials & info
    replaceAddr(0x00EC2444, reinterpret_cast<int>(servername));
    replaceAddr(0x00EC2448, reinterpret_cast<int>(userid));
    replaceAddr(0x00EC244C, reinterpret_cast<int>(passwd));

    replaceAddr(0x00DD868C, addr_from_this(&CPSQuickStart::OnCreate));
    replaceAddr(0x00DD867C, addr_from_this(&CPSQuickStart::OnNetMsg));
}

bool QuickStart::IsEnabled() {
    return CPSQuickStartEnabled[0] == '1';
}

void QuickStart::PreWinMain()
{
	printf("florian0's dev-client build on CMake\n");
	printf("WARNING: CPSQuickStart IS enabled!!!\n");
	printf("Servername: %ws, len(%d)\n", servername, wcslen(servername));
	printf("UserID: %ws, len(%d)\n", userid, wcslen(userid));
	//printf("PW: %ws, len(%d)\n", passwd, wcslen(passwd));
	printf("Charname: %s, len(%d)\n", CPSQuickStart::charname, strlen(CPSQuickStart::charname));
	printf("IBUV_TEXT: %s, len(%d)\n", CPSQuickStart::ibuv_text, strlen(CPSQuickStart::ibuv_text));
}