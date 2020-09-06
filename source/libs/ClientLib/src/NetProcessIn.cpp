#include "NetProcessIn.h"
#include "unsorted.h"
#include "ICPlayer.h"
#include <BSLib/multibyte.h>
#include "CharacterDependentData.h"
#include "TextStringManager.h"
#include "Game.h"
#include "PSMission.h"
#include "GInterface.h"


#ifdef CONFIG_DEBUG_NET_RECEIVE
#define DEBUG_PRINT_CALL() printf("%s\n", __FUNCTION__);
#else
#define DEBUG_PRINT_CALL()
#endif

void CNetProcessIn::RegisterPacketHandlers() {
    printf("Registering Handlers\n");
    m_handlers.insert(std::make_pair(0x3027, &CNetProcessIn::OnUpdateGameTime));
    m_handlers.insert(std::make_pair(0x3809, &CNetProcessIn::On3809));
    m_handlers.insert(std::make_pair(0x3055, &CNetProcessIn::OnResetClient));
    m_handlers.insert(std::make_pair(0xb005, &CNetProcessIn::OnLogoutAck));
    m_handlers.insert(std::make_pair(0xb006, &CNetProcessIn::Onb006));
    m_handlers.insert(std::make_pair(0x300a, &CNetProcessIn::On300a));
    m_handlers.insert(std::make_pair(0x3405, &CNetProcessIn::On3405));
    m_handlers.insert(std::make_pair(0x34b5, &CNetProcessIn::On34b5));
    m_handlers.insert(std::make_pair(0x300c, &CNetProcessIn::On300c));
    m_handlers.insert(std::make_pair(0x34a5, &CNetProcessIn::On34a5));
    m_handlers.insert(std::make_pair(0x3013, &CNetProcessIn::OnMyCharacterData));
    m_handlers.insert(std::make_pair(0x34a6, &CNetProcessIn::On34a6));
    m_handlers.insert(std::make_pair(0x3020, &CNetProcessIn::On3020));
    m_handlers.insert(std::make_pair(0x3017, &CNetProcessIn::OnObjectListBegin));
    m_handlers.insert(std::make_pair(0x3019, &CNetProcessIn::OnObjectListData));
    m_handlers.insert(std::make_pair(0x3018, &CNetProcessIn::OnObjectListEnd));
    m_handlers.insert(std::make_pair(0x3047, &CNetProcessIn::OnChestDataBegin));
    m_handlers.insert(std::make_pair(0x3049, &CNetProcessIn::OnChestDataData));
    m_handlers.insert(std::make_pair(0x3048, &CNetProcessIn::OnChestDataEnd));
    m_handlers.insert(std::make_pair(0x3015, &CNetProcessIn::OnObjectEntered));
    m_handlers.insert(std::make_pair(0x3016, &CNetProcessIn::OnObjectLeft));
    m_handlers.insert(std::make_pair(0x3076, &CNetProcessIn::On3076));
    m_handlers.insert(std::make_pair(0x30bf, &CNetProcessIn::On30bf));
    m_handlers.insert(std::make_pair(0xb0cb, &CNetProcessIn::Onb0cb));
    m_handlers.insert(std::make_pair(0xb03c, &CNetProcessIn::Onb03c));
    m_handlers.insert(std::make_pair(0x3092, &CNetProcessIn::On3092));
    m_handlers.insert(std::make_pair(0x30df, &CNetProcessIn::On30df));
    m_handlers.insert(std::make_pair(0x30cd, &CNetProcessIn::On30cd));
    m_handlers.insert(std::make_pair(0x30ce, &CNetProcessIn::On30ce));
    m_handlers.insert(std::make_pair(0x30d3, &CNetProcessIn::On30d3));
    m_handlers.insert(std::make_pair(0x30C1, &CNetProcessIn::On30C1));
    m_handlers.insert(std::make_pair(0x30C2, &CNetProcessIn::On30C2));
    m_handlers.insert(std::make_pair(0x30C3, &CNetProcessIn::On30C3));
    m_handlers.insert(std::make_pair(0x30C8, &CNetProcessIn::On30C8));
    m_handlers.insert(std::make_pair(0xB0C6, &CNetProcessIn::OnB0C6));
    m_handlers.insert(std::make_pair(0x30C9, &CNetProcessIn::On30C9));
    m_handlers.insert(std::make_pair(0x30E7, &CNetProcessIn::On30E7));
    m_handlers.insert(std::make_pair(0xB0C7, &CNetProcessIn::OnB0C7));
    m_handlers.insert(std::make_pair(0x30CA, &CNetProcessIn::On30CA));
    m_handlers.insert(std::make_pair(0xB116, &CNetProcessIn::OnB116));
    m_handlers.insert(std::make_pair(0xB117, &CNetProcessIn::OnB117));
    m_handlers.insert(std::make_pair(0xB420, &CNetProcessIn::OnB420));
    m_handlers.insert(std::make_pair(0x30D4, &CNetProcessIn::On30D4));
    m_handlers.insert(std::make_pair(0x3054, &CNetProcessIn::On3054));
    m_handlers.insert(std::make_pair(0x3056, &CNetProcessIn::On3056));
    m_handlers.insert(std::make_pair(0x304E, &CNetProcessIn::On304E));
    m_handlers.insert(std::make_pair(0x3052, &CNetProcessIn::On3052));
    m_handlers.insert(std::make_pair(0x3057, &CNetProcessIn::On3057));
    m_handlers.insert(std::make_pair(0xB045, &CNetProcessIn::OnB045));
    m_handlers.insert(std::make_pair(0x303D, &CNetProcessIn::On303D));
    m_handlers.insert(std::make_pair(0x30D2, &CNetProcessIn::On30D2));
    m_handlers.insert(std::make_pair(0x30CF, &CNetProcessIn::On30CF));
    m_handlers.insert(std::make_pair(0x3011, &CNetProcessIn::On3011));
    m_handlers.insert(std::make_pair(0x3058, &CNetProcessIn::On3058));
    m_handlers.insert(std::make_pair(0xB025, &CNetProcessIn::OnB025));
    m_handlers.insert(std::make_pair(0x3026, &CNetProcessIn::OnChatReceive));
    m_handlers.insert(std::make_pair(0x3091, &CNetProcessIn::On3091));
    m_handlers.insert(std::make_pair(0x302D, &CNetProcessIn::On302D));
    m_handlers.insert(std::make_pair(0xB021, &CNetProcessIn::OnB021));
    m_handlers.insert(std::make_pair(0xB024, &CNetProcessIn::OnB024));
    m_handlers.insert(std::make_pair(0xB023, &CNetProcessIn::OnB023));
    m_handlers.insert(std::make_pair(0x3028, &CNetProcessIn::On3028));
    m_handlers.insert(std::make_pair(0xB04F, &CNetProcessIn::OnB04F));
    m_handlers.insert(std::make_pair(0x30D0, &CNetProcessIn::On30D0));
    m_handlers.insert(std::make_pair(0x3200, &CNetProcessIn::On3200));
    m_handlers.insert(std::make_pair(0xB070, &CNetProcessIn::OnB070));
    m_handlers.insert(std::make_pair(0xB071, &CNetProcessIn::OnB071));
    m_handlers.insert(std::make_pair(0xB0BD, &CNetProcessIn::OnB0BD));
    m_handlers.insert(std::make_pair(0x330F, &CNetProcessIn::On330F));
    m_handlers.insert(std::make_pair(0xB0BE, &CNetProcessIn::OnB0BE));
    m_handlers.insert(std::make_pair(0xB0BC, &CNetProcessIn::OnB0BC));
    m_handlers.insert(std::make_pair(0xB072, &CNetProcessIn::OnB072));
    m_handlers.insert(std::make_pair(0x30A6, &CNetProcessIn::On30A6));
    m_handlers.insert(std::make_pair(0x30D1, &CNetProcessIn::On30D1));
    m_handlers.insert(std::make_pair(0x3206, &CNetProcessIn::On3206));
    m_handlers.insert(std::make_pair(0xB0A1, &CNetProcessIn::OnB0A1));
    m_handlers.insert(std::make_pair(0xB0A2, &CNetProcessIn::OnB0A2));
    m_handlers.insert(std::make_pair(0xB203, &CNetProcessIn::OnB203));
    m_handlers.insert(std::make_pair(0xB202, &CNetProcessIn::OnB202));
    m_handlers.insert(std::make_pair(0xB034, &CNetProcessIn::OnB034));
    m_handlers.insert(std::make_pair(0x3038, &CNetProcessIn::On3038));
    m_handlers.insert(std::make_pair(0x3039, &CNetProcessIn::On3039));
    m_handlers.insert(std::make_pair(0x3036, &CNetProcessIn::On3036));
    m_handlers.insert(std::make_pair(0xB03E, &CNetProcessIn::OnB03E));
    m_handlers.insert(std::make_pair(0xB03F, &CNetProcessIn::OnB03F));
    m_handlers.insert(std::make_pair(0x304D, &CNetProcessIn::On304D));
    m_handlers.insert(std::make_pair(0xB04C, &CNetProcessIn::OnB04C));
    m_handlers.insert(std::make_pair(0x3068, &CNetProcessIn::On3068));
    m_handlers.insert(std::make_pair(0x305C, &CNetProcessIn::On305C));
    m_handlers.insert(std::make_pair(0x30E0, &CNetProcessIn::On30E0));
    m_handlers.insert(std::make_pair(0x3040, &CNetProcessIn::On3040));
    m_handlers.insert(std::make_pair(0x3201, &CNetProcessIn::On3201));
    m_handlers.insert(std::make_pair(0x3041, &CNetProcessIn::On3041));
    m_handlers.insert(std::make_pair(0x3042, &CNetProcessIn::On3042));
    m_handlers.insert(std::make_pair(0x3153, &CNetProcessIn::On3153));
    m_handlers.insert(std::make_pair(0x3154, &CNetProcessIn::On3154));
    m_handlers.insert(std::make_pair(0xB046, &CNetProcessIn::OnB046));
    m_handlers.insert(std::make_pair(0xB04B, &CNetProcessIn::OnB04B));
    m_handlers.insert(std::make_pair(0xB0C0, &CNetProcessIn::OnB0C0));
    m_handlers.insert(std::make_pair(0xB050, &CNetProcessIn::OnB050));
    m_handlers.insert(std::make_pair(0xB051, &CNetProcessIn::OnB051));
    m_handlers.insert(std::make_pair(0xB0C5, &CNetProcessIn::OnB0C5));
    m_handlers.insert(std::make_pair(0xB059, &CNetProcessIn::OnB059));
    m_handlers.insert(std::make_pair(0xB05A, &CNetProcessIn::OnB05A));
    m_handlers.insert(std::make_pair(0xB074, &CNetProcessIn::OnB074));
    m_handlers.insert(std::make_pair(0x30EB, &CNetProcessIn::On30EB));
    m_handlers.insert(std::make_pair(0xB0EA, &CNetProcessIn::OnB0EA));
    m_handlers.insert(std::make_pair(0xB05B, &CNetProcessIn::OnB05B));
    m_handlers.insert(std::make_pair(0x34B1, &CNetProcessIn::On34B1));
    m_handlers.insert(std::make_pair(0xB060, &CNetProcessIn::OnB060));
    m_handlers.insert(std::make_pair(0x3864, &CNetProcessIn::On3864));
    m_handlers.insert(std::make_pair(0x3065, &CNetProcessIn::On3065));
    m_handlers.insert(std::make_pair(0xB062, &CNetProcessIn::OnB062));
    m_handlers.insert(std::make_pair(0xB067, &CNetProcessIn::OnB067));
    m_handlers.insert(std::make_pair(0xB069, &CNetProcessIn::OnB069));
    m_handlers.insert(std::make_pair(0xB06A, &CNetProcessIn::OnB06A));
    m_handlers.insert(std::make_pair(0xB06B, &CNetProcessIn::OnB06B));
    m_handlers.insert(std::make_pair(0xB06C, &CNetProcessIn::OnB06C));
    m_handlers.insert(std::make_pair(0x706D, &CNetProcessIn::On706D));
    m_handlers.insert(std::make_pair(0xB06D, &CNetProcessIn::OnB06D));
    m_handlers.insert(std::make_pair(0xB081, &CNetProcessIn::OnB081));
    m_handlers.insert(std::make_pair(0x3080, &CNetProcessIn::On3080));
    m_handlers.insert(std::make_pair(0x3085, &CNetProcessIn::On3085));
    m_handlers.insert(std::make_pair(0xB082, &CNetProcessIn::OnB082));
    m_handlers.insert(std::make_pair(0xB083, &CNetProcessIn::OnB083));
    m_handlers.insert(std::make_pair(0xB084, &CNetProcessIn::OnB084));
    m_handlers.insert(std::make_pair(0x3089, &CNetProcessIn::On3089));
    m_handlers.insert(std::make_pair(0x3086, &CNetProcessIn::On3086));
    m_handlers.insert(std::make_pair(0x3087, &CNetProcessIn::On3087));
    m_handlers.insert(std::make_pair(0x3088, &CNetProcessIn::On3088));
    m_handlers.insert(std::make_pair(0x30E8, &CNetProcessIn::On30E8));
    m_handlers.insert(std::make_pair(0x308C, &CNetProcessIn::On308C));
    m_handlers.insert(std::make_pair(0xB0B1, &CNetProcessIn::OnB0B1));
    m_handlers.insert(std::make_pair(0x30B8, &CNetProcessIn::On30B8));
    m_handlers.insert(std::make_pair(0xB0B2, &CNetProcessIn::OnB0B2));
    m_handlers.insert(std::make_pair(0x30B9, &CNetProcessIn::On30B9));
    m_handlers.insert(std::make_pair(0x30B7, &CNetProcessIn::On30B7));
    m_handlers.insert(std::make_pair(0xB0B3, &CNetProcessIn::OnB0B3));
    m_handlers.insert(std::make_pair(0xB0B5, &CNetProcessIn::OnB0B5));
    m_handlers.insert(std::make_pair(0xB0B4, &CNetProcessIn::OnB0B4));
    m_handlers.insert(std::make_pair(0xB0BA, &CNetProcessIn::OnB0BA));
    m_handlers.insert(std::make_pair(0x30BB, &CNetProcessIn::On30BB));
    m_handlers.insert(std::make_pair(0xB0A7, &CNetProcessIn::OnB0A7));
    m_handlers.insert(std::make_pair(0xB010, &CNetProcessIn::OnB010));
    m_handlers.insert(std::make_pair(0x30D6, &CNetProcessIn::On30D6));
    m_handlers.insert(std::make_pair(0x30D7, &CNetProcessIn::On30D7));
    m_handlers.insert(std::make_pair(0x30D5, &CNetProcessIn::On30D5));
    m_handlers.insert(std::make_pair(0xB0D8, &CNetProcessIn::OnB0D8));
    m_handlers.insert(std::make_pair(0xB0D9, &CNetProcessIn::OnB0D9));
    m_handlers.insert(std::make_pair(0x30EC, &CNetProcessIn::On30EC));
    m_handlers.insert(std::make_pair(0x30DC, &CNetProcessIn::On30DC));
    m_handlers.insert(std::make_pair(0xB515, &CNetProcessIn::OnB515));
    m_handlers.insert(std::make_pair(0x3514, &CNetProcessIn::On3514));
    m_handlers.insert(std::make_pair(0x3CA2, &CNetProcessIn::On3CA2));
    m_handlers.insert(std::make_pair(0x30E6, &CNetProcessIn::On30E6));
    m_handlers.insert(std::make_pair(0xB0E1, &CNetProcessIn::OnB0E1));
    m_handlers.insert(std::make_pair(0xB0E2, &CNetProcessIn::OnB0E2));
    m_handlers.insert(std::make_pair(0xB0E3, &CNetProcessIn::OnB0E3));
    m_handlers.insert(std::make_pair(0xB0E4, &CNetProcessIn::OnB0E4));
    m_handlers.insert(std::make_pair(0xB0E5, &CNetProcessIn::OnB0E5));
    m_handlers.insert(std::make_pair(0xB0E6, &CNetProcessIn::OnB0E6));
    m_handlers.insert(std::make_pair(0xB0F0, &CNetProcessIn::OnB0F0));
    m_handlers.insert(std::make_pair(0x38F5, &CNetProcessIn::On38F5));
    m_handlers.insert(std::make_pair(0xB0F1, &CNetProcessIn::OnB0F1));
    m_handlers.insert(std::make_pair(0xB0F8, &CNetProcessIn::OnB0F8));
    m_handlers.insert(std::make_pair(0xB0F3, &CNetProcessIn::OnB0F3));
    m_handlers.insert(std::make_pair(0x30FF, &CNetProcessIn::On30FF));
    m_handlers.insert(std::make_pair(0x3100, &CNetProcessIn::On3100));
    m_handlers.insert(std::make_pair(0xB0F2, &CNetProcessIn::OnB0F2));
    m_handlers.insert(std::make_pair(0xB0F4, &CNetProcessIn::OnB0F4));
    m_handlers.insert(std::make_pair(0x34B3, &CNetProcessIn::On34B3));
    m_handlers.insert(std::make_pair(0x3101, &CNetProcessIn::On3101));
    m_handlers.insert(std::make_pair(0x34B4, &CNetProcessIn::On34B4));
    m_handlers.insert(std::make_pair(0xB0F9, &CNetProcessIn::OnB0F9));
    m_handlers.insert(std::make_pair(0xB0F6, &CNetProcessIn::OnB0F6));
    m_handlers.insert(std::make_pair(0xB0FA, &CNetProcessIn::OnB0FA));
    m_handlers.insert(std::make_pair(0xB103, &CNetProcessIn::OnB103));
    m_handlers.insert(std::make_pair(0xB104, &CNetProcessIn::OnB104));
    m_handlers.insert(std::make_pair(0xB105, &CNetProcessIn::OnB105));
    m_handlers.insert(std::make_pair(0xB106, &CNetProcessIn::OnB106));
    m_handlers.insert(std::make_pair(0x3908, &CNetProcessIn::On3908));
    m_handlers.insert(std::make_pair(0xB107, &CNetProcessIn::OnB107));
    m_handlers.insert(std::make_pair(0xB0FB, &CNetProcessIn::OnB0FB));
    m_handlers.insert(std::make_pair(0x3102, &CNetProcessIn::On3102));
    m_handlers.insert(std::make_pair(0xB0FC, &CNetProcessIn::OnB0FC));
    m_handlers.insert(std::make_pair(0xB0FD, &CNetProcessIn::OnB0FD));
    m_handlers.insert(std::make_pair(0x3109, &CNetProcessIn::On3109));
    m_handlers.insert(std::make_pair(0x7110, &CNetProcessIn::On7110));
    m_handlers.insert(std::make_pair(0xB110, &CNetProcessIn::OnB110));
    m_handlers.insert(std::make_pair(0xB112, &CNetProcessIn::OnB112));
    m_handlers.insert(std::make_pair(0xB114, &CNetProcessIn::OnB114));
    m_handlers.insert(std::make_pair(0xB113, &CNetProcessIn::OnB113));
    m_handlers.insert(std::make_pair(0xB501, &CNetProcessIn::OnB501));
    m_handlers.insert(std::make_pair(0x30EF, &CNetProcessIn::On30EF));
    m_handlers.insert(std::make_pair(0x3305, &CNetProcessIn::On3305));
    m_handlers.insert(std::make_pair(0xB302, &CNetProcessIn::OnB302));
    m_handlers.insert(std::make_pair(0xB304, &CNetProcessIn::OnB304));
    m_handlers.insert(std::make_pair(0x7302, &CNetProcessIn::On7302));
    m_handlers.insert(std::make_pair(0xB30B, &CNetProcessIn::OnB30B));
    m_handlers.insert(std::make_pair(0xB308, &CNetProcessIn::OnB308));
    m_handlers.insert(std::make_pair(0xB309, &CNetProcessIn::OnB309));
    m_handlers.insert(std::make_pair(0xB30A, &CNetProcessIn::OnB30A));
    m_handlers.insert(std::make_pair(0x3B07, &CNetProcessIn::On3B07));
    m_handlers.insert(std::make_pair(0x3204, &CNetProcessIn::On3204));
    m_handlers.insert(std::make_pair(0xB155, &CNetProcessIn::OnB155));
    m_handlers.insert(std::make_pair(0x3156, &CNetProcessIn::On3156));
    m_handlers.insert(std::make_pair(0xB157, &CNetProcessIn::OnB157));
    m_handlers.insert(std::make_pair(0xB150, &CNetProcessIn::OnB150));
    m_handlers.insert(std::make_pair(0xB151, &CNetProcessIn::OnB151));
    m_handlers.insert(std::make_pair(0xB16A, &CNetProcessIn::OnB16A));
    m_handlers.insert(std::make_pair(0x3207, &CNetProcessIn::On3207));
    m_handlers.insert(std::make_pair(0xB0ED, &CNetProcessIn::OnB0ED));
    m_handlers.insert(std::make_pair(0x34BA, &CNetProcessIn::On34BA));
    m_handlers.insert(std::make_pair(0xB402, &CNetProcessIn::OnB402));
    m_handlers.insert(std::make_pair(0xFFC, &CNetProcessIn::OnFFC));
    m_handlers.insert(std::make_pair(0x2000, &CNetProcessIn::On2000));
    m_handlers.insert(std::make_pair(0xFFD, &CNetProcessIn::OnFFD));
    m_handlers.insert(std::make_pair(0xB05E, &CNetProcessIn::OnB05E));
    m_handlers.insert(std::make_pair(0x3078, &CNetProcessIn::On3078));
}


