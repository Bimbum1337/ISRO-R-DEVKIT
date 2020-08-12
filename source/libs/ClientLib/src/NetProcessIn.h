#pragma once

#include "GObj.h"
#include "Test/Test.h"

class CNetProcessIn : public CGObj {
    // Note: This class is "broken" at the original code
    //       There is no override for GFX_RUNTIME_CLASS or MESSAGEMAP

    // No virtuals, no overrides

public:
    void RegisterPacketHandlers();

private:
    /// \address 008a6e80
    void OnUpdateGameTime(CMsgStreamBuffer &msg);

    /// \address 008a6f50
    void On3809(CMsgStreamBuffer &msg);

    /// \address 0086dab0
    void OnResetClient(CMsgStreamBuffer &msg);

    /// \address 0086db40
    void OnLogoutAck(CMsgStreamBuffer &msg);

    /// \address 0086dbd0
    void Onb006(CMsgStreamBuffer &msg);

    /// \address 0086d550
    void On300a(CMsgStreamBuffer &msg);

    /// \address 0086e5b0
    void On3405(CMsgStreamBuffer &msg);

    /// \address 0086e100
    void On34b5(CMsgStreamBuffer &msg);

    /// \address 00874ea0
    void On300c(CMsgStreamBuffer &msg);

    /// \address 008a6580
    void On34a5(CMsgStreamBuffer &msg);

    /// \address 008a8c00
    void OnMyCharacterData(CMsgStreamBuffer &msg);

    /// \address 008abba0
    void On34a6(CMsgStreamBuffer &msg);

    /// \address 008a6dc0
    void On3020(CMsgStreamBuffer &msg);

    /// \address 008ac0e0
    void OnObjectListBegin(CMsgStreamBuffer &msg);

    /// \address 008ac170
    void OnObjectListData(CMsgStreamBuffer &msg);

    /// \address 008ac3d0
    void OnObjectListEnd(CMsgStreamBuffer &msg);

    /// \address 008a74f0
    void OnChestDataBegin(CMsgStreamBuffer &msg);

    /// \address 008a8c10
    void OnChestDataData(CMsgStreamBuffer &msg);

    /// \address 008a9100
    void OnChestDataEnd(CMsgStreamBuffer &msg);

    /// \address 008a6ca0
    void OnObjectEntered(CMsgStreamBuffer &msg);

    /// \address 008a6cc0
    void OnObjectLeft(CMsgStreamBuffer &msg);

    /// \address 008a6640
    void On3076(CMsgStreamBuffer &msg);

    /// \address 008a80a0
    void On30bf(CMsgStreamBuffer &msg);

    /// \address 008a7720
    void Onb0cb(CMsgStreamBuffer &msg);

    /// \address 008a8ea0
    void Onb03c(CMsgStreamBuffer &msg);

    /// \address 008a7550
    void On3092(CMsgStreamBuffer &msg);

    /// \address 008a7630
    void On30df(CMsgStreamBuffer &msg);

    /// \address 00881090
    void On30cd(CMsgStreamBuffer &msg);

    /// \address 00881100
    void On30ce(CMsgStreamBuffer &msg);

    /// \address 00881170
    void On30d3(CMsgStreamBuffer &msg);

    /// \address 0x008A8FC0
    void On30C1(CMsgStreamBuffer &msg);

    /// \address 0x008A9000
    void On30C2(CMsgStreamBuffer &msg);

    /// \address 0x008A7870
    void On30C3(CMsgStreamBuffer &msg);

    /// \address 0x008A6650
    void On30C8(CMsgStreamBuffer &msg);

    /// \address 0x008A7A70
    void OnB0C6(CMsgStreamBuffer &msg);

    /// \address 0x008AA340
    void On30C9(CMsgStreamBuffer &msg);

    /// \address 0x00883B10
    void On30E7(CMsgStreamBuffer &msg);

    /// \address 0x008A7AC0
    void OnB0C7(CMsgStreamBuffer &msg);

    /// \address 0x008A7690
    void On30CA(CMsgStreamBuffer &msg);

    /// \address 0x008A7B30
    void OnB116(CMsgStreamBuffer &msg);

