#include "SoundTool.h"

#include <imgui/imgui.h>
#include <GEffSoundBody.h>
#include <BSLib/multibyte.h>
#include <BSLib/Debug.h>

bool sound_item_getter(void* data, int idx, const char **outdata);

void SoundTool::Render() {
    static int current_item = 0;
    static std::vector<std::n_string> items;
    static bool inited = false;

    if (!bShow) return;

    if (!inited)
    {
        ImGui_Window_SoundTool_Filter(&items, L"");
        inited = true;
    }

    if (!ImGui::Begin("Sound Tool", &bShow))
    {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return;
    }

    if (ImGui::InputText("Filter", buffer, IM_ARRAYSIZE(buffer)))
    {
        // Value has changed
        BS_DEBUG("Value has changed: %s", buffer);
        ImGui_Window_SoundTool_Filter(&items, acp_n_decode(buffer, strlen(buffer)));
    }


    if (ImGui::ListBox("Sounds", &current_item, &sound_item_getter, (void*)&items, items.size(), 20))
    {
        CGEffSoundBody* snd = CGEffSoundBody::get();

        std::n_string itm = items[current_item];
        std::n_wstring sndKey = TO_NWSTRING(itm);

        snd->PlaySoundInner(&sndKey, 0, 0.0);
    }


    ImGui::End();
}

int SoundTool::ImGui_Window_SoundTool_Filter(std::vector<std::n_string> *items, const std::n_wstring &search) {
    CGEffSoundBody* snd = CGEffSoundBody::get();

    items->clear();

    for (std::n_hash_map<std::n_wstring, int>::iterator it = snd->m_sounds.begin(); it != snd->m_sounds.end(); ++it)
    {
        if (ImGui_Window_SoundTool_FilterMatch((*it).first, search))
            items->push_back(TO_NSTRING((*it).first));
    }

    return 0;
}

bool sound_item_getter(void *data, int idx, const char **outdata) {
    std::vector<std::n_string> *items = (std::vector<std::n_string>*)data;

    if (idx >= items->size())
        return false;

    std::n_string &str = items->at(idx);

    *outdata = str.c_str();

    return true;
}

bool SoundTool::ImGui_Window_SoundTool_FilterMatch(const std::n_wstring &input, const std::n_wstring &search) {
    if (search.empty())
        return true;
#if 0
    std::vector<std::n_wstring> input_tokens = split(input, L':');
	std::vector<std::n_wstring> search_tokens = split(input, L':');

	std::vector<std::n_wstring>::iterator it_input;
	std::vector<std::n_wstring>::iterator it_search;

	for (
		it_input = input_tokens.begin(),
		it_search = search_tokens.begin();
		it_input != input_tokens.end() && it_search != search_tokens.end();
		++it_input, ++it_search)
	{
		if ((*it_input).empty() || (*it_search).empty())
			continue;

		if ((*it_input).find(*it_search) == std::n_wstring::npos)
		{
			return false;
		}

	}
#endif

    return !(input.find(search) == std::n_wstring::npos);
}

void SoundTool::MenuItem() {
    ImGui::MenuItem("Sound Tool", 0, &bShow);
}
