#include "PSilkroad.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CPSilkroad, 0x00eed84c)

void CPSilkroad::Func_40() {
    // empty
}

void CPSilkroad::ErrorMessage(const wchar_t *message) {
    reinterpret_cast<void (__thiscall *)(CPSilkroad *, const wchar_t *)>(0x00861850)(this, message);
}

void CPSilkroad::ErrorMessagePar(const wchar_t *message, char codeletter, int codenumber) {
    reinterpret_cast<void (__thiscall *)(CPSilkroad *, const wchar_t *, char, int)>(0x00861890)(this, message,
                                                                                                codeletter, codenumber);
}

void CPSilkroad::ShowMessage(const wchar_t *message, D3DCOLOR color) {
    reinterpret_cast<void(__thiscall*)(CPSilkroad *, const wchar_t*, D3DCOLOR)>(0x008613b0)(this, message, color);
}
