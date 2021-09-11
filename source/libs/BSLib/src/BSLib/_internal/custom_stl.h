#pragma once

#include <string>
#include <functional>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cassert>
#include <hash_map>

namespace std {
    /// STL-compatible allocator that uses Silkroad's memory manager
    template<typename T>
    class MyAllocator {
    public:
        typedef T value_type;

        typedef value_type _FARQ *pointer;
        typedef value_type _FARQ &reference;
        typedef const value_type _FARQ *const_pointer;
        typedef const value_type _FARQ &const_reference;

        typedef _SIZT size_type;
        typedef _PDFT difference_type;

        template<class _Other>
        struct rebind {    // convert an allocator<_Ty> to an allocator <_Other>
            typedef MyAllocator<_Other> other;
        };

        /// construct default allocator (do nothing)
        MyAllocator() _THROW0() {
        }

        /// construct by copying (do nothing)
        MyAllocator(const MyAllocator<T> &) _THROW0() {
        }

        /// construct from a related allocator (do nothing)
        template<class _Other>
        MyAllocator(const MyAllocator<_Other> &) _THROW0() {
        }

        /// assign from a related allocator (do nothing)
        template<class _Other>
        MyAllocator<T> &operator=(const MyAllocator<_Other> &) {
            return (*this);
        }

        /// Allocate given amount of bytes
        /// \param n Number of bytes to be allocated
        /// \returns pointer to allocated memory
        pointer allocate(size_type n) {
            return reinterpret_cast<T *(__cdecl *)(size_type n)>(0x00401ED0)(n * sizeof(T));
        }

        /// Free given amount of bytes
        /// \param p pointer to the memory to free
        /// \param n size of the memory to free
        void deallocate(pointer p, size_type n) {
            return reinterpret_cast<void (__cdecl *)(pointer, size_type) > (0x00402AE0)(p, n * sizeof(T));
        }

        /// construct object at _Ptr with value _Val
        void construct(pointer _Ptr, const T &_Val) {
            _Construct(_Ptr, _Val);
        }

        /// destroy object at _Ptr
        void destroy(pointer _Ptr) {
            _Destroy(_Ptr);
        }

        /// estimate maximum array size
        _SIZT max_size() const _THROW0() {
            _SIZT _Count = (_SIZT) (-1) / sizeof(T);
            return (0 < _Count ? _Count : 1);
        }

        bool operator==(MyAllocator<T>) {
            return true;
        }
    };

    typedef basic_string<wchar_t, char_traits<wchar_t>, MyAllocator<wchar_t> > n_wstring;
    typedef basic_string<char, char_traits<char>, MyAllocator<char> > n_string;

    /// std::map using custom allocator. Choose this one over std::map
    template<typename Key, typename T, typename Compare = less<Key> >
    class n_map : public map<Key, T, Compare, MyAllocator<std::pair<const Key, T> > > {

    };

    /// std::map using custom allocator. Choose this one over std::map
    template<typename T, typename Compare = less<T> >
    class n_set : public set<T, Compare, MyAllocator<T> > {
    };

    /// std::vector using custom allocator. Choose this one over std::vector
    template<typename T>
    class n_vector : public vector<T, MyAllocator<T> > {

    };

    /// std::list using custom allocator. Choose this one over std::list
    template<typename T>
    class n_list : public list<T, MyAllocator<T> > {

    };

    /// std::hash_map using custom allocator. Choose this one over std::hash_map
    template<typename _Kty, typename _Ty>
    class n_hash_map : public stdext::hash_map<_Kty, _Ty, stdext::hash_compare<_Kty, ::std::less<_Kty> >,
            MyAllocator< ::std::pair<const _Kty, _Ty> > > {
    };
}
