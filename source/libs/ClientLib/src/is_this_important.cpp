#include "StdAfx.h"
#include "is_this_important.h"

// is_this_important::SetSomething(int) .text 008B00A0 0000004A 00000004 00000004 R . . . . . .
int is_this_important::SetSomething(int someval)
{
	field_0 = someval;
	creation_ticks = GetTickCount();
	field_8 = 0;
	if (1000 * someval / 1440u) // 1440 number of minutes per day
	{
		field_C = 0;
		field_18 = 1;
		return 1;
	}
	return 0;
}
