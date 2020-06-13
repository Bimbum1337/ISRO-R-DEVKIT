#include "GWnd.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CGWnd, 0x0110F94C)

void CGWnd::Func_24(int a1, int a2) {
    reinterpret_cast<void (__thiscall *)(CGWnd *, int, int)>(0x00B9D810)(this, a1, a2);
}

bool CGWnd::Func_25(int a1) {
    return true;
}

void CGWnd::Func_26(int a1) {
}

bool CGWnd::Func_27() {
    return true;
}

bool CGWnd::Func_28(int a1, int a2, int a3) {
    return false;
}

int CGWnd::OnMouseLeftUp(int a1, int x, int y) {
    return 0;
}

int CGWnd::OnMouseLeftDown(int a1, int x, int y) {
    return 0;
}

int CGWnd::Func_31(int a1, int a2, int a3) {
    return 0;
}

int CGWnd::OnMouseRightDown(int a1, int x, int y) {
    return 0;
}

int CGWnd::OnMouseRightUp(int a1, int x, int y) {
    return 0;
}

int CGWnd::Func_34(int a1, int a2, int a3) {
    return 0;
}

int CGWnd::OnMouseMove(int a1, int x, int y) {
    return 0;
}

int CGWnd::Func_36(int a1, short action, int a3, int a4) {
    return 0;
}

void CGWnd::Func_37() {
    return;
}

CGWnd::CGWnd() {
    m_bVisible = true;
    m_bClickable = true;
    N0000074F = true;
    N00000702 = false;

    sub_B9DA70(false);
}

void CGWnd::OnUpdate() {
    // empty
}

void CGWnd::RenderMyself() {
    if (!m_bVisible)
        return;
    // NOTE: This can trigger an endless recursion if RenderMyself is not properly overwritten
    CGWnd::Render();
}

void CGWnd::RenderMyChildren() {
    reinterpret_cast<void (__thiscall *)(CGWnd *)>(0x00BA0300)(this);
}

void CGWnd::Render() {
    RenderMyself();
    RenderMyChildren();
    Func_15();
}

void CGWnd::Func_15() {
    // empty
}

bool CGWnd::On3DEvent_MAYBE(Event3D *a2) {
    return false;
}

