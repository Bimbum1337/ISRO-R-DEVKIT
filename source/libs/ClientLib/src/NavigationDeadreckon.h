#pragma once

#include <d3dx9.h>
#include "GlobalHelpersThatHaveNoHomeYet.h"

class CNavigationDeadreckon
{
public:
	CNavigationDeadreckon(void);
	virtual ~CNavigationDeadreckon(void);

    void MoveTo(uregion &region, D3DVECTOR &coord);

    void MoveTo(uregion region, D3DVECTOR coord);

private:
	int N0000093D; //0x0004
	int N0000093E; //0x0008
	char pad_000C[4]; //0x000C
	D3DXVECTOR3 target_location; //0x0010
	char MoveRequestPending; //0x001C
	char pad_001D[3]; //0x001D
	int N00000942; //0x0020
	char N00000943; //0x0024
	char pad_0025[3]; //0x0025
	int N00000944; //0x0028
	int N00000945; //0x002C
	float N00000946; //0x0030
	char pad_0034[12]; //0x0034
	float view_direction; //0x0040
	int N0000094B; //0x0044
	int NotAllowedToMove; //0x0048
	int MoveBySkill_MAYBE; //0x004C
};

