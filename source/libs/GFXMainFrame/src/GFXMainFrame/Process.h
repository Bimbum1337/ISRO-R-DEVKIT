#pragma once

#include "GWnd.h"
#include <remodel/GlobalVar.h>

class CProcess : public CGWnd { // total size 176

	GFX_DECLARE_DYNAMIC_EXISTING(CProcess, 0x0110FA70);

	
	virtual void Func_38();
	virtual int Func_39();

    static CProcess *MakeProcess(const CGfxRuntimeClass& cls);

public:
	int N000006AB; //0x0084
	char pad_0088[20-4]; //0x0088
	int m_blProcessRunTerminate; //0x0098
	int m_blRun; //0x009C
private:
    CProcess* m_pProcessChild; //0x00A0, was not public
	char pad_00A4[12]; //0x00A4

public:
	bool On3DEvent_MAYBE(Event3D* a2) override;

public:
	CProcess* GetChildProcess();

	static GlobalVar<bool, 0x00EED310> m_bProcessNetMsg;
	
	CProcess* sub_BA7B90(const CGfxRuntimeClass &cls, int bSomething);

	void sub_BA7620(CProcess* pProcess);
	
	void SetProcessNetMsg(bool state);
};