void CNetProcessIn::OnUpdateGameTime(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()

    CPSMission *pM = (CPSMission *) theApp.GetCurrentProcess();

    msg >> pM->m_wDay >> pM->m_byHour >> pM->m_byMin;

    if (g_pCGInterface->field_0x7cd)
        return;

    CLocalTime_Sub localTimeSub;

    Fun_GetCfgGame()->m_LocalTime.FUN_008b01b0(&localTimeSub);

    Fun_GetCfgGame()->m_LocalTime.InitTimer(pM->m_dwRealTime, pM->m_wDay, pM->m_byHour, pM->m_byMin, 0);
}

void CNetProcessIn::On3809(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a6f50)(this, msg);
}

void CNetProcessIn::OnResetClient(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0086dab0)(this, msg);
}

void CNetProcessIn::OnLogoutAck(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0086db40)(this, msg);
}

void CNetProcessIn::Onb006(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0086dbd0)(this, msg);
}

void CNetProcessIn::On300a(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0086d550)(this, msg);
}

void CNetProcessIn::On3405(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0086e5b0)(this, msg);
}

void CNetProcessIn::On34b5(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0086e100)(this, msg);
}

void CNetProcessIn::On300c(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00874ea0)(this, msg);
}

void CNetProcessIn::On34a5(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a6580)(this, msg);
}

