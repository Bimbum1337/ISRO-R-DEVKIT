#pragma once

#include <d3dx9.h>

#define DXDrawLine ((void (__cdecl *)(int, int, int, int, int, float))0x00841F30)

template<typename T>
void PrettyLine3D(D3DVECTOR &p1, D3DVECTOR& p2, int step, int color, T* pNavmesh)
{
	CGFXVideo3d *gfx = CGFXVideo3d::get();

	float distance_x = p2.x - p1.x;
	float distance_z = p2.z - p1.z;

	float distance = sqrt(distance_x * distance_x + distance_z * distance_z);

	D3DVECTOR prev2d = {0,0,0};
	bool prevVis = false;

	for (int a = 0; a <= distance; a+=step)
	{
		D3DVECTOR p;
		p.x = p1.x + distance_x / distance * (float)a;
		p.z = p1.z + distance_z / distance * (float)a;

		pNavmesh->FindHeight(p);
		D3DVECTOR p2d;
		bool vis = gfx->Project(p, p2d) > 0;
		if (vis)
		{
			if (a>0 && prevVis) {
				DXDrawLine((int) prev2d.x, (int) prev2d.y, (int) p2d.x, (int) p2d.y, color, 1.0);
			}
		}

		prev2d = p2d;
		prevVis = vis;

	}
}

template<typename T>
void PrettyLine3D(D3DVECTOR &p1, D3DVECTOR& p2, int step, T* pNavmesh)
{
	PrettyLine3D(p1, p2, step, 0x00FF88FF, pNavmesh);
}

void rotatey(D3DXVECTOR3& vec, float radiant);
