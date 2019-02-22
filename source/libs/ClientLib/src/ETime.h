#pragma once


class CETime
{
public:
	char pad_0004[4]; //0x0004
	int avg_ticks_per_second; //0x0008
	int current_tick_count; //0x000C
	char pad_0010[28]; //0x0010
	int TicksElapsed; //0x002C
	float AnimationSpeedCorrection; //0x0030
	float runtime; //0x0034
	char pad_0038[44]; //0x0038

	virtual ~CETime();
};
