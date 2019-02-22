#include "StdAfx.h"
#include "CameraWorking.h"

void CCameraWorking::AddKeyframe(float a1, const D3DVECTOR& translation, const D3DXVECTOR4& rotation)
{
	reinterpret_cast<void(__thiscall*)(CCameraWorking*,float,const D3DVECTOR*,const D3DXVECTOR4*)>(0x004E67B0)(this, a1, &translation, &rotation);
}

void CCameraWorking::sub_4E6630()
{
	reinterpret_cast<void(__thiscall*)(CCameraWorking*)>(0x4E6630)(this);
}
