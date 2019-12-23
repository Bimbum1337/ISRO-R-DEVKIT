#pragma once
#include <d3dx9.h>

#include "GFX3DFunction/Common/dxutil.h"
#include "GFX3DFunction/Common/d3dutil.h"
#include "GFX3DFunction/Common/d3denumeration.h"
#include "GFX3DFunction/Common/d3dsettings.h"
#include "GFX3DFunction/Common/d3dapp.h"

#include "GFXMainFrame/Camera.h"
#include <cassert>

#pragma comment(lib, "d3dxof.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d3dx9dt.lib")
#pragma comment(lib, "comctl32.lib")

class CGFXVideo3d : public CD3DApplication
{
public:
	/* 
	 * Begin of virtuals
	 */

	virtual ~CGFXVideo3d(void);

	virtual bool CreateThings(HWND hWindow, void* msghandler, int a3)
	{
		return reinterpret_cast<bool (__thiscall*)(CGFXVideo3d*, HWND, void*, int)>(0x00BAE370)(
			this, hWindow, msghandler, a3);
	}

	virtual char Func_18()
	{
		return 1;
	}

	virtual void GetSizeInRect(RECT& rect);

	virtual bool SetSize(int width, int height)
	{
		return reinterpret_cast<bool (__thiscall*)(CGFXVideo3d*, int a2, int a3)>(0x0BAD590)(this, width, height);
	}

	virtual void GetSizeInVec2(D3DXVECTOR2& vec);

	virtual void GetViewportDimensions(D3DXVECTOR2& vec);

	virtual void SetCamera(CCamera& camera);
	virtual CCamera& GetCamera();
	virtual bool BeginScene();
	bool BeginSceneIMPL();
	virtual bool EndScene();
	virtual char Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride,
	                     const RGNDATA* pDirtyRegion);

	virtual void SetClearColor(D3DCOLOR color);
	virtual IDirect3DDevice9* GetDevice();
	virtual int Get_N0000942D();
	virtual char Set_N0000942D(int value);
	virtual char Func_32(float x, float y, D3DVECTOR& vec);

	virtual void Func_33(bool a2, D3DXVECTOR3* out, D3DXVECTOR3* a4, D3DXVECTOR3* a5, int count);
	virtual char Func_34(D3DVECTOR& a2, float a3);

	virtual HRESULT SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX& Matrix);

	virtual D3DMATRIX& GetViewmatrix();

	/* 
	 * End of virtuals
	 */

	template<_D3DTEXTURESTAGESTATETYPE Type>
	static void UpdateTextureStageState(int value)
	{
		assert(FALSE);
#if 0
		if (m_states[Type] == value)
			return;

		g_D3DDevice->SetTextureStageState(0, Type, value);
		m_states[Type] = value;
#endif
	}


	CGFXVideo3d(void);
	void SetMinDepthBits(int bits);
	bool IsLost();

	static inline CGFXVideo3d* init()
	{
		return *reinterpret_cast<CGFXVideo3d**>(0x0110F7EC) = new CGFXVideo3d;
	}


	static inline CGFXVideo3d* get()
	{
		return *((CGFXVideo3d**)0x0110F7EC);
	}

	char EndSceneIMPL();

	float Project(const D3DVECTOR& origin, D3DVECTOR& pos2d);


public: /* members */
	int N0000942D; //0x034C
	int res_width; //0x0350
	int res_height; //0x0354
	int m_color; //0x0358
	CCamera camera; //0x035C at 35C!
	char N00000816; //0x04B0
	char b_ClearMode; //0x04B1
	char pad_04B2[2]; //0x04B2
	int N00000817[39]; //0x04B4
	D3DMATRIX m_viewmatrix; //0x0550
	char pad_0590[1536]; //0x0590
};

#define g_CD3DApplication (*((CGFXVideo3d**)0x0110F7EC))

#define worldMatrix (*((D3DXMATRIX*)0x011113F8))
