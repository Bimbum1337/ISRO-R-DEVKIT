#include "NetProcessThird.h"

#ifdef CONFIG_DEBUG_NET
#define DEBUG_PRINT_CALL() printf("%s\n", __FUNCTION__);
#else
#define DEBUG_PRINT_CALL()
#endif

void CNetProcessThird::RegisterPacketHandlers() {
    m_handlers.insert(std::make_pair(0x3209, &CNetProcessThird::On3209));
    m_handlers.insert(std::make_pair(0x320a, &CNetProcessThird::On320a));
    m_handlers.insert(std::make_pair(0x320b, &CNetProcessThird::On320b));
    m_handlers.insert(std::make_pair(0xb11a, &CNetProcessThird::Onb11a));
    m_handlers.insert(std::make_pair(0x3159, &CNetProcessThird::On3159));
    m_handlers.insert(std::make_pair(0x315a, &CNetProcessThird::On315a));
    m_handlers.insert(std::make_pair(0x315b, &CNetProcessThird::On315b));
    m_handlers.insert(std::make_pair(0x315c, &CNetProcessThird::On315c));
    m_handlers.insert(std::make_pair(0x315d, &CNetProcessThird::On315d));
    m_handlers.insert(std::make_pair(0x315e, &CNetProcessThird::On315e));
    m_handlers.insert(std::make_pair(0x3161, &CNetProcessThird::On3161));
    m_handlers.insert(std::make_pair(0xb15f, &CNetProcessThird::Onb15f));
    m_handlers.insert(std::make_pair(0xb160, &CNetProcessThird::Onb160));
    m_handlers.insert(std::make_pair(0x325c, &CNetProcessThird::On325c));
    m_handlers.insert(std::make_pair(0x325d, &CNetProcessThird::On325d));
    m_handlers.insert(std::make_pair(0x325e, &CNetProcessThird::On325e));
    m_handlers.insert(std::make_pair(0xb121, &CNetProcessThird::Onb121));
    m_handlers.insert(std::make_pair(0xb30d, &CNetProcessThird::Onb30d));
    m_handlers.insert(std::make_pair(0xb168, &CNetProcessThird::Onb168));
    m_handlers.insert(std::make_pair(0xb470, &CNetProcessThird::Onb470));
    m_handlers.insert(std::make_pair(0x3c81, &CNetProcessThird::On3c81));
    m_handlers.insert(std::make_pair(0xb471, &CNetProcessThird::Onb471));
    m_handlers.insert(std::make_pair(0xb472, &CNetProcessThird::Onb472));
    m_handlers.insert(std::make_pair(0xb473, &CNetProcessThird::Onb473));
    m_handlers.insert(std::make_pair(0xb474, &CNetProcessThird::Onb474));
    m_handlers.insert(std::make_pair(0xb475, &CNetProcessThird::Onb475));
    m_handlers.insert(std::make_pair(0xb476, &CNetProcessThird::Onb476));
    m_handlers.insert(std::make_pair(0xb477, &CNetProcessThird::Onb477));
    m_handlers.insert(std::make_pair(0xb478, &CNetProcessThird::Onb478));
    m_handlers.insert(std::make_pair(0x3c80, &CNetProcessThird::On3c80));
    m_handlers.insert(std::make_pair(0x3c82, &CNetProcessThird::On3c82));
    m_handlers.insert(std::make_pair(0x3c86, &CNetProcessThird::On3c86));
    m_handlers.insert(std::make_pair(0xb483, &CNetProcessThird::Onb483));
    m_handlers.insert(std::make_pair(0x3c87, &CNetProcessThird::On3c87));
    m_handlers.insert(std::make_pair(0x3122, &CNetProcessThird::On3122));
    m_handlers.insert(std::make_pair(0x34aa, &CNetProcessThird::On34aa));
    m_handlers.insert(std::make_pair(0x325f, &CNetProcessThird::On325f));
    m_handlers.insert(std::make_pair(0x3261, &CNetProcessThird::On3261));
    m_handlers.insert(std::make_pair(0x34be, &CNetProcessThird::On34be));
    m_handlers.insert(std::make_pair(0x34d2, &CNetProcessThird::On34d2));
    m_handlers.insert(std::make_pair(0xb4df, &CNetProcessThird::Onb4df));
    m_handlers.insert(std::make_pair(0xb4e0, &CNetProcessThird::Onb4e0));
    m_handlers.insert(std::make_pair(0x34e1, &CNetProcessThird::On34e1));
    m_handlers.insert(std::make_pair(0x34f2, &CNetProcessThird::On34f2));
    m_handlers.insert(std::make_pair(0xb519, &CNetProcessThird::Onb519));
    m_handlers.insert(std::make_pair(0x751a, &CNetProcessThird::On751a));
    m_handlers.insert(std::make_pair(0xb51a, &CNetProcessThird::Onb51a));
    m_handlers.insert(std::make_pair(0xb51c, &CNetProcessThird::Onb51c));
    m_handlers.insert(std::make_pair(0xb51d, &CNetProcessThird::Onb51d));
    m_handlers.insert(std::make_pair(0x351e, &CNetProcessThird::On351e));
    m_handlers.insert(std::make_pair(0xb50c, &CNetProcessThird::Onb50c));
    m_handlers.insert(std::make_pair(0xb50e, &CNetProcessThird::Onb50e));
    m_handlers.insert(std::make_pair(0xb507, &CNetProcessThird::Onb507));
    m_handlers.insert(std::make_pair(0xb508, &CNetProcessThird::Onb508));
    m_handlers.insert(std::make_pair(0xb509, &CNetProcessThird::Onb509));
    m_handlers.insert(std::make_pair(0x350d, &CNetProcessThird::On350d));
    m_handlers.insert(std::make_pair(0xb506, &CNetProcessThird::Onb506));
    m_handlers.insert(std::make_pair(0xb50a, &CNetProcessThird::Onb50a));
    m_handlers.insert(std::make_pair(0xb50b, &CNetProcessThird::Onb50b));
    m_handlers.insert(std::make_pair(0x3530, &CNetProcessThird::On3530));
    m_handlers.insert(std::make_pair(0x3531, &CNetProcessThird::On3531));
    m_handlers.insert(std::make_pair(0x3532, &CNetProcessThird::On3532));
}


