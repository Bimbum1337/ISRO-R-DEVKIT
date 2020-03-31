#pragma once

#include "NIFWnd.h"

class CNIFStatic : public CNIFWnd { // 872 bytes
public:
	virtual void SetText(wchar_t* format, ...);
	char pad[32];
	
};