void CNetProcessIn::OnMyCharacterData(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a8c00)(this, msg);
}

void CNetProcessIn::On34a6(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008abba0)(this, msg);
}

void CNetProcessIn::On3020(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a6dc0)(this, msg);
}

void CNetProcessIn::OnObjectListBegin(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008ac0e0)(this, msg);
}

void CNetProcessIn::OnObjectListData(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008ac170)(this, msg);
}

void CNetProcessIn::OnObjectListEnd(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008ac3d0)(this, msg);
}

void CNetProcessIn::OnChestDataBegin(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a74f0)(this, msg);
}

void CNetProcessIn::OnChestDataData(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a8c10)(this, msg);
}

void CNetProcessIn::OnChestDataEnd(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a9100)(this, msg);
}

void CNetProcessIn::OnObjectEntered(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a6ca0)(this, msg);
}

void CNetProcessIn::OnObjectLeft(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a6cc0)(this, msg);
}

void CNetProcessIn::On3076(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a6640)(this, msg);
}

void CNetProcessIn::On30bf(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a80a0)(this, msg);
}

void CNetProcessIn::Onb0cb(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a7720)(this, msg);
}

void CNetProcessIn::Onb03c(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a8ea0)(this, msg);
}

void CNetProcessIn::On3092(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a7550)(this, msg);
}

