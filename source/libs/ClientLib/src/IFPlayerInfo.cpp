#include "IFPlayerInfo.h"
#include "CharacterDependentData.h"
#include "GInterface.h"
#include "GlobalDataManager.h"
#include "ICPlayer.h"
#include "TextStringManager.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFPlayerInfo, 0x00eea7e8)
GFX_IMPLEMENT_DYNCREATE_FN(CIFPlayerInfo, CIFWnd)

enum {
    GDR_PI_BTN_ADDHP = 14,
    GDR_PI_BTN_ADDMP = 15,
};

GFX_BEGIN_MESSAGE_MAP(CIFPlayerInfo, CIFWnd)
ONG_COMMAND(GDR_PI_BTN_ADDHP, &CIFPlayerInfo::OnClick_IncrementStr)
ONG_COMMAND(GDR_PI_BTN_ADDMP, &CIFPlayerInfo::OnClick_IncrementInt)
GFX_END_MESSAGE_MAP()

bool CIFPlayerInfo::OnCreate(long ln) {

    m_IRM.LoadFromFile("resinfo\\ifplayerinfo_trijob2.txt");

    m_IRM.CreateInterfaceSection("Create", this);


    m_pGDR_PI_TEXT_LEVEL = m_IRM.GetResObj<CIFStatic>(2, 1);
    m_pGDR_PI_TEXT_CURXP2 = m_IRM.GetResObj<CIFStatic>(5, 1);
    m_pGDR_PI_TEXT_NEXTXP2 = m_IRM.GetResObj<CIFStatic>(7, 1);
    m_pGDR_PI_TEXT_STAT2 = m_IRM.GetResObj<CIFStatic>(9, 1);
    m_pGDR_PI_HONOR_DATA = m_IRM.GetResObj<CIFStatic>(0x33, 1);
    m_pGDR_PI_TEXT_HONOR_STATIC = m_IRM.GetResObj<CIFStatic>(0x32, 1);
    m_pGDR_PI_TEXT_HP_DAT = m_IRM.GetResObj<CIFStatic>(0xc, 1);
    m_pGDR_PI_TEXT_MP_DAT = m_IRM.GetResObj<CIFStatic>(0xd, 1);
    m_pGDR_PI_TEXT_STRENGTH_DAT = m_IRM.GetResObj<CIFStatic>(0x12, 1);
    m_pGDR_PI_TEXT_INTELLECT_DAT = m_IRM.GetResObj<CIFStatic>(0x13, 1);
    m_pGDR_PI_TEXT_PHYATT_DAT = m_IRM.GetResObj<CIFStatic>(0x22, 1);
    m_pGDR_PI_TEXT_PHYDEF_DAT = m_IRM.GetResObj<CIFStatic>(0x23, 1);
    m_pGDR_PI_TEXT_PHYBAL_DAT = m_IRM.GetResObj<CIFStatic>(0x24, 1);
    m_pGDR_PI_TEXT_HIT_DAT = m_IRM.GetResObj<CIFStatic>(0x25, 1);
    m_pGDR_PI_TEXT_MAGATT_DAT = m_IRM.GetResObj<CIFStatic>(0x2a, 1);
    m_pGDR_PI_TEXT_MAGDEF_DAT = m_IRM.GetResObj<CIFStatic>(0x2b, 1);
    m_pGDR_PI_TEXT_MAGBAL_DAT = m_IRM.GetResObj<CIFStatic>(0x2c, 1);
    m_pGDR_PI_TEXT_PARRY_DAT = m_IRM.GetResObj<CIFStatic>(0x2d, 1);
    m_pGDR_PI_JOB_ALIAS = m_IRM.GetResObj<CIFStatic>(70, 1);
    m_pGDR_PI_JOB_ICON = m_IRM.GetResObj<CIFStatic>(71, 1);
    m_pGDR_PI_JOB_TITLE = m_IRM.GetResObj<CIFStatic>(72, 1);
    m_pGDR_PI_JOB_GRADE = m_IRM.GetResObj<CIFStatic>(73, 1);
    m_pGDR_PI_JOB_EXP = m_IRM.GetResObj<CIFStatic>(75, 1);
    m_pGDR_PI_JOB_EXP_GAUGE = m_IRM.GetResObj<CIFGauge>(74, 1);
    m_pGDR_PI_BTN_ADDHP = m_IRM.GetResObj<CIFButton>(14, 1);
    m_pGDR_PI_BTN_ADDMP = m_IRM.GetResObj<CIFButton>(15, 1);
    m_pGDR_PI_GAUGE_HPGAUGE = m_IRM.GetResObj<CIFGauge>(20, 1);
    m_pGDR_PI_GAUGE_MPGAUGE = m_IRM.GetResObj<CIFGauge>(21, 1);


    m_pGDR_PI_BTN_ADDMP->FUN_00656640("interface\\ifcommon\\com_plus_button_disable.ddj");
    m_pGDR_PI_BTN_ADDHP->FUN_00656640("interface\\ifcommon\\com_plus_button_disable.ddj");

    m_pGDR_PI_GAUGE_HPGAUGE->m_valueFg = 0.0f;
    m_pGDR_PI_GAUGE_MPGAUGE->m_valueFg = 0.0f;
    m_pGDR_PI_GAUGE_HPGAUGE->m_valueBg = 0.0f;
    m_pGDR_PI_GAUGE_MPGAUGE->m_valueBg = 0.0f;
    m_pGDR_PI_GAUGE_HPGAUGE->field_0x38c = 0.1f;
    m_pGDR_PI_GAUGE_MPGAUGE->field_0x38c = 0.1f;


    m_pGDR_PI_TEXT_PHYATT_DAT->SetTextFormatted(L"%d ~ %d",
                                                g_CCharacterDependentData.FUN_00987090().field_0,
                                                g_CCharacterDependentData.FUN_00987090().field_4);

    m_pGDR_PI_TEXT_PHYDEF_DAT->SetTextFormatted(L"%d",
                                                g_CCharacterDependentData.FUN_00987090().field_10);

    m_pGDR_PI_TEXT_PHYBAL_DAT->SetText(L"");

    m_pGDR_PI_TEXT_HIT_DAT->SetTextFormatted(L"%d",
                                             g_CCharacterDependentData.FUN_00987090().field_14);

    m_pGDR_PI_TEXT_MAGATT_DAT->SetTextFormatted(L"%d ~ %d",
                                                g_CCharacterDependentData.FUN_00987090().field_8,
                                                g_CCharacterDependentData.FUN_00987090().field_C);

    m_pGDR_PI_TEXT_MAGDEF_DAT->SetTextFormatted(L"%d",
                                                g_CCharacterDependentData.FUN_00987090().field_12);

    m_pGDR_PI_TEXT_MAGBAL_DAT->SetText(L"");

    m_pGDR_PI_TEXT_PARRY_DAT->SetTextFormatted(L"%d",
                                               g_CCharacterDependentData.FUN_00987090().field_16);

    return true;
}

