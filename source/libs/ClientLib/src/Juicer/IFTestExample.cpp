#include "IFTestExample.h"
#include "GInterface.h"
#include "Game.h"
#include "ICPlayer.h"
#include "IFInventory.h"

GFX_IMPLEMENT_DYNCREATE(CIFTestExample, CIFMainFrame)
GFX_BEGIN_MESSAGE_MAP(CIFTestExample, CIFMainFrame)
ONG_COMMAND(3, &CIFTestExample::On_m_btn1)

GFX_END_MESSAGE_MAP()

CIFTestExample::CIFTestExample(void)
{
}
CIFTestExample::~CIFTestExample(void)
{
}
bool CIFTestExample::OnCreate(long ln)
{
    CIFMainFrame::OnCreate(ln);

    RECT m_tileRect = { 32,44,286,282 };
    m_tile = (CIFNormalTile*)CGWnd::CreateInstance(this, GFX_RUNTIME_CLASS(CIFNormalTile), m_tileRect, 2, 0);
    m_tile->TB_Func_13("interface\\ifcommon\\bg_tile\\com_bg_tile_a.ddj", 0, 0);

    RECT m_btn1Rect ={126,47,102,30};
    m_btn1 = (CIFButton*)CGWnd::CreateInstance(this, GFX_RUNTIME_CLASS(CIFButton), m_btn1Rect, 3, 0);
    m_btn1->TB_Func_13("interface\\ifcommon\\com_mid_button.ddj", 0, 0);
    m_btn1->SetText(L"Click Me");

    RECT m_static0Rect ={30,100,200,200};
    m_static0 = (CIFStatic*)CGWnd::CreateInstance(this, GFX_RUNTIME_CLASS(CIFStatic), m_static0Rect, 6, 0);
    m_static0->m_FontTexture.sub_8B4400(0, 0);
    m_static0->m_FontTexture.sub_8B4750(0);
    m_static0->TB_Func_5(0);
    m_static0->TB_Func_6(0);
    m_static0->m_FontTexture.SetColor(0xff0000);
    m_static0->SetText(L"Yo :)");

    TB_Func_13("interface\\frame\\mframe_wnd_", 0, 0);
    SetText(L"Main Window");
    return true;
}


void CIFTestExample::OnUpdate()
{

}
void CIFTestExample::On_m_btn1(){
    CIFWnd* Mainpopup =  g_pCGInterface->m_IRM.GetResObj<CIFWnd>(25, 1);
    if(Mainpopup)
    {
        int invCount = *(byte*) ((DWORD32)g_pCICPlayer + 0x2408);

        CIFInventory* Inventory = Mainpopup->m_IRM.GetResObj<CIFInventory>(70,1);

        int count = 0;

        for (int i = 0; i < invCount; i++) {
            CIFSlotWithHelp* pSlot = *reinterpret_cast<CIFSlotWithHelp**>(Inventory->pSlots + (i * 4));
            if(pSlot->ItemInfo)
            {
                int typeId = pSlot->ItemInfo->GetItemData()->m_typeId.m_type_id_value;

            }
        }

    }
}

