#pragma once

#include "IFWnd.h"
#include "IFStatic.h"
#include "IFButton.h"
#include "IFGauge.h"

class CIFPlayerInfo : public CIFWnd
{
public:
	CIFStatic* m_levelText; //0x036C 
	CIFStatic* m_currentExpValueText; //0x0370 
	CIFStatic* m_nextExpValueText; //0x0374 
	CIFStatic* m_statPointValueText; //0x0378 
	CIFStatic* m_honorPointValueText; //0x037C 
	CIFStatic* N000021BC; //0x0380 
	CIFStatic* m_hpValueText; //0x0384 
	CIFStatic* m_strengthValueText; //0x0388 
	CIFStatic* m_mpValueText; //0x038C 
	CIFStatic* m_intellectValueText; //0x0390 
	CIFButton* m_intellectPlusButton; //0x0394 
	CIFButton* m_strengthPlusButton; //0x0398 
	CIFGauge* m_hpGauge; //0x039C 
	CIFGauge* m_mpGauge; //0x03A0 
	CIFStatic* m_phyAtkValueText; //0x03A4 
	CIFStatic* m_phyDefValueText; //0x03A8 
	CIFStatic* m_phyBalanceValueText; //0x03AC 
	CIFStatic* m_hitRateValueText; //0x03B0 
	CIFStatic* m_magAtkValueText; //0x03B4 
	CIFStatic* m_magDefValueText; //0x03B8 
	CIFStatic* m_magBalanceValueText; //0x03BC 
	CIFStatic* m_parryRatioValueText; //0x03C0 
	CIFStatic* m_jobAliasValueText; //0x03C4 
	CIFStatic* N000021D1; //0x03C8 
	CIFStatic* m_jobLevelValueText; //0x03CC 
	CIFStatic* N000021D3; //0x03D0 
	CIFStatic* m_jobExpValueText; //0x03D4 
	CIFGauge* m_jobExpGauge; //0x03D8 

}; //Size=0x03DC