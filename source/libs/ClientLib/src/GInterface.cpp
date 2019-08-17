#include "StdAfx.h"
#include "GInterface.h"
#include "IFflorian0Guide.h"

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
	return (CIF_NPCWindow*)this->m_IRM2.GetResObj(GDR_NPCWINDOW, 1);
}

CIFMainPopup* CGInterface::Get_GDR_MAINPOPUP()
{
	return (CIFMainPopup*)this->m_IRM2.GetResObj(GDR_MAINPOPUP, 1);
}

CIFStorageRoom* CGInterface::Get_GDR_STORAGEROOM()
{
	return (CIFStorageRoom*)this->m_IRM2.GetResObj(GDR_STORAGEROOM, 1);
}

CIFStorageRoom* CGInterface::Get_GDR_GUILDSTORAGEROOM()
{
	return (CIFStorageRoom*)this->m_IRM2.GetResObj(GDR_GUILDSTORAGEROOM, 1);
}

void CGInterface::WriteErrorMessage(byte errorType, unsigned __int16 errorCode, int colorARGB, int a5, int a6)
{
	return reinterpret_cast<void(__thiscall*)(void*, byte, unsigned __int16, int, int, int)>(0x00778190)(this, errorType, errorCode, colorARGB, a5, a6);
}
