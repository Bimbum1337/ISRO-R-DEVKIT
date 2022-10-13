#pragma once

#include "IFFrame.h"
#include "IFStatic.h"
#include "IFCloseButton.h"
#include "IFDragableArea.h"

class CIFMainFrame : public CIFFrame {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFMainFrame, 0x117D984)

    GFX_DECLARE_MESSAGE_MAP(CIFMainFrame)
public:
    /// \address 00816F20
    CIFMainFrame();

    // Destructor is trivial
    // \address 00816F60
    // ~CIFMainFrame();

    /// \address 00816F80
    bool OnCreate(long ln) override;

    /// \address 00817210
    void SetGWndSize(int width, int height) override;

    /// \address 00817230
    bool SetText(const wchar_t *src) override;

private:
    void OnClick_Exit();

private:
    CIFStatic *m_title; //0x7B8
    CIFDragableArea *m_handleBar; //0x07BC
    CIFCloseButton *m_close; //0x07C0

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x7C4)
        ENSURE_OFFSET(m_title, 0x7B8)
        ENSURE_OFFSET(m_handleBar, 0x07BC)
        ENSURE_OFFSET(m_close, 0x07C0)
    END_FIXTURE()

    RUN_FIXTURE(CIFMainFrame)
};
