#include <string>

// Stolen from here https://github.com/ianchi/jThread/blob/master/src/winUtil.cpp

std::string acp_encode(const std::wstring &wstr);
std::string acp_encode(const std::wstring *wstr);
std::string acp_encode(const wchar_t* text, size_t length);

std::wstring acp_decode(const std::string& str);
std::wstring acp_decode(char* str);

