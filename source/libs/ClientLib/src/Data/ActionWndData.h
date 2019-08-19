#pragma once

#include <string>

#pragma pack(push,4)
class CActionWndData
{
public:
	virtual void Unknown();

	unsigned __int32 m_id;
	unsigned __int32 m_enabled;
	std::wstring m_codeName128;
	std::string m_assocFileIcon;
	unsigned __int32 m_row;
	unsigned __int32 m_col;
};
#pragma pack(pop)