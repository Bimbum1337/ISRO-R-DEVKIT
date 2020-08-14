#include "PSilkroad.h"

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
