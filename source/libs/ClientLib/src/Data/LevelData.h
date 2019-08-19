#pragma once

class CLevelData
{
public:
	virtual void Unknown();

	char gap[4];
	unsigned __int8 m_level;
	char gap2[7];
	unsigned __int64 m_expC;
	unsigned __int32 m_expM;
	char gap3[8];
	unsigned __int32 m_jobExpTrader;
	unsigned __int32 m_jobExpRobber;
	unsigned __int32 m_jobExpHunter;
};