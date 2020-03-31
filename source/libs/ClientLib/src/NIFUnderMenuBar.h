#pragma once

#include "NIFWnd.h"
#include "NIFGauge.h"
#include "NIFStatic.h"

// https://www.elitepvpers.com/forum/sro-pserver-guides-releases/4256375-source-fix-old-exp-bar-writing-code.html
class NIFUnderMenuBar : public CNIFWnd {
public:
    char padx[8];

    CNIFGauge* gauge_skillexp; // 350
    CNIFStatic* lbl_percentage; // 354
    CNIFStatic* lbl_spcount; // 358
    CNIFStatic* lbl_exp_bar_scaler; // 35C
    CNIFStatic* lbl_360; // 360
    CNIFStatic* lbl_percent_bar; // 364
    CNIFStatic* lbl_level; // 368
    CNIFGauge* gauges[10]; // 36C

char pad_cnifundermenubar[352-36-(10*4)];


void Update();
};