void CNetProcessThird::On3209(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00898f80)(this, msg);
}

void CNetProcessThird::On320a(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00898ff0)(this, msg);
}

void CNetProcessThird::On320b(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899060)(this, msg);
}

void CNetProcessThird::Onb11a(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008990c0)(this, msg);
}

void CNetProcessThird::On3159(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008992b0)(this, msg);
}

void CNetProcessThird::On315a(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899350)(this, msg);
}

void CNetProcessThird::On315b(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008993b0)(this, msg);
}

void CNetProcessThird::On315c(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899480)(this, msg);
}

void CNetProcessThird::On315d(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008994e0)(this, msg);
}

void CNetProcessThird::On315e(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899530)(this, msg);
}

void CNetProcessThird::On3161(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899420)(this, msg);
}

void CNetProcessThird::Onb15f(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089b660)(this, msg);
}

void CNetProcessThird::Onb160(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899580)(this, msg);
}

void CNetProcessThird::On325c(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899cf0)(this, msg);
}

void CNetProcessThird::On325d(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899e60)(this, msg);
}

void CNetProcessThird::On325e(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089f710)(this, msg);
}

void CNetProcessThird::Onb121(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008a1360)(this, msg);
}

void CNetProcessThird::Onb30d(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089c3a0)(this, msg);
}

void CNetProcessThird::Onb168(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008995e0)(this, msg);
}

void CNetProcessThird::Onb470(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899630)(this, msg);
}

void CNetProcessThird::On3c81(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008986c0)(this, msg);
}

void CNetProcessThird::Onb471(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899730)(this, msg);
}

void CNetProcessThird::Onb472(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008997a0)(this, msg);
}

void CNetProcessThird::Onb473(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899800)(this, msg);
}

void CNetProcessThird::Onb474(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899850)(this, msg);
}

void CNetProcessThird::Onb475(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008998a0)(this, msg);
}

void CNetProcessThird::Onb476(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008998f0)(this, msg);
}

void CNetProcessThird::Onb477(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899940)(this, msg);
}

void CNetProcessThird::Onb478(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089c620)(this, msg);
}

void CNetProcessThird::On3c80(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008a2110)(this, msg);
}

void CNetProcessThird::On3c82(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089bcc0)(this, msg);
}

void CNetProcessThird::On3c86(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089bf00)(this, msg);
}

void CNetProcessThird::Onb483(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089b7b0)(this, msg);
}

void CNetProcessThird::On3c87(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089bae0)(this, msg);
}

void CNetProcessThird::On3122(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008999b0)(this, msg);
}

void CNetProcessThird::On34aa(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x00899f40)(this, msg);
}

void CNetProcessThird::On325f(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a0d0)(this, msg);
}

void CNetProcessThird::On3261(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a1a0)(this, msg);
}

void CNetProcessThird::On34be(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a250)(this, msg);
}

void CNetProcessThird::On34d2(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089f860)(this, msg);
}

void CNetProcessThird::Onb4df(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a310)(this, msg);
}

void CNetProcessThird::Onb4e0(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a4c0)(this, msg);
}

void CNetProcessThird::On34e1(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a540)(this, msg);
}

void CNetProcessThird::On34f2(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089dbf0)(this, msg);
}

void CNetProcessThird::Onb519(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a590)(this, msg);
}

void CNetProcessThird::On751a(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089f010)(this, msg);
}

void CNetProcessThird::Onb51a(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a6c0)(this, msg);
}

void CNetProcessThird::Onb51c(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a710)(this, msg);
}

void CNetProcessThird::Onb51d(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a760)(this, msg);
}

void CNetProcessThird::On351e(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a7b0)(this, msg);
}

void CNetProcessThird::Onb50c(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a820)(this, msg);
}

void CNetProcessThird::Onb50e(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008a38a0)(this, msg);
}

void CNetProcessThird::Onb507(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089a9a0)(this, msg);
}

void CNetProcessThird::Onb508(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008a31d0)(this, msg);
}

void CNetProcessThird::Onb509(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089aa00)(this, msg);
}

void CNetProcessThird::On350d(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x008a3470)(this, msg);
}

void CNetProcessThird::Onb506(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089ab50)(this, msg);
}

void CNetProcessThird::Onb50a(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089ac00)(this, msg);
}

void CNetProcessThird::Onb50b(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089ad90)(this, msg);
}

void CNetProcessThird::On3530(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089ae80)(this, msg);
}

void CNetProcessThird::On3531(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089afa0)(this, msg);
}

void CNetProcessThird::On3532(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessThird *, CMsgStreamBuffer &)>(0x0089b000)(this, msg);
}
