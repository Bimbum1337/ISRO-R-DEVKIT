#pragma once
#include "GFXMainFrame/EntityManager.h"

class CEntityManagerClient : public CEntityManager
{
	
};

#define g_pGfxEttManager (*(CEntityManagerClient**)0x013BAE08)

