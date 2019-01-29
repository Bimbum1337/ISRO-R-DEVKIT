#include <string>
#include <BSLib/BSLib.h>

// Stolen from here https://github.com/ianchi/jThread/blob/master/src/winUtil.cpp

#define TO_NWSTRING(x) acp_n_decode(x)
#define TO_WSTRING(x) acp_decode(x)

#define TO_STRING(x) acp_encode(x)
#define TO_NSTRING(x) acp_n_encode(x)


// primitive to std::string
std::string acp_encode(const wchar_t* text, size_t length);
std::n_string acp_n_encode(const wchar_t* text, size_t length);

// std::wstring to std::string
std::string acp_encode(const std::wstring &wstr);
std::string acp_encode(const std::wstring *wstr);

// std::n_wstring to std::string
std::string acp_encode(const std::n_wstring *wstr);
std::string acp_encode(const std::n_wstring &wstr);

// std::n_wstring to std::n_string
std::n_string acp_n_encode(const std::wstring *wstr);
std::n_string acp_n_encode(const std::wstring &wstr);

// std::n_wstring to std::n_string
std::n_string acp_n_encode(const std::n_wstring *wstr);
std::n_string acp_n_encode(const std::n_wstring &wstr);

// primitive to std::wstring
std::wstring acp_decode(const char* str, size_t length);
std::n_wstring acp_n_decode(const char* str, size_t length);

// std::string to std::wstring
std::wstring acp_decode(const std::string& str);
std::wstring acp_decode(const std::string* str);

// std::string to std::n_wstring
std::n_wstring acp_n_decode(const std::string& str);
std::n_wstring acp_n_decode(const std::string* str);

// std::n_string to std::wstring
std::wstring acp_decode(const std::n_string& str);
std::wstring acp_decode(const std::n_string* str);

// std::n_string to std::n_wstring
std::n_wstring acp_n_decode(const std::n_string& str);
std::n_wstring acp_n_decode(const std::n_string* str);
