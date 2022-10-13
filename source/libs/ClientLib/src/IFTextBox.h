#pragma once

#include "IFListCtrl.h"

class CIFTextBox : public CIFListCtrl {
// TODO: Add Runtime Class Info
public:
    /// \address 00638B50
    void sub_638B50(int a2);

    /// \address 0064E380
    void sub_64E380(int a2);

    /// \address 00638C70
    void sub_638C70(int a2);

    /// \address 00638D50
    void sub_638D50(int a2);

    /// \address 00638D40
    void sub_638D40(int a2);

    /// \address 0064F8A0
    void sub_64F8A0(std::n_wstring &str, int a3, int a4, int a5, int a6, int a7, int a8);

    /// \address 0064F660
    void sub_64F660(std::n_string &str, int a3, int a4, int a5, int a6, int a7, int a8);


private:
    char N00009D87; //0x03D8
    char pad_03CD[15]; //0x03D9
    /// Number of lines currently stored in the text box
    int m_CurrentLines; //0x03E8

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x3EC)
        ENSURE_OFFSET(m_CurrentLines, 0x03E8)
    END_FIXTURE()

    RUN_FIXTURE(CIFTextBox)
};
