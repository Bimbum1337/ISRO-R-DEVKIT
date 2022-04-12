 

## 1. An interface definition file (Media/resinfo/ifflorian0.txt)

This file describes how your interface is going to look. The `CIFFrame` is necessary to make your window look less shitty and `CIFNormalTile` will render over the hole in the middle of the interface. Please note that every ID has to be unique for your window and the IDs `1`,`2`,`3` and probably more are reserved. So just start at `5` and you are safe. The names seem to be irrelevant.

To layout your window, use the `Rect`-option. The format is as follows: "x, y, width, height"

```
Interface Text


Section = Create,"0,0,0,0","0"
{
	GDR_FLORIAN0_LABEL:CIFStatic
	{
		ClientRect=RECT,"0,0,0,0"
		Color=COLOR,"255,214,171,46"
		DDJ=STRING,""
		FontColor=COLOR,"255,254,251,216"
		FontIndex=INTEGER,"2"
		HAlign=INTEGER,"1"
		ID=INTEGER,"10"
		Rect=RECT,"31,58,120,20"
		Style=INTEGER,"0"
		SubSection=STRING,""
		Text=STRING,""
		UV_LB=POINT,"0,1"
		UV_LT=POINT,"0,0"
		UV_RB=POINT,"1,1"
		UV_RT=POINT,"1,0"
		VAlign=INTEGER,"1"
	}
	GDR_FLORIAN0_BTN:CIFButton
	{
		ClientRect=RECT,"0,0,0,0"
		Color=COLOR,"255,73,102,178"
		DDJ=STRING,"interface\\system\\sys_button.ddj"
		FontColor=COLOR,"255,254,251,216"
		FontIndex=INTEGER,"0"
		HAlign=INTEGER,"1"
		ID=INTEGER,"11"
		Rect=RECT,"31,92,0,0"
		Style=INTEGER,"0"
		SubSection=STRING,""
		Text=STRING,"UIIT_STT_FLORIAN0_BTN"
		UV_LB=POINT,"0,1"
		UV_LT=POINT,"0,0"
		UV_RB=POINT,"1,1"
		UV_RT=POINT,"1,0"
		VAlign=INTEGER,"1"
	}
	GDR_FLORIAN0_LABEL_TIME:CIFStatic
	{
		ClientRect=RECT,"0,0,0,0"
		Color=COLOR,"255,214,171,46"
		DDJ=STRING,""
		FontColor=COLOR,"255,254,251,216"
		FontIndex=INTEGER,"1"
		HAlign=INTEGER,"1"
		ID=INTEGER,"13"
		Rect=RECT,"31,159,120,20"
		Style=INTEGER,"0"
		SubSection=STRING,""
		Text=STRING,""
		UV_LB=POINT,"0,1"
		UV_LT=POINT,"0,0"
		UV_RB=POINT,"1,1"
		UV_RT=POINT,"1,0"
		VAlign=INTEGER,"1"
	}
	GDR_FLORIAN0_FRAME:CIFFrame
	{
		ClientRect=RECT,"0,0,0,0"
		Color=COLOR,"255,108,205,164"
		DDJ=STRING,"interface\\inventory\\int_window_"
		FontColor=COLOR,"255,255,255,255"
		FontIndex=INTEGER,"0"
		HAlign=INTEGER,"2"
		ID=INTEGER,"6"
		Rect=RECT,"17,45,366,240"
		Style=INTEGER,"0"
		SubSection=STRING,""
		Text=STRING,""
		UV_LB=POINT,"0,1"
		UV_LT=POINT,"0,0"
		UV_RB=POINT,"1,1"
		UV_RT=POINT,"1,0"
		VAlign=INTEGER,"0"
	}
	GDR_FLORIAN0_BGTILE:CIFNormalTile
	{
		ClientRect=RECT,"0,0,0,0"
		Color=COLOR,"255,72,211,143"
		DDJ=STRING,"interface\\ifcommon\\bg_tile\\com_bg_tile_b.ddj"
		FontColor=COLOR,"255,255,255,255"
		FontIndex=INTEGER,"0"
		HAlign=INTEGER,"0"
		ID=INTEGER,"5"
		Rect=RECT,"22,50,355,230"
		Style=INTEGER,"0"
		SubSection=STRING,""
		Text=STRING,""
		UV_LB=POINT,"0,1"
		UV_LT=POINT,"0,0"
		UV_RB=POINT,"1,1"
		UV_RT=POINT,"1,0"
		VAlign=INTEGER,"0"
	}
}
```

## 2. Register your custom interface

For the normal ingame location, just use `Media.pk2/resinfo/ginterface.txt`. On other occasions like login or character select check out the `ps*.txt` files. As previously described, the ID has to be unique, in this case unique for the whole file.

