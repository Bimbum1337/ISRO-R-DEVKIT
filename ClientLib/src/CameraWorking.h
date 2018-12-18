#pragma once
#include <d3dx9.h>

class CCameraWorking // size = 280, confirmed by CGInterface::ctor
{
public:
	char pad_0004[232-4]; //0x0004
	float float_E8; //0x00E8
	char pad_00EC[4]; //0x00EC
	float float_F0; //0x00F0
	char pad_00F4[4]; //0x00F4
	D3DXVECTOR3 location; //0x00F8
	D3DXVECTOR4 rotation; //0x0104
	// float zoom; //0x0110 replaced by D3DXVECTOR4
	char pad_0114[4]; //0x0114

	void sub_4E5BF0(float x)
	{
		reinterpret_cast<void(__thiscall*)(CCameraWorking*,float)>(0x4E5BF0)(this, x);
	}

	void AddKeyframe(float a1, const D3DVECTOR& translation, const D3DXVECTOR4& rotation);
	void sub_4E6630();

	virtual ~CCameraWorking()
	{
		// TODO: Implement ~CCameraWorking (required for destructing CPSOuterInterface)
	}
}; //Size: 0x0118
