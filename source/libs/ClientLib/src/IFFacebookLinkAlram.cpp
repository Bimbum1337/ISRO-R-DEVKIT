#include "IFFacebookLinkAlram.h"
#include "GInterface.h"
#include "IFMessageBox.h"
#include <remodel/MemberFunctionHook.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFFacebookLinkAlram, 0x1177054)

HOOK_ORIGINAL_MEMBER(0x0055DA20, &CIFFacebookLinkAlram::OnFacebookNavigate)
void CIFFacebookLinkAlram::OnFacebookNavigate(CIFWnd* p_wnd,int confirmed)
{
    if(p_wnd->IsSame(GFX_RUNTIME_CLASS(CIFMessageBox))){
        if(confirmed == 1)
            ShellExecute(NULL, "open", "https://www.google.com", NULL, NULL, SW_SHOWNORMAL);

        CIFMessageBox* p_msgbox = (CIFMessageBox*) p_wnd;
        g_pCGInterface->sub_85D9C0(p_msgbox,0,0);
    }
}

bool CIFFacebookLinkAlram::OnCreateIMPL(long ln)
{
    return reinterpret_cast<bool (__thiscall *)(CIFFacebookLinkAlram *,long)>(0x0055DE40)(this,ln);
}