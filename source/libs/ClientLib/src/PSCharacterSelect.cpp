#include "PSCharacterSelect.h"
#include "Game.h"
#include "IFButton.h"
#include "IFFade.h"
#include "IFStatic.h"
#include "IFTextBox.h"
#include "IFWnd.h"
#include "Keyframe.h"
#include "World.h"
#include <BSLib/Debug.h>
#include <remodel/MemberFunctionHook.h>

GlobalVar<bool, 0x00EED9B8> g_bIsUnityServer;

const Keyframe frames_intro[] = {
        Keyframe(60.0f, -15.0f, 700.0f, 0.1f, 3.0f, 0.0f, 30.0f),
        Keyframe(60.0f, -15.0f, 660.0f, 0.1f, 3.0f, 0.0f, 30.0f),
};


bool CPSCharacterSelect::OnCreateIMPL(long ln) {
    PutDump("CPSCharacterSelect::OnCreate(%d)\n", ln);

    theApp.sub_8371D0();

    FUN_0085b400();

    SetProcessNetMsg(true);

    m_IRM.LoadFromFile("resinfo\\pscharacterselect.txt");
    m_IRM.CreateInterfaceSection("Select", this);
    m_IRM.CreateInterfaceSection("Info", m_IRM.GetResObj(GDR_STA_CHARINFO, 1));
    m_IRM.CreateInterfaceSection("Warning", m_IRM.GetResObj(GDR_STA_WPOPUP, 1));
    m_IRM.CreateInterfaceSection("Remain", m_IRM.GetResObj(GDR_STA_REMAINTIME, 1));
    m_IRM.CreateInterfaceSection("China", m_IRM.GetResObj(GDR_STA_CHINA, 1));
    m_IRM.CreateInterfaceSection("Europe", m_IRM.GetResObj(GDR_STA_EUROPE, 1));

    m_IRM.GetResObj(GDR_TEXT_MESSAGE2, 1)->ShowGWnd(false);

    if (g_bIsUnityServer) {
        m_IRM.CreateInterfaceSection("UnityServer",
                                     m_IRM.GetResObj(GDR_STA_UNITY_SERVER_NOTIFY, 1));
        m_IRM.GetResObj(GDR_STA_UNITY_SERVER_NOTIFY, 1)->ShowGWnd(true);
    }

    m_IRM.CreateInterfaceSection("ChangeName", m_IRM.GetResObj(GDR_STA_UNITY_SERVER_CHANGENAME, 1));
    m_IRM.CreateInterfaceSection("NameDuplicate", m_IRM.GetResObj(GDR_STA_NAME_DUPLICATE, 1));

    m_IRM.GetResObj(GDR_STA_SCREENUP, 1)->ApplyGlobalScale(0);
    m_IRM.GetResObj(GDR_STA_SCREENDOWN, 1)->ApplyGlobalScale(0);
    m_IRM.GetResObj(GDR_STA_TITLE, 1)->ApplyGlobalScale(0);
    m_IRM.GetResObj(GDR_STA_REGIONTITLE, 1)->ApplyGlobalScale(0);
    m_IRM.GetResObj(GDR_FADE, 1)->ApplyGlobalScale(0);

    wnd_rect a2 = m_IRM.GetResObj(GDR_STA_SCREENUP, 1)->GetBounds();

    wnd_rect v109 = m_IRM.GetResObj(GDR_STA_SCREENDOWN, 1)->GetBounds();

    const ClientResolutonData &res = CGame::GetClientDimensionStuff();

    int v12 = res.width - 209;

    int buttons_y = v109.top() + 27;

    // State: All chars visible
    m_IRM.GetResObj(GDR_BTN_CREATE, 1)->MoveGWnd(v12, buttons_y);
    m_IRM.GetResObj(GDR_BTN_BACK, 1)->MoveGWnd(v12 + 104, buttons_y);

    // State: One char selected
    m_IRM.GetResObj(GDR_BTN_START, 1)->MoveGWnd(v12 - 104, buttons_y);
    m_IRM.GetResObj(GDR_BTN_DELETE, 1)->MoveGWnd(v12, buttons_y);
    m_IRM.GetResObj(GDR_BTN_RESTORE, 1)->MoveGWnd(v12, buttons_y);
    m_IRM.GetResObj(GDR_BTN_BACK2, 1)->MoveGWnd(v12 + 104, buttons_y);
    m_IRM.GetResObj(GDR_STA_CHARINFO, 1)->MoveGWnd(res.width - 271, a2.bottom() + 41);

    // State: Char being deleted
    wnd_size size = m_IRM.GetResObj(GDR_STA_REMAINTIME, 1)->GetSize();
    m_IRM.GetResObj(GDR_STA_REMAINTIME, 1)->MoveGWnd((res.width - size.width) / 2, v109.bottom() - 102);

    m_IRM.GetResObj(GDR_TEXT_MESSAGE, 1)->MoveGWnd(v109.top() + 26, v109.bottom() + 29);
    m_IRM.GetResObj(GDR_TEXT_MESSAGE, 1)->SetGWndSize(res.width - 26, 100);

    m_IRM.GetResObj(GDR_TEXT_MESSAGE2, 1)->MoveGWnd(res.width - 701, 36);


    const ClientRes &client = theApp.GetRes();


    wnd_size v108 = m_IRM.GetResObj(GDR_STA_WPOPUP, 1)->GetSize();
    m_IRM.GetResObj(GDR_STA_WPOPUP, 1)->MoveGWnd((client.res[0].width - v108.width) / 2, (client.res[0].height - v108.height) / 2);

    v108 = m_IRM.GetResObj(GDR_STA_WPOPUP, 1)->GetSize();
    m_IRM.GetResObj(GDR_STA_UNITY_SERVER_NOTIFY, 1)->MoveGWnd((client.res[0].width - v108.width) / 2, (client.res[0].height - v108.height) / 2);
    m_IRM.GetResObj(GDR_STA_UNITY_SERVER_NOTIFY, 1)->ShowGWnd(false);

    v108 = m_IRM.GetResObj(GDR_STA_UNITY_SERVER_CHANGENAME, 1)->GetSize();
    m_IRM.GetResObj(GDR_STA_UNITY_SERVER_CHANGENAME, 1)->MoveGWnd((client.res[0].width - v108.width) / 2, (client.res[0].height - v108.height) / 2);
    m_IRM.GetResObj(GDR_STA_UNITY_SERVER_CHANGENAME, 1)->ShowGWnd(false);

    v108 = m_IRM.GetResObj(GDR_STA_NAME_DUPLICATE, 1)->GetSize();
    m_IRM.GetResObj(GDR_STA_NAME_DUPLICATE, 1)->MoveGWnd((client.res[0].width - v108.width) / 2, (client.res[0].height - v108.height) / 2);
    m_IRM.GetResObj(GDR_STA_NAME_DUPLICATE, 1)->ShowGWnd(false);

    m_IRM.GetResObj(GDR_BTN_PREV, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_BTN_NEXT, 1)->ShowGWnd(false);

    static int names[] = {
            GDR_STA_NAMECHANGE1,
            GDR_STA_NAMECHANGE2,
            GDR_STA_NAMECHANGE3,
            GDR_STA_NAMECHANGE4};

    for (int i = 0; i < 4; i++) {
        m_IRM.GetResObj(names[i], 1)->ShowGWnd(false);
    }

    m_IRM.GetResObj(GDR_BTN_CANCEL, 1)->MoveGWnd(v12 + 104, buttons_y);

    // Text Boxes on Idol Screen
    m_IRM.GetResObj<CIFTextBox>(GDR_TEXT_MESSAGE, 1)->SetLineHeight(15);
    m_IRM.GetResObj<CIFTextBox>(GDR_TEXT_CHINA, 1)->SetLineHeight(16);
    m_IRM.GetResObj<CIFTextBox>(GDR_TEXT_EUROPE, 1)->SetLineHeight(17);

    // Border Box for Europe Textbox on Idol Screen
    idol_label[0] = m_IRM.GetResObj<CIFStatic>(GDR_STA_EUROPE, 1);
    idol_label[0]->TB_Func_9(0);

    // Border Box for China Textbox on Idol Screen
    idol_label[1] = m_IRM.GetResObj<CIFStatic>(GDR_STA_CHINA, 1);
    idol_label[1]->TB_Func_9(0);


    m_IRM.GetResObj(GDR_STA_ISLAM, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_BTN_START, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_BTN_DELETE, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_BTN_RESTORE, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_BTN_BACK2, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_STA_CHARINFO, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_STA_WPOPUP, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_STA_REMAINTIME, 1)->ShowGWnd(false);

    m_IRM.GetResObj<CIFTextBox>(GDR_TB_INFO, 1)->SetLineHeight(15);

    CIFFade *screenfade = m_IRM.GetResObj<CIFFade>(GDR_SCREENFADE, 1);
    screenfade->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
    screenfade->ShowGWnd(false);

    CIFFade *fade = m_IRM.GetResObj<CIFFade>(GDR_FADE, 1);
    fade->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));
    fade->sub_6526E0(-128, 0, 1.5, 0.0, 1);

    m_IRM.GetResObj(GDR_LOADING_CHINA, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_LOADING_EUROPE, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_LOADINGFRAME, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_LOADING_STA, 1)->ShowGWnd(false);
    m_IRM.GetResObj(GDR_LOADINGG, 1)->ShowGWnd(false);

    FUN_00bbda70(1);

    GETMAP()->Func_1(0x6951);

    D3DXVECTOR3 loc(960, 0, 960);

    GETMAP()->Func_0(0x6951, loc);

    m_box.SetResource("res\\interface\\box.bsr", 1);
    m_box.SetLocation(D3DXVECTOR3(155, -20, 652));
    m_box.SetRotation(3.0);

    const D3DVECTOR box_loc[] = {
            {157.0f, -20.0f, 654.4f},
            {156.2f, -20.0f, 651.6f},
            {155.6f, -20.0f, 651.6f},
    };

    const float box_rot[] = {
            3.31f,
            3.03f,
            3.00f};

    const char *box_resources[] = {
            "res\\interface\\interface_idol_europe.bsr",
            "res\\interface\\interface_idol_china.bsr",
            "res\\interface\\interface_lizard.bsr"};


    for (int i = 0; i < 3; i++) {
        idols[i].SetResource(box_resources[i], 1);
        idols[i].SetLocation(box_loc[i]);
        idols[i].SetRotation(box_rot[i]);
    }


    field_0x220 = 0;

    // Map animation callback stuff
    idols[2].m_compound->Func_7(*this);
    // Something with animation speed
    idols[2].Func_3(0, 0, 0, 0, 1.0, 1.0);

    if (N0000098B == 0 || N0000098B == 10) {
        this->TriggerAnimation_Intro();
    }

    m_seconds_elapsed = 0.0f;
    m_minutes_elapsed = 0;

    field_0x11c = false;

    FUN_008560e0();

    if (g_bIsUnityServer)
        FUN_008548d0(true);

    WaitGWnd(false);

    return true;
}

