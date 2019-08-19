#pragma once

#include <string>

#pragma pack(push,4)
class CItemData
{
public:
	virtual void Unknown();

	char gap0[3 * 4];
	unsigned __int16 m_unknown0;
	unsigned __int32 m_id;
	std::wstring m_codeName128;
private:
	std::string m_empty0;
	std::string m_empty1;
public:
	std::wstring m_nameStrId128;
	std::wstring m_descStrId128;
	unsigned __int32 m_decayTime;

	char gap1[2 * 4];

	unsigned __int8 m_canTrade;
	unsigned __int8 m_canSell;
	unsigned __int8 m_canBuy;
	unsigned __int8 m_canBorrow;

	unsigned __int8 m_canDrop;
	unsigned __int8 m_canPick;
	unsigned __int8 m_canRepair;
	unsigned __int8 m_canRevive;

	unsigned __int8 m_canUse;
	unsigned __int8 m_canThrow;

	unsigned __int64 m_price;
	unsigned __int64 m_sellPrice;
	unsigned __int32 m_costRepair;
	unsigned __int32 m_costRevive;
	unsigned __int32 m_costBorrow;
	unsigned __int32 m_keepingFee;
	signed __int32 m_reqLevelType1;
	signed __int32 m_reqLevelType2;
	signed __int32 m_reqLevelType3;
	signed __int32 m_reqLevelType4;
	unsigned __int32 m_reqLevel1;
	unsigned __int32 m_reqLevel2;
	unsigned __int32 m_reqLevel3;
	unsigned __int32 m_reqLevel4;
	unsigned __int32 m_maxContain;
	unsigned __int32 m_regionId;
	unsigned __int32 m_dir;
	unsigned __int32 m_offsetX;
	unsigned __int32 m_offsetY;
	unsigned __int32 m_offsetZ;
	unsigned __int32 m_speed1;
	unsigned __int32 m_speed2;
	unsigned __int32 m_scale;
	unsigned __int32 m_bcHeight;
	unsigned __int32 m_bcRadius;
	unsigned __int32 m_eventId;
	std::string m_assocFileObj128;
	std::string m_assocFileDrop128;
	std::string m_assocFileIcon128;
	std::string m_assocFile1_128;
	std::string m_assocFile2_128;
};
#pragma pack(pop)