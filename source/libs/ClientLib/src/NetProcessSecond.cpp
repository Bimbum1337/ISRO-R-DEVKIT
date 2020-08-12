#include "NetProcessSecond.h"

#ifdef CONFIG_DEBUG_NET
#define DEBUG_PRINT_CALL() printf("%s\n", __FUNCTION__);
#else
#define DEBUG_PRINT_CALL()
#endif

void CNetProcessSecond::RegisterPacketHandlers() {
    m_handlers.insert(std::make_pair(0xb118, &CNetProcessSecond::Onb118));
    m_handlers.insert(std::make_pair(0xb119, &CNetProcessSecond::Onb119));
    m_handlers.insert(std::make_pair(0x3120, &CNetProcessSecond::On3120));
    m_handlers.insert(std::make_pair(0x320c, &CNetProcessSecond::On320c));
    m_handlers.insert(std::make_pair(0x30da, &CNetProcessSecond::On30da));
    m_handlers.insert(std::make_pair(0xb0db, &CNetProcessSecond::Onb0db));
    m_handlers.insert(std::make_pair(0xb250, &CNetProcessSecond::Onb250));
    m_handlers.insert(std::make_pair(0xb251, &CNetProcessSecond::Onb251));
    m_handlers.insert(std::make_pair(0x3253, &CNetProcessSecond::On3253));
    m_handlers.insert(std::make_pair(0x3255, &CNetProcessSecond::On3255));
    m_handlers.insert(std::make_pair(0x3254, &CNetProcessSecond::On3254));
    m_handlers.insert(std::make_pair(0xb252, &CNetProcessSecond::Onb252));
    m_handlers.insert(std::make_pair(0xb30c, &CNetProcessSecond::Onb30c));
    m_handlers.insert(std::make_pair(0xb256, &CNetProcessSecond::Onb256));
    m_handlers.insert(std::make_pair(0x3256, &CNetProcessSecond::On3256));
    m_handlers.insert(std::make_pair(0x3257, &CNetProcessSecond::On3257));
    m_handlers.insert(std::make_pair(0xb258, &CNetProcessSecond::Onb258));
    m_handlers.insert(std::make_pair(0xb259, &CNetProcessSecond::Onb259));
    m_handlers.insert(std::make_pair(0xb25a, &CNetProcessSecond::Onb25a));
    m_handlers.insert(std::make_pair(0x7030, &CNetProcessSecond::On7030));
    m_handlers.insert(std::make_pair(0xb030, &CNetProcessSecond::Onb030));
    m_handlers.insert(std::make_pair(0xb031, &CNetProcessSecond::Onb031));
    m_handlers.insert(std::make_pair(0xb461, &CNetProcessSecond::Onb461));
    m_handlers.insert(std::make_pair(0xb463, &CNetProcessSecond::Onb463));
    m_handlers.insert(std::make_pair(0xb462, &CNetProcessSecond::Onb462));
    m_handlers.insert(std::make_pair(0xb47a, &CNetProcessSecond::Onb47a));
    m_handlers.insert(std::make_pair(0xb47b, &CNetProcessSecond::Onb47b));
    m_handlers.insert(std::make_pair(0xb47c, &CNetProcessSecond::Onb47c));
    m_handlers.insert(std::make_pair(0xb47d, &CNetProcessSecond::Onb47d));
    m_handlers.insert(std::make_pair(0x747e, &CNetProcessSecond::On747e));
    m_handlers.insert(std::make_pair(0xb47e, &CNetProcessSecond::Onb47e));
    m_handlers.insert(std::make_pair(0xb0ff, &CNetProcessSecond::Onb0ff));
    m_handlers.insert(std::make_pair(0x3103, &CNetProcessSecond::On3103));
    m_handlers.insert(std::make_pair(0x385f, &CNetProcessSecond::On385f));
    m_handlers.insert(std::make_pair(0xb05d, &CNetProcessSecond::Onb05d));
    m_handlers.insert(std::make_pair(0x3077, &CNetProcessSecond::On3077));
    m_handlers.insert(std::make_pair(0xb4d4, &CNetProcessSecond::Onb4d4));
    m_handlers.insert(std::make_pair(0x34d5, &CNetProcessSecond::On34d5));
    m_handlers.insert(std::make_pair(0xb516, &CNetProcessSecond::Onb516));
}


void CNetProcessSecond::Onb118(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d690)(this, msg);
}

void CNetProcessSecond::Onb119(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d700)(this, msg);
}

void CNetProcessSecond::On3120(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088f880)(this, msg);
}

void CNetProcessSecond::On320c(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088dad0)(this, msg);
}

void CNetProcessSecond::On30da(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d570)(this, msg);
}

void CNetProcessSecond::Onb0db(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d5c0)(this, msg);
}

void CNetProcessSecond::Onb250(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088f630)(this, msg);
}

void CNetProcessSecond::Onb251(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d160)(this, msg);
}

void CNetProcessSecond::On3253(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d1d0)(this, msg);
}

void CNetProcessSecond::On3255(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088eb10)(this, msg);
}

void CNetProcessSecond::On3254(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088e690)(this, msg);
}

void CNetProcessSecond::Onb252(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d390)(this, msg);
}

void CNetProcessSecond::Onb30c(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00895530)(this, msg);
}

void CNetProcessSecond::Onb256(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088f9e0)(this, msg);
}

void CNetProcessSecond::On3256(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x008905d0)(this, msg);
}

void CNetProcessSecond::On3257(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00895810)(this, msg);
}

void CNetProcessSecond::Onb258(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d750)(this, msg);
}

void CNetProcessSecond::Onb259(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d9c0)(this, msg);
}

void CNetProcessSecond::Onb25a(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088da80)(this, msg);
}

void CNetProcessSecond::On7030(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d840)(this, msg);
}

void CNetProcessSecond::Onb030(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d8c0)(this, msg);
}

void CNetProcessSecond::Onb031(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088d910)(this, msg);
}

void CNetProcessSecond::Onb461(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088dca0)(this, msg);
}

void CNetProcessSecond::Onb463(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088dec0)(this, msg);
}

void CNetProcessSecond::Onb462(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088df60)(this, msg);
}

void CNetProcessSecond::Onb47a(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x008907f0)(this, msg);
}

void CNetProcessSecond::Onb47b(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00890960)(this, msg);
}

void CNetProcessSecond::Onb47c(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088df80)(this, msg);
}

void CNetProcessSecond::Onb47d(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00890ab0)(this, msg);
}

void CNetProcessSecond::On747e(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00890fa0)(this, msg);
}

void CNetProcessSecond::Onb47e(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00892c50)(this, msg);
}

void CNetProcessSecond::Onb0ff(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088fd00)(this, msg);
}

void CNetProcessSecond::On3103(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00890210)(this, msg);
}

void CNetProcessSecond::On385f(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00895bb0)(this, msg);
}

void CNetProcessSecond::Onb05d(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088e1c0)(this, msg);
}

void CNetProcessSecond::On3077(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088e090)(this, msg);
}

void CNetProcessSecond::Onb4d4(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x0088e210)(this, msg);
}

void CNetProcessSecond::On34d5(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00891080)(this, msg);
}

void CNetProcessSecond::Onb516(CMsgStreamBuffer &msg) {
    DEBUG_PRINT_CALL()
    reinterpret_cast<void (__thiscall *)(CNetProcessSecond *, CMsgStreamBuffer &)>(0x00891250)(this, msg);
}
