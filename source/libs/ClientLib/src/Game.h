#pragma once
#include <string>
#include "GFXMainFrame/GFXMainFrame.h"
#include <GFX3DFunction/GFontTexture.h>
#include <GFXFileManagerLIB/IFileManager.h>
#include <BSLib/StringCheck.h>

#include "unsorted.h"
#include "GEffSoundBody.h"
#include "DxSound.h"
#include "RTLoading.h"
#include "IFConsole.h"
#include "is_this_important.h"

struct ClientResolutonData
{
    char pad_0000[36]; //0x0000
    int width; //0x0024
    int height; //0x0028
}; //Size: 0x002C

struct ClientRes
{
    char index;
    ClientResolutonData res[1]; //0x0004
}; //Size: 0x0030

struct WhatIsThis {
    undefined4 field_0;
    char field_4;
};

class CGame : public CGFXMainFrame {

public:
    /// \address 004F9CD0
    static const ClientResolutonData &GetClientDimensionStuff();

    static CStringCheck *GetBadwordFilter();

    /// \address 004f9d00
    static WhatIsThis& STA_FUN_004f9d00();

private:
    /// \address 00835240
    const ClientRes& sub_835240() const;


public:
	int N0000051E; //0x0490
	CGFontTexture* font; //0x0494
	char pad_0498[40]; //0x0498
	CDxSound* p_CDXSound; //0x04C0
	IFileManager* pFM_Media; //0x04C4
	IFileManager* pFM_Map; //0x04C8
	IFileManager* pFM_Data; //0x04CC
	IFileManager* pFM_Music; //0x04D0
	IFileManager* pFM_AdditionalData; //0x04D4
	IFileManager* pFM_Particles; //0x04D8
	IFileManager* m_RTLoading_FMs[5]; //0x04DC
	CGEffSoundBody* m_CGEffSoundBody; //0x04F0 4F0
	CIFConsole* m_Console; //0x04F4
	char pad_04F8[104]; //0x04F8
	int N00000884; //0x0560
	char pad_0564[8]; //0x0564
	int N00000887; //0x056C
	ClientRes N00000888; //0x0570
	char pad_05A0[44]; //0x05A0
	CRTLoading m_RTLoading; //0x05CC 5CC
	char pad_062C[280]; //0x062C
	std::string str_gateway_server; //0x0744
	std::string m_strGameType; //0x0760
	char pad_077C[4]; //0x077C
	std::string m_strRegKey; //0x0780
	std::string str_textdata_basepath; //0x079C 79C
	char pad_07B8[28]; //0x07B8
	short m_RelatedToDrvUpdate; //0x07D4 checked to be >= 2004
	char pad_07D6[14]; //0x07D6
	char b_RelatedToDrvUpdate; //0x07E4
	char pad_07E5[1]; //0x07E5
	short gateport; //0x07E6
	int m_version; //0x07E8 7E8
	char pad_07EC[4]; //0x07EC
	is_this_important N0000092E; //0x07F0 somewhat related to ticking?
	char pad_080C[4]; //0x080C
	int m_contentId; //0x0810 810
	int m_divisionId; //0x0814
	int m_gatewayId; //0x0818
	CGfxRuntimeClass* m_runtimeClass; //0x081C
	char N0000093A; //0x0820
	char pad_0821[55]; //0x0821
	int langId; //0x0858
	char pad_085C[28]; //0x085C
	std::string str_emblem_server; //0x0878
	std::string str_emblem_folder; //0x0894
	std::string str_intro_scriptname; //0x08B0
	std::string str_intro_soundtrack; //0x08CC
	CStringCheck * m_badWordFilter;
	char pad_08E8[120-4]; //0x08E8

	void SetWindowPos();
	int sub_83580(int arg);
	void LoadAndInitStuffIMPL(int a1);

	void InitGameAssets();
	void LoadTextfiles();
	void ResizeMainWindow();

	void ClientReadConfiguration();
	void LoadPK2s();
	void LoadFileManager();
	IFileManager* OpenPackFile(std::string pakfile, std::string passwd, int mode);

	void SplitCommandline();
	
	void InitializeAfterTitle();
	void sub_8371D0();

	ClientRes &GetRes();
	void sub_BA3FC0(int i, int i1);

	void *GetFont(int a2);
};

#define g_CGame ((CGame*)0x00EECE80)

// I am so sorry :cry:
#define theApp (*g_CGame)
