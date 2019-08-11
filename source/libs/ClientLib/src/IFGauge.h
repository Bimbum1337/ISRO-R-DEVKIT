#pragma once
#include "IFStatic.h"

class CIFGauge : public CIFStatic
{
public:
	float N00002200; //0x0380 
	float N00002201; //0x0384 
	char pad_0x0388[0x3C]; //0x0388

}; //Size=0x03C4