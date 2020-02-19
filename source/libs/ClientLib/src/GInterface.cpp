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
