#pragma once

#include "IFWnd.h"
/// \brief Container, automatically stretching to screen width (or parent width, unsure)
/// \details Container resizes and draws borders accordingly. Allows specifing textures
///          for top, left, bottom and right edges, as well as corners.
class CIFStretchWnd : public CIFWnd {
public: /* interface functions */

    /// \brief Set the textures for all four edges
    /// \remarks The interface was improved. The original code was passing
    ///          all the strings by value, which was completely unnecessary.
    /// \address 00819690
    void SetEdgeTextures(const std::n_string &left,
                         const std::n_string &top,
                         const std::n_string &right,
                         const std::n_string &bottom);

    /// \brief Set the textures for all four corners
    /// \address 008199e0
    void SetCornerTextures(const std::n_string &cornerTexturePath);

private: /* members */
    char pad_0x036C[0x34]; //0x036C
    char *N000062E6; //0x03A0
    char pad_0x03A4[0x18]; //0x03A4
    char *N000062F0; //0x03BC
    char pad_0x03C0[0x18]; //0x03C0
    char *N000062F7; //0x03D8
    char pad_0x03DC[0x18]; //0x03DC
    char *N000062FE; //0x03F4
    char pad_0x03F8[0x18]; //0x03F8
    char *N00006305; //0x0410
    char pad_0x0414[0x18]; //0x0414
    char *N0000630C; //0x042C
    char pad_0x0430[0x18]; //0x0430
    char *N00006313; //0x0448
    char pad_0x044C[0x18]; //0x044C
    char *N0000631A; //0x0464
    char pad_0x0468[0x35C]; //0x0468

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x07C4)
    END_FIXTURE()

    RUN_FIXTURE(CIFStretchWnd)
};
