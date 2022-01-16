#pragma once

#include "BSLib/BSLib.h"
#include <d3dx9.h>

class CControler : CObjChild {
    struct WindowsKeys {
        char pad_0000[8];
        bool BACKSPACE_Key;
        bool TAB_Key;
        char pad_0010[2];
        bool CLEAR_Key;
        bool ENTER_Key;
        char pad_0015[2];
        bool SHIFT_Key;
        bool CTRL_Key;
        bool ALT_Key;
        bool PAUSE_Key;
        bool CAPSLOCK_Key;
        char pad_0023[6];
        bool ESC_Key;
        char pad_0031[4];
        bool SPACEBAR_Key;
        bool PAGEUP_Key;
        bool PAGEDOWN_Key;
        bool END_Key;
        bool HOME_Key;
        bool ARROW_LEFT_Key;
        bool ARROW_UP_Key;
        bool ARROW_RIGHT_Key;
        bool ARROW_DOWN_Key;
        bool SELECT_Key;
        bool PRINT_Key;
        bool EXECUTE_Key;
        bool PRINT_SCREEN_Key;
        bool INS_Key;
        bool DEL_Key;
        bool HELP_Key;
    };

    struct InputKeys {
        bool NUM_UP0;
        bool NUM_UP1;
        bool NUM_UP2;
        bool NUM_UP3;
        bool NUM_UP4;
        bool NUM_UP5;
        bool NUM_UP6;
        bool NUM_UP7;
        bool NUM_UP8;
        bool NUM_UP9;
        char pad_0010[7];
        bool A_Key;
        bool B_Key;
        bool C_Key;
        bool D_Key;
        bool E_Key;
        bool F_Key;
        bool G_Key;
        bool H_Key;
        bool I_Key;
        bool J_Key;
        bool K_Key;
        bool L_Key;
        bool M_Key;
        bool N_Key;
        bool O_Key;
        bool P_Key;
        bool Q_Key;
        bool R_Key;
        bool S_Key;
        bool T_Key;
        bool U_Key;
        bool V_Key;
        bool W_Key;
        bool X_Key;
        bool Y_Key;
        bool Z_Key;

    };

    struct OtherKeys {
        bool LWIN_Key;
        bool RWIN_Key;
        bool APP_Key;
        bool N00000B56;
        bool SLEEP_Key;
        // num pad keys!
        bool NUM0_Key;
        bool NUM1_Key;
        bool NUM2_Key;
        bool NUM3_Key;
        bool NUM4_Key;
        bool NUM5_Key;
        bool NUM6_Key;
        bool NUM7_Key;
        bool NUM8_Key;
        bool NUM9_Key;
        char pad_0015[6];

    };

    struct F_Keys {
        bool F01_Key;
        bool F02_Key;
        bool F03_Key;
        bool F04_Key;
        bool F05_Key;
        bool F06_Key;
        bool F07_Key;
        bool F08_Key;
        bool F09_Key;
        bool F10_Key;
        bool F11_Key;
        bool F12_Key;
        bool F13_Key;
        bool F14_Key;
        bool F15_Key;
        bool F16_Key;
        bool F17_Key;
        bool F18_Key;
        bool F19_Key;
        bool F20_Key;
        bool F21_Key;
        bool F22_Key;
        bool F23_Key;
        bool F24_Key;
    };

public: // this is public as here 0053a65e
    bool m_bCursorVisible; //0x0020
private:// cursour info
    char pad_0021[3]; //0x0021
    int N00000065; //0x0024  // change when cursour icon change...
    HCURSOR m_currentCursor; //0x0028
    char pad_002c[36]; //0x002c
public: // correct as here 00479132 , 004896d5
    D3DXVECTOR2 m_fCursorPos; //0x0050
private: // true if button pressed or hold...
    WindowsKeys windowsKeys; //0x0058
    InputKeys inputKeys; //0x0088
    OtherKeys otherKeys; //0x00B3
    F_Keys fKeys; //0x00C8
    char pad_00E0[8]; //0x00E0
    bool NUMLOCK_Key; //0x00E8
    bool SCROLLLOCK_Key; //0x00E9
    char pad_00EA[40]; //0x00EA
    bool OEM_1; //0x0112 //this is the ';:' key
    bool OEM_PLUS; //0x0113 // '+' key
    bool OEM_COMMA; //0x0114 // ',' key
    bool OEM_MINUS; //0x0115 // '-' key
    bool OEM_PERIOD; //0x0116 // '.' key
    bool OEM_2; //0x0117 // the '/?' key
    bool OEM_3; //0x0118 // the '`~' key
    char pad_0119[26]; //0x0119
    bool OEM_4; //0x0133 // the '[{' key
    bool OEM_5; //0x0134 // the '\|' key
    bool OEM_6; //0x0135 // the ']}' key
    bool OEM_7; //0x0136 // the '  ' "  ' key
    bool OEM_8; //0x0137
    char pad_0138[288]; //0x0138
    bool LBUTTON_Mouse; //0x0258
    bool MBUTTON_Mouse; //0x0259
    bool RBUTTON_Mouse; //0x025A
    char pad_025B[1]; //0x025B
private:
BEGIN_FIXTURE()
        ENSURE_SIZE(0x25c)
        ENSURE_OFFSET(m_bCursorVisible, 0x20)
        ENSURE_OFFSET(m_currentCursor, 0x28)
        ENSURE_OFFSET(m_fCursorPos, 0x50)
        ENSURE_OFFSET(windowsKeys, 0x58)
        ENSURE_OFFSET(inputKeys, 0x88)
        ENSURE_OFFSET(otherKeys, 0xb3)
        ENSURE_OFFSET(fKeys, 0xc8)
        ENSURE_OFFSET(LBUTTON_Mouse, 0x258)
        ENSURE_OFFSET(MBUTTON_Mouse, 0x259)
        ENSURE_OFFSET(RBUTTON_Mouse, 0x25A)

    END_FIXTURE()

    RUN_FIXTURE(CControler)
};