void CIFPlayerInfo::OnUpdate() {
    if (((g_pCICPlayer != NULL) && (g_pCICPlayer->GetMaxHp() == 0)) ||
        (IsVisible() == 0) ||
        (g_pCICPlayer == NULL)) {
        return;
    }

    m_IRM.GetResObj<CIFWnd>(1, 1)->SetText(g_pCICPlayer->GetCharName().c_str());

    m_pGDR_PI_TEXT_LEVEL->SetTextFormatted(TSM_GETTEXTPTR(L"UIIT_STT_LV_LEVEL"), g_pCICPlayer->GetCurrentLevel());

    m_pGDR_PI_TEXT_CURXP2->SetTextFormatted(L"%I64d", g_pCICPlayer->GetCurrentExp());

    m_pGDR_PI_TEXT_NEXTXP2->SetTextFormatted(L"%I64d", g_CGlobalDataManager->GetLevelData(g_pCICPlayer->GetCurrentLevel()).m_expC);

    m_pGDR_PI_TEXT_STAT2->SetTextFormatted(L"%d", g_pCICPlayer->GetStatPointAvailable());

    if (g_CCharacterDependentData.IsInTrainingCamp()) {
        int points = g_CCharacterDependentData.FUN_00993120(g_pCICPlayer->GetCharName());

        if (points != 0) {
            m_pGDR_PI_HONOR_DATA->SetTextFormatted(L"%d", points);
            m_pGDR_PI_TEXT_HONOR_STATIC->ShowGWnd(true);
        }
    } else {
        m_pGDR_PI_HONOR_DATA->SetText(TSM_GETTEXTPTR(L"UIIT_STT_TC_CAMP_NOT_JOIN"));
        m_pGDR_PI_TEXT_HONOR_STATIC->ShowGWnd(true);
    }

    m_pGDR_PI_BTN_ADDMP->SetEnabledState(g_pCICPlayer->GetStatPointAvailable() != 0);
    m_pGDR_PI_BTN_ADDHP->SetEnabledState(g_pCICPlayer->GetStatPointAvailable() != 0);

    float maxHp = static_cast<float>(g_pCICPlayer->GetMaxHp());
    float currentHp = static_cast<float>(min(g_pCICPlayer->FUN_009c7880(), g_pCICPlayer->GetMaxHp()));
    m_pGDR_PI_GAUGE_HPGAUGE->m_valueFg = currentHp / maxHp;
    m_pGDR_PI_GAUGE_HPGAUGE->m_valueBg = currentHp / maxHp;

    float currentMp = static_cast<float>(min(g_pCICPlayer->GetCurrentMp(), g_pCICPlayer->GetMaxMp()));
    float maxMp = static_cast<float>(g_pCICPlayer->GetMaxMp());
    m_pGDR_PI_GAUGE_MPGAUGE->m_valueFg = currentMp / maxMp;
    m_pGDR_PI_GAUGE_MPGAUGE->m_valueBg = currentMp / maxMp;

    m_pGDR_PI_TEXT_LEVEL->Func_50(TSM_GETTEXTPTR(L"UIIT_STT_LV_LEVEL"), g_pCICPlayer->GetCurrentLevel());

    m_pGDR_PI_TEXT_CURXP2->Func_50(L"%I64d", g_pCICPlayer->GetCurrentExp());

    m_pGDR_PI_TEXT_NEXTXP2->Func_50(L"%I64d", g_CGlobalDataManager->GetLevelData(g_pCICPlayer->GetCurrentLevel()).m_expC);

    m_pGDR_PI_TEXT_STAT2->Func_50(L"%d", g_pCICPlayer->GetStatPointAvailable());

    if (g_CCharacterDependentData.IsInTrainingCamp()) {
        int points = g_CCharacterDependentData.FUN_00993120(g_pCICPlayer->GetCharName());

        if (points != 0) {
            m_pGDR_PI_HONOR_DATA->Func_50(L"%d", points);
            m_pGDR_PI_TEXT_HONOR_STATIC->ShowGWnd(true);
        }
    }

    m_pGDR_PI_TEXT_HP_DAT->Func_50(L"%d / %d",
                                   min(g_pCICPlayer->FUN_009c7880(), g_pCICPlayer->GetMaxHp()),
                                   g_pCICPlayer->GetMaxHp());

    m_pGDR_PI_TEXT_MP_DAT->Func_50(L"%d / %d",
                                   min(g_pCICPlayer->GetCurrentMp(), g_pCICPlayer->GetMaxMp()),
                                   g_pCICPlayer->GetMaxMp());


    m_pGDR_PI_TEXT_STRENGTH_DAT->Func_50(L"%d", g_pCICPlayer->GetStrength());
    m_pGDR_PI_TEXT_INTELLECT_DAT->Func_50(L"%d", g_pCICPlayer->GetIntelligence());


    m_pGDR_PI_TEXT_PHYATT_DAT->Func_50(L"%d ~ %d",
                                       g_CCharacterDependentData.FUN_00987090().field_0,
                                       g_CCharacterDependentData.FUN_00987090().field_4);

    m_pGDR_PI_TEXT_PHYDEF_DAT->Func_50(L"%d",
                                       g_CCharacterDependentData.FUN_00987090().field_10);

    {
        int value1 = (g_pCICPlayer->GetCurrentLevel() * 2 + g_pCICPlayer->GetStrength() + 14) * 100;
        // was float value2 = ((g_pCICPlayer->GetCurrentLevel() - 1) * 7 + 56) * 0.857142865657806;
        int value2 = (g_pCICPlayer->GetCurrentLevel() + 7) * 6;

        // Cap at 120 %
        int value3 = min(120, value1 / value2);

        m_pGDR_PI_TEXT_PHYBAL_DAT->Func_50(L"%d %%", value3);
    }

    m_pGDR_PI_TEXT_HIT_DAT->Func_50(L"%d",
                                    g_CCharacterDependentData.FUN_00987090().field_14);

    m_pGDR_PI_TEXT_MAGATT_DAT->Func_50(L"%d ~ %d",
                                       g_CCharacterDependentData.FUN_00987090().field_8,
                                       g_CCharacterDependentData.FUN_00987090().field_C);

    m_pGDR_PI_TEXT_MAGDEF_DAT->Func_50(L"%d",
                                       g_CCharacterDependentData.FUN_00987090().field_12);

    {
        float value1 = g_pCICPlayer->GetIntelligence() * 100;
        float value2 = (g_pCICPlayer->GetCurrentLevel() + 7) * 4;

        // Cap at 120 %
        float value3 = min(120, value1 / value2);
        m_pGDR_PI_TEXT_MAGBAL_DAT->Func_50(L"%d %%", static_cast<int>(value3));
    }

    m_pGDR_PI_TEXT_PARRY_DAT->Func_50(L"%d",
                                      g_CCharacterDependentData.FUN_00987090().field_16);


    const std::n_wstring &jobAlias = g_pCICPlayer->GetJobAlias();

    if (jobAlias.length() == 0) {
        m_pGDR_PI_JOB_ALIAS->SetTextFormatted(L"<%s>", TSM_GETTEXT(L"UIIT_STT_NONE"));
    } else {
        m_pGDR_PI_JOB_ALIAS->SetText(jobAlias.c_str());
    }


    undefined1 jobType = g_pCICPlayer->FUN_009db0d0();
    if (jobType == 0) {
        m_pGDR_PI_JOB_ICON->TB_Func_13("", 0, 0);
        m_pGDR_PI_JOB_TITLE->SetTextFormatted(L"<%s>", TSM_GETTEXTPTR(L"UIIT_STT_NONE"));
        m_pGDR_PI_JOB_GRADE->SetText(L"");
        m_pGDR_PI_JOB_EXP_GAUGE->m_valueBg = 0.0f;
        m_pGDR_PI_JOB_EXP_GAUGE->m_valueFg = 0.0f;
        m_pGDR_PI_JOB_EXP->SetText(L"0 %");
    } else {
        int jobLevel = g_pCICPlayer->GetJobLevel();
        const CLevelData::SData &levelData = g_CGlobalDataManager->GetLevelData(jobLevel);

        const wchar_t *title = NULL;
        int requiredExp = -1;

        if (jobType == 1) {
            m_pGDR_PI_JOB_ICON->TB_Func_13("interface\\ifcommon\\com_job_merchant.ddj", 0, 0);

            requiredExp = levelData.m_jobExpTrader;

            if (g_pCICPlayer->Func_36().m_nationality == 0) {
                title = L"UIIT_STT_CLASS_MERCHANT_%d";
            } else {
                title = L"UIIT_STT_CLASS_EU_MERCHANT_%d";
            }
        } else if (jobType == 2) {
            m_pGDR_PI_JOB_ICON->TB_Func_13("interface\\ifcommon\\com_job_thief.ddj", 0, 0);

            requiredExp = levelData.m_jobExpRobber;

            if (g_pCICPlayer->Func_36().m_nationality == 0) {
                title = L"UIIT_STT_CLASS_THIEF_%d";
            } else {
                title = L"UIIT_STT_CLASS_EU_THIEF_%d";
            }
        } else if (jobType == 3) {
            m_pGDR_PI_JOB_ICON->TB_Func_13("interface\\ifcommon\\com_job_hunter.ddj", 0, 0);

            requiredExp = levelData.m_jobExpHunter;

            if (g_pCICPlayer->Func_36().m_nationality == 0) {
                title = L"UIIT_STT_CLASS_HUNTER_%d";
            } else {
                title = L"UIIT_STT_CLASS_EU_HUNTER_%d";
            }
        }

        wchar_t buffer[0x100];
        swprintf(buffer, size(buffer), title, jobLevel);
        m_pGDR_PI_JOB_TITLE->SetText(TSM_GETTEXTPTR(buffer));
        m_pGDR_PI_JOB_GRADE->SetTextFormatted(L"%d %s", jobLevel, TSM_GETTEXTPTR(L"UIIT_STT_GRADE"));

        if (requiredExp != -1) {
            int currentExperience = g_pCICPlayer->GetCurrentJobExperiencePoints();

            m_pGDR_PI_JOB_EXP_GAUGE->m_valueFg = static_cast<float>(currentExperience) / static_cast<float>(requiredExp);
            m_pGDR_PI_JOB_EXP_GAUGE->m_valueBg = m_pGDR_PI_JOB_EXP_GAUGE->m_valueFg;

            m_pGDR_PI_JOB_EXP->SetTextFormatted(L"%d%% (%d)",
                                                static_cast<int>(static_cast<float>(currentExperience) / static_cast<float>(requiredExp) * 100.0f),
                                                currentExperience);
        } else {
            m_pGDR_PI_JOB_EXP_GAUGE->m_valueFg = 1.0f;
            m_pGDR_PI_JOB_EXP_GAUGE->m_valueBg = 1.0f;

            m_pGDR_PI_JOB_EXP->SetText(L"100%");
        }
    }
}

