#pragma once

#include <string>

#pragma pack(push,4)
class CRefPackageItemData
{
public:
	virtual void Unknown();

	char gap[4];
	unsigned __int32 m_id;
	char gap1[4];
	std::wstring m_codeName128;
	unsigned __int16 m_saleTag;
	std::wstring m_expandTerm;
	std::wstring m_nameStrId;
	std::wstring m_descStrId;
	std::string m_assocFileIcon;
	//std::string m_empty; maybe something
};
#pragma pack(pop)