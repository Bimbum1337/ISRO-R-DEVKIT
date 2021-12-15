#pragma once

#define bs_msg

#ifndef GFX_MSG_CALL
#define GFX_MSG_CALL
#endif

/// Supported function signatures for message map handlers
enum BSSig {
    /// Mark the end of the message map array
    GfxSig_end = 0,
    BSSig_u10 = 10, // int (int, int)
    BSSig_u12 = 12, //
    BSSig_u16 = 16, // int (UINT, UINT, UINT)
    BSSig_u38 = 38  // void (int, int)
};

#define GFX_WM_COMMAND 0x0001

enum {
    GFX_WM_KEYUP = 0x101,
    GFX_WM_CHAR = 0x102,
};

#define ONG_COMMAND(Id, Func) \
    { GFX_WM_COMMAND , 0, Id, Id, BSSig_u12, 0, \
        (GFX_PMSG) \
        (static_cast< void (GFX_MSG_CALL CGWndBase::*)() > ( Func )), \
        0, 0, 0 },

#define ONG_BSSig_u38(Cmd, a1, Id, Func) \
	{ Cmd, a1, Id, Id, BSSig_u38, 0, \
		(GFX_PMSG) \
		(static_cast< void (GFX_MSG_CALL CGWndBase::*)(int, int) > ( Func )), \
		0, 0, 0 },

#define ONG_KEYUP() \
    { GFX_WM_KEYUP, 0, 0, 0, BSSig_u16, 0, \
        (GFX_PMSG) \
        (static_cast< int (GFX_MSG_CALL CGWndBase::*)(UINT, UINT, UINT) > ( &ThisClass :: OnKeyUp)), \
        0, 0, 0},

#define ONG_CHAR() \
    { GFX_WM_CHAR, 0, 0, 0, BSSig_u16, 0, \
        (GFX_PMSG) \
        (static_cast< int (GFX_MSG_CALL CGWndBase::*)(UINT, UINT, UINT) > ( &ThisClass :: OnChar)), \
        0, 0, 0},

#define ONG_WM_32868() \
    { 32868, 0, 0, 0, BSSig_u10, 0, \
    (GFX_PMSG) \
    (static_cast< int (GFX_MSG_CALL CGWndBase::*)(int, int) > ( &ThisClass :: On32868)), \
        0, 0, 0},

#define ONG_WM_4001() \
    { 0x4001, 0, 0, 0, 0xA, 0, \
    (GFX_PMSG) \
    (static_cast< int (GFX_MSG_CALL CGWndBase::*)(int, int) > ( &ThisClass :: On4001)), \
        0, 0, 0},

#define ONG_WM_4002() \
    { 0x4002, 0, 0, 0, 0xA, 0, \
    (GFX_PMSG) \
    (static_cast< int (GFX_MSG_CALL CGWndBase::*)(int, int) > ( &ThisClass :: On4002)), \
        0, 0, 0},

#define ONG_WM_4003() \
    { 0x4003, 0, 0, 0, 0xA, 0, \
    (GFX_PMSG) \
    (static_cast< int (GFX_MSG_CALL CGWndBase::*)(int, int) > ( &ThisClass :: On4003)), \
        0, 0, 0},

#define ONG_VISIBLE_CHANGE() \
    { 0x4004, 0, 0, 0, 0xA, 0, \
    (GFX_PMSG) \
    (static_cast< int (GFX_MSG_CALL CGWndBase::*)(int, int) > ( &ThisClass :: OnVisibleStateChange)), \
    0, 0, 0},

#define ONG_WM_4005() \
    { 0x4005, 0, 0, 0, 0xA, 0, \
    (GFX_PMSG) \
    (static_cast< int (GFX_MSG_CALL CGWndBase::*)(int, int) > ( &ThisClass :: On4005)), \
        0, 0, 0},

#define ONG_WM_4006() \
	{ 0x4006, 0, 0, 0, 0xA, 0, \
	(GFX_PMSG) \
	(static_cast< int (GFX_MSG_CALL CGWndBase::*)(int, int) > ( &ThisClass :: On4006)), \
		0, 0, 0},

// Mostly used by:
// SetFocus_MAYBE .text 00B9D9F0 00000049 00000004 00000000 R . . . . . .
#define ONG_WM_4008() \
	{ 0x4008, 0, 0, 0, 0xA, 0, \
	(GFX_PMSG) \
	(static_cast< int (GFX_MSG_CALL CGWndBase::*)(int, int) > ( &ThisClass :: On4008)), \
		0, 0, 0},
