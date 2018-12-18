#pragma once

#define bs_msg

#ifndef GFX_MSG_CALL
#define GFX_MSG_CALL
#endif

enum BSSig
{
	GfxSig_end = 0,
	BSSig_u10 = 10, // int (int, int)
	BSSig_u12 = 12, // 
	BSSig_u16 = 16  // int (UINT, UINT, UINT)
};

#define GFX_WM_COMMAND 0x0001

#define ONG_COMMAND(Id, Func) \
	{ GFX_WM_COMMAND , 0, Id, Id, BSSig_u12, 0, \
		(GFX_PMSG) \
		(static_cast< void (GFX_MSG_CALL CGWndBase::*)() > ( Func )), \
		0, 0, 0 },


#define ONG_WM_258() \
	{ 258, 0, 0, 0, BSSig_u16, 0, \
		(GFX_PMSG) \
		(static_cast< int (GFX_MSG_CALL CGWndBase::*)(UINT, UINT, UINT) > ( &ThisClass :: On258)), \
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

#define ONG_WM_4006() \
	{ 0x4001, 0, 0, 0, 0xA, 0, \
	(GFX_PMSG) \
	(static_cast< int (GFX_MSG_CALL CGWndBase::*)(int, int) > ( &ThisClass :: On4006)), \
		0, 0, 0},
