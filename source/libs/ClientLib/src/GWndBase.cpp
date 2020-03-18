#include "StdAfx.h"
#include "GWndBase.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CGWndBase, 0x0110F630)

// CGWndBase::Func_7(void) .text 00B90A80 00000033 0000000C 00000001 R . . . . . .
void CGWndBase::Func_7(CGWndBase *a2) {
    printf(__FUNCTION__ " (%p : %s)\n", a2, a2->GetRuntimeClass()->m_lpszClassName);
    //N00000707.push_back(a2);
    reinterpret_cast<void (__thiscall *)(CGWndBase *, CGWndBase *)>(0x00B90A80)(this, a2);
}

// CGWndBase::AddControlToList(int) .text 00B90AC0 00000035 0000000C 00000001 R . . . . T .
int CGWndBase::AddControlToList(CGWndBase *a2) {
    printf(__FUNCTION__ " (%p : %s)\n", a2, a2->GetRuntimeClass()->m_lpszClassName);
    return reinterpret_cast<int (__thiscall *)(CGWndBase *, CGWndBase *)>(0x00B90AC0)(this, a2);
}

// CGWndBase::RemoveControlFromList(void) .text 00B913D0 0000006B 0000000C 00000004 R . . . . . .
void CGWndBase::RemoveControlFromList(CGWndBase *a2) {
    printf(__FUNCTION__ " (%p : %s)\n", a2, a2->GetRuntimeClass()->m_lpszClassName);
    reinterpret_cast<void (__thiscall *)(CGWndBase *, CGWndBase *)>(0x00B913D0)(this, a2);
}

// CGWndBase::OnCreate(int) .text 00B8F1F0 00000005 00000000 00000000 R . . . . . .
bool CGWndBase::OnCreate(long ln) {
    return 1;
}

// CGWndBase::OnRelease() .text 00B8F200 00000003   R . . . . . .
bool CGWndBase::OnRelease() {
    return 1;
}

// CGWndBase::OnUpdate() .text 00B92070 000003F8 00000048 00000000 R . . . . T .
void CGWndBase::OnUpdate() {
    reinterpret_cast<void (__thiscall *)(CGWndBase *)>(0x00B92070)(this);
}

void CGWndBase::RenderMyself() {
    if (m_bVisible) {
        if (N0000074F) {
            this->RenderMyself();
            this->RenderMyChildren();
        }
    }
}

void CGWndBase::RenderMyChildren() {
    return;
}

void CGWndBase::Func_15() {
    return;
}

void CGWndBase::Render() {
    CGWndBase::RenderMyself();
}

bool CGWndBase::On3DEvent_MAYBE(Event3D *a2) {
    return reinterpret_cast<bool (__thiscall *)(CGWndBase *, Event3D *)>(0x00B91440)(this, a2);
}

bool CGWndBase::Func_18(int a1) {
    return false;
}

void CGWndBase::OnWndMessage(int a1) {
    return;
}

void CGWndBase::Func_20() {
    reinterpret_cast<void (__thiscall *)(CGWndBase *)>(0x00B90C00)(this);
}

void CGWndBase::SetGWndSize(int width, int height) {
    CGWndBase::Func_22(width, height);
}

void CGWndBase::Func_22(int x, int y) {
    reinterpret_cast<void (__thiscall *)(CGWndBase *, int, int)>(0x00B91A40)(this, x, y);
}

void CGWndBase::ShowGWnd(bool bVisible) {
    reinterpret_cast<void (__thiscall *)(CGWndBase *, bool)>(0x00B8F500)(this, bVisible);
}

// CGWndBase::CGWndBase(void) .text 00B8FCD0 000000B2 00000030 00000000 R . . . . T .
CGWndBase::CGWndBase() {
    this->m_lnListLockWrite = 0;
    this->m_lnListLockRead = 0;
    this->N000006F5 = 0;
    this->N000006F9 = 1;
    this->N000006F7 = 0;
    this->m_UniqueID = 0;
    this->m_hgWnd = 0;
    this->N000006FB = 0;
    this->m_iflist = 0;
    this->N00000703 = 0;
    this->N00000705 = 0;

    this->bounds.left = 0;
    this->bounds.top = 0;
    this->bounds.right = 0;
    this->bounds.bottom = 0;

    RECT rect = {0, 0, 0, 0};

    this->sub_B8F440(rect);
}

bool CGWndBase::IsVisible() {
    return this->m_bVisible;
}

void CGWndBase::ApplyGlobalScale(int x) {
    reinterpret_cast<void (__cdecl *)(CGWndBase *, int)>(0x00849C70)(this, x);
}

void CGWndBase::GetBounds(RECT &a2) {
    a2 = this->bounds;
}

void CGWndBase::sub_6526E0(char a0, unsigned char opacity, float time, float a4, char a5) {
    reinterpret_cast<void (__thiscall *)(CGWndBase *, char, unsigned char, float, float, char)>(0x6526E0)(this, a0,
                                                                                                          opacity, time,
                                                                                                          a4, a5);
}

// CGWndBase::sub_B9DA70(char) .text 00B9DA70 0000000A 00000000 00000001 R . . . . T .
void CGWndBase::sub_B9DA70(bool b) {
    reinterpret_cast<void (__thiscall *)(CGWndBase *, bool)>(0x00B9DA70)(this, b);
}

const int CGWndBase::UniqueID() {
    return this->m_UniqueID;
}

void CGWndBase::sub_B8F440(const RECT &rect) {
    N000006FD = rect;
}
