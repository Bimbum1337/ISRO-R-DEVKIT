#pragma once

#include <ghidra/undefined.h>
#include "IGIDObject.h"
#include "ClassLink.h"
#include "Test/Test.h"

enum TRIJOB_TYPE : char { /* Job Type of the Player */
    TRIJOB_HUNTER = 3,
    TRIJOB_NOJOB = 4,
    TRIJOB_THIEF = 1,
    TRIJOB_TRADER = 0
};

class CICharactor : public CIGIDObject {
    friend CClassLink<CICharactor>;
public:

    virtual void Func_34();

    virtual void Func_35();

    virtual void Func_36();

    virtual void Func_37();

    virtual void Func_38();

    virtual void Func_39();

    virtual void Func_40();

    virtual void Func_41();

    virtual void Func_42();

    virtual TRIJOB_TYPE GetJobType();

    virtual void SetJobType(TRIJOB_TYPE type);

    virtual void Func_45();

    virtual void Func_46();

    virtual void Func_47();

    virtual void Func_48();

    virtual void Func_49();

    virtual void Func_50();

    virtual void Func_51();

    virtual void Func_52();

    virtual void Func_53();

    virtual void Func_54();


    /// \brief Display the given text message above the entity for a certain amount of time.
    /// \address 009c77c0
    /// \param message The message to be displayed
    /// \param color Color of the letters being displayed
    void ShowMessageAboveEntity(const std::n_wstring &message, D3DCOLOR color);

private:
    undefined field_0x254[0x273 - 0x254];
    CClassLink<CICharactor> classLink;
    std::list<void *> decolist;
    undefined field_0x290[0x474 - 0x290];
    CGFontTexture m_textureMessageAbove;
    undefined field_0x4dc[0x50c - 0x4dc];
    undefined field_0x50c;
    TRIJOB_TYPE b_JobType;
    undefined field_0x510[0x78b - 0x50d];

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x78c)
        ENSURE_OFFSET(classLink, 0x274)
        ENSURE_OFFSET(decoList, 0x284)
        ENSURE_OFFSET(m_textureMessageAbove, 0x474)
        ENSURE_OFFSET(b_JobType, 0x50d)
    END_FIXTURE()
};