void CNetProcessIn::On30df(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008a7630)(this, msg);
}

void CNetProcessIn::On30cd(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881090)(this, msg);
}

void CNetProcessIn::On30ce(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881100)(this, msg);
}

void CNetProcessIn::On30d3(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881170)(this, msg);
}

void CNetProcessIn::On30C1(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A8FC0)(this, msg);
}

void CNetProcessIn::On30C2(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A9000)(this, msg);
}

void CNetProcessIn::On30C3(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7870)(this, msg);
}

void CNetProcessIn::On30C8(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A6650)(this, msg);
}

void CNetProcessIn::OnB0C6(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7A70)(this, msg);
}

void CNetProcessIn::On30C9(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008AA340)(this, msg);
}

void CNetProcessIn::On30E7(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00883B10)(this, msg);
}

void CNetProcessIn::OnB0C7(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7AC0)(this, msg);
}

void CNetProcessIn::On30CA(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7690)(this, msg);
}

void CNetProcessIn::OnB116(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7B30)(this, msg);
}

void CNetProcessIn::OnB117(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7B80)(this, msg);
}

void CNetProcessIn::OnB420(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7D20)(this, msg);
}

void CNetProcessIn::On30D4(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00889D90)(this, msg);
}

void CNetProcessIn::On3054(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7020)(this, msg);
}

