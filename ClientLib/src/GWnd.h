#pragma once

#include "GWndBase.h"

class CProcess; /* forward decl to avoid include recursion */

class CGWnd : public CGWndBase {
	// 132 - 132 = 0 <- no additional bytes :)
	GFX_DECLARE_DYNAMIC_EXISTING(CGWnd, 0x0110F94C)

public:
	virtual void F24(int a1, int a2);
	virtual bool F25(int a1);
	virtual void F26(int a1);
	virtual bool F27();
	virtual bool F28(int a1, int a2, int a3);
	virtual int F29(int a1, int a2, int a3);
	virtual int F30(int a1, int a2, int a3);
	virtual int F31(int a1, int a2, int a3);
	virtual int F32(int a1, int a2, int a3);
	virtual int F33(int a1, int a2, int a3);
	virtual int F34(int a1, int a2, int a3);
	virtual int F35(int a1, int a2, int a3);
	virtual int F36(int a1, int a2, int a3, int a4);
	virtual void Func_37();

	CGWnd();

	void OnUpdate() override;
	void RenderMyself() override;
	void RenderMyChildren() override;
	void Render() override;

	void Func_15() override;

	bool On3DEvent_MAYBE(Event3D* a2) override;



	static CGWnd* CreateInstance(CProcess* pParent, CGfxRuntimeClass* pType, RECT& Rect, int a4, int a5)
	{
		return reinterpret_cast<CGWnd*(__cdecl*)(CProcess*,CGfxRuntimeClass*,RECT*,int,int)>(0x00BA20B0)(pParent, pType, &Rect, a4, a5);
	}
};