void CIFPlayerInfo::ShowGWnd(bool bVisible) {
    if(((bVisible != false) && g_pCICPlayer != NULL) && (g_pCICPlayer->GetStrength() != 0)) {
        m_pGDR_PI_GAUGE_HPGAUGE->m_valueBg = static_cast<float>(g_pCICPlayer->FUN_009c7880()) / g_pCICPlayer->GetStrength() * 10.0f;
        m_pGDR_PI_GAUGE_HPGAUGE->m_valueFg = m_pGDR_PI_GAUGE_HPGAUGE->m_valueBg;
        m_pGDR_PI_GAUGE_MPGAUGE->m_valueBg = static_cast<float>(g_pCICPlayer->FUN_009c7880()) / g_pCICPlayer->GetIntelligence() * 10.0f;
        m_pGDR_PI_GAUGE_MPGAUGE->m_valueFg = m_pGDR_PI_GAUGE_MPGAUGE->m_valueBg;
    }
    CIFWnd::ShowGWnd(bVisible);
    //reinterpret_cast<void(__thiscall *)(CIFPlayerInfo *, bool)>(0x006b8310)(this, bVisible);
}

void CIFPlayerInfo::OnClick_IncrementStr() {
    g_pCGInterface->RequestStatIncrement(0x4b, 1, 0, 1);
}

void CIFPlayerInfo::OnClick_IncrementInt() {
    g_pCGInterface->RequestStatIncrement(0x4b, 2, 0, 1);
}
