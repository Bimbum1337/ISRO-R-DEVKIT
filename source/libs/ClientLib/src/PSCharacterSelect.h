#pragma once

#include "AnimationCallback.h"
#include "CObjAnimation.h"
#include "IFStatic.h"
#include "PSOuterInterface.h"
#include <ghidra/undefined.h>

class CPSCharacterSelect : public CPSOuterInterface, public CAnimationCallback {

    enum {
        GDR_STA_SCREENUP = 1,
        GDR_STA_SCREENDOWN = 2,
        GDR_STA_TITLE = 3,
        GDR_STA_REGIONTITLE = 4,
        GDR_STA_PLAYER1 = 6,
        GDR_STA_PLAYER2 = 7,
        GDR_STA_PLAYER3 = 8,
        GDR_STA_CHINA = 9,
        GDR_STA_ISLAM = 10,
        GDR_STA_EUROPE = 11,
        GDR_BTN_CREATE = 12,
        GDR_BTN_BACK = 13,
        GDR_BTN_START = 14,
        GDR_BTN_DELETE = 15,
        GDR_BTN_BACK2 = 16,
        GDR_BTN_CANCEL = 17,
        GDR_STA_CHARINFO = 18,
        GDR_SCREENFADE = 19,
        GDR_STA_WPOPUP = 20,
        GDR_FADE = 21,
        GDR_LOADING_CHINA = 22,
        GDR_LOADINGFRAME = 23,
        GDR_LOADINGG = 24,
        GDR_BTN_RESTORE = 25,
        GDR_STA_REMAINTIME = 26,
        GDR_LOADING_STA = 27,
        GDR_LOADING_EUROPE = 28,
        GDR_STA_NAME = 31,
        GDR_GAU_HP = 32,
        GDR_GAU_MP = 33,
        GDR_STA_EXP = 34,
        GDR_STA_SP = 35,
        GDR_STA_LEVEL = 36,
        GDR_STA_WNAME = 41,
        GDR_BTN_WACCEPT = 42,
        GDR_BTN_WCANCEL = 43,
        GDR_TB_INFO = 44,
        GDR_BTN_PREV = 45,
        GDR_BTN_NEXT = 46,
        GDR_STA_NAMECHANGE1 = 47,
        GDR_STA_NAMECHANGE2 = 48,
        GDR_STA_NAMECHANGE3 = 49,
        GDR_STA_NAMEPAGE = 50,
        GDR_STA_NAMECHANGE4 = 51,
        GDR_STA_WREMINTIME1 = 51,
        GDR_PML_WREMINTIME2 = 52,
        GDR_REMAING = 53,
        GDR_REMAINGBOX = 54,
        GDR_TB_NDTEXT = 94,
        GDR_STATIC1 = 101,
        GDR_STATIC2 = 102,
        GDR_STATIC3 = 103,
        GDR_TEXT_CHINA = 200,
        GDR_TEXT_EUROPE = 201,
        GDR_TEXT_ISLAM = 202,
        GDR_TEXT_MESSAGE = 500,
        GDR_TEXT_MESSAGE2 = 501,
        GDR_STA_UNITY_SERVER_NOTIFY = 900,
        GDR_PML_SUINFO = 901,
        GDR_BTN_SUACCEPT = 902,
        GDR_STA_SUTITLE = 903,
        GDR_VSC_SUINFO = 904,
        GDR_STA_UNITY_SERVER_CHANGENAME = 920,
        GDR_STA_CHANGENAME = 921,
        GDR_STA_BEFORENAME = 922,
        GDR_STA_AFTERNAME = 923,
        GDR_EDIT_BEFORENAME = 924,
        GDR_EDIT_AFTERNAME = 925,
        GDR_BTN_CNCHECK = 926,
        GDR_BTN_CNACCEPT = 927,
        GDR_BTN_CNCANCEL = 928,
        GDR_TEXT_CHANGENAME = 929,
        GDR_STA_NAME_DUPLICATE = 940,
        GDR_BTN_NDOK = 942,
        GDR_STA_NDSUBJECT = 943,
        GDR_TEXT = 10000
    };

public:

    /// \address 0085eb10
    bool OnCreateIMPL(long ln);

private:
    /// \address 0085b400
    void FUN_0085b400();

    /// \address 008560e0
    void FUN_008560e0();

    /// \address 008548d0
    void FUN_008548d0(bool a1);

public: /* only public for hook */
    /// \address 0085b1f0
    void TriggerAnimation_Intro();
private:
    /// \address 00854860
    void FUN_00854860(CIFStatic* obj, unsigned char opacity, float time, float a4, char a5);

private:
    undefined field_0x110;
    undefined field_0x111;
    undefined field_0x112;
    undefined field_0x113;
    undefined field_0x114;
    undefined field_0x115;
    undefined field_0x116;
    undefined field_0x117;
    undefined field_0x118;
    undefined field_0x119;
    undefined field_0x11a;
    undefined field_0x11b;
    undefined1 field_0x11c;
    undefined field_0x11d;
    undefined field_0x11e;
    undefined field_0x11f;
    float m_seconds_elapsed;
    undefined4 m_minutes_elapsed;
    undefined4 m_last_update;
    undefined1 current_charcount;
    undefined field_0x12d;
    undefined field_0x12e;
    undefined1 m_btCurState;
    undefined1 m_characters;
    undefined field_0x131;
    undefined field_0x132;
    undefined field_0x133;
    undefined field_0x134;
    undefined field_0x135;
    undefined field_0x136;
    undefined field_0x137;
    undefined field_0x138;
    undefined field_0x139;
    undefined field_0x13a;
    undefined field_0x13b;
    undefined field_0x13c;
    undefined field_0x13d;
    undefined field_0x13e;
    undefined field_0x13f;
    undefined field_0x140;
    undefined field_0x141;
    undefined field_0x142;
    undefined field_0x143;
    undefined field_0x144;
    undefined field_0x145;
    undefined field_0x146;
    undefined field_0x147;
    undefined field_0x148;
    undefined field_0x149;
    undefined field_0x14a;
    undefined field_0x14b;
    undefined field_0x14c;
    undefined field_0x14d;
    undefined field_0x14e;
    undefined field_0x14f;
    undefined field_0x150;
    undefined field_0x151;
    undefined field_0x152;
    undefined field_0x153;
    undefined field_0x154;
    undefined field_0x155;
    undefined field_0x156;
    undefined field_0x157;
    undefined field_0x158;
    undefined field_0x159;
    undefined field_0x15a;
    undefined field_0x15b;
    undefined field_0x15c;
    undefined field_0x15d;
    undefined field_0x15e;
    undefined field_0x15f;
    CCObjAnimation idols[3];
    CCObjAnimation m_box;
    undefined4 field_0x220;
    undefined field_0x224;
    undefined field_0x225;
    undefined field_0x226;
    undefined field_0x227;
    CIFStatic * idol_label[2];

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x230)
        ENSURE_OFFSET(m_seconds_elapsed, 0x120)
        ENSURE_OFFSET(idols, 0x160)
        ENSURE_OFFSET(m_box, 0x1f0)
        ENSURE_OFFSET(idol_label, 0x228)
    END_FIXTURE()

    RUN_FIXTURE(CPSCharacterSelect)
};
