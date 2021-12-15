#pragma once

#pragma pack(push, 4)
class CLevelData
{
public:
	virtual void Unknown();

    struct SData {
        unsigned __int8 m_level; // 0x0000
        char gap2[4];
        unsigned __int64 m_expC; // 0x0008
        unsigned __int32 m_expM; // 0x000C
        char gap3[8];
        unsigned __int32 m_jobExpTrader;
        unsigned __int32 m_jobExpRobber;
        unsigned __int32 m_jobExpHunter;
    };

	char gap[4];

    SData data;
};
#pragma pack(pop)