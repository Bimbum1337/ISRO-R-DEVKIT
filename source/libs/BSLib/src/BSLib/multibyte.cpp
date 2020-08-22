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

std::n_string acp_n_encode(const wchar_t* text, size_t length)
{
	if( length == 0 ) return std::n_string();
    int size_needed = WideCharToMultiByte(CP_ACP, 0, text, length, NULL, 0, NULL, NULL);
    std::n_string strTo( size_needed, 0 );
    WideCharToMultiByte(CP_ACP, 0, text, length, &strTo[0], size_needed, NULL, NULL);
    return strTo;
}

std::string acp_encode(const std::wstring& wstr)
{
	return acp_encode(&wstr);
}

std::string acp_encode(const std::wstring* wstr)
{
	return acp_encode(wstr->c_str(), wstr->length());
}

std::string acp_encode(const std::n_wstring* wstr)
{
	return acp_encode(wstr->c_str(), wstr->length());
}

std::string acp_encode(const std::n_wstring& wstr)
{
	return acp_encode(&wstr);
}

std::n_string acp_n_encode(const std::wstring* wstr)
{
	return acp_n_encode(wstr->c_str(), wstr->length());
}

std::n_string acp_n_encode(const std::wstring& wstr)
{
	return acp_n_encode(&wstr);
}

std::n_string acp_n_encode(const std::n_wstring* wstr)
{
	return acp_n_encode(wstr->c_str(), wstr->length());
}

std::n_string acp_n_encode(const std::n_wstring& wstr)
{
	return acp_n_encode(&wstr);
}

std::wstring acp_decode(const char* str, size_t length)
{
	if (length == 0) return std::wstring();
    int size_needed = MultiByteToWideChar(CP_ACP, 0, &str[0], length, NULL, 0);
    std::wstring wstrTo( size_needed, 0 );
    MultiByteToWideChar(CP_ACP, 0, &str[0], length, &wstrTo[0], size_needed);
    return wstrTo;
}

std::n_wstring acp_n_decode(const char* str, size_t length)
{
	if (length == 0) return std::n_wstring();
    int size_needed = MultiByteToWideChar(CP_ACP, 0, &str[0], length, NULL, 0);
    std::n_wstring wstrTo( size_needed, 0 );
    MultiByteToWideChar(CP_ACP, 0, &str[0], length, &wstrTo[0], size_needed);
    return wstrTo;
}

std::wstring acp_decode(const std::string& str)
{
	return acp_decode(&str);
}

std::wstring acp_decode(const std::string* str)
{
	return acp_decode(str->c_str(), str->length());
}

std::n_wstring acp_n_decode(const std::string& str)
{
	return acp_n_decode(&str);
}

std::n_wstring acp_n_decode(const std::string* str)
{
	return acp_n_decode(str->c_str(), str->length());
}

std::wstring acp_decode(const std::n_string& str)
{
	return acp_decode(&str);
}

std::wstring acp_decode(const std::n_string* str)
{
	return acp_decode(str->c_str(), str->length());
}

std::n_wstring acp_n_decode(const std::n_string& str)
{
	return acp_n_decode(&str);
}

std::n_wstring acp_n_decode(const std::n_string* str)
{
	return acp_n_decode(str->c_str(), str->length());
}

