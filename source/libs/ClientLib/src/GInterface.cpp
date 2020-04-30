#include "StdAfx.h"
#include "GInterface.h"
#include "IFflorian0Guide.h"
#include "IFNotify.h"
#include "IFChatViewer.h"
#include "IFNotify.h"

void CGInterface::RenderToggle_GDR_ACTION()
{
	return reinterpret_cast<void(__thiscall*)(void*)>(0x0079D5B0)(this);
}

void CGInterface::RenderToggle_GDR_APPRENTICESHIP()
{
	return reinterpret_cast<void(__thiscall*)(void*)>(0x0079B0B0)(this);
}
void CGInterface::RenderToggle_GDR_PLAYERINFO()
{
	return reinterpret_cast<void(__thiscall*)(void*)>(0x0079ACE0)(this);
}

void CGInterface::RenderToggle_GDR_GAMEGUIDE()
{
	return reinterpret_cast<void(__thiscall*)(void*)>(0x0079F690)(this);
}
void CGInterface::RenderToggle_GDR_INVENTORY()
{
	return reinterpret_cast<void(__thiscall*)(void*)>(0x0079B020)(this);
}
void CGInterface::RenderToggle_GDR_PARTY()
{
	return reinterpret_cast<void(__thiscall*)(void*)>(0x0079AE90)(this);
}
void CGInterface::RenderToggle_GDR_SKILL()
{
	return reinterpret_cast<void(__thiscall*)(void*)>(0x0079AE00)(this);
}

void CGInterface::RenderToggle_WORLDMAP_GUIDE()
{
	return reinterpret_cast<void(__thiscall*)(void*)>(0x0079ABE0)(this);
}
void CGInterface::Render_GDR_AUTO_POTION(bool visible)
{
	return reinterpret_cast<void(__thiscall*)(void*, bool)>(0x0079C750)(this, visible);
}

void CGInterface::CreateFlorian0Event() {
    CGWnd *guide = GetAlarmManager()->GetGuide(GUIDE_FLORIAN0);
}

CAlramGuideMgrWnd *CGInterface::GetAlarmManager() {
    return m_IRM.GetResObj<CAlramGuideMgrWnd>(GDR_ALRAM_GUIDE_MGR_WND, 1);
}

bool CGInterface::OnCreateIMPL(long ln) {

    BeforeOnCreate();

    bool b = reinterpret_cast<bool(__thiscall*)(CGInterface*, long)>(0x0078c910)(this, ln);

    AfterOnCreate();

    return b;
}

void CGInterface::BeforeOnCreate() {

}

void CGInterface::AfterOnCreate() {
    CreateFlorian0Event();
}

void CGInterface::ShowMessage_Quest(const std::n_wstring &msg) {
    CIFNotify* notify = m_IRM.GetResObj<CIFNotify>(GDR_UPDATE_QUEST_INFO, 1);
    notify->ShowMessage(msg);
}

void CGInterface::ShowMessage_Notice(const std::n_wstring &msg) {
    CIFNotify* notify = m_IRM.GetResObj<CIFNotify>(GDR_NOTICE, 1);
    notify->ShowMessage(msg);
}

void CGInterface::ShowMessage_Warning(const std::n_wstring &msg) {
    CIFNotify* notify = m_IRM.GetResObj<CIFNotify>(GDR_WARNING_WND, 1);
    notify->ShowMessage(msg);
}


int CGInterface::Get_SelectedObjectId()
{
	return this->m_selectedObjectId;
}

CIFTimerWnd* CGInterface::Get_TimerWindow()
{
	return this->m_timerWindow;
}

CIFQuickStateHalfWnd* CGInterface::Get_QuickStateHalfWnd()
{
	return this->N00002637;
}

CIF_NPCWindow* CGInterface::Get_GDR_NPCWINDOW()
{
	return (CIF_NPCWindow*)this->m_IRM.GetResObj(GDR_NPCWINDOW, 1);
}

CIFMainPopup* CGInterface::Get_GDR_MAINPOPUP()
{
	return (CIFMainPopup*)this->m_IRM.GetResObj(GDR_MAINPOPUP, 1);
}

CIFStorageRoom* CGInterface::Get_GDR_STORAGEROOM()
{
	return (CIFStorageRoom*)this->m_IRM.GetResObj(GDR_STORAGEROOM, 1);
}

CIFStorageRoom* CGInterface::Get_GDR_GUILDSTORAGEROOM()
{
	return (CIFStorageRoom*)this->m_IRM.GetResObj(GDR_GUILDSTORAGEROOM, 1);
}

void CGInterface::WriteErrorMessage(byte errorType, unsigned __int16 errorCode, int colorARGB, int a5, int a6)
{
	return reinterpret_cast<void(__thiscall*)(void*, byte, unsigned __int16, int, int, int)>(0x00778190)(this, errorType, errorCode, colorARGB, a5, a6);
}

void CGInterface::WriteSystemMessage(eLogType level, const wchar_t *str) {
    reinterpret_cast<void(__thiscall*)(CGInterface*,eLogType,const wchar_t*)>(0x007781B0)(this, level, str);
}

void CGInterface::sub_787C10(SChatMetaData &meta) {
    reinterpret_cast<void(__thiscall*)(CGInterface*, SChatMetaData*)>(0x787C10)(this, &meta);
}

int CGInterface::TryParseChatCommands(const wchar_t *text, RECT &r, std::vector<void *> &v) {
    return reinterpret_cast<int(__thiscall*)(CGInterface*, const wchar_t *, RECT*, std::vector<void*> *)>(0x0078BEA0)(this, text, &r, &v);
}

CNIFCommunityWnd *CGInterface::GetCommunityWnd() {
    return reinterpret_cast<CNIFCommunityWnd*(__thiscall*)(CGInterface*)>(0x007994f0)(this);
}

void CGInterface::FUN_00777c30(ChatType type, const wchar_t *message, D3DCOLOR color, int a5) {
    CIFChatViewer* chatViewer = m_IRM.GetResObj<CIFChatViewer>(GDR_CHATVIEWER, 1);
    chatViewer->FUN_007aca30(type, color, message, 0, a5);
}

void CGInterface::FUN_00778a10(int a2, const wchar_t* message, D3DCOLOR color) {
    reinterpret_cast<void(__thiscall*)(CGInterface*, int, const wchar_t*, D3DCOLOR)>(0x00778a10)(this, a2, message, color);
}

void CGInterface::FUN_00777cf0(const std::n_wstring &recipient) {
    reinterpret_cast<void(__thiscall*)(CGInterface*, const std::n_wstring*)>(0x00777cf0)(this, &recipient);
}
