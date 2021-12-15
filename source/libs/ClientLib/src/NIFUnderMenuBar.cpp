// Credits: @florian0 https://www.elitepvpers.com/forum/sro-pserver-guides-releases/4256375-source-fix-old-exp-bar-writing-code.html

#include "NIFUnderMenuBar.h"

#include "ICPlayer.h"

#include <stdio.h>
#include "GlobalDataManager.h"
#include "Data\LevelData.h"

#include <cmath>

void NIFUnderMenuBar::Update() {
    // Skip, if player object is not loaded yet (KEEP!)
    if (!g_pCICPlayer) {
        return;
    }

    // Some other call that is important (KEEP!)
    ((void (__thiscall *)(NIFUnderMenuBar *)) 0x46CD80)(this);

    // Check if control is visible
    if (!((char (__thiscall *)(NIFUnderMenuBar *)) 0x00B8F530)(this)) {
        return;
    }

    // Retrieve LevelData for current Level
    // (this is one line of Media\server_dep\silkroad\textdata\leveldata.txt)
    CLevelData *data = g_CGlobalDataManager->m_levelDataMap[g_pCICPlayer->m_level];

    // Don't continue if level-data is invalid
    if (data == NULL) {
        return;
    }

    // Calculate EXP as percentage value
    double exp_percentage = g_pCICPlayer->m_exp_current * 100.0 / data->data.m_expC;

    // Limit maximum percentage to 99.99%
    if (exp_percentage > 99.99) {
        exp_percentage = 99.99;
    }

    // Calculate the number of bars that are full
    int barnum = static_cast<int>(floor(exp_percentage / 10.0));


    for (int i = 0; i < 10; i++) {

        // Fill or empty bars
        if (barnum <= i) {
            gauges[i]->background_value = 0.0;
            gauges[i]->foreground_value = 0.0;
        } else {
            gauges[i]->background_value = 1.0;
            gauges[i]->foreground_value = 1.0;
        }
    }

    // Fill the bar that is neither full or empty with the remaining percentage
    float exp_remain = static_cast<float>((exp_percentage - (barnum * 10.0)) / 10.0);

    gauges[barnum]->background_value = exp_remain;
    gauges[barnum]->foreground_value = exp_remain;

    // Assign more texts
    this->lbl_level->SetText(L"Level: %d", g_pCICPlayer->m_exp_current);
    this->lbl_percentage->SetText(L"%.2lf %%", exp_percentage);

    // Skillpoints
    this->lbl_spcount->SetText(L"%d", g_pCICPlayer->m_skillpoint);
    this->gauge_skillexp->background_value = g_pCICPlayer->m_skillpoint_progress / 400.0f;
    this->gauge_skillexp->foreground_value = g_pCICPlayer->m_skillpoint_progress / 400.0f;

    // You can also draw text directly at the gauge. It will be centered automatically
    // this->gauge_skillexp->SetText(L"%d", g_CICPlayer->skill_exp);


    this->lbl_exp_bar_scaler->SetText(L""); // Prescaler is disabled

    // This label is right in the middle of the EXP-Bar
    //this->lbl_360->SetText(L"lbl_360");
};
