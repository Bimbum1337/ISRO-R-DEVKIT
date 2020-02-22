#pragma once

#include "IFWnd.h"

class CIFTimerWnd : public CIFWnd
{
public:
	char pad_0x036C[0x20]; //0x036C
	CIFStatic* m_number0; //0x038C 
	CIFStatic* m_number1; //0x0390 
	CIFStatic* m_colon; //0x0394 
	CIFStatic* m_number2; //0x0398 
	CIFStatic* m_number3; //0x039C 
	CIFStatic* N00006506; //0x03A0 
	CIFStatic* N00006507; //0x03A4 
	CIFStatic* N0000650B; //0x03A8 

}; //Size=0x03AC