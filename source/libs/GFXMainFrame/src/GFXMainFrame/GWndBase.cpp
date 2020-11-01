#include "GWndBase.h"
#include <BSLib/Debug.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CGWndBase, 0x0110F630)

void CGWndBase::Func_7(CGWndBase *a2) {
    BS_DEBUG_LOW(__FUNCTION__ " (%p : %s)", a2, a2->GetRuntimeClass()->m_lpszClassName);
    //N00000707.push_back(a2);
    reinterpret_cast<void (__thiscall *)(CGWndBase *, CGWndBase *)>(0x00B90A80)(this, a2);
}

int CGWndBase::AddControlToList(CGWndBase *a2) {
    BS_DEBUG_LOW(__FUNCTION__ " (%p : %s)", a2, a2->GetRuntimeClass()->m_lpszClassName);
    return reinterpret_cast<int (__thiscall *)(CGWndBase *, CGWndBase *)>(0x00B90AC0)(this, a2);
}

void CGWndBase::RemoveControlFromList(CGWndBase *a2) {
    BS_DEBUG_LOW(__FUNCTION__ " (%p : %s)", a2, a2->GetRuntimeClass()->m_lpszClassName);
    reinterpret_cast<void (__thiscall *)(CGWndBase *, CGWndBase *)>(0x00B913D0)(this, a2);
}

bool CGWndBase::OnCreate(long ln) {
    return 1;
}

bool CGWndBase::OnRelease() {
    return 1;
}

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

CGWndBase::CGWndBase() {
    this->m_lnListLockWrite = 0;
    this->m_lnListLockRead = 0;
    this->N000006F5 = 0;
    this->N000006F9 = 1;
    this->m_parentControl = 0;
    this->m_UniqueID = 0;
    this->m_hgWnd = 0;
    this->N000006FB = 0;
    this->m_iflist = 0;
    this->N00000703 = 0;
    this->N00000705 = 0;

	this->bounds.pos.x = 0;
	this->bounds.pos.y = 0;
	this->bounds.size.height = 0;
	this->bounds.size.width = 0;

    RECT rect = {0, 0, 0, 0};

    this->sub_B8F440(rect);
}

bool CGWndBase::IsVisible() {
    return this->m_bVisible;
}

void CGWndBase::ApplyGlobalScale(int x) {
    reinterpret_cast<void (__cdecl *)(CGWndBase *, int)>(0x00849C70)(this, x);
}

CGWndBase::wnd_rect CGWndBase::GetBounds() const {
	return this->bounds;
}

void CGWndBase::sub_6526E0(char a0, unsigned char opacity, float time, float a4, char a5) {
    reinterpret_cast<void (__thiscall *)(CGWndBase *, char, unsigned char, float, float, char)>(0x6526E0)(this, a0,
                                                                                                          opacity, time,
                                                                                                          a4, a5);
}

void CGWndBase::sub_B9DA70(bool b) {
    reinterpret_cast<void (__thiscall *)(CGWndBase *, bool)>(0x00B9DA70)(this, b);
}

int CGWndBase::UniqueID() const {
    return this->m_UniqueID;
}

void CGWndBase::sub_B8F440(const RECT &rect) {
    N000006FD = rect;
}

// CGWndBase::GetParentControl() .text 00B8F4F0 00000004   R . . . . T .
CGWndBase *CGWndBase::GetParentControl() const {
    return m_parentControl;
}

// CGWndBase::SetFocus_MAYBE(void) .text 00B9D9F0 00000049 00000004 00000000 R . . . . . .
void CGWndBase::SetFocus_MAYBE() {
    reinterpret_cast<void(__thiscall*)(CGWndBase*)>(0x00B9D9F0)(this);
}

CGWndBase::wnd_pos CGWndBase::GetPos() const {
    return this->bounds.pos;
}

CGWndBase::wnd_size CGWndBase::GetSize() const {
    return this->bounds.size;
}
