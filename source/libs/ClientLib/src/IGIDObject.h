#pragma once

#include "IObject.h"
#include "Data/CharacterData.h"

#include <GFX3DFunction/GFontTexture.h>

class CIGIDObject : public CIObject {
public:
    /// \address 004df110
    void Func_15(int param_1, float *param_2) override;

    virtual void Func_18();

    virtual void Func_19();

    virtual void Func_20();

    virtual void Func_21();

    virtual void Func_22();

    virtual void Func_23();

    virtual void Func_24();

    virtual void Func_25();

    virtual void Func_26();

    virtual void Func_27();

    virtual void Func_28();

    virtual void Func_29();

    virtual void Func_30();

    virtual void Func_31();

    virtual void Func_32();

    virtual void Func_33();

public:
    /// \brief Get the assigned name of this object
    const std::n_wstring &GetName() const;

    const CCharacterData::SData *GetSData() const;

    const int GetUniqueId() const;
private:
    char pad_00DC[28]; //0x00DC
protected:
    int m_uniqueId; // 0x00F8
private:
    char pad_00FC[20]; // 0x00FC
protected:
    std::n_wstring m_name; //0x0110
    CGFontTexture fonttexture_playername; //0x012C
    std::n_wstring m_titleText; //0x019C
    CGFontTexture fonttexture_title; //0x01B8
private:
    char pad_0228[8]; //0x0228
    CCharacterData::SData* m_characterData; //0x0230
    char pad_0234[0x124]; //0x0234

BEGIN_FIXTURE()
        ENSURE_SIZE(0x358)
        ENSURE_OFFSET(m_uniqueId, 0x00F8)
        ENSURE_OFFSET(m_name, 0x110)
        ENSURE_OFFSET(fonttexture_playername, 0x12c)
        ENSURE_OFFSET(fonttexture_title, 0x01B8)

    END_FIXTURE()

    RUN_FIXTURE(CIGIDObject)
};
