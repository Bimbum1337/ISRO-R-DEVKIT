#pragma once

#include <ghidra/undefined.h>
#include "IGIDObject.h"
#include "ClassLink.h"
#include "Test/Test.h"

enum TRIJOB_TYPE { /* Job Type of the Player */
    TRIJOB_HUNTER=3,
    TRIJOB_NOJOB=4,
    TRIJOB_THIEF=1,
    TRIJOB_TRADER=0
};

class CICharactor : public CIGIDObject {
    friend CClassLink<CICharactor>;
public:

    /// \brief Display the given text message above the entity for a certain amount of time.
    /// \address 009c77c0
    /// \param message The message to be displayed
    /// \param color Color of the letters being displayed
    void ShowMessageAboveEntity(const std::n_wstring &message, D3DCOLOR color);

private:
    undefined field_0x254[0x273-0x254];
    CClassLink<CICharactor> classLink;
    std::list<void*> decolist;
    undefined field_0x290[0x474-0x290];
    CGFontTexture m_textureMessageAbove;
    undefined field_0x4dc[0x50c-0x4dc];
    undefined field_0x50c;
    TRIJOB_TYPE b_JobType;
    undefined field_0x50e;
    undefined field_0x50f;
    undefined field_0x510[0x78b-0x510];

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x78c)
        ENSURE_OFFSET(classLink, 0x274)
        ENSURE_OFFSET(decoList, 0x284)
        ENSURE_OFFSET(m_textureMessageAbove, 0x474)
        ENSURE_OFFSET(b_JobType, 0x50d)
    END_FIXTURE()
};