    /// \address 0x008A7B80
    void OnB117(CMsgStreamBuffer &msg);

    /// \address 0x008A7D20
    void OnB420(CMsgStreamBuffer &msg);

    /// \address 0x00889D90
    void On30D4(CMsgStreamBuffer &msg);

    /// \address 0x008A7020
    void On3054(CMsgStreamBuffer &msg);

    /// \address 0x008A97C0
    void On3056(CMsgStreamBuffer &msg);

    /// \address 0x008A70D0
    void On304E(CMsgStreamBuffer &msg);

    /// \address 0x008ADF50
    void On3052(CMsgStreamBuffer &msg);

    /// \address 0x008A9E30
    void On3057(CMsgStreamBuffer &msg);

    /// \address 0x0088B200
    void OnB045(CMsgStreamBuffer &msg);

    /// \address 0x00880F80
    void On303D(CMsgStreamBuffer &msg);

    /// \address 0x008ADD60
    void On30D2(CMsgStreamBuffer &msg);

    /// \address 0x008726E0
    void On30CF(CMsgStreamBuffer &msg);

    /// \address 0x00872710
    void On3011(CMsgStreamBuffer &msg);

    /// \address 0x00872740
    void On3058(CMsgStreamBuffer &msg);

    /// \address 0x00877340
    void OnB025(CMsgStreamBuffer &msg);

    /// \address 0x00877810
    void OnChatReceive(CMsgStreamBuffer &msg);

    /// \address 0x008A7950
    void On3091(CMsgStreamBuffer &msg);

    /// \address 0x00872010
    void On302D(CMsgStreamBuffer &msg);

    /// \address 0x008A5750
    void OnB021(CMsgStreamBuffer &msg);

    /// \address 0x008A4EC0
    void OnB024(CMsgStreamBuffer &msg);

    /// \address 0x008A4F80
    void OnB023(CMsgStreamBuffer &msg);

    /// \address 0x008A50E0
    void On3028(CMsgStreamBuffer &msg);

    /// \address 0x008A51E0
    void OnB04F(CMsgStreamBuffer &msg);

    /// \address 0x008A5280
    void On30D0(CMsgStreamBuffer &msg);

    /// \address 0x008A52F0
    void On3200(CMsgStreamBuffer &msg);

    /// \address 0x008A5FD0
    void OnB070(CMsgStreamBuffer &msg);

    /// \address 0x008A4960
    void OnB071(CMsgStreamBuffer &msg);

    /// \address 0x008A59E0
    void OnB0BD(CMsgStreamBuffer &msg);

    /// \address 0x008A4A30
    void On330F(CMsgStreamBuffer &msg);

    /// \address 0x008A5DA0
    void OnB0BE(CMsgStreamBuffer &msg);

    /// \address 0x008A4B00
    void OnB0BC(CMsgStreamBuffer &msg);

    /// \address 0x008A4DE0
    void OnB072(CMsgStreamBuffer &msg);

    /// \address 0x008A4980
    void On30A6(CMsgStreamBuffer &msg);

    /// \address 0x008A4990
    void On30D1(CMsgStreamBuffer &msg);

    /// \address 0x008A5360
    void On3206(CMsgStreamBuffer &msg);

    /// \address 0x00880BE0
    void OnB0A1(CMsgStreamBuffer &msg);

    /// \address 0x00880CC0
    void OnB0A2(CMsgStreamBuffer &msg);

    /// \address 0x00880E90
    void OnB203(CMsgStreamBuffer &msg);

    /// \address 0x00880DB0
    void OnB202(CMsgStreamBuffer &msg);

    /// \address 0x0087F370
    void OnB034(CMsgStreamBuffer &msg);

    /// \address 0x008A9260
    void On3038(CMsgStreamBuffer &msg);

    /// \address 0x008A9560
    void On3039(CMsgStreamBuffer &msg);

    /// \address 0x008A78B0
    void On3036(CMsgStreamBuffer &msg);

    /// \address 0x00880A20
    void OnB03E(CMsgStreamBuffer &msg);

    /// \address 0x00880A70
    void OnB03F(CMsgStreamBuffer &msg);

