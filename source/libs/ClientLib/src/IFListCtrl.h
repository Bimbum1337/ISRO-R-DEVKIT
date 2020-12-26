#pragma once

#include "IFWnd.h"
#include "LinkedScroll.h"

class CIFListCtrl : public CIFWnd, public CLinkedScroll {

public:
    struct SLineOfText {
    private:
        char pad_0000[24]; //0x0000
    public:
        CGFontTexture* m_font; //0x0018
    };

public:
    /// \brief Set the color of the line highlighting (usually background color)
    /// \address 00638CF0
    void SetHighlightColor(D3DCOLOR a2);

    /// \brief Enable or disable highlighting the line under cursor
    /// \address 00638D00
    void SetHightlineLine(bool a2);

    void SetLineHeight(int height);

    /// \copybrief CIFWnd::OnCreate
    /// \address 00638B20
    bool OnCreate(long ln) override;

    /// \address 0063A940
    /// \remark This func seems to return the currently selected line of text in the list control.
    CIFListCtrl::SLineOfText* sub_63A940();

    /// \copybrief CLinkedScroll::GetNumberOfItems
    /// \address 00638cd0
    int GetNumberOfItems() const override;

private:
    char pad_0384[2]; //0x0384
    char m_bHighlighLine; //0x0386
    char pad_0387[1]; //0x0387
    char N00009DA0; //0x0388
    char pad_0389[19]; //0x0389

public:
    /// Number of pixels per line of text (breaking lines take twice the space, or more)
    int m_LineHeight; //0x039C

    /// Number if lines to keep in history
    int m_LinesOfHistory; //0x03A0

    // Number of lines shown by the control
    int m_HeightInLines; //0x03A4

private:
    char N00009DA8; //0x03A8
    char pad_03A9[1]; //0x03A9
    char N00009F32; //0x03AA
    char pad_03AB[29-8]; //0x03AB
    /// Number of items in the list
    int m_numberOfItems; // 0x3C0
    D3DCOLOR m_OtherColor; // 0x3C4
    D3DCOLOR m_BackgroundColor; //0x03C8

};

