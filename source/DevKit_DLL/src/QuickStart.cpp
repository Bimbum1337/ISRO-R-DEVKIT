#include "QuickStart.h"
#include "Game.h"
#include "Util.h"
#include <memory/hook.h>
#include "PSQuickStart.h"
#include "hooks/Hooks.h"
#include <BSLib/Debug.h>

void setQuickStartProcess(CGame *game);


void setQuickStartProcess(CGame *game) {
    // Enable Quickstart
    BS_INFO("Enabling quickstart");
    game->m_runtimeClass = reinterpret_cast<CGfxRuntimeClass *>(0x00EED974);
}

void QuickStart::Setup() {

    if (!DoesFileExists(cPath))
        return;

    LoadConfig();

    if (!IsEnabled())
        return;

    PlaceHooks();
}

void QuickStart::LoadConfig() {
    char enabled[2] = {0};

    ConfigReadA("enabled", enabled, 2);
    m_enabled = enabled[0] == '1';

    ConfigReadW(L"servername", servername, 32);
    ConfigReadW(L"userid", userid, 32);
    ConfigReadW(L"passwd", passwd, 32);
    ConfigReadA("charname", CPSQuickStart::charname, sizeof(CPSQuickStart::charname));
    ConfigReadA("ibuv_text", CPSQuickStart::ibuv_text, sizeof(CPSQuickStart::ibuv_text));
}

void QuickStart::PlaceHooks() {
    // Override credentials & info
    replaceAddr(0x00EC2444, reinterpret_cast<int>(servername));
    replaceAddr(0x00EC2448, reinterpret_cast<int>(userid));
    replaceAddr(0x00EC244C, reinterpret_cast<int>(passwd));

    replaceAddr(0x00DD868C, addr_from_this(&CPSQuickStart::OnCreate));
    replaceAddr(0x00DD867C, addr_from_this(&CPSQuickStart::OnNetMsg));

    OnPostLoadGameOption(setQuickStartProcess);
}

bool QuickStart::IsEnabled() const {
    return m_enabled;
}

void QuickStart::ConfigReadA(const char *key, char *value, size_t nSize) const {
    GetPrivateProfileStringA("sro_devkit", key, "", value, nSize, cPath);
}

void QuickStart::ConfigReadW(const wchar_t *key, wchar_t *value, size_t nSize) const {
    GetPrivateProfileStringW(L"sro_devkit", key, L"", value, nSize, wPath);
}

QuickStart::QuickStart() :
        cPath(".\\setting\\CPSQuickStart.ini"),
        wPath(L".\\setting\\CPSQuickStart.ini") {

}
