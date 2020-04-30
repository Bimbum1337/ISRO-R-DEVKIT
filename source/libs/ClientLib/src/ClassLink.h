#pragma once

// Hello Linux kernel
// https://github.com/torvalds/linux/blob/master/include/linux/list.h#L600

// This code is probably a product of:
// DEV: 여전히 충돌하고 있습니다. 어떻게해야합니까?
// BOSS: 문제를 해결하거나 해고하십시오!

#include <remodel/GlobalVar.h>

#define CLASSLINK_LOOP_BEGIN(cls) \
    for (CClassLink<cls>::s->cursor = CClassLink<cls>::s->begin; CClassLink<cls>::s->cursor != 0; /* no auto increment */) { \
        cls *obj = CClassLink<cls>::s->cursor->container();


#define CLASSLINK_LOOP_END(cls)                                                     \
        if (CClassLink<cls>::s->cursorInvalidated) {                                \
            CClassLink<cls>::s->cursorInvalidated = false;                          \
        } else {                                                                    \
            CClassLink<cls>::s->cursor = CClassLink<cls>::s->cursor->next;          \
        }                                                                           \
    }

#define CLASSLINK_STATIC_IMPL2(cls) \
    template<> bool CClassLink<CICharactor>::doLink; \
    template<> int CClassLink<cls>::count; \
    template<> CClassLink<cls> *CClassLink<cls>::begin; \
    template<> CClassLink<cls> *CClassLink<cls>::end; \
    template<> CClassLink<cls> *CClassLink<cls>::cursor; \
    template<> bool CClassLink<cls>::cursorInvalidated;

#define CLASSLINK_STATIC_IMPL(cls)                                                  \
    template<> GlobalVar<CClassLink<cls>::Statics, 0x00ec4ce4> CClassLink<cls>::s;

template<typename T>
class CClassLink {
    // TODO: Once all ClassLink references are resolved, we need to remove
    //       that structure and use the members directly
    struct Statics {
        bool doLink;
        int count;
        CClassLink<T> *begin;
        CClassLink<T> *end;
        CClassLink<T> *cursor;
        int cursorInvalidated;
    };

public:
    CClassLink()
            : isLinked(false), prev(0), next(0) {
        if (!s.doLink)
            return;

        isLinked = true;

        // Are we first?
        if (s.begin == nullptr) {
            s.begin = this;
            s.end = this;
        } else {
            s.end->next = this;
            this->prev = s.end;
            this->next = nullptr;
            s.end = this;
        }
        s.count++;
    }

    virtual ~CClassLink() {
        if (!isLinked)
            return;

        isLinked = false;
        if (s->cursor == this) {
            s->cursor = this->next;
            s->cursorInvalidated = true;
        }

        s->count--;

        // Replace list begin if we are first entry
        if (prev == 0) {
            s->begin = this->next;
        } else {
            prev->next = next;
        }

        // If we have a next, update that one
        if (next != 0) {
            next->prev = prev;
        } else {
            s->end = prev;
        }

        // We are gone now
        next = 0;
        prev = 0;
    }

    // get the container of this list head
    T *container() {
        return reinterpret_cast<T *>(reinterpret_cast<char*>(this) - offsetof(T, classLink));
    }

public: /* statics */
    static GlobalVar<Statics, 0x00ec4ce4> s;

public: /* members */
    bool isLinked;
    CClassLink<T> *prev;
    CClassLink<T> *next;
};
