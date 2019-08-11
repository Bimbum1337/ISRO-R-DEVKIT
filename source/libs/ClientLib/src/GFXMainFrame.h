#pragma once

#include <Windows.h>
#include "MsgHandler.h"

#include "Process.h"
#include <BSLib/BSLib.h>
#include <GFX3DFunction/Camera.h>
#include "ETime.h"

class CGFXMainFrame : public CObjChild, public CMsgHandler {
public:
	virtual void LoadAndInitStuff(int a1); // maybe init (cgame implementation loads settings)
	virtual char F9(); // returns 1 in this impl
	virtual void Cycle();
	virtual void SetNextProcess(CGfxRuntimeClass*); // this func is also referenced by address. WTF.
	virtual void Renderer(); // wat?
	virtual char RenderFrame();
	virtual void F14();
	virtual void F15(); // asserts if m_blDrawing == 0
	virtual char VirtualApplyDepthBufferPriority(int a1); // returns 0
	virtual int F17(int a1); // returns 1
	virtual char F18(int a1); // returns 0


	HWND GetHWnd() const;
	char _CreateFont(int a2, int size, std::wstring *name, int a5, int a6, int a7); // overload for wstring (non original)
	char _CreateFont(int a2, int a3, const char *name, int a5, int a6, int a7); // original name without "_" , FUCK Windows.h

	char RenderFrameIMPL();

	void SetProcess(CProcess* process);
	
private:
	CProcess* process_current; //0x0024
	CProcess* process_next; //0x0028, Is CPSOuterInterface as of CPSLogo::OnUpdate (accesses 0xE8, which is out of range of CProcess)
	CProcess* process_prev; //0x002C
	int m_blDrawing; //0x0030 name by error in 00BA3C10
	HWND mainHWND; //0x0034
	HINSTANCE mainInstance; //0x0038
	HMODULE hFileManager; //0x003C
	char b_RenderingPossible; //0x0040
	char N00009632; //0x0041
	char pad_0042[2]; //0x0042
	int N00000584; //0x0044
	char pad_0048[2]; //0x0048
	char b_Debug; //0x004A
	char pad_004B[33]; //0x004B
	CETime primary_timebase; //0x006C
	CETime N0000058F; //0x00D0
	char working_dir[260]; //0x0134
	char executable_name[260]; //0x0238
public:
	CCamera camera; //0x033C
};
