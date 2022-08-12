#pragma once

#include <Windows.h>

#include <remodel/GlobalVar.h>
#include <ClientNet/MsgStreamBuffer.h>

// class CMsgStreamBuffer;


class CWhatever;

struct CGfxRuntimeClass;
struct GFX_MSGMAP;

class CObj;

class CObjChild;


#include "_internal/custom_stl.h"

#include "_internal/_BSDynamic.h"
#include "_internal/_BSMsg.h"

template<typename T, int N>
int size(T (&)[N]) { return N; }

/// Common base class for runtime-identifiable objects
class CObj {
public:
    static const GlobalVar<CGfxRuntimeClass, 0x0110F8FC> classCObj;

    virtual CGfxRuntimeClass const *GetRuntimeClass() const;

    virtual CGfxRuntimeClass const *GetParentRuntimeClass() const;

    /// Create a new object of this type. This needs to be created for every derived class.
    /// \returns Pointer to the created object
    static CObj *__stdcall CreateObject();

    /// Delete an existing object of this type. This needs to be created for every derived class.
    /// Usually just calls the (virtual) destructor.
    /// \param pObj Object to delete
    static void __cdecl DeleteObject(CObj *pObj);


    /// \address 00b94b70
    bool IsSame(const CGfxRuntimeClass &rtclass) const;

    /// \address 00b94b90
    bool IsKindOf(const CGfxRuntimeClass &rtclass) const;

public:
    virtual ~CObj();

#if 0
    void* operator new(size_t num_bytes);
#endif
};

/// Meta-data-structure for runtime-identifiable objects. Every CObj-derived 
/// class has a global instance of this structure containing all relevant meta 
/// data.
/// Funfact: Joymax stole this class from afx.h and renamed various macros. LOL.
struct CGfxRuntimeClass {
    /// Name of the class
    const char *m_lpszClassName;

    /// Absolutely no clue
    unsigned int m_wSchema; // schema number of the loaded class

    /// Size of the class in bytes
    int m_nObjectSize;

    /// Pointer to the meta-base class
    CGfxRuntimeClass const *m_pBaseClass;

    int field_10;
    int field_14;

    /// Function pointer to the \ref CObj::CreateObject equivalent function
    CObj *(__stdcall *m_pfnCreateObject)();

    /// Function pointer to the \ref CObj::DeleteObject equivalent function
    void (__cdecl *m_pfnDeleteObject)(CObj *);

    /// Evaluate if the current class is derived from the given class
    BOOL IsDerivedFrom(const CGfxRuntimeClass *pBaseClass) const;

    /// Initialize a new instance of this class.
    /// This was probably the constructor.
    void BuildThunk(const char *str, CObj *(__stdcall *create_object)(), void(__cdecl *delete_object)(CObj *),
                    CGfxRuntimeClass *baseclass, size_t size, int x) const;

    // dynamic name lookup and creation
    // static CGfxRuntimeClass* __stdcall FromName(const char * lpszClassName);
    // static CGfxRuntimeClass* __stdcall FromName(const wchar_t * lpszClassName);
    // static CObj* __stdcall CreateObject(const char * lpszClassName);
    // static CObj* __stdcall CreateObject(const wchar_t * lpszClassName);
};

class CWhatever {
    int x[5];
};

/// Some kind of intermediate base class. Contains message handling, networking
/// and timers ...
class CObjChild : public CObj {
public:
    const virtual GFX_MSGMAP *GetMessageMap() const;

    static const struct GFX_MSGMAP_ENTRY *GetThisMessageEntries();

    static const GFX_MSGMAP messageMapCObjChild;

    virtual int Func_4(int a2);

    /// Callback when a timer elapses
    /// \param timerId Numeric identifier of the timer
    virtual void OnTimer(int timerId);

    /// Callback when a network msg arrives
    /// \param pMsg Pointer to the received message. This is not essentially a
    ///             a server network message. Some MsgIds appear weird.
    ///             See \ref CPSQuickStart::OnNetMsg for example MsgIds.
    /// \returns true, if the message was handled, false, otherwise. A message 
    ///          must be completely read before returning. Call 
    ///          \ref CMsgStreamBuffer::FlushRemaining if there are any bytes 
    ///          left over.
    virtual BOOL OnNetMsg(CMsgStreamBuffer *pMsg);

    CObjChild();

    /// \brief Start a timer in the current object
    /// \address 00b93320
    /// \param timerId Id of the timer
    /// \param timeoutMs Timer interval in milliseconds
    /// \details Starts a timer with the given interval. The \ref CObjChild::OnTimer callback is asserted when the
    ///          timeout occurs.
    int StartTimer(int timerId, int timeoutMs);

protected:
    /// \brief Stop a timer in the current object
    /// \address 00B93170
    /// \param timerId Id of the timer
    int KillTimer(int timerId);

private:
    char pad_0004[16];
    std::n_list<CWhatever> m_list;
};


/// Dummy class that serves as castable target class for message handlers
class CCmdTarget : public CObj {
};

typedef void (CCmdTarget::*GFX_PMSG)(void);

/// Entry of a message map array. Each entry specifies one function.
struct GFX_MSGMAP_ENTRY {
    /// windows message
    UINT nMessage;
    /// control code or WM_NOTIFY code
    UINT nCode;
    /// control ID (or 0 for windows messages)
    UINT nID;
    /// used for entries specifying a range of control id's
    UINT nLastID;
    /// signature type (action) or pointer to message #
    UINT_PTR nSig;
    UINT nU0;
    /// routine to call (or special value)
    GFX_PMSG pfn;
    UINT nU1;
    UINT nU2;
    UINT nU3;
};


/// Message map of a class. Likely to be present when deriving from 
/// \ref CObjChild . Only present when the class implements custom message 
/// handlers. 
struct GFX_MSGMAP {
    /// Pointer to the base message map entry.
    const GFX_MSGMAP *lpBaseMsgMap;

    /// Pointer to the array of message map entires.
    const GFX_MSGMAP_ENTRY *lpEntries;
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
        typedef theClass ThisClass;                           \
        typedef baseClass TheBaseClass;                       \
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
        typedef theClass ThisClass;                           \
        static const BS_MSGMAP_ENTRY _messageEntries[] =  \
        { \
        {0/*cmd*/, 0/*code*/, 0/*ID*/, 0/*LastID*/, 0/*nSig*/, 0/*nU0*/, (BS_PMSG)0/*pfn*/, 0/*nU1*/, 0/*nU2*/, 0/*nU3*/ } \
    }; \
        return &_messageEntries[0]; \
    } \
    const BS_MSGMAP theClass::messageMap##theClass = {NULL , GetThisMessageEntries()};