void CNetProcessIn::On3056(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A97C0)(this, msg);
}

void CNetProcessIn::On304E(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A70D0)(this, msg);
}

void CNetProcessIn::On3052(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008ADF50)(this, msg);
}

void CNetProcessIn::On3057(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A9E30)(this, msg);
}

void CNetProcessIn::OnB045(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0088B200)(this, msg);
}

void CNetProcessIn::On303D(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880F80)(this, msg);
}

void CNetProcessIn::On30D2(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008ADD60)(this, msg);
}

void CNetProcessIn::On30CF(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008726E0)(this, msg);
}

void CNetProcessIn::On3011(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872710)(this, msg);
}

void CNetProcessIn::On3058(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872740)(this, msg);
}

void CNetProcessIn::OnB025(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00877340)(this, msg);
}

void CNetProcessIn::OnChatReceive(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
#if 1
    std::n_wstring senderW;
    std::n_wstring messageW;
    std::n_string messageA;
    std::n_string senderA;

    int entityId;
    bool bIsFromMyself = false;

    ChatType chatType;

    msg >> chatType;

    switch (chatType) {
        case CHAT_All:
        case CHAT_AllGM: {
            msg >> entityId >> messageA;

            messageW = acp_n_decode(messageA);

            CIGIDObject *pObject = GetCharacterObjectByID_MAYBE(entityId);

            if (pObject == NULL) {
                senderW = L"???";
            } else {
                if (pObject->IsSame(GFX_RUNTIME_CLASS(CICPlayer)))
                    return;

                senderW = pObject->GetName();

                if (pObject->IsKindOf(GFX_RUNTIME_CLASS(CICUser))) {
                    printf("Job type is %d\n", reinterpret_cast<CICUser *>(pObject)->GetJobType());

                    if (reinterpret_cast<CICUser *>(pObject)->GetJobType() != TRIJOB_NOJOB) {
                        senderW.insert(0, L"*");
                    }
                }
            }
            break;
        }

        default: {
            msg >> senderA >> messageA;

            messageW = acp_n_decode(messageA);
            senderW = acp_n_decode(senderA);

            if (senderW == g_pCICPlayer->GetCharName())
                return;

            break;
        }

        case CHAT_Party : {
            msg >> senderA >> messageA;

            senderW = acp_n_decode(senderA);
            messageW = acp_n_decode(messageA);

            if (g_pCICPlayer->GetName() == senderW)
                return;

            if(g_pCICPlayer->GetJobType() != TRIJOB_NOJOB) {
                senderW.insert(0, L"*");
            }
            break;
        }

        case CHAT_Global: {
            msg >> senderA >> messageA;

            messageW = acp_n_decode(messageA);

            if (senderA.length() == 0) {
                senderW = L"???";
            } else {
                senderW = acp_n_decode(senderA);
            }

            if (g_pCICPlayer->GetCharName() == senderW) {
                bIsFromMyself = true;
            }

            break;
        }

        case CHAT_Notice: {
            msg >> messageA;
            messageW = acp_n_decode(messageA);
            bIsFromMyself = false;
            break;
        }

        case CHAT_Stall: {
            msg >> senderA >> messageA;

            messageW = acp_n_decode(messageA);
            senderW = acp_n_decode(senderA);

            if (g_pCICPlayer->GetName() == senderW)
                return;

            break;
        }

        case CHAT_NPC: {
            msg >> entityId >> messageA;

            CIGIDObject *pObject = GetCharacterObjectByID_MAYBE(entityId);

            if (pObject == NULL) {
                senderW = L"???";
            } else {
                if (pObject->IsSame(GFX_RUNTIME_CLASS(CICPlayer))) {
                    senderW = reinterpret_cast<CICPlayer *>(pObject)->GetCharName();
                    bIsFromMyself = true;
                } else {
                    senderW = pObject->GetName();
                }
            }

            messageW = g_CTextStringManager->FUN_008c9bb0(messageW);

            if (pObject->IsKindOf(GFX_RUNTIME_CLASS(CICUser))) {
                chatType = CHAT_All;
            }

            break;
        }

        case CHAT_Academy: {
            msg >> senderA >> messageA;

            messageW = acp_n_decode(messageA);
            senderW = acp_n_decode(senderA);

            if (g_pCICPlayer->GetCharName() == senderW)
                return;


        }

    }

    if (g_pCICPlayer == NULL)
        return;


    if (senderW.length() == 0) {
        senderW = acp_n_decode(senderA);
    }

    if (messageW.length() == 0) {
        messageW = acp_n_decode(messageA);
    }

    WriteToChatWindow(chatType, senderW, entityId, messageW, bIsFromMyself);

#else
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00877810)(this, msg);
#endif
}

