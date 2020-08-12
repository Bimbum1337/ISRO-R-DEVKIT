#include "BSLib.h"
#include <cassert>


/*const CGfxRuntimeClass CObj::classCObj= {
	"CObj",
	sizeof(CObj),
	-1,
	NULL,
	NULL,
	NULL,
	&CObj::CreateObject,
	&CObj::DeleteObject
};*/

const GlobalVar<CGfxRuntimeClass, 0x0110F8FC> CObj::classCObj;

CGfxRuntimeClass const *CObj::GetRuntimeClass() const {
    return classCObj;
}

CGfxRuntimeClass const *CObj::GetParentRuntimeClass() const {
    return classCObj->m_pBaseClass;
}

CObj *PASCAL

CObj::CreateObject() {
    return new CObj;
}

void __cdecl CObj::DeleteObject(CObj *pObj) {
    delete pObj;
}

CObj::~CObj() {

}

bool CObj::IsSame(const CGfxRuntimeClass &rtclass) const {
    return reinterpret_cast<bool (__thiscall *)(const CObj *, const CGfxRuntimeClass &)>(0x00b94b70)(this, rtclass);
}

bool CObj::IsKindOf(const CGfxRuntimeClass &rtclass) const {
    return reinterpret_cast<bool (__thiscall *)(const CObj *, const CGfxRuntimeClass &)>(0x00b94b90)(this, rtclass);
}

const GFX_MSGMAP CObjChild::messageMapCObjChild = {
        0,
        GetThisMessageEntries()
};

// CGfxRuntimeClass::IsDerivedFrom(CRuntimeClass *) .text 00B94B60 00000008 00000000 00000000 R . . . . . .
BOOL CGfxRuntimeClass::IsDerivedFrom(const CGfxRuntimeClass *pBaseClass) const {
    assert(FALSE);
    return FALSE;
}

const GFX_MSGMAP *CObjChild::GetMessageMap() const {
    return &messageMapCObjChild;
}

const GFX_MSGMAP_ENTRY *CObjChild::GetThisMessageEntries() {
    static const GFX_MSGMAP_ENTRY _messageEntries[] =
            {
                    {0, 0, 0, 0, 0, 0, (GFX_PMSG) 0, 0, 0, 0}
            };
    return &_messageEntries[0];
}

// CObjChild::Func_4(void) .text 0046FDA0 00000006 00000000 00000000 R . . . . . .
int CObjChild::Func_4(int a2) {
    return -1;
}

// CObjChild::OnTimer(void) .text 0046FD90 00000003 00000000 00000000 R . . . . . .
void CObjChild::OnTimer(int) {
    // empty
}

// CObjChild::OnNetMsg(void) .text 0046FD80 00000005 00000000 00000000 R . . . . . .
BOOL CObjChild::OnNetMsg(CMsgStreamBuffer *) {
    return FALSE;
}

CObjChild::CObjChild() {
    // empty
}

int CObjChild::StartTimer(int timerId, int timeoutMs) {
    return reinterpret_cast<int (__thiscall*)(CObjChild*, int, int)>(0x00b93320)(this, timerId, timeoutMs);
}


int CObjChild::KillTimer(int timerId) {
    return reinterpret_cast<int (__thiscall *)(CObjChild *, int)>(0x00B93170)(this, timerId);
}

# if 0
void* CObj::operator new(size_t num_bytes) {
	return CMemPoolManager_Allocate(num_bytes);
}

void CObj::operator delete(void* data) {
	CMemPoolManager_Free(data);
}
#endif
