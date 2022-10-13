#include "GEffSoundBody.h"

void CGEffSoundBody::PlaySoundA(const wchar_t* sndFile)
{
#if 0
  if ( field_15 != -10000 )
  {
    std::n_wstring key = L"UI:";
    key += sndFile;
    key += L":-:-:-:-";
    PlaySoundInner(&key, 0, 0.0);
  }
#endif
}

void CGEffSoundBody::PlaySoundInner(std::n_wstring* str, int a2, float a3)
{
	reinterpret_cast<void(__thiscall*)(CGEffSoundBody*, std::n_wstring*, int,float)>(0x00BE1590)(this, str, a2, a3);
}

CGEffSoundBody* CGEffSoundBody::get()
{
	return *reinterpret_cast<CGEffSoundBody**>(0x013B47C8);
}
