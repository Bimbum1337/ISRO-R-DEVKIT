#pragma once
#include "PSilkroad.h"
#include "CameraWorking.h"

class CPSOuterInterface :
	public CPSilkroad
{
	GFX_DECLARE_DYNAMIC_EXISTING(CPSOuterInterface, 0x00EED954);
public:
	// size 10C / 268
	CCameraWorking* m_cameraworking; //0x00E0
	int current_state; //0x00E4
	int N0000098B; //0x00E8
	char pad_00EC[32]; //0x00EC

public:
	void OnTimer(int a1) override;
	void OnUpdate() override;
	void Func_40() override;

	void RenderMyself() override;

public:

	void Handle_0xFFC(CMsgStreamBuffer* p_msg);

	CPSOuterInterface()
	{
		reinterpret_cast<void(__thiscall*)(CPSOuterInterface*)>(0x008629A0)(this);
	}

	~CPSOuterInterface()
	{

	}
};

