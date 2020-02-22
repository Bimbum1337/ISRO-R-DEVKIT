#pragma once

#include "BSLib/BSLib.h"

class FakeWinMain_CPSQuickStart
{
public:
	static int APIENTRY _FakeWinMain_CPSQuickStart(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow);
	static void Setup(std::vector<const CGfxRuntimeClass*>* a);
	void RegisterObject(const CGfxRuntimeClass*);

private:
	
	//static HINSTANCE hInst;
};
