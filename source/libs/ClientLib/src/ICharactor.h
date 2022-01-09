#pragma once

#include <ghidra/undefined.h>
#include "IGIDObject.h"
#include "ClassLink.h"
#include "Test/Test.h"
#include "Data/CharacterData.h"

enum TRIJOB_TYPE : char { /* Job Type of the Player */
    TRIJOB_HUNTER = 3,
    TRIJOB_NOJOB = 4,
    TRIJOB_THIEF = 2,
    TRIJOB_TRADER = 1
};

class CICharactor : public CIGIDObject {
    friend CClassLink<CICharactor>;
public:

    virtual void Func_34();

    virtual void Func_35();

    virtual const CCharacterData::SData &Func_36(); // TODO:: could lead to crashes further on

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

    unsigned int GetMaxHp() const;

    unsigned int GetCurrentMp() const;

    unsigned int GetMaxMp() const;

    /// \address 009c7880
    unsigned int FUN_009c7880() const;

private:
    char pad_0254[32]; //0x0254
    class CClassLink<CICharactor> classLink; //0x0274
    class std::list<void*> decolist; //0x0284
    char pad_0290[452]; //0x0290
    unsigned int m_mpCurrent; //0x0454
    unsigned int m_hpMax; //0x0458
    unsigned int m_mpMax; //0x045C
    unsigned int m_hpCurrent; //0x0460
    char pad_0464[4]; //0x0464
    unsigned int N00000A38; //0x0468
    char pad_046C[16]; //0x046C
    class CGFontTexture m_textureMessageAbove; //0x047C
    char pad_04E4[41]; //0x04E4
    TRIJOB_TYPE b_JobType; //0x050D
    char pad_050E[638]; //0x050E

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x78c)
        ENSURE_OFFSET(classLink, 0x274)
        ENSURE_OFFSET(decoList, 0x284)
        ENSURE_OFFSET(m_mpCurrent, 0x0454)
        ENSURE_OFFSET(m_hpMax, 0x0458)
        ENSURE_OFFSET(m_mpMax, 0x045C)
        ENSURE_OFFSET(m_hpCurrent, 0x0460)
        ENSURE_OFFSET(m_textureMessageAbove, 0x474)
        ENSURE_OFFSET(b_JobType, 0x50d)
    END_FIXTURE()
};
