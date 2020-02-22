#pragma once

#include <string>

#pragma pack(push, 4)
class CGameGuideData
{
	virtual void Unknown();

	unsigned __int32 m_id;
	unsigned __int32 m_unknown;
	unsigned __int32 m_linkrelation_maybe;
	std::wstring m_msg;
	std::wstring m_msgMenu;
};
#pragma pack(pop)