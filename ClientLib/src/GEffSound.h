#pragma once

#include "GObj.h"

class CGEffSound : public CGObj
{
	// this class is pure virtual / abstract

	// 30 virtual methods in total, CGObj has 7, 23 methods left

public:
	virtual void Func_7() = 0;
	virtual void Func_8() = 0;
	virtual void Func_9() = 0;
	virtual void PlaySound(const wchar_t *sndFile) = 0;
	virtual void Func_11() = 0;
	virtual void Func_12() = 0;
	virtual void Func_13() = 0;
	virtual void Func_14() = 0;
	virtual void Func_15() = 0;
	virtual void Func_16() = 0;
	virtual void Func_17() = 0;
	virtual void Func_18(int) = 0;
	virtual void Func_19() = 0;
	virtual void Func_20() = 0;
	virtual void Func_21() = 0;
	virtual void Func_22() = 0;
	virtual void Func_23() = 0;
	virtual void Func_24() = 0;
	virtual void Func_25() = 0;
	virtual void Func_26() = 0;
	virtual void Func_27() = 0;
	virtual void Func_28() = 0;
	virtual void Func_29() = 0;
};
