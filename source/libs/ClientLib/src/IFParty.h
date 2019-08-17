#pragma once

#include "IFWnd.h"
#include "IFPartySlot.h"
#include "IFStaticWithPictureClip.h"
#include "IFButton.h"
#include "IFStatic.h"
#include "IFGauge.h"

class CIFParty : public CIFWnd
{
public:
	CIFPartySlot* m_partySlot0; //0x036C 
	CIFPartySlot* m_partySlot1; //0x0370 
	CIFPartySlot* m_partySlot2; //0x0374 
	CIFPartySlot* m_partySlot3; //0x0378 
	CIFPartySlot* m_partySlot4; //0x037C 
	CIFPartySlot* m_partySlot5; //0x0380 
	CIFPartySlot* m_partySlot6; //0x0384 
	CIFStaticWithPictureClip* m_leaderPlayerPicture; //0x0388 
	CIFButton* m_dismissButton; //0x038C 
	CIFStatic* m_leaderLevelLabel; //0x0390 
	CIFStatic* m_leaderLevelValueText; //0x0394 
	CIFStatic* m_leaderNameValueText; //0x0398 
	CIFStatic* m_leaderGuildNameValueText; //0x039C 
	CIFGauge* m_leaderHpGauge; //0x03A0 
	CIFGauge* m_leaderMpGauge; //0x03A4 
	CIFStatic* m_leaderFlagIcon; //0x03A8 
	CIFStatic* m_leaderRaceIcon; //0x03AC 
	char pad_0x03B0[0x4]; //0x03B0

}; //Size=0x03B4