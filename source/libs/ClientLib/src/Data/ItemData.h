#pragma once

#include <string>
#include <Test/Test.h>

#include <TypeId.h>

#pragma pack(push, 4)
class CItemData {
public:
    struct SData {

        bool IsGlobalMessageScroll() const;


        TypeId m_typeId; //0x0000
        unsigned __int32 m_id; //0x0004
        std::wstring m_codeName128; //0x0008
        std::wstring m_objName128; //0x0024
        std::wstring m_orgObjCodeName128; //0x0040
        char pad_0064[4]; //0x005C
        std::wstring m_nameStrId128; //0x0060
        std::wstring m_descStrId128; //0x007C
        unsigned __int32 m_decayTime; //0x0098
        char pad_009C[4]; //0x009C
        unsigned __int32 m_Rarity; //0x00A0
        unsigned __int8 m_canTrade; //0x00A4
        unsigned __int8 m_canSell; //0x00A5
        unsigned __int8 m_canBuy; //0x00A6
        unsigned __int8 m_canBorrow; //0x00A7
        unsigned __int8 m_canDrop; //0x00A8
        unsigned __int8 m_canPick; //0x00A9
        unsigned __int8 m_canRepair; //0x00AA
        unsigned __int8 m_canRevive; //0x00AB
        unsigned __int8 m_canUse; //0x00AC
        unsigned __int8 m_canThrow; //0x00AD
        char pad_00AE[2]; //0x00AE
        unsigned __int64 m_price; //0x00B0
        unsigned __int64 m_sellPrice; //0x00B8
        unsigned __int32 m_costRepair; //0x00C0
        unsigned __int32 m_costRevive; //0x00C4
        unsigned __int32 m_costBorrow; //0x00C8
        unsigned __int32 m_keepingFee; //0x00CC
        signed __int32 m_reqLevelType1; //0x00D0
        signed __int32 m_reqLevelType2; //0x00D4
        signed __int32 m_reqLevelType3; //0x00D8
        signed __int32 m_reqLevelType4; //0x00DC
        unsigned __int32 m_reqLevel1; //0x00E0
        unsigned __int32 m_reqLevel2; //0x00E4
        unsigned __int32 m_reqLevel3; //0x00E8
        unsigned __int32 m_reqLevel4; //0x00EC
        unsigned __int32 m_maxContain; //0x00F0
        unsigned __int32 m_regionId; //0x00F4
        unsigned __int32 m_dir; //0x098
        unsigned __int32 m_offsetX; //0x09C
        unsigned __int32 m_offsetY; //0x0100
        unsigned __int32 m_offsetZ; //0x0104
        unsigned __int32 m_speed1; //0x0108
        unsigned __int32 m_speed2; //0x010C
        unsigned __int32 m_scale; //0x0110
        unsigned __int32 m_bcHeight; //0x0114
        unsigned __int32 m_bcRadius; //0x0118
        unsigned __int32 m_eventId; //0x011C
        unsigned __int32 ObjItemLinkID; //0x0120
        std::string m_assocFileObj128; //0x0124
        std::string m_assocFileDrop128; //0x0140
        std::string m_assocFileIcon128; //0x015C
        std::string m_assocFile1_128; //0x0178
        std::string m_assocFile2_128; //0x0194
        char pad_01B0[32]; //0x01B0
        unsigned __int32 m_maxStock;          //0x01D0
        unsigned __int32 m_reqGender;         //0x01D4
        unsigned __int32 n_reqStr;            //0x01D8
        unsigned __int32 m_reqInt;            //0x01DC
        unsigned __int32 m_itemClass;         //0x01E0
        unsigned __int32 m_setId;             //0x01E4
        unsigned __int32 m_durabilityMin;     //0x01E8
        unsigned __int32 m_durabilityMax;     //0x01EC
        float m_phyDefMin;                    //0x01F0
        float m_phyDefMax;                    //0x01F4
        float m_phyDefIncrease;               //0x01F8
        unsigned __int32 m_evasionRatioMin;   //0x01FC
        unsigned __int32 m_evasionRatioMax;   //0x0200
        float m_evasionRatioIncrease;         //0x0204
        unsigned __int32 m_PARMin;            //0x0208
        unsigned __int32 m_PARMax;            //0x020C
        float m_PARIncrease;                  //0x0210
        unsigned __int32 m_blockRatioMin;     //0x0214
        unsigned __int32 m_blockRatioMax;     //0x0218
        float m_magDefMin;                    //0x021C
        float m_magDefMax;                    //0x0220
        float m_magDefIncrease;               //0x0224
        unsigned __int32 m_MARMin;            //0x0228
        unsigned __int32 m_MARMax;            //0x022C
        float m_MARIncrease;                  //0x0230
        unsigned __int32 m_phyDefStrMin;      //0x0234
        unsigned __int32 m_phyDefStrMax;      //0x0238
        unsigned __int32 m_magDefIntMin;      //0x023C
        unsigned __int32 m_magDefIntMax;      //0x0240
        unsigned __int32 m_quivered;          //0x0244
        unsigned __int32 m_ammo1TID4;         //0x0248
        unsigned __int32 m_ammo2TID4;         //0x024C
        unsigned __int32 m_ammo3TID4;         //0x0250
        unsigned __int32 m_ammo4TID4;         //0x0254
        unsigned __int32 m_ammo5TID4;         //0x0258
        unsigned __int32 m_speedClass;        //0x025C
        unsigned __int32 m_twoHanded;         //0x0260
        unsigned __int32 m_range;             //0x0264
        unsigned __int32 m_phyAttackMinMin;   //0x0268
        unsigned __int32 m_phyAttackMinMax;   //0x026C
        unsigned __int32 m_phyAttackMaxMin;   //0x0270
        unsigned __int32 m_phyAttackMaxMax;   //0x0274
        float m_phyAttackIncrease;            //0x0278
        unsigned __int32 m_magAttackMinMin;   //0x027C
        unsigned __int32 m_magAttackMinMax;   //0x0280
        unsigned __int32 m_magAttackMaxMin;   //0x0284
        unsigned __int32 m_magAttackMaxMax;   //0x0288
        float m_magAttackIncrease;            //0x028C
        unsigned __int32 m_phyAttackStrMinMin;//0x0290
        unsigned __int32 m_phyAttackStrMinMax;//0x0294
        unsigned __int32 m_phyAttackStrMaxMin;//0x0298
        unsigned __int32 m_phyAttackStrMaxMax;//0x029C
        unsigned __int32 m_magAttackIntMinMin;//0x02A0
        unsigned __int32 m_magAttackIntMinMax;//0x02A4
        unsigned __int32 m_magAttackIntMaxMin;//0x02A8
        unsigned __int32 m_magAttackIntMaxMax;//0x02AC
        unsigned __int32 m_hitRateMin;        //0x02B0
        unsigned __int32 m_hitRateMax;        //0x02B4
        float m_hitRateIncrease;              //0x02B8
        unsigned __int32 m_criticalHitRateMin;//0x02BC
        unsigned __int32 m_criticalHitRateMax;//0x02C0
        signed __int32 m_param1;              //0x02C4
        signed __int32 m_param2;              //0x02C8
        signed __int32 m_param3;              //0x02CC
        signed __int32 m_param4;              //0x02D0
        signed __int32 m_param5;              //0x02D4
        signed __int32 m_param6;              //0x02D8
        signed __int32 m_param7;              //0x02DC
        signed __int32 m_param8;              //0x02E0
        signed __int32 m_param9;              //0x02E4
        signed __int32 m_param10;             //0x02E8
        signed __int32 m_param11;             //0x02EC
        signed __int32 m_param12;             //0x02F0
        signed __int32 m_param13;             //0x02F4
        signed __int32 m_param14;             //0x02F8
        signed __int32 m_param15;             //0x02FC
        signed __int32 m_param16;             //0x0300
        signed __int32 m_param17;             //0x0304
        signed __int32 m_param18;             //0x0308
        signed __int32 m_param19;             //0x030C
        signed __int32 m_param20;             //0x0310
        std::wstring m_desc1_128;
        std::wstring m_desc2_128;
        std::wstring m_desc3_128;
        std::wstring m_desc4_128;
        std::wstring m_desc5_128;
        std::wstring m_desc6_128;
        std::wstring m_desc7_128;
        std::wstring m_desc8_128;
        std::wstring m_desc9_128;
        std::wstring m_desc10_128;
        std::wstring m_desc11_128;
        std::wstring m_desc12_128;
        std::wstring m_desc13_128;
        std::wstring m_desc14_128;
        std::wstring m_desc15_128;
        std::wstring m_desc16_128;
        std::wstring m_desc17_128;
        std::wstring m_desc18_128;
        std::wstring m_desc19_128;
        std::wstring m_desc20_128;
        // m_maxMagicOptCount ?? m_childItemCount ??

    private:
        BEGIN_FIXTURE()
            ENSURE_OFFSET(m_codeName128, 0x8)
            ENSURE_OFFSET(m_Rarity, 0xA0)
            ENSURE_OFFSET(m_maxStock, 0x1D0)
        END_FIXTURE()

        RUN_FIXTURE(SData)
    };

public:
    virtual ~CItemData();

    /// \address 00973420
    const SData &GetData() const;

private:
    // CItemData constructor is not to be used yet. Its private so no one can make an instance of this class
    CItemData();

private:
    char pad_0000[16-4]; //0x0000

    const SData mData;

private:
    BEGIN_FIXTURE()
        ENSURE_OFFSET(mData, 0x0010)
    END_FIXTURE()

    RUN_FIXTURE(CItemData)
};
#pragma pack(pop)
