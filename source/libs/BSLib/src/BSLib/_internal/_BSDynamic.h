#pragma once

#define _GFX_RUNTIME_CLASS(class_name) (class_name::class##class_name)
#define GFX_RUNTIME_CLASS(class_name) _GFX_RUNTIME_CLASS(class_name)

#define GFX_DECLARE_DYNCREATE_FN(class_name) \
    static CObj* PASCAL CreateObject(); \
    static void __cdecl DeleteObject(CObj*);

#define GFX_DECLARE_DYNCREATE(class_name) \
    GFX_DECLARE_DYNAMIC(class_name) \
    GFX_DECLARE_DYNCREATE_FN(class_name)

#define GFX_DECLARE_DYNAMIC(class_name) \
public: \
    static const CGfxRuntimeClass class##class_name; \
    virtual CGfxRuntimeClass const* GetRuntimeClass() const; \
    virtual CGfxRuntimeClass const* GetParentRuntimeClass() const;


#define GFX_IMPLEMENT_DYNAMIC(class_name, base_class_name) \
    GFX_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL, NULL)

#define GFX_IMPLEMENT_DYNCREATE_FN(class_name, base_class_name) \
        CObj* PASCAL class_name::CreateObject() \
        { return new class_name; } \
        void __cdecl class_name::DeleteObject(CObj* pObj) \
        { delete pObj; }

#define GFX_IMPLEMENT_DYNCREATE(class_name, base_class_name) \
        GFX_IMPLEMENT_DYNCREATE_FN(class_name, base_class_name) \
        GFX_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, \
        class_name::CreateObject, class_name::DeleteObject)

#define GFX_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, pfnDelete) \
    const CGfxRuntimeClass class_name::class##class_name = { \
    #class_name, sizeof(class class_name), wSchema, \
    base_class_name::class##base_class_name, NULL, NULL, \
    pfnNew, pfnDelete}; \
    CGfxRuntimeClass const* class_name::GetRuntimeClass() const \
    { return &GFX_RUNTIME_CLASS(class_name); } \
    CGfxRuntimeClass const* class_name::GetParentRuntimeClass() const \
    { return GFX_RUNTIME_CLASS(class_name).m_pBaseClass; }


/////////////////////////////////////////////////////
// Existing

#define GFX_DECLARE_DYNAMIC_EXISTING(class_name, offset) \
public: \
    static const GlobalVar<CGfxRuntimeClass, offset> class##class_name; \
    virtual CGfxRuntimeClass const* GetRuntimeClass() const; \
    virtual CGfxRuntimeClass const* GetParentRuntimeClass() const; // east const ftw


#define GFX_IMPLEMENT_DYNAMIC_EXISTING(class_name, offset) \
    GFX_IMPLEMENT_RUNTIMECLASS_EXISTING(class_name, offset)

#define GFX_IMPLEMENT_RUNTIMECLASS_EXISTING(class_name, offset) \
    const GlobalVar<CGfxRuntimeClass, offset> class_name::class##class_name; \
    CGfxRuntimeClass const* class_name::GetRuntimeClass() const \
    { return GFX_RUNTIME_CLASS(class_name); } \
    CGfxRuntimeClass const* class_name::GetParentRuntimeClass() const \
    { return GFX_RUNTIME_CLASS(class_name)->m_pBaseClass; }
