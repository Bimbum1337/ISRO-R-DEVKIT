#pragma once

#include <Windows.h>
#include <list>
#include "BSLib/BSLib.h"


struct Event3D
{
	char pad_0000[4]; //0x0000
	int Msg; //0x0004
	char pad_0008[12]; //0x0008
	int lParam; //0x0014
	int wParam; //0x0018
}; //Size: 0x001C

/**
 * This class acts as a parent for any control and provides a container for child-controls
 * Note: As of current state of knowledge, OnUpdate() must be overwritten in any derived class to avoid an endless loop
 */
class CGWndBase : public CObjChild { // size 32 + 100 = 132
	GFX_DECLARE_DYNAMIC_EXISTING(CGWndBase, 0x0110F630)

public:
	virtual void Func_7(CGWndBase* a2);
	virtual int AddControlToList(CGWndBase* a2);
	virtual void RemoveControlFromList(CGWndBase* a2);
	virtual bool OnCreate(long ln);
	virtual bool OnRelease();
	virtual void OnUpdate();
	virtual void RenderMyself();
	virtual void RenderMyChildren();
	virtual void Func_15();
	virtual void Render();
	virtual bool On3DEvent_MAYBE(Event3D* a2);
	virtual bool Func_18(int a1);
	virtual void OnWndMessage(int a1);
	virtual void Func_20();
	virtual void SetGWndSize(int width, int height);
	virtual void Func_22(int x, int y);
	virtual void SetVisibility(bool);


public:
	
	CGWndBase();

	bool IsVisible();
	void ApplyGlobalScale(int x);
	void GetBounds(RECT& a2);

	void sub_6526E0(char n00009771, unsigned char opacity, float time, float a4, char a5);
	
	void sub_B9DA70(bool b);


	const int UniqueID();

protected:
	void sub_B8F440(const RECT& rect);

private:
	int m_lnListLockRead; //0x0020
	int m_lnListLockWrite; //0x0024
	bool N000006F5; //0x0028
	char pad_0029[3]; //0x0029
	int m_hgWnd; //0x002C
	int N000006F7; //0x0030
	int m_UniqueID; //0x0034
	int N000006F9; //0x0038
	bool N000006FB; //0x003C
	char pad_003D[3]; //0x003D
	RECT bounds; //0x0040 was private, 40
	RECT N000006FD; //0x0050
	char pad_0060[1]; //0x0060
protected:
	bool m_bVisible; //0x0061 61
	bool m_bClickable; //0x0062
	bool N0000074F; //0x0063
	bool N00000702; //0x0064
private:
	char pad_0065[3]; //0x0065
	int N00000703; //0x0068
	int m_iflist; //0x006C
	short N00000705; //0x0070
	char pad_0072[6]; //0x0072
	std::n_list<CGWndBase*> N00000707; //0x0078
};
