#include "IFTargetWindowCommonEnemy.h"
#include "IFStatic.h"
#include "IFGauge.h"

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFTargetWindowCommonEnemy, 0x00eea59c)

GFX_IMPLEMENT_DYNCREATE_FN(CIFTargetWindowCommonEnemy, CIFWnd)

enum {
    GDR_TWCE_GEM = 10, // CIFStatic
    GDR_TWCE_GAUGE_HPGAUGE = 1, // CIFGauge
    GDR_TWCE_TEXT_ID = 0, // CIFStatic
};

GFX_BEGIN_MESSAGE_MAP(CIFTargetWindowCommonEnemy, CIFWnd)

GFX_END_MESSAGE_MAP()

bool CIFTargetWindowCommonEnemy::OnCreate(long ln) {
    //printf("%s\n", __FUNCTION__);
    //return reinterpret_cast<bool (__thiscall *)(const CIFTargetWindowCommonEnemy *, long)>(0x0069aaa0)(this, ln);

    m_IRM.LoadFromFile("resinfo\\iftw_commonenemy.txt");
    m_IRM.CreateInterfaceSection("Create", this);

    m_pGDR_TWCE_TEXT_ID = m_IRM.GetResObj<CIFStatic>(GDR_TWCE_TEXT_ID, 1); // 0x370
    m_pGDR_TWCE_GAUGE_HPGAUGE = m_IRM.GetResObj<CIFGauge>(GDR_TWCE_GAUGE_HPGAUGE, 1); // 0x374
    m_pGDR_TWCE_GAUGE_HPGAUGE->field_0x38c = 0.1;
    return true;
}

void CIFTargetWindowCommonEnemy::OnUpdate() {
    //printf("%s\n", __FUNCTION__);
    reinterpret_cast<void (__thiscall *)(const CIFTargetWindowCommonEnemy *)>(0x0069a550)(this);
}