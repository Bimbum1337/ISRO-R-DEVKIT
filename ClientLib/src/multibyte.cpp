#include "StdAfx.h"
#include "multibyte.h"
#include <Windows.h>
#include <string>

// Stolen from here https://github.com/ianchi/jThread/blob/master/src/winUtil.cpp


std::string acp_encode(const wchar_t* text, size_t length)
{
	if( length == 0 ) return std::string();
    int size_needed = WideCharToMultiByte(CP_ACP, 0, text, length, NULL, 0, NULL, NULL);
    std::string strTo( size_needed, 0 );
    WideCharToMultiByte(CP_ACP, 0, text, length, &strTo[0], size_needed, NULL, NULL);
    return strTo;
}

std::string acp_encode(const std::wstring &wstr)
{
	return acp_encode(wstr.c_str(), wstr.length());
}

std::string acp_encode(const std::wstring *wstr)
{
	return acp_encode(wstr->c_str(), wstr->length());
}

std::wstring acp_decode(const std::string& str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo( size_needed, 0 );
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

std::wstring acp_decode(char* str)
{
	int len = strlen(str);
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], len, NULL, 0);
    std::wstring wstrTo( size_needed, 0 );
    MultiByteToWideChar(CP_UTF8, 0, &str[0], len, &wstrTo[0], size_needed);
    return wstrTo;
}
