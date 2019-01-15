#pragma once

#include <d3dx9.h>

class NavEdge
{
public:
	virtual ~NavEdge();

	D3DXVECTOR2 EdgeMin;
	D3DXVECTOR2 EdgeMax;
	int N1;
	int N2;
	char N3;
	char gapx[3];
	char N4_1;
	char N4_2;
	char N4_3;
	char gap;

	char N5;

};

