#include "Util.h"

#include <sys/stat.h>

#include <memory/hook.h>

#include "hooks/Hooks.h"
#include "hooks/GFXVideo3d_Hook.h"
#include "hooks/CGame_Hook.h"

#include "hooks/WndProc_Hook.h"

#include "CPSVersionCheck.h"
#include "ICMonster.h"
#include "ICPlayer.h"
#include "QuickStart.h"
#include <BSLib/Debug.h>
#include <GFX3DFunction/RStateMgr.h>
#include <GInterface.h>
#include <ICUser.h>
#include <IFChatViewer.h>
#include <NetProcessIn.h>
#include <NetProcessSecond.h>
#include <NetProcessThird.h>
#include <PSCharacterSelect.h>

std::vector<const CGfxRuntimeClass *> register_objects;
std::vector<overrideFnPtr> override_objects;

QuickStart quickstart;

void Setup() {

#ifdef CONFIG_DEBUG_CONSOLE
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);

    replaceAddr(0x92EB76 + 1 , (int) &DebugPrintCallback);

    placeHook(0x00D88960, Put);
#endif

    vftableHook(0x01068CC4, 17, addr_from_this(&CGFXVideo3D_Hook::CreateThingsHook));
    vftableHook(0x01068CC4, 26, addr_from_this(&CGFXVideo3D_Hook::EndSceneHook));
    vftableHook(0x01068CC4, 20, addr_from_this(&CGFXVideo3D_Hook::SetSizeHook));

    replaceOffset(0x009490F6, addr_from_this(&CGame_Hook::LoadGameOption));
    replaceOffset(0x0092ECC5, addr_from_this(&CGame_Hook::InitGameAssets_Impl));

    replaceAddr(0x0092D537 + 4, (int) &WndProcHook);

    vftableHook(0x0101011C, 10, addr_from_this(&CGInterface::OnCreateIMPL));

    placeHook(0x007390B0, addr_from_this(&CAlramGuideMgrWnd::GetGuide));

    vftableHook(0x1034984,10, addr_from_this(&CPSVersionCheck::OnCreate));

    JMPFunction(0x00B2D276,0xB2D429);
    //vftableHook(0x00dd811c, 10, addr_from_this(&CPSCharacterSelect::OnCreateIMPL));

    //vftableHook(0x00de2e7c, 15, addr_from_this(&CICUser::Func_15_impl));
    //vftableHook(0x00de256c, 15, addr_from_this(&CICharactor::Func_15_impl));
    //vftableHook(0x00de2c24, 15, addr_from_this(&CICPlayer::Func_15_impl));
    //vftableHook(0x00de26c4, 15, addr_from_this(&CICMonster::Func_15_impl));



    //replaceOffset(0x0084c9bf, addr_from_this(&CNetProcessIn::RegisterPacketHandlers));
    //replaceOffset(0x00898656, addr_from_this(&CNetProcessSecond::RegisterPacketHandlers));
   // replaceOffset(0x008a4876, addr_from_this(&CNetProcessThird::RegisterPacketHandlers));

    //replaceOffset(0x009ded0d, addr_from_this(&CRStateMgr::FUN_00470060));



    //quickstart.Setup();
}

bool DoesFileExists(const std::string &name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

void RegisterObject(const CGfxRuntimeClass *obj) {
    register_objects.push_back(obj);
}

void OverrideObject(overrideFnPtr fn) {
    override_objects.push_back(fn);
}

void InstallRuntimeClasses(CGame *) {
    // Replace Create & Delete for existing classes
    // Note: We can't just inject existing objects like we would do with new objects.
    //       Joymax uses == on GFX_RUNTIME_CLASS(), so we would end up breaking this comparison

    for (std::vector<const CGfxRuntimeClass *>::const_iterator it = register_objects.begin();
         it != register_objects.end(); ++it) {
        reinterpret_cast<void (__thiscall *)(const CGfxRuntimeClass *, const char *, void *, void *,const CGfxRuntimeClass *, size_t, int)>(0x00D6A380)(*it,(*it)->m_lpszClassName, (*it)->m_pfnCreateObject, (*it)->m_pfnDeleteObject, (*it)->m_pBaseClass, (*it)->m_nObjectSize, 0);
    }

    for (std::vector<overrideFnPtr>::const_iterator it = override_objects.begin(); it != override_objects.end(); ++it) {
        (*it)();
    }
}
