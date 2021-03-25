#include <BSLib/multibyte.h>
#include "GFXMainFrame.h"

HWND CGFXMainFrame::GetHWnd() const
{
	return this->mainHWND;
}

char CGFXMainFrame::_CreateFont(int a2, int size, std::wstring* name, int a5, int a6, int a7)
{
	std::string fontname = acp_encode(name);

	return _CreateFont(a2, size, fontname.c_str(), a5, a6, a7);
}

char CGFXMainFrame::_CreateFont(int a2, int size, const char* name, int a5, int a6, int a7)
{
	return reinterpret_cast<char (__thiscall *)(void*, int, short, const char*, int, int, int)>(0x00BA6140)(this, a2, size, name, a5, a6, a7);
}

#define ApplyDepthBufferPriority(x,y,z)   (reinterpret_cast<char (__thiscall *)(CGFXMainFrame*, int, int, int)>(0x00BA3CC0))(this,x,y,z)

#define RENDER_GAME_OVERLAY 0x807


void CGFXMainFrame::SetProcess(CProcess* process)
{
	this->process_next = process;
	this->N00000584 = 0;
	this->N00009632 = 1;
}

void CGFXMainFrame::SetNextProcessSTAT(CGfxRuntimeClass* cls)
{
	reinterpret_cast<void(*)(CGfxRuntimeClass*)>(0x0BA75F0)(cls);
}

CProcess *CGFXMainFrame::GetCurrentProcess() const {
    return process_current;
}

const char *CGFXMainFrame::GetWorkingDir() const {
    return working_dir;
}
