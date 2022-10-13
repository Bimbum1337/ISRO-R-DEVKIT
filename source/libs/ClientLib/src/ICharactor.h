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
    /// \address 009cf1b0
    void Func_15(int param_1, float *param_2) override;
    void Func_15_impl(int param_1, float *param_2);

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
    char pad_0358[32]; //0x0358
    class CClassLink<CICharactor> classLink; //0x0378
    class std::list<void*> decolist; //0x0388
    char pad_0394[452]; //0x0394
    unsigned int m_mpCurrent; //0x0558
    unsigned int m_hpMax; //0x055C
    unsigned int m_mpMax; //0x0560
    unsigned int m_hpCurrent; //0x0564
    char pad_0568[4]; //0x0568
    unsigned int N00000A38; //0x056C
    char pad_0570[16]; //0x0570
    class CGFontTexture m_textureMessageAbove; //0x0580
    char pad_05F0[12]; //0x05F0
protected:
    float m_renderY; //0x05FC
    float m_renderX; //0x0600
    float m_renderDepth; //0x0604
private:
    char pad_0608[17]; //0x0608
    TRIJOB_TYPE b_JobType; //0x0619
    char pad_061A[0x2A2]; //0x061A

    BEGIN_FIXTURE()
        ENSURE_SIZE(0x8BC)
        ENSURE_OFFSET(classLink, 0x378)
        ENSURE_OFFSET(decolist, 0x388)
        ENSURE_OFFSET(m_mpCurrent, 0x0558)
        ENSURE_OFFSET(m_hpMax, 0x055C)
        ENSURE_OFFSET(m_mpMax, 0x0560)
        ENSURE_OFFSET(m_hpCurrent, 0x0564)
        ENSURE_OFFSET(m_textureMessageAbove, 0x0580)
        ENSURE_OFFSET(m_renderY, 0x05FC)
        ENSURE_OFFSET(m_renderX, 0x0600)
        ENSURE_OFFSET(m_renderDepth, 0x0604)
        ENSURE_OFFSET(b_JobType, 0x619)
    END_FIXTURE()

    RUN_FIXTURE(CICharactor)
};