void CNetProcessIn::On3091(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7950)(this, msg);
}

void CNetProcessIn::On302D(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872010)(this, msg);
}

void CNetProcessIn::OnB021(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A5750)(this, msg);
}

void CNetProcessIn::OnB024(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A4EC0)(this, msg);
}

void CNetProcessIn::OnB023(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A4F80)(this, msg);
}

void CNetProcessIn::On3028(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A50E0)(this, msg);
}

void CNetProcessIn::OnB04F(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A51E0)(this, msg);
}

void CNetProcessIn::On30D0(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A5280)(this, msg);
}

void CNetProcessIn::On3200(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A52F0)(this, msg);
}

void CNetProcessIn::OnB070(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A5FD0)(this, msg);
}

void CNetProcessIn::OnB071(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A4960)(this, msg);
}

void CNetProcessIn::OnB0BD(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A59E0)(this, msg);
}

void CNetProcessIn::On330F(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A4A30)(this, msg);
}

void CNetProcessIn::OnB0BE(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A5DA0)(this, msg);
}

void CNetProcessIn::OnB0BC(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A4B00)(this, msg);
}

void CNetProcessIn::OnB072(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A4DE0)(this, msg);
}

void CNetProcessIn::On30A6(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A4980)(this, msg);
}

void CNetProcessIn::On30D1(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A4990)(this, msg);
}

void CNetProcessIn::On3206(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A5360)(this, msg);
}

void CNetProcessIn::OnB0A1(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880BE0)(this, msg);
}