```
GDR_FLORIAN0:CIFflorian0
{
	ClientRect=RECT,"0,0,0,0"
	Color=COLOR,"255,8,214,78"
	DDJ=STRING,"interface\\frame\\mframe_wnd_"
	FontColor=COLOR,"255,255,255,255"
	FontIndex=INTEGER,"0"
	HAlign=INTEGER,"0"
	ID=INTEGER,"1338"
	Rect=RECT,"300,200,400,300"
	Style=INTEGER,"0"
	SubSection=STRING,""
	Text=STRING,"UIIT_PAG_FLORIAN0"
	UV_LB=POINT,"0,1"
	UV_LT=POINT,"0,0"
	UV_RB=POINT,"1,1"
	UV_RT=POINT,"1,0"
	VAlign=INTEGER,"0"
}
```

## 3. Write some code

Phew. No code so far. Lets change that.

This is the absolute minimum code you can have. `DYNCREATE` is for allowing the class to be instanciated by Silkroad and `MESSAGE_MAP` is to handle messages (like Show/Hide/Click/etc).

```cpp
#pragma once
#include "IFMainFrame.h"


class CIFflorian0 : public CIFMainFrame
{
	GFX_DECLARE_DYNCREATE(CIFflorian0)
	GFX_DECLARE_MESSAGE_MAP(CIFflorian0)

public:
	CIFflorian0(void);
	~CIFflorian0(void);

	bool OnCreate(long ln) override;
	
private:
	// no members
};
```

```cpp
#include "IFflorian0.h"

#define GDR_FLORIAN0_BGTILE 5
#define GDR_FLORIAN0_FRAME 6
#define GDR_FLORIAN0_LABEL 10
#define GDR_FLORIAN0_BTN 11
#define GDR_FLORIAN0_LABEL_TIME 13

GFX_IMPLEMENT_DYNCREATE(CIFflorian0, CIFMainFrame)

GFX_BEGIN_MESSAGE_MAP(CIFflorian0, CIFMainFrame)
	// empty
GFX_END_MESSAGE_MAP()


CIFflorian0::CIFflorian0(void)
{
}


CIFflorian0::~CIFflorian0(void)
{
}

bool CIFflorian0::OnCreate(long ln)
{
	// Populate inherited members
	CIFMainFrame::OnCreate(ln);

	m_IRM.LoadFromFile("resinfo\\ifflorian0.txt");
	m_IRM.CreateInterfaceSection("Create", this);

	return true;
}

```

## 4. User interaction

Having a window is cool. But is pretty much [ussless](http://i.epvpimg.com/moDGfab.png) without any user interaction.

Add a method to handle your pressed button. Better make it private or protected to avoid some idiot (probably you) calling it out of context.

My code simply prints "Hello World" with a increasing counter to the label. The typename in the <> describes which type to expect to be returned. Make sure your type is correct. There is no parachute or safety net.

```cpp
private:
	void On_BtnClick();
```

```cpp
void CIFflorian0::On_BtnClick()
{
	static int i = 0;

	wchar_t buffer[80];
	swprintf(buffer, L"Hello World (%d)", i++);

	m_IRM.GetResObj<CIFStatic>(GDR_FLORIAN0_LABEL, 1)->SetText(buffer);
}
```

The last thing to do is tie the handler to the button. Thats what the message map is for.

```cpp
GFX_BEGIN_MESSAGE_MAP(CIFflorian0, CIFMainFrame)
	ONG_COMMAND(GDR_FLORIAN0_BTN, &On_BtnClick)
GFX_END_MESSAGE_MAP()
```

Done. Now you have a cool button.

## 5. Background tasks

Your window can refresh it self on every redraw. Lets show that by implementing a simple clock.

This code takes the time and puts it into a string.

```cpp
time_t rawtime;
struct tm * timeinfo;
wchar_t buffer[80];

time (&rawtime);
timeinfo = localtime(&rawtime);

wcsftime(buffer,sizeof(buffer),L"%d-%m-%Y %H:%M:%S",timeinfo);
```

To make that code run in the background, just implement OnUpdate

```cpp
void OnUpdate() override;
```

```cpp
void CIFflorian0::OnUpdate()
{
	// Code for getting the time
	time_t rawtime;
	struct tm * timeinfo;
	wchar_t buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	wcsftime(buffer,sizeof(buffer),L"%d-%m-%Y %H:%M:%S",timeinfo);

	// Set label to the time string
	m_IRM.GetResObj<CIFStatic>(GDR_FLORIAN0_LABEL_TIME, 1)->SetText(buffer);
}
```

Thats all. 

!!! danger "Important note"
    Everything you do in here is executed syncronus once per frame. Everything you execute in here will lower your framerate and can cause lags. If you suffer from lags when your window is visible, check your code here.

