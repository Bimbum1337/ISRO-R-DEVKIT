#pragma once

#include "IFFrame.h"
#include "IFDragableArea.h"
#include "IFEdit.h"

class CIFWholeChat : public CIFFrame {

    GFX_DECLARE_DYNAMIC_EXISTING(CIFWholeChat, 0x00eec7a8)

    GFX_DECLARE_DYNCREATE_FN(CIFWholeChat)

    GFX_DECLARE_MESSAGE_MAP(CIFWholeChat)

public:
    /// \address 007ef6f0
    bool OnCreate(long ln) override;

    /// \address 00815490
    void RenderMyself() override;

    /// \address 007ef3c0
    undefined1 OnCloseWnd() override;

    /// \address 007ef3a0
    void SetGWndSize(int width, int height) override;

    /// \address 007ef400
    void FUN_007ef400(int numberOfItemsLeft);

private:
    /// \address 007ef900
    int OnKeyUp(UINT, UINT, UINT);

    /// \address 007ef550
    void SendGlobalMessage();

    /// \address 007ef490
    void FUN_007ef490();

private:
    // Inventory slot of item this window was opened from
    int m_SlotOfChattingItem;
    // Number of items left in slot
    int m_NumberOfItemsLeft;

    CIFEdit *m_pEdit;
    CIFStatic *m_pCreatedStatic;
    CIFDragableArea *m_pDragableArea;


    BEGIN_FIXTURE()
        ENSURE_SIZE(1988)
        ENSURE_OFFSET(m_SlotOfChattingItem, 0x7b0)
        ENSURE_OFFSET(m_NumberOfItemsLeft,  0x7b4)
        ENSURE_OFFSET(m_pEdit, 0x7b8)
        ENSURE_OFFSET(m_pCreatedStatic, 0x7bc)
        ENSURE_OFFSET(m_pDragableArea, 0x7c0)
    END_FIXTURE()

    RUN_FIXTURE(CIFWholeChat)
};
