#pragma once

#include "IObject.h"

#include <GFX3DFunction/GFontTexture.h>

class CIGIDObject : public CIObject {
public:
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

private:
    char pad_00DC[52]; //0x00DC
    std::n_wstring m_name; //0x0110
    CGFontTexture fonttexture_playername; //0x012C
    char pad_0194[28]; //0x0194
    CGFontTexture fonttexture_title; //0x01B0
    char pad_0218[60]; //0x0218

BEGIN_FIXTURE()
        ENSURE_SIZE(0x254)

        ENSURE_OFFSET(m_name, 0x110)
        ENSURE_OFFSET(fonttexture_playername, 0x12c)
        ENSURE_OFFSET(fonttexture_title, 0x1b0)

    END_FIXTURE()

    RUN_FIXTURE(CIGIDObject)
};
