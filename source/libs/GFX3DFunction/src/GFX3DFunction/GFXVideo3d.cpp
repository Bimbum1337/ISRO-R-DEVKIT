#include "GFXVideo3d.h"
#include <cstdio>
#include <cmath>

#include <d3d9.h>
#include <d3dx9.h>


CGFXVideo3d::CGFXVideo3d()
	//: CD3DApplication(), camera()
{
	camera.camera = D3DXVECTOR3(0, 0, -100);
	camera.origin = D3DXVECTOR3(0, 0, 0);
	camera.rotation_unknown1 = D3DXVECTOR3(0, 1, 0);
	camera.rotation_to_world = D3DXVECTOR4(0, 0, 0, 100);

	D3DXMatrixIdentity(&worldMatrix);

	SetClearColor(0x7D7D7D);

	N0000942D = 0;
	N00000816 = 0;
	

	m_d3dEnumeration.AppUsesDepthBuffer = true;
	m_d3dEnumeration.AppMinDepthBits = 16;

	if (this->m_d3dSettings.IsWindowed)
		m_d3dSettings.Windowed_VertexProcessingType = MIXED_VP;
	else
		m_d3dSettings.Fullscreen_VertexProcessingType = MIXED_VP;

	m_color = 0;
	b_ClearMode = 1;
}

void CGFXVideo3d::SetMinDepthBits(int bits)
{
	m_d3dEnumeration.AppMinDepthBits = bits;
}

bool CGFXVideo3d::IsLost()
{
	return m_bDeviceLost;
}


CGFXVideo3d::~CGFXVideo3d()
{
}


float CGFXVideo3d::Project(const D3DVECTOR& origin, D3DVECTOR& pos2d)
{
	D3DMATRIX* view = &(this->m_viewmatrix);
	D3DVIEWPORT9 viewport;

	this->m_pd3dDevice->GetViewport(&viewport);

	float w = view->_14 * origin.x + view->_24 * origin.y + view->_34 * origin.z + view->_44;

	pos2d.x = 0;
	pos2d.y = 0;

	if (w > 0)
	{
		// can see object

		float x = view->_11 * origin.x + view->_21 * origin.y + view->_31 * origin.z + view->_41;
		float y = view->_12 * origin.x + view->_22 * origin.y + view->_32 * origin.z + view->_42;

		//D3DXVECTOR2 screendim;

		//this->GetViewportDimensions(screendim);

		//printf("screendim %d %d\n", screendim[0], screendim[1]);

        float viewport_width = static_cast<float>(viewport.Width);
        float viewport_height = static_cast<float>(viewport.Height);
        float viewport_x = static_cast<float>(viewport.X);
        float viewport_y = static_cast<float>(viewport.Y);

		float pos_x = ((x / w) * (viewport_width / 2.0f)) + viewport_x + (viewport_width / 2.0f);
		float pos_y = -((y / w) * (viewport_height / 2.0f)) + viewport_y + (viewport_height / 2.0f);


		pos2d.x = pos_x;
		pos2d.y = pos_y;
	}

	return w;
}

HRESULT CGFXVideo3d::SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX& Matrix)
{
	return this->m_pd3dDevice->SetTransform(State, &Matrix);
}

D3DMATRIX& CGFXVideo3d::GetViewmatrix()
{
	return this->m_viewmatrix;
}

bool CGFXVideo3d::BeginScene()
{
	return BeginSceneIMPL();
}

bool CGFXVideo3d::BeginSceneIMPL()
{
	if (m_bDeviceLost)
		Sleep(100);

	if (Render3DEnvironment())
	{
		if (!b_ClearMode)
		{
			m_pd3dDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, m_color, 1.0, 0);
		}
		else
		{
			m_pd3dDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, m_color, 1.0, 0);
		}

		if (m_pd3dDevice->BeginScene() != D3D_OK)
		{
			b_ClearMode = 0;
			return S_FALSE;
		}
	}

	return S_OK;
}

bool CGFXVideo3d::EndScene()
{
	m_pd3dDevice->EndScene();
	return 1;
}

char CGFXVideo3d::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride,
                          const RGNDATA* pDirtyRegion)
{
	if (m_pd3dDevice->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion) == D3DERR_DEVICELOST)
	{
		m_bDeviceLost = true;
		return 0;
	}

	return 1;
}

void CGFXVideo3d::SetClearColor(D3DCOLOR color)
{
	m_color = color;
	b_ClearMode = 1;
}

IDirect3DDevice9* CGFXVideo3d::GetDevice()
{
	return this->m_pd3dDevice;
}

int CGFXVideo3d::Get_N0000942D()
{
	return N0000942D;
}

char CGFXVideo3d::Set_N0000942D(int value)
{
	N0000942D = value;
	return 1;
}

char CGFXVideo3d::Func_32(float x, float y, D3DVECTOR& vec)
{
	D3DXVECTOR2 vp;
	GetViewportDimensions(vp);

	if (camera.N00000757)
		return 0;

	vec.x = (x - vp.x / 2.0f) / vp.x * camera.rotation_to_world.z;
	vec.y = (y - vp.y / 2.0f) / vp.y * camera.rotation_to_world.z;
	vec.z = 1.0;

	return 1;
}

void CGFXVideo3d::Func_33(bool a2, D3DXVECTOR3* out, D3DXVECTOR3* a4, D3DXVECTOR3* a5, int count)
{
	reinterpret_cast<void(__thiscall*)(CGFXVideo3d*, char, D3DXVECTOR3*, D3DXVECTOR3*, D3DXVECTOR3*, int)>(
		0x00BAEAD0)(
		this, a2, out, a4, a5, count);
}

char CGFXVideo3d::Func_34(D3DVECTOR& a2, float a3)
{
	return reinterpret_cast<char(__thiscall*)(CGFXVideo3d*, D3DVECTOR*, float)>(0x00BAD840)(this, &a2, a3);
}



void CGFXVideo3d::GetSizeInRect(RECT& rect)
{
	rect.top = 0;
	rect.left = 0;
	rect.bottom = this->res_height;
	rect.right = this->res_width;
}

void CGFXVideo3d::GetSizeInVec2(D3DXVECTOR2& vec)
{
	vec.x = static_cast<float>(res_width);
	vec.y = static_cast<float>(res_height);
}

void CGFXVideo3d::GetViewportDimensions(D3DXVECTOR2& vec)
{
	vec.x = static_cast<float>(res_width);
	vec.y = static_cast<float>(res_height);

	D3DVIEWPORT9 viewport;

	if (this->m_pd3dDevice->GetViewport(&viewport) == 0)
	{
		vec.x = static_cast<float>(viewport.Width);
		vec.y = static_cast<float>(viewport.Height);
	}
}

void CGFXVideo3d::SetCamera(CCamera& camera)
{
	reinterpret_cast<void (__thiscall*)(CGFXVideo3d*, CCamera*)>(0x00BAECB0)(this, &camera);
}

CCamera& CGFXVideo3d::GetCamera()
{
	return this->camera;
}
