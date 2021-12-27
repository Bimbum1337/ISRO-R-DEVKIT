#include "IFTargetWindowJobPlayer.h"
#include "unsorted.h"
#include "IFStatic.h"
#include "TextStringManager.h"
#include "ICUser.h"

#include <remodel/MemberFunctionHook.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFTargetWindowJobPlayer, 0x00eea5bc)

GFX_IMPLEMENT_DYNCREATE_FN(CIFTargetWindowJobPlayer, CIFWnd)

enum {
    GDR_TWJP_JOB_ALIAS = 1, // CIFStatic
    GDR_TWJP_JOB_ICON = 10, // CIFStatic
    GDR_TWJP_JOB_GRADENAME = 11, // CIFStatic
    GDR_TWJP_JOB_GRADE = 12, // CIFStatic
    GDR_TWJP_KINDRED_MARK = 20, // CIFStatic
};

GFX_BEGIN_MESSAGE_MAP(CIFTargetWindowJobPlayer, CIFWnd)

GFX_END_MESSAGE_MAP()

bool CIFTargetWindowJobPlayer::OnCreate(long ln) {
    //printf("%s\n", __FUNCTION__);
    //return reinterpret_cast<bool (__thiscall *)(const CIFTargetWindowJobPlayer *, long)>(0x0069ac40)(this, ln);

    m_IRM.LoadFromFile("resinfo\\iftw_jobplayer_trijob2.txt");
    m_IRM.CreateInterfaceSection("Create", this);
    return true;
}

HOOK_ORIGINAL_MEMBER(0x0069ac90, &CIFTargetWindowJobPlayer::FUN_0069ac90);
void CIFTargetWindowJobPlayer::FUN_0069ac90(int objectId) {
    m_objectId = objectId;
    CICUser* pUser = static_cast<CICUser*>(GetCharacterObjectByID_MAYBE(m_objectId));
    if(pUser == NULL) {
        return;
    }
    m_IRM.GetResObj<CIFStatic>(GDR_TWJP_KINDRED_MARK, 1)->TB_Func_13(GetKindredTextureFilePath(pUser->GetSData()->m_nationality, 0), 0, 0);
    m_IRM.GetResObj<CIFStatic>(GDR_TWJP_JOB_ALIAS, 1)->SetText(pUser->GetName().c_str());
    CIFStatic* p_JOB_ICON = m_IRM.GetResObj<CIFStatic>(GDR_TWJP_JOB_ICON, 1);

    const wchar_t *title = NULL;

    TRIJOB_TYPE trijobType = pUser->GetJobType();
    if(trijobType == TRIJOB_TRADER) {
        p_JOB_ICON->TB_Func_13("interface\\targetwindow\\tw_job_merchant.ddj", 0, 0);

        if (pUser->GetSData()->m_nationality == 0) {
            title = L"UIIT_STT_CLASS_MERCHANT_%d";
        } else {
            title = L"UIIT_STT_CLASS_EU_MERCHANT_%d";
        }
    } else if (trijobType == TRIJOB_THIEF) {
        p_JOB_ICON->TB_Func_13("interface\\targetwindow\\tw_job_thief.ddj", 0, 0);

        if (pUser->GetSData()->m_nationality == 0) {
            title = L"UIIT_STT_CLASS_THIEF_%d";
        } else {
            title = L"UIIT_STT_CLASS_EU_THIEF_%d";
        }
    } else if (trijobType == TRIJOB_HUNTER) {
        p_JOB_ICON->TB_Func_13("interface\\targetwindow\\tw_job_hunter.ddj", 0, 0);

        if (pUser->GetSData()->m_nationality == 0) {
            title = L"UIIT_STT_CLASS_HUNTER_%d";
        } else {
            title = L"UIIT_STT_CLASS_EU_HUNTER_%d";
        }
    }

    CIFStatic* p_JOB_GRADENAME = m_IRM.GetResObj<CIFStatic>(GDR_TWJP_JOB_GRADENAME, 1);

    wchar_t buffer[0x100];
    swprintf(buffer, size(buffer), title, pUser->GetJobLevel());
    p_JOB_GRADENAME->SetText(TSM_GETTEXTPTR(buffer));

    m_IRM.GetResObj<CIFStatic>(GDR_TWJP_JOB_GRADE, 1)->SetTextFormatted(L"%d %s", pUser->GetJobLevel(), TSM_GETTEXTPTR(L"UIIT_STT_GRADE"));
}
