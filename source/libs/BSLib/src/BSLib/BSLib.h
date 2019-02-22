#pragma once
#include <Windows.h>

#include <remodel/GlobalVar.h>
#include <ClientNet/MsgStreamBuffer.h>

class CWhatever;
struct CGfxRuntimeClass;
struct GFX_MSGMAP;
class CObj;
	class CObjChild;


#include "_internal/custom_stl.h"

#include "_internal/_BSDynamic.h"
#include "_internal/_BSMsg.h"


class CObj
{
public:
	static const GlobalVar<CGfxRuntimeClass, 0x0110F8FC> classCObj;

	virtual CGfxRuntimeClass const* GetRuntimeClass() const;
	virtual CGfxRuntimeClass const* GetParentRuntimeClass() const;

	static CObj* __stdcall CreateObject();
	static void __cdecl DeleteObject(CObj*);
	
public:
	virtual ~CObj();

	// void* operator new(size_t num_bytes);
};

// Funfact: Joymax stole this class from afx.h and renamed various macros. LOL.
struct CGfxRuntimeClass
{
	const char * m_lpszClassName;
	int m_nObjectSize;
	unsigned int m_wSchema; // schema number of the loaded class

	CGfxRuntimeClass const *m_pBaseClass;

	int field_10;
	int field_14;
	
	CObj*(__stdcall *m_pfnCreateObject)();
	void(__cdecl *m_pfnDeleteObject)(CObj*);

	
	BOOL IsDerivedFrom(const CGfxRuntimeClass* pBaseClass) const;

	void BuildThunk(const char* str, CObj*(__stdcall * create_object)(), void(__cdecl * delete_object)(CObj*), CGfxRuntimeClass* baseclass, size_t size, int x) const;

	// dynamic name lookup and creation
	// static CGfxRuntimeClass* __stdcall FromName(const char * lpszClassName);
	// static CGfxRuntimeClass* __stdcall FromName(const wchar_t * lpszClassName);
	// static CObj* __stdcall CreateObject(const char * lpszClassName);
	// static CObj* __stdcall CreateObject(const wchar_t * lpszClassName);
};

class CWhatever
{
	int x[5];
};


// Class: CObjChild
// Metadata:
// -  Number of Virtuals in total: 7
// -  
class CObjChild : public CObj
{
public:
	const virtual GFX_MSGMAP* GetMessageMap() const;
	static const struct GFX_MSGMAP_ENTRY* GetThisMessageEntries(); \
	static const GFX_MSGMAP messageMapCObjChild;

	virtual int Func_4(int a2);

	virtual void OnTimer(int); // This is Func_5
	
	virtual BOOL OnNetMsg(CMsgStreamBuffer*);

	CObjChild();

private:
	char pad_0004[16];
	std::n_list<CWhatever> m_list;
};


class CCmdTarget : public CObj
{
};

typedef void (CCmdTarget::*GFX_PMSG)(void);

struct GFX_MSGMAP_ENTRY
{
	UINT nMessage; // windows message
	UINT nCode; // control code or WM_NOTIFY code
	UINT nID; // control ID (or 0 for windows messages)
	UINT nLastID; // used for entries specifying a range of control id's
	UINT_PTR nSig; // signature type (action) or pointer to message #
	UINT nU0;
	GFX_PMSG pfn; // routine to call (or special value)
	UINT nU1;
	UINT nU2;
	UINT nU3;
};


struct GFX_MSGMAP
{
	const GFX_MSGMAP* lpBaseMsgMap;
	const GFX_MSGMAP_ENTRY* lpEntries;
};


#define GFX_DECLARE_MESSAGE_MAP(theClass) \
protected: \
	static const GFX_MSGMAP_ENTRY* GetThisMessageEntries(); \
	const GFX_MSGMAP* GetMessageMap() const override; \
	static const GFX_MSGMAP messageMap##theClass;

#define GFX_BEGIN_MESSAGE_MAP(theClass, baseClass) \
	const GFX_MSGMAP theClass::messageMap##theClass = { &baseClass::messageMap##baseClass, GetThisMessageEntries()};\
	const GFX_MSGMAP* theClass :: GetMessageMap() const \
		{ return &messageMap##theClass; } \
	const GFX_MSGMAP_ENTRY* theClass :: GetThisMessageEntries() \
	{ \
		typedef theClass ThisClass;						   \
		typedef baseClass TheBaseClass;					   \
		static const GFX_MSGMAP_ENTRY _messageEntries[] =  \
		{

#define GFX_END_MESSAGE_MAP() \
		{0, 0, 0, 0, 0, 0, (GFX_PMSG)0, 0, 0, 0 } \
	}; \
		return &_messageEntries[0]; \
	}

#define GFX_EMPTY_MESSAGE_MAP(theClass) \
	const BS_MSGMAP* theClass::GetMessageMap() const \
		{ return &messageMap##theClass; } \
	const BS_MSGMAP_ENTRY* theClass :: GetThisMessageEntries() \
	{ \
		typedef theClass ThisClass;						   \
		static const BS_MSGMAP_ENTRY _messageEntries[] =  \
		{ \
		{0/*cmd*/, 0/*code*/, 0/*ID*/, 0/*LastID*/, 0/*nSig*/, 0/*nU0*/, (BS_PMSG)0/*pfn*/, 0/*nU1*/, 0/*nU2*/, 0/*nU3*/ } \
	}; \
		return &_messageEntries[0]; \
	} \
	const BS_MSGMAP theClass::messageMap##theClass = {NULL , GetThisMessageEntries()};