    /// \address 0x008A75C0
    void On304D(CMsgStreamBuffer &msg);

    /// \address 0x0087A7B0
    void OnB04C(CMsgStreamBuffer &msg);

    /// \address 0x00873990
    void On3068(CMsgStreamBuffer &msg);

    /// \address 0x008735D0
    void On305C(CMsgStreamBuffer &msg);

    /// \address 0x00881600
    void On30E0(CMsgStreamBuffer &msg);

    /// \address 0x0088BF30
    void On3040(CMsgStreamBuffer &msg);

    /// \address 0x00882280
    void On3201(CMsgStreamBuffer &msg);

    /// \address 0x008822C0
    void On3041(CMsgStreamBuffer &msg);

    /// \address 0x008825D0
    void On3042(CMsgStreamBuffer &msg);

    /// \address 0x00882DE0
    void On3153(CMsgStreamBuffer &msg);

    /// \address 0x00882E50
    void On3154(CMsgStreamBuffer &msg);

    /// \address 0x00888E30
    void OnB046(CMsgStreamBuffer &msg);

    /// \address 0x00886AC0
    void OnB04B(CMsgStreamBuffer &msg);

    /// \address 0x0087FFD0
    void OnB0C0(CMsgStreamBuffer &msg);

    /// \address 0x00880AC0
    void OnB050(CMsgStreamBuffer &msg);

    /// \address 0x00880B10
    void OnB051(CMsgStreamBuffer &msg);

    /// \address 0x00872590
    void OnB0C5(CMsgStreamBuffer &msg);

    /// \address 0x00883520
    void OnB059(CMsgStreamBuffer &msg);

    /// \address 0x008809D0
    void OnB05A(CMsgStreamBuffer &msg);

    /// \address 0x00880B60
    void OnB074(CMsgStreamBuffer &msg);

    /// \address 0x00881670
    void On30EB(CMsgStreamBuffer &msg);

    /// \address 0x00881690
    void OnB0EA(CMsgStreamBuffer &msg);

    /// \address 0x008727A0
    void OnB05B(CMsgStreamBuffer &msg);

    /// \address 0x00871D50
    void On34B1(CMsgStreamBuffer &msg);

    /// \address 0x00880010
    void OnB060(CMsgStreamBuffer &msg);

    /// \address 0x00886B10
    void On3864(CMsgStreamBuffer &msg);

    /// \address 0x00883CC0
    void On3065(CMsgStreamBuffer &msg);

    /// \address 0x008800B0
    void OnB062(CMsgStreamBuffer &msg);

    /// \address 0x00880120
    void OnB067(CMsgStreamBuffer &msg);

    /// \address 0x00883F90
    void OnB069(CMsgStreamBuffer &msg);

    /// \address 0x008840D0
    void OnB06A(CMsgStreamBuffer &msg);

    /// \address 0x008801E0
    void OnB06B(CMsgStreamBuffer &msg);

    /// \address 0x008841F0
    void OnB06C(CMsgStreamBuffer &msg);

    /// \address 0x00884660
    void On706D(CMsgStreamBuffer &msg);

    /// \address 0x008847D0
    void OnB06D(CMsgStreamBuffer &msg);

    /// \address 0x00880330
    void OnB081(CMsgStreamBuffer &msg);

    /// \address 0x0088AA60
    void On3080(CMsgStreamBuffer &msg);

    /// \address 0x008803F0
    void On3085(CMsgStreamBuffer &msg);

    /// \address 0x00880430
    void OnB082(CMsgStreamBuffer &msg);

    /// \address 0x008804A0
    void OnB083(CMsgStreamBuffer &msg);

    /// \address 0x00880520
    void OnB084(CMsgStreamBuffer &msg);

    /// \address 0x00880590
    void On3089(CMsgStreamBuffer &msg);

    /// \address 0x0087FCB0
    void On3086(CMsgStreamBuffer &msg);

    /// \address 0x0088BB50
    void On3087(CMsgStreamBuffer &msg);

    /// \address 0x00880840
    void On3088(CMsgStreamBuffer &msg);

    /// \address 0x00880970
    void On30E8(CMsgStreamBuffer &msg);

    /// \address 0x008806B0
    void On308C(CMsgStreamBuffer &msg);

