#pragma once

#include <BSLib/BSLib.h>

#include <Test/Test.h>
#include <ClientNet/MsgStreamBuffer.h>

class CNetProcessThird : public CObjChild {
public:
    void RegisterPacketHandlers();


private:
    /// \address 00898f80
    void On3209(CMsgStreamBuffer &msg);

    /// \address 00898ff0
    void On320a(CMsgStreamBuffer &msg);

    /// \address 00899060
    void On320b(CMsgStreamBuffer &msg);

    /// \address 008990c0
    void Onb11a(CMsgStreamBuffer &msg);

    /// \address 008992b0
    void On3159(CMsgStreamBuffer &msg);

    /// \address 00899350
    void On315a(CMsgStreamBuffer &msg);

    /// \address 008993b0
    void On315b(CMsgStreamBuffer &msg);

    /// \address 00899480
    void On315c(CMsgStreamBuffer &msg);

    /// \address 008994e0
    void On315d(CMsgStreamBuffer &msg);

    /// \address 00899530
    void On315e(CMsgStreamBuffer &msg);

    /// \address 00899420
    void On3161(CMsgStreamBuffer &msg);

    /// \address 0089b660
    void Onb15f(CMsgStreamBuffer &msg);

    /// \address 00899580
    void Onb160(CMsgStreamBuffer &msg);

    /// \address 00899cf0
    void On325c(CMsgStreamBuffer &msg);

    /// \address 00899e60
    void On325d(CMsgStreamBuffer &msg);

    /// \address 0089f710
    void On325e(CMsgStreamBuffer &msg);

    /// \address 008a1360
    void Onb121(CMsgStreamBuffer &msg);

    /// \address 0089c3a0
    void Onb30d(CMsgStreamBuffer &msg);

    /// \address 008995e0
    void Onb168(CMsgStreamBuffer &msg);

    /// \address 00899630
    void Onb470(CMsgStreamBuffer &msg);

    /// \address 008986c0
    void On3c81(CMsgStreamBuffer &msg);

    /// \address 00899730
    void Onb471(CMsgStreamBuffer &msg);

    /// \address 008997a0
    void Onb472(CMsgStreamBuffer &msg);

    /// \address 00899800
    void Onb473(CMsgStreamBuffer &msg);

    /// \address 00899850
    void Onb474(CMsgStreamBuffer &msg);

    /// \address 008998a0
    void Onb475(CMsgStreamBuffer &msg);

    /// \address 008998f0
    void Onb476(CMsgStreamBuffer &msg);

    /// \address 00899940
    void Onb477(CMsgStreamBuffer &msg);

    /// \address 0089c620
    void Onb478(CMsgStreamBuffer &msg);

    /// \address 008a2110
    void On3c80(CMsgStreamBuffer &msg);

    /// \address 0089bcc0
    void On3c82(CMsgStreamBuffer &msg);

    /// \address 0089bf00
    void On3c86(CMsgStreamBuffer &msg);

    /// \address 0089b7b0
    void Onb483(CMsgStreamBuffer &msg);

    /// \address 0089bae0
    void On3c87(CMsgStreamBuffer &msg);

    /// \address 008999b0
    void On3122(CMsgStreamBuffer &msg);

    /// \address 00899f40
    void On34aa(CMsgStreamBuffer &msg);

    /// \address 0089a0d0
    void On325f(CMsgStreamBuffer &msg);

    /// \address 0089a1a0
    void On3261(CMsgStreamBuffer &msg);

    /// \address 0089a250
    void On34be(CMsgStreamBuffer &msg);

    /// \address 0089f860
    void On34d2(CMsgStreamBuffer &msg);

    /// \address 0089a310
    void Onb4df(CMsgStreamBuffer &msg);

    /// \address 0089a4c0
    void Onb4e0(CMsgStreamBuffer &msg);

    /// \address 0089a540
    void On34e1(CMsgStreamBuffer &msg);

    /// \address 0089dbf0
    void On34f2(CMsgStreamBuffer &msg);

    /// \address 0089a590
    void Onb519(CMsgStreamBuffer &msg);

    /// \address 0089f010
    void On751a(CMsgStreamBuffer &msg);

    /// \address 0089a6c0
    void Onb51a(CMsgStreamBuffer &msg);

    /// \address 0089a710
    void Onb51c(CMsgStreamBuffer &msg);

    /// \address 0089a760
    void Onb51d(CMsgStreamBuffer &msg);

    /// \address 0089a7b0
    void On351e(CMsgStreamBuffer &msg);

    /// \address 0089a820
    void Onb50c(CMsgStreamBuffer &msg);

    /// \address 008a38a0
    void Onb50e(CMsgStreamBuffer &msg);

    /// \address 0089a9a0
    void Onb507(CMsgStreamBuffer &msg);

    /// \address 008a31d0
    void Onb508(CMsgStreamBuffer &msg);

    /// \address 0089aa00
    void Onb509(CMsgStreamBuffer &msg);

    /// \address 008a3470
    void On350d(CMsgStreamBuffer &msg);

    /// \address 0089ab50
    void Onb506(CMsgStreamBuffer &msg);

    /// \address 0089ac00
    void Onb50a(CMsgStreamBuffer &msg);

    /// \address 0089ad90
    void Onb50b(CMsgStreamBuffer &msg);

    /// \address 0089ae80
    void On3530(CMsgStreamBuffer &msg);

    /// \address 0089afa0
    void On3531(CMsgStreamBuffer &msg);

    /// \address 0089b000
    void On3532(CMsgStreamBuffer &msg);


private:
    std::n_hash_map<int, void (__thiscall CNetProcessThird::*)(CMsgStreamBuffer &)> m_handlers; // 0x20

    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_handlers, 0x20)
    END_FIXTURE()

    RUN_FIXTURE(CNetProcessThird)
};