void CPSCharacterSelect::FUN_0085b400() {
    reinterpret_cast<void(__thiscall *)(CPSCharacterSelect *)>(0x0085b400)(this);
}


HOOK_ORIGINAL_MEMBER(0x0085b1f0, &CPSCharacterSelect::TriggerAnimation_Intro);
void CPSCharacterSelect::TriggerAnimation_Intro() {
    FUN_00854860(m_IRM.GetResObj<CIFStatic>(GDR_STA_TITLE, 1), 255, 0.5f, 0.0f, 0);
    m_IRM.GetResObj<CIFStatic>(GDR_STA_REGIONTITLE, 1)->ShowGWnd(false);

    idol_label[0]->ShowGWnd(false);
    idol_label[1]->ShowGWnd(false);

    CIFButton *createBtn = m_IRM.GetResObj<CIFButton>(GDR_BTN_CREATE, 1);
    FUN_00854860(createBtn, 255, 0.5f, 0.0f, 0);
    wnd_pos createBtnPos = createBtn->GetPos();
    createBtn->MoveGWnd2(createBtnPos);

    CIFButton *backBtn = m_IRM.GetResObj<CIFButton>(GDR_BTN_CREATE, 1);
    FUN_00854860(backBtn, 255, 0.5f, 0.0f, 0);
    wnd_pos backBtnPos = backBtn->GetPos();
    createBtn->MoveGWnd2(backBtnPos);

    m_IRM.GetResObj<CIFButton>(GDR_BTN_CANCEL, 1)->ShowGWnd(false);

    m_cameraworking->sub_4E6630();

    for (int i = 0; i < size(frames_intro); i++) {
        m_cameraworking->AddKeyframe(static_cast<float>(i * i),
                                     frames_intro[i].position,
                                     frames_intro[i].rotation);
    }

    theApp.camera.origin = m_cameraworking->location;
    theApp.camera.rotation_to_world = m_cameraworking->rotation;

    m_cameraworking->float_F0 = 2.0;
    current_state = 0;
}

void CPSCharacterSelect::FUN_008560e0() {
    reinterpret_cast<void(__thiscall *)(CPSCharacterSelect *)>(0x008560e0)(this);
}

void CPSCharacterSelect::FUN_008548d0(bool a1) {
    reinterpret_cast<void(__thiscall *)(CPSCharacterSelect *, bool)>(0x008548d0)(this, a1);
}
void CPSCharacterSelect::FUN_00854860(CIFStatic *obj, unsigned char opacity, float time, float a4, char a5) {
    obj->sub_6526E0(obj->GetN00009BB9(), opacity, time, a4, a5);
}
