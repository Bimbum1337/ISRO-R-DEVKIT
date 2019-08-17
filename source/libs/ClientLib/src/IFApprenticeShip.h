#pragma once

#include "IFWnd.h"
#include "IFStaticWithPictureClip.h"
#include "IFApprenticeShipSlot.h"
#include "IFStatic.h"
#include "IFButton.h"
#include "IFSelectableArea.h"

class CIFApprenticeShip : public CIFWnd
{
public:
	char pad_0x036C[0x4]; //0x036C
	CIFStaticWithPictureClip* N00002206; //0x0370 
	CIFApprenticeShipSlot* m_apprenticeshipSlot0; //0x0374 
	CIFApprenticeShipSlot* m_apprenticeshipSlot1; //0x0378 
	CIFApprenticeShipSlot* m_apprenticeshipSlot2; //0x037C 
	CIFApprenticeShipSlot* m_apprenticeshipSlot3; //0x0380 
	CIFApprenticeShipSlot* m_apprenticeshipSlot4; //0x0384 
	CIFApprenticeShipSlot* m_apprenticeshipSlot5; //0x0388 
	CIFApprenticeShipSlot* m_apprenticeshipSlot6; //0x038C 
	CIFStatic* N0000220E; //0x0390 
	CIFStatic* N0000220F; //0x0394 
	CIFStatic* N00002210; //0x0398 
	CIFStatic* N00002211; //0x039C 
	CIFStatic* N00002212; //0x03A0 
	CIFStatic* N00002213; //0x03A4 
	CIFButton* N00002217; //0x03A8 
	CIFButton* N00002218; //0x03AC 
	CIFButton* N00002219; //0x03B0 
	CIFSelectableArea* N0000221A; //0x03B4 
	char pad_0x03B8[0x1AC]; //0x03B8

}; //Size=0x0564