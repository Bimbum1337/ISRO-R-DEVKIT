#pragma once
#include "BufRender.h"
#include "IFStatic.h"
#include "IFButton.h"
#include "IFGauge.h"
#include "IFDecoratedStatic.h"
#include "IFStaticWithPictureClip.h"

class CIFPlayerMiniInfo : public CIFStatic
{
public:
	void Render() override;
private:
	CIFStatic* WindowSelectedOverlay; //0x0380 
	__int8 N0000126E; //0x0384 
	char pad_0x0385[0x3]; //0x0385
	CBufRender* BufRender; //0x0388 
	char pad_0x038C[0x4]; //0x038C
	CIFButton* RemainSkillPointButton; //0x0390 
	CIFGauge* HPGauge; //0x0394 
	CIFGauge* MPGauge; //0x0398 
	CIFStatic* PartyLeaderFlag; //0x039C 
	CIFStatic* ZerkPoint_1; //0x03A0 
	CIFStatic* ZerkPoint_2; //0x03A4 
	CIFStatic* ZerkPoint_3; //0x03A8 
	CIFStatic* ZerkPoint_4; //0x03AC 
	CIFStatic* ZerkPoint_5; //0x03B0 
	CIFButton* ZerkActivateButton; //0x03B4 
	CIFStatic* NameText; //0x03B8 
	CIFStatic* LevelText; //0x03BC 
	CIFStatic* HPText; //0x03C0 
	CIFStatic* MPText; //0x03C4 
	CIFStaticWithPictureClip* N0000125D; //0x03C8 
	CIFButton* ShowStatsButton; //0x03CC 
	CIFStatic* WindowAll; //0x03D0 
	CIFStatic* StrLabel; //0x03D4 
	CIFStatic* IntLabel; //0x03D8 
	CIFStatic* PhyAtkLabel; //0x03DC 
	CIFStatic* PhyDefLabel; //0x03E0 
	CIFStatic* MagAtkLabel; //0x03E4 
	CIFStatic* MagDefLabel; //0x03E8 
	CIFStatic* HitRateLabel; //0x03EC 
	CIFStatic* ParryRatioLabel; //0x03F0 
	CIFStatic* PhyBalanceLabel; //0x03F4 
	CIFStatic* MagBalanceLabel; //0x03F8 
	CIFStatic* STRDisplay; //0x03FC 
	CIFStatic* INTDisplay; //0x0400 
	CIFStatic* PhyAtkDisplay; //0x0404 
	CIFStatic* PhyDefDisplay; //0x0408 
	CIFStatic* MagAtkDisplay; //0x040C 
	CIFStatic* MagDefDisplay; //0x0410 
	CIFStatic* HitRateDisplay; //0x0414 
	CIFStatic* ParryRateDisplay; //0x0418 
	CIFStatic* PhyBalanceDisplay; //0x041C 
	CIFStatic* MagBalanceDisplay; //0x0420 
	CIFStatic* ZerkFaceOverlay; //0x0424 
	CIFStatic* ZerkWindowOverlay; //0x0428 
	CIFStatic* PKIcon; //0x042C 
	CIFStatic* ForfeitFlagIcon; //0x0430 
	CIFStatic* N00001242; //0x0434 
	CIFStatic* FortressProgressIcon; //0x0438 
	CIFDecoratedStatic* ZerkPointOverlay_1; //0x043C 
	CIFDecoratedStatic* ZerkPointOverlay_2; //0x0440 
	CIFDecoratedStatic* ZerkPointOverlay_3; //0x0444 
	CIFDecoratedStatic* ZerkPointOverlay_4; //0x0448 
	CIFDecoratedStatic* ZerkPointOverlay_5; //0x044C 
	char pad_0x0450[0x18]; //0x0450
	CIFStatic* HPWarningOverlay; //0x0468 
	CIFStatic* MPWarningOverlay; //0x046C 
};