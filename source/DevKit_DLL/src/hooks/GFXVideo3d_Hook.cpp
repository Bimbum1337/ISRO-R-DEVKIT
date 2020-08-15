#include "Hooks.h"
#include "GFXVideo3d_Hook.h"

extern std::vector<endscene_handler_t> hooks_endscene;
extern std::vector<create_handler_t> hooks_create;
extern std::vector<setsize_handler_t> hooks_setsize_pre;
extern std::vector<setsize_handler_t> hooks_setsize_post;

bool CGFXVideo3D_Hook::CreateThingsHook(HWND hWindow, void* msghandler, int a3)
{
	bool a = reinterpret_cast<bool (__thiscall*)(CGFXVideo3d*, HWND, void*, int)>(0x00BAE370)(
		this, hWindow, msghandler, a3);

	for (std::vector<create_handler_t>::iterator it = hooks_create.begin();
		it != hooks_create.end();
		++it)
	{
		(*it)(hWindow, msghandler, a3);
	}

	return a;
}

bool CGFXVideo3D_Hook::EndSceneHook()
{
	for (std::vector<endscene_handler_t>::iterator it = hooks_endscene.begin();
		it != hooks_endscene.end();
		++it)
	{
		(*it)();
	}

	// Full qualified name to avoid redirection through the vftable
	//return CGFXVideo3D_Hook::EndScene();

	m_pd3dDevice->EndScene();
	return true;
}

bool CGFXVideo3D_Hook::SetSizeHook(int width, int height)
{
	for (std::vector<setsize_handler_t>::iterator it = hooks_setsize_pre.begin();
		it != hooks_setsize_pre.end();
		++it)
	{
		(*it)(width, height);
	}

	CGFXVideo3d::SetSize(width, height);

	for (std::vector<setsize_handler_t>::iterator it = hooks_setsize_post.begin();
		it != hooks_setsize_post.end();
		++it)
	{
		(*it)(width, height);
	}

	return true;
}
