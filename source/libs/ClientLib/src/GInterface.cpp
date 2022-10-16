#include "GInterface.h"
#include "BSLib/Debug.h"
#include "GlobalDataManager.h"
#include "IFChatViewer.h"
#include "IFNotify.h"
#include "IFflorian0Guide.h"
#include "Juicer/IFTestExample.h"

#include <BSLib/multibyte.h>

#include <remodel/MemberFunctionHook.h>

void CGInterface::RenderToggle_WORLDMAP_GUIDE() {
    return reinterpret_cast<void (__thiscall *)(void *)>(0x0079ABE0)(this);
}

void CGInterface::Render_GDR_AUTO_POTION(bool visible) {
    return reinterpret_cast<void (__thiscall *)(void *, bool)>(0x0079C750)(this, visible);
}

void CGInterface::CreateFlorian0Event() {
    CGWnd *guide = GetAlarmManager()->GetGuide(GUIDE_FLORIAN0);
}

CAlramGuideMgrWnd *CGInterface::GetAlarmManager() {
    return m_IRM.GetResObj<CAlramGuideMgrWnd>(GDR_ALRAM_GUIDE_MGR_WND, 1);
}

bool CGInterface::OnCreateIMPL(long ln) {
    BS_DEBUG_LOW("ImGui_WndProc");

    BeforeOnCreate();

    bool b = reinterpret_cast<bool (__thiscall *)(CGInterface *, long)>(0x00873E50)(this, ln);

    AfterOnCreate();

    return b;
}

void CGInterface::BeforeOnCreate() {

}

void CGInterface::AfterOnCreate() {
    CreateFlorian0Event();

    RECT testRect = {409,137,350,350};
    (CIFTestExample*)CGWnd::CreateInstance(this, GFX_RUNTIME_CLASS(CIFTestExample), testRect, 134021, 0);
}

void CGInterface::ShowMessage_Quest(const std::n_wstring &msg) {
    CIFNotify *notify = m_IRM.GetResObj<CIFNotify>(GDR_UPDATE_QUEST_INFO, 1);
    notify->ShowMessage(msg);
}

void CGInterface::ShowMessage_Notice(const std::n_wstring &msg) {
    CIFNotify *notify = m_IRM.GetResObj<CIFNotify>(GDR_NOTICE, 1);
    notify->ShowMessage(msg);
}

void CGInterface::ShowMessage_Warning(const std::n_wstring &msg) {
    CIFNotify *notify = m_IRM.GetResObj<CIFNotify>(GDR_WARNING_WND, 1);
    notify->ShowMessage(msg);
}


int CGInterface::Get_SelectedObjectId() {
    return this->m_selectedObjectId;
}

CIFTimerWnd *CGInterface::Get_TimerWindow() {
    return this->m_timerWindow;
}

CIFQuickStateHalfWnd *CGInterface::Get_QuickStateHalfWnd() {
    return this->N00002637;
}

CIF_NPCWindow *CGInterface::Get_GDR_NPCWINDOW() {
    return (CIF_NPCWindow *) this->m_IRM.GetResObj(GDR_NPCWINDOW, 1);
}

//HOOK_ORIGINAL_MEMBER(0x00798D00, &CGInterface::GetMainPopup);
CIFMainPopup *CGInterface::GetMainPopup() {
    return (CIFMainPopup *) this->m_IRM.GetResObj(GDR_MAINPOPUP, 1);
}

CIFStorageRoom *CGInterface::Get_GDR_STORAGEROOM() {
    return (CIFStorageRoom *) this->m_IRM.GetResObj(GDR_STORAGEROOM, 1);
}

CIFStorageRoom *CGInterface::Get_GDR_GUILDSTORAGEROOM() {
    return (CIFStorageRoom *) this->m_IRM.GetResObj(GDR_GUILDSTORAGEROOM, 1);
}

void CGInterface::WriteErrorMessage(byte errorType, unsigned __int16 errorCode, int colorARGB, int a5, int a6) {
    return reinterpret_cast<
            void (__thiscall *)(void *, byte, unsigned __int16, int, int, int)
            >(0x00778190)(this, errorType, errorCode, colorARGB, a5, a6);
}

void CGInterface::WriteSystemMessage(eLogType level, const wchar_t *str) {
    reinterpret_cast<void (__thiscall *)(CGInterface *, eLogType, const wchar_t *)>(0x007781B0)(this, level, str);
}

void CGInterface::sub_787C10(SChatMetaData &meta) {
    reinterpret_cast<void (__thiscall *)(CGInterface *, SChatMetaData *)>(0x787C10)(this, &meta);
}

int CGInterface::TryParseChatCommands(const wchar_t *text, RECT &r, std::vector<void *> &v) {
    return reinterpret_cast<
            int (__thiscall *)(CGInterface *, const wchar_t *, RECT *, std::vector<void *> *)
            >(0x0078BEA0)(this, text, &r, &v);
}

void CGInterface::ToggleQuestNew() {
    reinterpret_cast<void (__thiscall *)(CGInterface *)>(0x007990e0)(this);
}

CNIFCommunityWnd *CGInterface::GetCommunityWnd() {
    return reinterpret_cast<CNIFCommunityWnd *(__thiscall *)(CGInterface *)>(0x007994f0)(this);
}

void CGInterface::FUN_00777c30(ChatType type, const wchar_t *message, D3DCOLOR color, int a5) {
    CIFChatViewer *chatViewer = m_IRM.GetResObj<CIFChatViewer>(GDR_CHATVIEWER, 1);
    chatViewer->FUN_007aca30(type, color, message, 0, a5);
}

void CGInterface::FUN_00778a10(int a2, const wchar_t *message, D3DCOLOR color) {
    reinterpret_cast<
            void (__thiscall *)(CGInterface *, int, const wchar_t *, D3DCOLOR)
            >(0x00778a10)(this, a2, message, color);
}

void CGInterface::FUN_00777cf0(const std::n_wstring &recipient) {
    reinterpret_cast<void (__thiscall *)(CGInterface *, const std::n_wstring *)>(0x00777cf0)(this, &recipient);
}

CIFSystemMessage *CGInterface::GetSystemMessageView() {
    return m_IRM.GetResObj<CIFSystemMessage>(GDR_SYSTEM_MESSAGE_VIEW, 1);
}

void CGInterface::FUN_0079a7e0(CGWndBase *pGWnd) const {
    reinterpret_cast<void (__thiscall *)(const CGInterface *, CGWndBase *)>(0x0079a7e0)(this, pGWnd);
}

void CGInterface::FUN_0079b8a0(undefined1 a1, undefined4 a2) {
    reinterpret_cast<void(__thiscall *)(CGInterface *, undefined1, undefined4)>(0x0079b8a0)(this, a1, a2);
}

void CGInterface::RequestStatIncrement(undefined4 a1, undefined4 a2, undefined4 a3, undefined4 a4) {
    if (a1 == 0x4b) {
        if (a2 == 1) {
            NEWMSG(0x7050)
            SENDMSG()
        } else if (a2 == 2) {
            NEWMSG(0x7051)
            SENDMSG()
        }
    }
}

void CGInterface::FUN_00777a70(undefined4 param_1, undefined4 param_2) {
    reinterpret_cast<void(__thiscall *)(CGInterface *, undefined4, undefined4)>(0x00777a70)(this, param_1, param_2);
}
