#pragma once

#include "IFMainFrame.h"
#include "IFNPCTalk.h"

class CIF_NPCWindow : public CIFMainFrame
{
public:
	char pad_0x07BC[0xC]; //0x07BC
	CIF_NPCTalk* m_npcTalk; //0x07C8 
	char pad_0x07CC[0xC]; //0x07CC

}; //Size=0x07D8
