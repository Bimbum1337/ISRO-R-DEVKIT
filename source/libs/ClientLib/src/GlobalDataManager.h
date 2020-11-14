#pragma once

#include <map>
#include <ghidra/undefined.h>
#include "Data/ItemData.h"
#include "Data/CharacterData.h"
#include "Data/GameGuideData.h"
#include "Data/ActionWndData.h"
#include "Data/RefScrapOfPackageItemData.h"
#include "Data/RefPackageItemData.h"
#include "Data/RefPricePolicyOfItem.h"
#include "Data/RefShopdata.h"
#include "Data/RefShopTabGroupData.h"
#include "Data/RefShopTabData.h"
#include "Data/ShopItemStockQuantity.h"
#include "Data/LevelData.h"
#include "Data/TeleportData.h"
#include "Data/TeleportLink.h"
#include "Data/TeleportBuilding.h"
#include "Data/NPCChatData.h"
#include "Data/MessageTipData.h"
#include "Data/MagicOptionData.h"
#include "Data/QuestData.h"
#include "Data/DropGoldData.h"
#include "Data/NPCPosData.h"
#include "Data/MallItemMenuListData.h"
#include "Data/ShopItemStockPeriod.h"
#include "Data/GachaItemSetData.h"
#include "Data/GachaNpcData.h"
#include "Data/LevelGoldData.h"


#define g_CGlobalDataManager ((CGlobalDataManager*)0x00EEDF08)

class CGlobalDataManager {
public:
    virtual void Unknown();

    undefined4 FUN_008cbac0(int a1);


    char gap0[0x254];

    std::map<unsigned __int32, CItemData *> m_itemDataMap; //0x258
    std::map<unsigned __int32, CCharacterData *> m_characterDataMap; //0x264
    std::map<unsigned __int32, CGameGuideData *> m_gameGuideDataMap; //0x270
    char unknown_gap[4 * 20]; // 0x27C
    std::map<unsigned __int32, CActionWndData *> m_actionWndDataMap; //0x2CC
    char empty_maps_times_8[3 * 4 * 8]; //0x2D8
    std::map<unsigned __int32, CRefScrapOfPackageItemData *> m_refScrapOfPackageItemData; //0x338
    std::map<unsigned __int32, CRefPackageItemData *> m_refPackageItemDataMap; //0x344
    std::map<unsigned __int32, CRefPricePolicyOfItem *> m_refPricePolicyOfItemMap; //0x350
    std::map<unsigned __int32, CRefShopdata *> m_refShopDataMap; //0x35C
    std::map<unsigned __int32, CRefShopTabGroupData *> m_refShopTabGroupDataMap; //0x368
    std::map<unsigned __int32, CRefShopTabData *> m_refShopTabDataMap; //0x374
    char itemmall_related_map[3 * 4]; //0x380
    char itemmall_related_map2[3 * 4]; //0x38C
    char empty_maps_times_8_2[3 * 4 * 8]; //0x398
    char refshoptabdata_related_map[3 * 4]; //0x3F8
    std::map<unsigned __int32, CShopItemStockQuantity *> m_shopItemStockQuantityMap; //0x404
    std::map<unsigned __int32, CLevelData *> m_levelDataMap; //0x410
    std::map<unsigned __int32, CTeleportData *> m_teleportDataMap; //0x41C
    std::map<unsigned __int32, CTeleportLink *> m_teleportLinkMap; //0x428
    std::map<unsigned __int32, CTeleportBuilding *> m_teleportBuildingMap; //0x434
    std::map<unsigned __int32, CNPCChatData *> m_npcChatDataMap; //0x440
    std::map<unsigned __int32, CMessageTipData *> m_messageTipDataMap; //0x44C
    std::map<unsigned __int32, CMagicOptionData *> m_magicOptionDataMap; //0x458
    std::map<unsigned __int32, CQuestData *> m_questDataMap; //0x464
    char gap1[3 * 4];
    std::map<unsigned __int8, CDropGoldData *> m_dropGoldDataMap; //0x47C
    std::map<unsigned __int32, CNPCPosData *> m_npcPosDataMap; //0x488
    std::map<unsigned __int32, CMallItemMenuListData *> m_mallItemMenuListDataMap; //0x494
    std::map<unsigned __int32, CShopItemStockPeriod *> m_shopItemStockPeriodMap; //0x4A0

    char gap2[26 * 4];    //0x4AC
    std::map<unsigned __int32, CGachaItemSetData *> m_gachaItemSetDataMap; //0x4FC
    std::map<unsigned __int32, CGachaNpcData *> m_gachaNpcDataMap; //0x508
    char gap3[4 * 4];    //0x514
    std::map<unsigned __int8, CLevelGoldData *> m_levelGoldDataMap; //0x524
    char gap4[3 * 4];
};
