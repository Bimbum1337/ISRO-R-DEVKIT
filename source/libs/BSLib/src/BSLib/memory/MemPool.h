#pragma once

#define _TO_NUMBER(x) (x + '0')
#define _AT_BYTE(num, x) (static_cast<unsigned long long>(x) << ((64-8) - (num * 8)))

#define _X_TAG_FIN(val100, val10, val1) \
    _AT_BYTE(3, _TO_NUMBER(val100)) + \
    _AT_BYTE(4, _TO_NUMBER(val10)) + \
    _AT_BYTE(5, _TO_NUMBER(val1))

#define _X_TAG_1(val, val100, val10) \
    _X_TAG_FIN(val100, val10, (val - (val100 * 100) - (val10 * 10)))

#define _X_TAG_10(val, val100) \
    _X_TAG_1(val, val100, (val - val100 * 100) / 10)

#define _X_TAG_100(val) \
    _X_TAG_10(val, (val / 100))

#define _TAG(type, val) \
    _AT_BYTE(2, type) + _X_TAG_100(val)


template<unsigned long long Tag, typename Type, int U1, int U2>
class CMemPool {
public:
    Type *alloc() {
        return reinterpret_cast<Type*(__thiscall*)(CMemPool*)>(0x00425400)(this);
    }
};
