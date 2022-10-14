#include "IFflorian0Guide.h"
#include <BSLib/Debug.h>
#include "GEffSoundBody.h"
#include "GInterface.h"

GFX_IMPLEMENT_DYNCREATE(CIFflorian0Guide, CIFDecoratedStatic)

bool CIFflorian0Guide::OnCreate(long ln)
{
	BS_DEBUG_LOW("> " __FUNCTION__ "(%d)", ln);
    CIFDecoratedStatic::OnCreate(ln);

    TB_Func_13("interface\\bimbum\\itemmall_1.ddj", 0, 0);
    sub_634470("interface\\bimbum\\itemmall_2.ddj");

    set_N00009BD4(20);
    set_N00009BD3(100);

    return true;
}

int CIFflorian0Guide::OnMouseLeftUp(int a1, int x, int y)
{
	BS_DEBUG_LOW("> " __FUNCTION__ "(%d, %d, %d)", a1, x, y);

	CGEffSoundBody::get()->PlaySound(L"snd_quest");
    MessageBox(NULL, TEXT("Hello World"), TEXT("Hello World"), MB_OK);

	return 0;
}

void CIFflorian0Guide::OnCIFReady()
{
	BS_DEBUG_LOW("> " __FUNCTION__);

	CIFDecoratedStatic::OnCIFReady();
	sub_633990();
}