void CNetProcessIn::OnB0A2(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880CC0)(this, msg);
}

void CNetProcessIn::OnB203(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880E90)(this, msg);
}

void CNetProcessIn::OnB202(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880DB0)(this, msg);
}

void CNetProcessIn::OnB034(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087F370)(this, msg);
}

void CNetProcessIn::On3038(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A9260)(this, msg);
}

void CNetProcessIn::On3039(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A9560)(this, msg);
}

void CNetProcessIn::On3036(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A78B0)(this, msg);
}

void CNetProcessIn::OnB03E(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880A20)(this, msg);
}

void CNetProcessIn::OnB03F(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880A70)(this, msg);
}

void CNetProcessIn::On304D(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A75C0)(this, msg);
}

void CNetProcessIn::OnB04C(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087A7B0)(this, msg);
}

void CNetProcessIn::On3068(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00873990)(this, msg);
}

void CNetProcessIn::On305C(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008735D0)(this, msg);
}

void CNetProcessIn::On30E0(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881600)(this, msg);
}

void CNetProcessIn::On3040(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0088BF30)(this, msg);
}

void CNetProcessIn::On3201(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00882280)(this, msg);
}

void CNetProcessIn::On3041(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008822C0)(this, msg);
}

void CNetProcessIn::On3042(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008825D0)(this, msg);
}

void CNetProcessIn::On3153(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00882DE0)(this, msg);
}

void CNetProcessIn::On3154(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00882E50)(this, msg);
}

void CNetProcessIn::OnB046(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00888E30)(this, msg);
}

void CNetProcessIn::OnB04B(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00886AC0)(this, msg);
}

void CNetProcessIn::OnB0C0(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087FFD0)(this, msg);
}

void CNetProcessIn::OnB050(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880AC0)(this, msg);
}

void CNetProcessIn::OnB051(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880B10)(this, msg);
}

void CNetProcessIn::OnB0C5(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872590)(this, msg);
}

void CNetProcessIn::OnB059(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00883520)(this, msg);
}

void CNetProcessIn::OnB05A(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008809D0)(this, msg);
}

void CNetProcessIn::OnB074(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880B60)(this, msg);
}

void CNetProcessIn::On30EB(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881670)(this, msg);
}

void CNetProcessIn::OnB0EA(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881690)(this, msg);
}

void CNetProcessIn::OnB05B(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008727A0)(this, msg);
}

void CNetProcessIn::On34B1(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00871D50)(this, msg);
}

void CNetProcessIn::OnB060(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880010)(this, msg);
}

void CNetProcessIn::On3864(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00886B10)(this, msg);
}

void CNetProcessIn::On3065(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00883CC0)(this, msg);
}

void CNetProcessIn::OnB062(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008800B0)(this, msg);
}

void CNetProcessIn::OnB067(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880120)(this, msg);
}

void CNetProcessIn::OnB069(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00883F90)(this, msg);
}

void CNetProcessIn::OnB06A(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008840D0)(this, msg);
}

void CNetProcessIn::OnB06B(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008801E0)(this, msg);
}

void CNetProcessIn::OnB06C(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008841F0)(this, msg);
}

void CNetProcessIn::On706D(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00884660)(this, msg);
}

void CNetProcessIn::OnB06D(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008847D0)(this, msg);
}

void CNetProcessIn::OnB081(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880330)(this, msg);
}

void CNetProcessIn::On3080(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0088AA60)(this, msg);
}

void CNetProcessIn::On3085(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008803F0)(this, msg);
}

void CNetProcessIn::OnB082(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880430)(this, msg);
}

void CNetProcessIn::OnB083(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008804A0)(this, msg);
}

void CNetProcessIn::OnB084(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880520)(this, msg);
}

void CNetProcessIn::On3089(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880590)(this, msg);
}

void CNetProcessIn::On3086(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087FCB0)(this, msg);
}

void CNetProcessIn::On3087(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0088BB50)(this, msg);
}

void CNetProcessIn::On3088(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880840)(this, msg);
}

void CNetProcessIn::On30E8(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00880970)(this, msg);
}

void CNetProcessIn::On308C(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008806B0)(this, msg);
}

void CNetProcessIn::OnB0B1(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872040)(this, msg);
}

void CNetProcessIn::On30B8(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00873C10)(this, msg);
}

void CNetProcessIn::OnB0B2(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008720F0)(this, msg);
}

void CNetProcessIn::On30B9(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008721B0)(this, msg);
}

void CNetProcessIn::On30B7(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087A260)(this, msg);
}

void CNetProcessIn::OnB0B3(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00873FF0)(this, msg);
}

void CNetProcessIn::OnB0B5(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872450)(this, msg);
}

void CNetProcessIn::OnB0B4(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872500)(this, msg);
}

void CNetProcessIn::OnB0BA(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00878230)(this, msg);
}

void CNetProcessIn::On30BB(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00873D60)(this, msg);
}

void CNetProcessIn::OnB0A7(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7A20)(this, msg);
}

void CNetProcessIn::OnB010(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008743A0)(this, msg);
}

void CNetProcessIn::On30D6(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008811E0)(this, msg);
}

void CNetProcessIn::On30D7(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881280)(this, msg);
}

void CNetProcessIn::On30D5(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008812B0)(this, msg);
}

void CNetProcessIn::OnB0D8(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881450)(this, msg);
}

