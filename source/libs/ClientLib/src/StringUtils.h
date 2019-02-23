#pragma once


// TODO: Make this match only for strings ...
std::vector<std::n_wstring> split(const std::n_wstring& s, wchar_t seperator)
{
   std::vector<std::n_wstring> output;

    int prev_pos = 0, pos = 0;

    while((pos = s.find(seperator, pos)) != std::n_wstring::npos)
    {
        std::n_wstring substring( s.substr(prev_pos, pos-prev_pos) );

		output.push_back(substring);

        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos-prev_pos)); // Last word

    return output;
}
