#pragma once

#include "IFWnd.h"

class CIFBuffViewer : public CIFWnd {
    GFX_DECLARE_DYNAMIC_EXISTING(CIFBuffViewer, 0x00eec908)

    GFX_DECLARE_DYNCREATE_FN(CIFBuffViewer)

    GFX_DECLARE_MESSAGE_MAP(CIFBuffViewer)

    struct SBuffListData {
    private:
        char pad[0x30];
    };

public:

    CIFBuffViewer();

    /// \address 007fab80
    bool OnCreate(long ln) override;
private:
    undefined4 field1_0x36c;
    undefined4 field2_0x370;
    undefined4 field3_0x374;
    undefined4 field4_0x378;
    undefined4 field5_0x37c;
    undefined4 field6_0x380;
    undefined4 field7_0x384;
    std::n_list<SBuffListData> field8_0x388;
    std::n_list<SBuffListData> field9_0x394;
    undefined4 field10_0x3a0;
    undefined4 field11_0x3a4;

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x3a8)
    END_FIXTURE()

    RUN_FIXTURE(CIFBuffViewer)
};
