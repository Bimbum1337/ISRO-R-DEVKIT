#pragma once

#include <cxxtest/TestSuite.h>

#include "TypeId.h"

class TestTypeId : public CxxTest::TestSuite {
public:
    void testTID1Min() {
        // TID1 Range: 0x1c
        // 0001 1100
        // 0x4 == 1
        // 0x5 == 2
        // ...
        // 0x1c == 7
        TypeId tid(0x4);
        TS_ASSERT(tid.Is(TID<1, 0, 0, 0>()));
        TS_ASSERT_EQUALS(tid.Is(TID<2, 0, 0, 0>()), false);
    }

    void testTID1Max() {
        TypeId tid(0x1c);
        TS_ASSERT(tid.Is(TID<7, 0, 0, 0>()));
        TS_ASSERT_EQUALS(tid.Is(TID<6, 0, 0, 0>()), false);
    }

    void testTID2Min() {
        // TID 2 Range: 0x60
        // 0110 0000
        // 0x20 == 1
        // ...
        // 0x60 == 5

        TypeId tid(0x20);
        TS_ASSERT(tid.Is(TID<0, 1, 0, 0>()));
        TS_ASSERT_EQUALS(tid.Is(TID<0, 2, 0, 0>()), false);
    }

    void testTID2Max() {
        TypeId tid(0x60);
        TS_ASSERT(tid.Is(TID<0, 3, 0, 0>()));
        TS_ASSERT_EQUALS(tid.Is(TID<0, 2, 0, 0>()), false);
    }

    void testTID3Min() {
        // TID 3 Range: 0x780
        // 0111 1000 0000
        // 0x80 == 1
        // ...
        // 0x780 = 15
        TypeId tid(0x80);
        TS_ASSERT(tid.Is(TID<0, 0, 1, 0>()));
        TS_ASSERT_EQUALS(tid.Is(TID<0, 0, 2, 0>()), false);
    }

    void testTID3Max() {
        TypeId tid(0x780);
        TS_ASSERT(tid.Is(TID<0, 0, 15, 0>()));
        TS_ASSERT_EQUALS(tid.Is(TID<0, 0, 14, 0>()), false);
    }

    void testTID4Min() {
        // TID 4 Range: 0xf800
        // 1111 1000 0000 0000
        // 0x800 == 1
        // ...
        // 0xf800 == 31
        TypeId tid(0x800);
        TS_ASSERT(tid.Is(TID<0, 0, 0, 1>()));
        TS_ASSERT_EQUALS(tid.Is(TID<0, 0, 0, 2>()), false);
    }

    void testTID4Max() {
        TypeId tid(0xf800);
        TS_ASSERT(tid.Is(TID<0, 0, 0, 31>()));
        TS_ASSERT_EQUALS(tid.Is(TID<0, 0, 0, 30>()), false);
    }

    void testRealTypeIds() {
        TypeId tid(0x29EC);
        TS_ASSERT(tid.Is(TypeIdRegistry::ITEM_ETC_SCROLL_GLOBALCHATTING));
    }
};