    /// \address 0x00872040
    void OnB0B1(CMsgStreamBuffer &msg);

    /// \address 0x00873C10
    void On30B8(CMsgStreamBuffer &msg);

    /// \address 0x008720F0
    void OnB0B2(CMsgStreamBuffer &msg);

    /// \address 0x008721B0
    void On30B9(CMsgStreamBuffer &msg);

    /// \address 0x0087A260
    void On30B7(CMsgStreamBuffer &msg);

    /// \address 0x00873FF0
    void OnB0B3(CMsgStreamBuffer &msg);

    /// \address 0x00872450
    void OnB0B5(CMsgStreamBuffer &msg);

    /// \address 0x00872500
    void OnB0B4(CMsgStreamBuffer &msg);

    /// \address 0x00878230
    void OnB0BA(CMsgStreamBuffer &msg);

    /// \address 0x00873D60
    void On30BB(CMsgStreamBuffer &msg);

    /// \address 0x008A7A20
    void OnB0A7(CMsgStreamBuffer &msg);

    /// \address 0x008743A0
    void OnB010(CMsgStreamBuffer &msg);

    /// \address 0x008811E0
    void On30D6(CMsgStreamBuffer &msg);

    /// \address 0x00881280
    void On30D7(CMsgStreamBuffer &msg);

    /// \address 0x008812B0
    void On30D5(CMsgStreamBuffer &msg);

    /// \address 0x00881450
    void OnB0D8(CMsgStreamBuffer &msg);

    /// \address 0x008814B0
    void OnB0D9(CMsgStreamBuffer &msg);

    /// \address 0x00884A30
    void On30EC(CMsgStreamBuffer &msg);

    /// \address 0x008A7EE0
    void On30DC(CMsgStreamBuffer &msg);

    /// \address 0x00881570
    void OnB515(CMsgStreamBuffer &msg);

    /// \address 0x00884CA0
    void On3514(CMsgStreamBuffer &msg);

    /// \address 0x008ABCC0
    void On3CA2(CMsgStreamBuffer &msg);

    /// \address 0x00884DD0
    void On30E6(CMsgStreamBuffer &msg);

    /// \address 0x008890B0
    void OnB0E1(CMsgStreamBuffer &msg);

    /// \address 0x00889210
    void OnB0E2(CMsgStreamBuffer &msg);

    /// \address 0x00889370
    void OnB0E3(CMsgStreamBuffer &msg);

    /// \address 0x0088A130
    void OnB0E4(CMsgStreamBuffer &msg);

    /// \address 0x008830F0
    void OnB0E5(CMsgStreamBuffer &msg);

    /// \address 0x00881740
    void OnB0E6(CMsgStreamBuffer &msg);

    /// \address 0x008852C0
    void OnB0F0(CMsgStreamBuffer &msg);

    /// \address 0x00887330
    void On38F5(CMsgStreamBuffer &msg);

    /// \address 0x00881820
    void OnB0F1(CMsgStreamBuffer &msg);

    /// \address 0x00881890
    void OnB0F8(CMsgStreamBuffer &msg);

    /// \address 0x00881950
    void OnB0F3(CMsgStreamBuffer &msg);

    /// \address 0x0088A420
    void On30FF(CMsgStreamBuffer &msg);

    /// \address 0x008819B0
    void On3100(CMsgStreamBuffer &msg);

    /// \address 0x008819E0
    void OnB0F2(CMsgStreamBuffer &msg);

    /// \address 0x00881C60
    void OnB0F4(CMsgStreamBuffer &msg);

    /// \address 0x0087FCD0
    void On34B3(CMsgStreamBuffer &msg);

    /// \address 0x00883060
    void On3101(CMsgStreamBuffer &msg);

    /// \address 0x00887300
    void On34B4(CMsgStreamBuffer &msg);

    /// \address 0x00881A70
    void OnB0F9(CMsgStreamBuffer &msg);

    /// \address 0x00881AE0
    void OnB0F6(CMsgStreamBuffer &msg);

    /// \address 0x00881BD0
    void OnB0FA(CMsgStreamBuffer &msg);

