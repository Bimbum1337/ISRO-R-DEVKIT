#pragma once

#include "IFStatic.h"

class CIFEdit : public CIFStatic {
GFX_DECLARE_DYNAMIC_EXISTING(CIFEdit, 0x00ee9540)

public:
    /// \address 00634EA0
    bool HasFocus() const;

    /// \address 00635150
    void AddValue_404(undefined4 value);

    /// \address 00635070
    void SetValue_404(undefined4 value);

    /// \address 00635060
    undefined4 GetValue_404() const;

    /// \address 00635170
    bool IsSetValue_404(undefined4 value) const;

    /// \address 00634f80
    void FUN_00634f80(unsigned int a1);

    /// \address 006351b0
    void SetTextmode(undefined4 mode);

    const std::n_wstring &GetCurrentText() const;

private:
    char pad_0x0380[0xB100]; //0x0380 ????
};
