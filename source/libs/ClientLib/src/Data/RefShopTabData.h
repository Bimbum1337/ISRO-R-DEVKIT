#pragma once

#include <string>

#pragma pack(push, 4)
class CRefShopTabData
{
	virtual void Unknown();

	unsigned __int32 m_country;
	unsigned __int32 m_id;
	std::wstring m_codeName128;
	unsigned __int32 m_tabGroupLinkId;
	std::wstring* m_strId128Tab;
};
#pragma pack(pop)