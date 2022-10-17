#include "CPSTile.h"
#include "BSLib/multibyte.h"
#include "IFStatic.h"
bool CPSTile::OnCreateIMPL(long ln) {
    bool result = reinterpret_cast<bool(__thiscall*)(CPSTile*, long)>(0x00977650)(this, ln);
    CGWndBase *pCGwndBase = NULL;
    for (std::n_list<CGWndBase *>::const_iterator it = N00000707.begin();
         it != N00000707.end();
         ++it) {
        if((*it)->UniqueID() == 0)
        {
            pCGwndBase = *it;

            CIFStatic* m_version = (CIFStatic*) pCGwndBase;
            std::n_wstring m_text = m_version->GetText();

            if(m_text.find(L"Data") != std::string::npos)
                m_version->SetText(L"A7aKit -> Data");
            else
                m_version->SetText(L"A7aKit -> Version");

            m_version->m_FontTexture.SetColor(0xffff00);

        }
    }

    return result;
}

