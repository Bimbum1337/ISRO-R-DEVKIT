#pragma once

#pragma pack(push, 4)
class CGachaItemSetData
{
	virtual void Unknown();

	char gap0[4];
	unsigned __int32 m_refItemId;
	unsigned __int16 m_ratio;

	unsigned __int32 m_count;
	unsigned __int32 m_gachaId;
	char gap1[4];
	unsigned __int32 m_param1;
	unsigned __int32 m_param2;
	unsigned __int32 m_param3;
	unsigned __int32 m_param4;
};
#pragma pack(pop)