void CNetProcessIn::OnB0D9(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008814B0)(this, msg);
}

void CNetProcessIn::On30EC(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00884A30)(this, msg);
}

void CNetProcessIn::On30DC(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A7EE0)(this, msg);
}

void CNetProcessIn::OnB515(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881570)(this, msg);
}

void CNetProcessIn::On3514(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00884CA0)(this, msg);
}

void CNetProcessIn::On3CA2(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008ABCC0)(this, msg);
}

void CNetProcessIn::On30E6(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00884DD0)(this, msg);
}

void CNetProcessIn::OnB0E1(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008890B0)(this, msg);
}

void CNetProcessIn::OnB0E2(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00889210)(this, msg);
}

void CNetProcessIn::OnB0E3(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00889370)(this, msg);
}

void CNetProcessIn::OnB0E4(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0088A130)(this, msg);
}

void CNetProcessIn::OnB0E5(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008830F0)(this, msg);
}

void CNetProcessIn::OnB0E6(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881740)(this, msg);
}

void CNetProcessIn::OnB0F0(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008852C0)(this, msg);
}

void CNetProcessIn::On38F5(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00887330)(this, msg);
}

void CNetProcessIn::OnB0F1(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881820)(this, msg);
}

void CNetProcessIn::OnB0F8(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881890)(this, msg);
}

void CNetProcessIn::OnB0F3(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881950)(this, msg);
}

void CNetProcessIn::On30FF(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0088A420)(this, msg);
}

void CNetProcessIn::On3100(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008819B0)(this, msg);
}

void CNetProcessIn::OnB0F2(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008819E0)(this, msg);
}

void CNetProcessIn::OnB0F4(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881C60)(this, msg);
}

void CNetProcessIn::On34B3(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087FCD0)(this, msg);
}

void CNetProcessIn::On3101(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00883060)(this, msg);
}

void CNetProcessIn::On34B4(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00887300)(this, msg);
}

void CNetProcessIn::OnB0F9(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881A70)(this, msg);
}

void CNetProcessIn::OnB0F6(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881AE0)(this, msg);
}

void CNetProcessIn::OnB0FA(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881BD0)(this, msg);
}

void CNetProcessIn::OnB103(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00889680)(this, msg);
}

void CNetProcessIn::OnB104(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881CB0)(this, msg);
}

void CNetProcessIn::OnB105(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008857B0)(this, msg);
}

void CNetProcessIn::OnB106(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881D00)(this, msg);
}

void CNetProcessIn::On3908(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008897C0)(this, msg);
}

void CNetProcessIn::OnB107(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881D80)(this, msg);
}

void CNetProcessIn::OnB0FB(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881DD0)(this, msg);
}

void CNetProcessIn::On3102(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087FD00)(this, msg);
}

void CNetProcessIn::OnB0FC(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881E20)(this, msg);
}

void CNetProcessIn::OnB0FD(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881E70)(this, msg);
}

void CNetProcessIn::On3109(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087FD90)(this, msg);
}

void CNetProcessIn::On7110(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00885920)(this, msg);
}

void CNetProcessIn::OnB110(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881EC0)(this, msg);
}

void CNetProcessIn::OnB112(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881F30)(this, msg);
}

void CNetProcessIn::OnB114(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00885AE0)(this, msg);
}

void CNetProcessIn::OnB113(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881F80)(this, msg);
}

void CNetProcessIn::OnB501(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00885C20)(this, msg);
}

void CNetProcessIn::On30EF(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0088A770)(this, msg);
}

void CNetProcessIn::On3305(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087FDD0)(this, msg);
}

void CNetProcessIn::OnB302(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00885E50)(this, msg);
}

void CNetProcessIn::OnB304(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00881FD0)(this, msg);
}

void CNetProcessIn::On7302(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00886000)(this, msg);
}

void CNetProcessIn::OnB30B(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00882030)(this, msg);
}

void CNetProcessIn::OnB308(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00886170)(this, msg);
}

void CNetProcessIn::OnB309(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008820B0)(this, msg);
}

void CNetProcessIn::OnB30A(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00882130)(this, msg);
}

void CNetProcessIn::On3B07(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00886310)(this, msg);
}

void CNetProcessIn::On3204(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087FE00)(this, msg);
}

void CNetProcessIn::OnB155(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872810)(this, msg);
}

void CNetProcessIn::On3156(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872810)(this, msg);
}

void CNetProcessIn::OnB157(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872940)(this, msg);
}

void CNetProcessIn::OnB150(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008729E0)(this, msg);
}

void CNetProcessIn::OnB151(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872CD0)(this, msg);
}

void CNetProcessIn::OnB16A(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00872FA0)(this, msg);
}

void CNetProcessIn::On3207(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0088A820)(this, msg);
}

void CNetProcessIn::OnB0ED(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008821C0)(this, msg);
}

void CNetProcessIn::On34BA(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008867A0)(this, msg);
}

void CNetProcessIn::OnB402(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008A5230)(this, msg);
}

void CNetProcessIn::OnFFC(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x008832A0)(this, msg);
}

void CNetProcessIn::On2000(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00888DA0)(this, msg);
}

void CNetProcessIn::OnFFD(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x0087FE40)(this, msg);
}

void CNetProcessIn::OnB05E(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00878B40)(this, msg);
}

void CNetProcessIn::On3078(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessIn *, CMsgStreamBuffer &)>(0x00873140)(this, msg);
}

