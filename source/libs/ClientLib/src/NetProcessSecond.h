#pragma once

#include <BSLib/BSLib.h>
#include <Test/Test.h>

class CNetProcessSecond : public CObjChild {

public:
    void RegisterPacketHandlers();


private:
    /// \address 0088d690
    void Onb118(CMsgStreamBuffer &msg);

    /// \address 0088d700
    void Onb119(CMsgStreamBuffer &msg);

    /// \address 0088f880
    void On3120(CMsgStreamBuffer &msg);

    /// \address 0088dad0
    void On320c(CMsgStreamBuffer &msg);

    /// \address 0088d570
    void On30da(CMsgStreamBuffer &msg);

    /// \address 0088d5c0
    void Onb0db(CMsgStreamBuffer &msg);

    /// \address 0088f630
    void Onb250(CMsgStreamBuffer &msg);

    /// \address 0088d160
    void Onb251(CMsgStreamBuffer &msg);

    /// \address 0088d1d0
    void On3253(CMsgStreamBuffer &msg);

    /// \address 0088eb10
    void On3255(CMsgStreamBuffer &msg);

    /// \address 0088e690
    void On3254(CMsgStreamBuffer &msg);

    /// \address 0088d390
    void Onb252(CMsgStreamBuffer &msg);

    /// \address 00895530
    void Onb30c(CMsgStreamBuffer &msg);

    /// \address 0088f9e0
    void Onb256(CMsgStreamBuffer &msg);

    /// \address 008905d0
    void On3256(CMsgStreamBuffer &msg);

    /// \address 00895810
    void On3257(CMsgStreamBuffer &msg);

    /// \address 0088d750
    void Onb258(CMsgStreamBuffer &msg);

    /// \address 0088d9c0
    void Onb259(CMsgStreamBuffer &msg);

    /// \address 0088da80
    void Onb25a(CMsgStreamBuffer &msg);

    /// \address 0088d840
    void On7030(CMsgStreamBuffer &msg);

    /// \address 0088d8c0
    void Onb030(CMsgStreamBuffer &msg);

    /// \address 0088d910
    void Onb031(CMsgStreamBuffer &msg);

    /// \address 0088dca0
    void Onb461(CMsgStreamBuffer &msg);

    /// \address 0088dec0
    void Onb463(CMsgStreamBuffer &msg);

    /// \address 0088df60
    void Onb462(CMsgStreamBuffer &msg);

    /// \address 008907f0
    void Onb47a(CMsgStreamBuffer &msg);

    /// \address 00890960
    void Onb47b(CMsgStreamBuffer &msg);

    /// \address 0088df80
    void Onb47c(CMsgStreamBuffer &msg);

    /// \address 00890ab0
    void Onb47d(CMsgStreamBuffer &msg);

    /// \address 00890fa0
    void On747e(CMsgStreamBuffer &msg);

    /// \address 00892c50
    void Onb47e(CMsgStreamBuffer &msg);

    /// \address 0088fd00
    void Onb0ff(CMsgStreamBuffer &msg);

    /// \address 00890210
    void On3103(CMsgStreamBuffer &msg);

    /// \address 00895bb0
    void On385f(CMsgStreamBuffer &msg);

    /// \address 0088e1c0
    void Onb05d(CMsgStreamBuffer &msg);

    /// \address 0088e090
    void On3077(CMsgStreamBuffer &msg);

    /// \address 0088e210
    void Onb4d4(CMsgStreamBuffer &msg);

    /// \address 00891080
    void On34d5(CMsgStreamBuffer &msg);

    /// \address 00891250
    void Onb516(CMsgStreamBuffer &msg);


private:
    std::n_hash_map<int, void (__thiscall CNetProcessSecond::*)(CMsgStreamBuffer &)> m_handlers; // 0x20

    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_handlers, 0x20)
    END_FIXTURE()

    RUN_FIXTURE(CNetProcessSecond)
};