    /// \address 0x00889680
    void OnB103(CMsgStreamBuffer &msg);

    /// \address 0x00881CB0
    void OnB104(CMsgStreamBuffer &msg);

    /// \address 0x008857B0
    void OnB105(CMsgStreamBuffer &msg);

    /// \address 0x00881D00
    void OnB106(CMsgStreamBuffer &msg);

    /// \address 0x008897C0
    void On3908(CMsgStreamBuffer &msg);

    /// \address 0x00881D80
    void OnB107(CMsgStreamBuffer &msg);

    /// \address 0x00881DD0
    void OnB0FB(CMsgStreamBuffer &msg);

    /// \address 0x0087FD00
    void On3102(CMsgStreamBuffer &msg);

    /// \address 0x00881E20
    void OnB0FC(CMsgStreamBuffer &msg);

    /// \address 0x00881E70
    void OnB0FD(CMsgStreamBuffer &msg);

    /// \address 0x0087FD90
    void On3109(CMsgStreamBuffer &msg);

    /// \address 0x00885920
    void On7110(CMsgStreamBuffer &msg);

    /// \address 0x00881EC0
    void OnB110(CMsgStreamBuffer &msg);

    /// \address 0x00881F30
    void OnB112(CMsgStreamBuffer &msg);

    /// \address 0x00885AE0
    void OnB114(CMsgStreamBuffer &msg);

    /// \address 0x00881F80
    void OnB113(CMsgStreamBuffer &msg);

    /// \address 0x00885C20
    void OnB501(CMsgStreamBuffer &msg);

    /// \address 0x0088A770
    void On30EF(CMsgStreamBuffer &msg);

    /// \address 0x0087FDD0
    void On3305(CMsgStreamBuffer &msg);

    /// \address 0x00885E50
    void OnB302(CMsgStreamBuffer &msg);

    /// \address 0x00881FD0
    void OnB304(CMsgStreamBuffer &msg);

    /// \address 0x00886000
    void On7302(CMsgStreamBuffer &msg);

    /// \address 0x00882030
    void OnB30B(CMsgStreamBuffer &msg);

    /// \address 0x00886170
    void OnB308(CMsgStreamBuffer &msg);

    /// \address 0x008820B0
    void OnB309(CMsgStreamBuffer &msg);

    /// \address 0x00882130
    void OnB30A(CMsgStreamBuffer &msg);

    /// \address 0x00886310
    void On3B07(CMsgStreamBuffer &msg);

    /// \address 0x0087FE00
    void On3204(CMsgStreamBuffer &msg);

    /// \address 0x00872810
    void OnB155(CMsgStreamBuffer &msg);

    /// \address 0x00872810
    void On3156(CMsgStreamBuffer &msg);

    /// \address 0x00872940
    void OnB157(CMsgStreamBuffer &msg);

    /// \address 0x008729E0
    void OnB150(CMsgStreamBuffer &msg);

    /// \address 0x00872CD0
    void OnB151(CMsgStreamBuffer &msg);

    /// \address 0x00872FA0
    void OnB16A(CMsgStreamBuffer &msg);

    /// \address 0x0088A820
    void On3207(CMsgStreamBuffer &msg);

    /// \address 0x008821C0
    void OnB0ED(CMsgStreamBuffer &msg);

    /// \address 0x008867A0
    void On34BA(CMsgStreamBuffer &msg);

    /// \address 0x008A5230
    void OnB402(CMsgStreamBuffer &msg);

    /// \address 0x008832A0
    void OnFFC(CMsgStreamBuffer &msg);

    /// \address 0x00888DA0
    void On2000(CMsgStreamBuffer &msg);

    /// \address 0x0087FE40
    void OnFFD(CMsgStreamBuffer &msg);

    /// \address 0x00878B40
    void OnB05E(CMsgStreamBuffer &msg);

    /// \address 0x00873140
    void On3078(CMsgStreamBuffer &msg);

private:
    std::n_hash_map<int, void (__thiscall CNetProcessIn::*)(CMsgStreamBuffer &)> m_handlers; // 0x20

    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_handlers, 0x20)
    END_FIXTURE()

    RUN_FIXTURE(CNetProcessIn)
};
