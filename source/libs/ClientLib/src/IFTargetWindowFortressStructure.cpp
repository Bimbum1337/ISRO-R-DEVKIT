#include "IFTargetWindowFortressStructure.h"
#include "IFStatic.h"
#include "IFGauge.h"
#include "IFButton.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFTargetWindowFortressStructure, 0x00ee7b00)

GFX_IMPLEMENT_DYNCREATE_FN(CIFTargetWindowFortressStructure, CIFWnd)

enum {
    GDR_TWFS_D_BUTTON = 11, // CIFButton
    GDR_TWFS_GEM = 10, // CIFStatic
    GDR_TWFS_GAUGE_HPGAUGE = 1, // CIFGauge
    GDR_TWFS_TEXT_ID = 0, // CIFStatic
};

GFX_BEGIN_MESSAGE_MAP(CIFTargetWindowFortressStructure, CIFWnd)

GFX_END_MESSAGE_MAP()

bool CIFTargetWindowFortressStructure::OnCreate(long ln) {
    //printf("%s\n", __FUNCTION__);
    //return reinterpret_cast<bool (__thiscall *)(const CIFTargetWindowFortressStructure *, long)>(0x00565480)(this, ln);

    m_IRM.LoadFromFile("resinfo\\iftw_fortressstructure.txt");
    m_IRM.CreateInterfaceSection("Create", this);

    m_pGDR_TWFS_TEXT_ID = m_IRM.GetResObj<CIFStatic>(GDR_TWFS_TEXT_ID, 1); // 0x370
    m_pGDR_TWFS_GAUGE_HPGAUGE = m_IRM.GetResObj<CIFGauge>(GDR_TWFS_GAUGE_HPGAUGE, 1); // 0x374
    m_pGDR_TWFS_D_BUTTON = m_IRM.GetResObj<CIFButton>(GDR_TWFS_D_BUTTON, 1); // 0x378

    m_pGDR_TWFS_GAUGE_HPGAUGE->field_0x38c = 0.1;
    m_pGDR_TWFS_D_BUTTON->TB_Func_13("interface\\ifcommon\\com_d_windowclose.ddj", 0, 0);
    m_pGDR_TWFS_D_BUTTON->TB_Func_13("interface\\ifcommon\\com_d_windowclose.ddj", 0, 0);
    m_pGDR_TWFS_D_BUTTON->FUN_00656590("interface\\ifcommon\\com_d_windowclose_press.ddj");

    return true;
}

void CIFTargetWindowFortressStructure::OnUpdate() {
    //printf("%s\n", __FUNCTION__);
    reinterpret_cast<void (__thiscall *)(const CIFTargetWindowFortressStructure *)>(0x00564890)(this);
}
