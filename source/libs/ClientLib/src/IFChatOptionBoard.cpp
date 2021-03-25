#include <BSLib/Debug.h>
#include "IFChatOptionBoard.h"
#include "Game.h"
#include <remodel/MemberFunctionHook.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFChatOptionBoard, 0x00eec128)

GFX_IMPLEMENT_DYNCREATE_FN(CIFChatOptionBoard, CIFWnd)

#define GDR_COB_CB_GAME 14
#define GDR_COB_CB_PARTY 13
#define GDR_COB_CB_STATUS 12
#define GDR_COB_CB_FIGHT 11
#define GDR_COB_CB_GAIN 10

GFX_BEGIN_MESSAGE_MAP(CIFChatOptionBoard, CIFWnd)
            ONG_COMMAND(GDR_COB_CB_GAME, &CIFChatOptionBoard::OnOptionChanged)
            ONG_COMMAND(GDR_COB_CB_PARTY, &CIFChatOptionBoard::OnOptionChanged)
            ONG_COMMAND(GDR_COB_CB_STATUS, &CIFChatOptionBoard::OnOptionChanged)
            ONG_COMMAND(GDR_COB_CB_FIGHT, &CIFChatOptionBoard::OnOptionChanged)
            ONG_COMMAND(GDR_COB_CB_GAIN, &CIFChatOptionBoard::OnOptionChanged)
GFX_END_MESSAGE_MAP()

HOOK_ORIGINAL_MEMBER(0x007a9400, &CIFChatOptionBoard::IsGainChecked)

bool CIFChatOptionBoard::IsGainChecked() const {
    return m_pGDR_COB_CB_GAIN->GetCheckedState_MAYBE();
}

HOOK_ORIGINAL_MEMBER(0x007a9410, &CIFChatOptionBoard::IsFightChecked);

bool CIFChatOptionBoard::IsFightChecked() const {
    return m_pGDR_COB_CB_FIGHT->GetCheckedState_MAYBE();
}

HOOK_ORIGINAL_MEMBER(0x007a9420, &CIFChatOptionBoard::IsStatusChecked);

bool CIFChatOptionBoard::IsStatusChecked() const {
    return m_pGDR_COB_CB_STATUS->GetCheckedState_MAYBE();
}

HOOK_ORIGINAL_MEMBER(0x007a9430, &CIFChatOptionBoard::IsPartyChecked);

bool CIFChatOptionBoard::IsPartyChecked() const {
    return m_pGDR_COB_CB_PARTY->GetCheckedState_MAYBE();
}

HOOK_ORIGINAL_MEMBER(0x007a9440, &CIFChatOptionBoard::IsGameChecked);

bool CIFChatOptionBoard::IsGameChecked() const {
    return m_pGDR_COB_CB_GAME->GetCheckedState_MAYBE();
}

bool CIFChatOptionBoard::On3DEvent_MAYBE(Event3D *) {
    return true;
}

void CIFChatOptionBoard::OnOptionChanged() {
    char buffer[0x200];
    sprintf_s(buffer, "%s\\Setting\\chop.dat", theApp.GetWorkingDir());

    FILE *file = fopen(buffer, "wb+");
    if (file != NULL) {
        bool data[5];
        data[0] = m_pGDR_COB_CB_GAIN->GetCheckedState_MAYBE();
        data[1] = m_pGDR_COB_CB_FIGHT->GetCheckedState_MAYBE();
        data[2] = m_pGDR_COB_CB_STATUS->GetCheckedState_MAYBE();
        data[3] = m_pGDR_COB_CB_PARTY->GetCheckedState_MAYBE();
        data[4] = m_pGDR_COB_CB_GAME->GetCheckedState_MAYBE();
        fwrite(&data[0], 1, 5, file);
        fclose(file);
    }
}

bool CIFChatOptionBoard::OnCreate(long ln) {
    m_IRM.LoadFromFile("resinfo\\ifchatoptionboard.txt");
    m_IRM.CreateInterfaceSection("Create", this);

    m_pGDR_COB_CB_GAIN = m_IRM.GetResObj<CIFCheckBox>(GDR_COB_CB_GAIN, 1);
    m_pGDR_COB_CB_FIGHT = m_IRM.GetResObj<CIFCheckBox>(GDR_COB_CB_FIGHT, 1);
    m_pGDR_COB_CB_STATUS = m_IRM.GetResObj<CIFCheckBox>(GDR_COB_CB_STATUS, 1);
    m_pGDR_COB_CB_PARTY = m_IRM.GetResObj<CIFCheckBox>(GDR_COB_CB_PARTY, 1);
    m_pGDR_COB_CB_GAME = m_IRM.GetResObj<CIFCheckBox>(GDR_COB_CB_GAME, 1);

    char buffer[0x200];
    sprintf_s(buffer, "%s\\Setting\\chop.dat", theApp.GetWorkingDir());

    FILE *file = fopen(buffer, "rb+");
    if (file == NULL) {
        m_pGDR_COB_CB_FIGHT->FUN_00656d50(false);
        return true;
    }

    char config[5];
    fread_s(&config[0], sizeof(config), 1, 5, file);

    m_pGDR_COB_CB_GAIN->FUN_00656d50(config[0] != 0);
    m_pGDR_COB_CB_FIGHT->FUN_00656d50(config[1] != 0);
    m_pGDR_COB_CB_STATUS->FUN_00656d50(config[2] != 0);
    m_pGDR_COB_CB_PARTY->FUN_00656d50(config[3] != 0);
    m_pGDR_COB_CB_GAME->FUN_00656d50(config[4] != 0);

    fclose(file);

    return true;
}
