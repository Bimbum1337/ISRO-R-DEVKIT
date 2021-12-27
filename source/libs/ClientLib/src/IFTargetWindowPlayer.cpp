#include "IFTargetWindowPlayer.h"
#include "IFStatic.h"
#include "unsorted.h"
#include "TextStringManager.h"
#include "ICPlayer.h"

#include <remodel/MemberFunctionHook.h>

GFX_IMPLEMENT_DYNAMIC_EXISTING(CIFTargetWindowPlayer, 0x00eea5dc)

GFX_IMPLEMENT_DYNCREATE_FN(CIFTargetWindowPlayer, CIFWnd)

enum {
    GDR_TW_KINDRED_MARK = 10, // CIFStatic
    GDR_TWP_TEXT_NAME = 1, // CIFStatic
};

GFX_BEGIN_MESSAGE_MAP(CIFTargetWindowPlayer, CIFWnd)

GFX_END_MESSAGE_MAP()

bool CIFTargetWindowPlayer::OnCreate(long ln) {
    //printf("%s\n", __FUNCTION__);
    //return reinterpret_cast<bool (__thiscall *)(const CIFTargetWindowPlayer *, long)>(0x0069b180)(this, ln);

    m_IRM.LoadFromFile("resinfo\\iftw_player.txt");
    m_IRM.CreateInterfaceSection("Create", this);

    return true;
}

HOOK_ORIGINAL_MEMBER(0x0069b0d0, &CIFTargetWindowPlayer::FUN_0069b0d0);
void CIFTargetWindowPlayer::FUN_0069b0d0(int objectId) {
    m_objectId = objectId;
    CIGIDObject* pObject = GetCharacterObjectByID_MAYBE(m_objectId);
    if(pObject != NULL) {
        m_IRM.GetResObj<CIFStatic>(GDR_TWP_TEXT_NAME, 1)->SetText(pObject->GetName().c_str());
        m_IRM.GetResObj<CIFStatic>(GDR_TW_KINDRED_MARK, 1)->TB_Func_13(GetKindredTextureFilePath(pObject->GetSData()->m_nationality, 0), 0, 0);
    }
}
