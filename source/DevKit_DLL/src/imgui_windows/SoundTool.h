#pragma once

#include <BSLib/BSLib.h>

class SoundTool {
public:
    void Render();

    void MenuItem();


private:
    int ImGui_Window_SoundTool_Filter(std::vector<std::n_string> *items, const std::n_wstring &search);

    bool ImGui_Window_SoundTool_FilterMatch(const std::n_wstring &input, const std::n_wstring &search);


private:
    bool bShow;
    char buffer[100];
};
