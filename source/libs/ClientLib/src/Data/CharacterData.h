#pragma once

#include <BSLib/BSLib.h>

class CCharacterData {
public:
    virtual ~CCharacterData();

    const std::n_wstring &Codename() const;

    int Health() const;

private:
    char pad_0004[12]; //0x0004
    std::n_wstring m_codename; //0x0010
    std::n_wstring N00001353; //0x002C
    std::n_wstring N00001354; //0x0048
    char pad_0064[4]; //0x0064
    std::n_wstring translationSlug; //0x0068
    std::n_wstring N00001357; //0x0084
    char pad_00A0[140]; //0x00A0
    std::n_string resfile; //0x012C
    std::n_string N0000138C; //0x0148
    char pad_0164[28]; //0x0164
    std::n_string N00001394; //0x0180
    std::n_string N0000139C; //0x019C
    char pad_01B8[24]; //0x01B8
    int m_health; //0x01D0

private:
    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_codename, 0x0010)
        ENSURE_OFFSET(m_health, 0x01D0)
    END_FIXTURE()

    RUN_FIXTURE(CCharacterData)
};
