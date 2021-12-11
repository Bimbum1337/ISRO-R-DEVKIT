#include "SOItem.h"
#include "GlobalDataManager.h"


const CItemData::SData *CSOItem::GetItemData() const {
    const CItemData::SData *data = NULL;

    if (m_refObjItemId != 0) {
        data = &g_CGlobalDataManager->GetItemData(m_refObjItemId);
    }

    return data;
}

int CSOItem::GetQuantity() const {
    return m_quantity;
}
