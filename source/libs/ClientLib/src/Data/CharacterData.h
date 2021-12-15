#pragma once

#include <BSLib/BSLib.h>
#include <ghidra/undefined.h>

class CCharacterData {
public:
    struct SData {
        undefined4 m_objectId;
        undefined field_0x4;
        undefined field_0x5;
        undefined field_0x6;
        undefined field_0x7;
        std::n_wstring m_codename;
        std::n_wstring field_0x24;
        std::n_wstring field_0x40;
        undefined field_0x5c;
        undefined field_0x5d;
        undefined field_0x5e;
        undefined field_0x5f;
        std::n_wstring field_0x60;
        std::n_wstring field_0x7c;
        undefined field_0x98;
        undefined field_0x99;
        undefined field_0x9a;
        undefined field_0x9b;
        undefined1 m_nationality;
        char pad_00A0[135];
        std::n_string resfile;
        std::n_string N0000138C;
        char pad_0164[28];
        std::n_string N00001394;
        std::n_string N0000139C;
        char pad_01B8[24];
        int m_health;

    private:
        BEGIN_FIXTURE()
            ENSURE_OFFSET(m_objectId, 0x0000)
            ENSURE_OFFSET(m_codename, 0x0008)
            ENSURE_OFFSET(m_health, 0x01C8)
        END_FIXTURE()

        RUN_FIXTURE(SData)
    };
public:
    virtual ~CCharacterData();

private:
    char pad_0004[4];
    SData data;

};
