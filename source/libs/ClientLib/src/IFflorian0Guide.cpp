#include "../../../DevKit_DLL/src/StdAfx.h"
#include "IFflorian0Guide.h"
#include "GEffSoundBody.h"

GFX_IMPLEMENT_DYNCREATE(CIFflorian0Guide, CIFDecoratedStatic)


bool CIFflorian0Guide::OnCreate(long ln)
{
	printf("> " __FUNCTION__ "(%d)\n", ln);
	CIFDecoratedStatic::OnCreate(ln);

	TB_Func_13("icon\\etc\\webgacha2_1.ddj", 0, 0);
	sub_634470("icon\\etc\\webgacha2_2.ddj");

	set_N00009BD4(2);
	set_N00009BD3(500);

	CGEffSoundBody::get()->PlaySound(L"snd_quest");

	return true;
}

int CIFflorian0Guide::OnClickEvent(int a1, int x, int y)
{
	printf("> " __FUNCTION__ "(%d, %d, %d)\n", a1, x, y);

	CGEffSoundBody::get()->PlaySound(L"snd_quest");

	return 0;
}

void CIFflorian0Guide::Func_41()
{
	printf("> " __FUNCTION__ "\n");

	CIFDecoratedStatic::Func_41();
	sub_633990();

}
