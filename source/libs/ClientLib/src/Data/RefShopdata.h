#pragma once

#include <string>

#pragma pack(push, 4)
class CRefShopdata
{
public:
	virtual void Unknown();

	unsigned __int32 m_country;
	unsigned __int32 m_id;
	std::wstring m_codeName128;
};
#pragma pack(pop)