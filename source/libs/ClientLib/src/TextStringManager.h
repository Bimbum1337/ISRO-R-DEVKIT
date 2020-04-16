#pragma once

#include <string>
#include <BSLib/BSLib.h>

class CTextStringManager {
public:
    //void ReadTranslationFile(char *filename, int lang, IFileManager *fm, int a5, int a6);
    //void sub_8CA8F0(const char * file, IFileManager *fm);

    /// Get translated string by identifier-token
    /// \address 008C9C30
    /// \param identifier Identifier for the string to translate. Example: "UIIT_STT_CANT_CHATTING"
    /// \returns The translated string
    const std::n_wstring *GetString(const wchar_t *identifier);
};

#define g_CTextStringManager ((CTextStringManager*)0x00EEDE90)

#define TSM_GETTEXTPTR(text) (g_CTextStringManager->GetString(L##text)->c_str())
#define TSM_GETTEXT(text) (g_CTexStringManager->GetString(L##text))
