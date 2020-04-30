#pragma once

#include "IFScrollBar.h"
#include "IFButton.h"

class CIFVerticalScroll : public CIFScrollBar {
public:
    /// \address 0065A390
    void sub_65A390(RECT a2);

    /// \address 0065A5C0
    void sub_65A5C0(int a2);

    /// \address 0065A5A0
    void sub_65A5A0(int a2);

    /// \address 0065A500
    void sub_65A500(short a2);

private:
	CIFButton* m_arrowUpButton; //0x03AC 
	CIFButton* m_arrowDownButton; //0x03B0 
	CIFButton* m_scrollButton; //0x03B4 
	char pad_0x03B8[0x4]; //0x03B8
};
