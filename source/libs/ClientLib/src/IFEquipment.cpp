#include "IFEquipment.h"
#include "GInterface.h"
#include "ICPlayer.h"
#include "IFButton.h"
#include "IFSystemMessage.h"
#include <ctime>

bool CIFEquipment::OnCreateIMPL(long ln)
{
    bool result = reinterpret_cast<bool(__thiscall *)(CIFEquipment *, long)>(0x78C6A0)(this, ln);

    RECT m_btn1Rect ={44,257,90,22};
    CIFButton* m_autosort = (CIFButton*)CGWnd::CreateInstance(this, GFX_RUNTIME_CLASS(CIFButton), m_btn1Rect, 15779, 0);
    m_autosort->TB_Func_13("interface\\mall\\mall_button.ddj", 0, 0);
    m_autosort->SetText(L"Auto Sort");

    return result;
}
time_t lastUpdate = clock();
bool isRunning = false;
void CIFEquipment::OnUpdateIMPL() {
    reinterpret_cast<bool(__thiscall *)(CIFEquipment *)>(0x78BAB0)(this);
    if(isSortRequested && float(clock() - lastUpdate) / CLOCKS_PER_SEC > 0.3)
    {

        bool finished = false;

        bool isPacketSent = false;

        D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 0);
        CIFSystemMessage *systemmessage = g_pCGInterface->GetSystemMessageView();
        if(!isRunning)
        {
            isRunning = true;
            systemmessage->WriteMessage(255, color, L"Starting sorting the inventory.", 0, 1);
        }

        int invCount = *(byte*) ((DWORD32)g_pCICPlayer + 0x2408);
        CIFInventory* Inventory = ((CIFMainPopup*)this->GetParentControl())->m_IRM.GetResObj<CIFInventory>(70,1);

        for (int i = 0; i < invCount; i++) {
            CIFSlotWithHelp* pSlot = *reinterpret_cast<CIFSlotWithHelp**>(Inventory->pSlots + (i * 4));
            if(pSlot->ItemInfo)
            {
                int itemId = pSlot->ItemInfo->GetItemData()->m_id;
                int itemCount = pSlot->ItemInfo->GetQuantity();
                int maxCount = pSlot->ItemInfo->GetItemData()->m_maxstack;

                if(itemCount < maxCount)
                {
                    for (int j = i+1; j < invCount; j++) {

                        CIFSlotWithHelp* pSlotj = *reinterpret_cast<CIFSlotWithHelp**>(Inventory->pSlots + (j * 4));
                        if(pSlotj->ItemInfo)
                        {
                            int itemIdj = pSlotj->ItemInfo->GetItemData()->m_id;
                            int itemCountj = pSlotj->ItemInfo->GetQuantity();

                            if(itemIdj == itemId && itemCountj < maxCount)
                            {

                                int countToMove = 0;
                                if(itemCount + itemCountj <= maxCount)
                                    countToMove = itemCount;
                                else
                                    countToMove = itemCount + itemCountj - maxCount;

                                CMsgStreamBuffer buf(0x7034);
                                buf << BYTE(0x0) << BYTE(i + 13) << BYTE(j + 13) << UINT16(countToMove);
                                SendMsg(buf);

                                isPacketSent = true;
                                break;
                            }
                        }
                    }
                }
            }

            if(isPacketSent)
                break;

            if(i == invCount - 1)
            {
                finished = true;
                isRunning = false;
            }

        }

        if(finished)
        {
            color = D3DCOLOR_ARGB(255, 0, 255, 0);
            systemmessage->WriteMessage(255, color, L"Finished sorting the inventory.", 0, 1);
            isSortRequested = false;
        }

        lastUpdate = clock();
    }
}

