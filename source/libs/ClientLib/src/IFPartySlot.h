#pragma once

#include "IFWnd.h"
#include "IFStatic.h"
#include "IFGauge.h"
#include "IFStaticWithPictureClip.h"
#include "IFButton.h"

class CIFPartySlot : public CIFWnd
{
public:
	char pad_0x036C[0xC]; //0x036C
	CIFStatic* m_playerNameValueText; //0x0378 
	CIFStatic* m_guildNameValueText; //0x037C 
	CIFStatic* m_levelLabel; //0x0380 
	CIFStatic* m_levelValueText; //0x0384 
	CIFGauge* m_hpGauge; //0x0388 
	CIFGauge* m_mpGauge; //0x038C 
	CIFStaticWithPictureClip* m_playerPicture; //0x0390 
	CIFButton* m_leaveButton; //0x0394 
	char pad_0x0398[0x4]; //0x0398

}; //Size=0x039C