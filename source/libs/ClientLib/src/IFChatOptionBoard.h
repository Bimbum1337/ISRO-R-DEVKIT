#pragma once

#include "IFWnd.h"
#include "IFCheckBox.h"

class CIFChatOptionBoard : public CIFWnd {

    GFX_DECLARE_DYNAMIC_EXISTING(CIFChatOptionBoard, 0x00eec128)

    GFX_DECLARE_DYNCREATE_FN(CIFChatOptionBoard)

    GFX_DECLARE_MESSAGE_MAP(CIFChatOptionBoard)

public:
    /// \copybrief CGWndBase::OnCreate
    /// \copydetails CGWndBase::OnCreate
    /// \address 007a95f0
    bool OnCreate(long ln) override;

    /// \copybrief CGWndBase::On3DEvent_MAYBE
    /// \copydetails CGWndBase::On3DEvent_MAYBE
    /// \address 007a9450
    bool On3DEvent_MAYBE(Event3D *) override;

public:
    /// \brief Tell, if the gain (acquisition) option is checked
    /// \details If the option is checked, the game will print EXP/SP related information
    ///          to the system message log.
    /// \address 007a9400
    bool IsGainChecked() const;

    /// \brief Tell, if the fight (combat) option is checked
    /// \details If the option is checked, the game will print combat related information
    ///          to the system message log.
    /// \address 007a9410
    bool IsFightChecked() const;

    /// \brief Tell, if the status option is checked
    /// \details If the option is checked, the game will print status related information
    ///          to the system message log.
    /// \address 007a9420
    bool IsStatusChecked() const;

    /// \brief Tell, if the party option is checked
    /// \details If the option is checked, the game will print party related information
    ///          to the system message log.
    /// \address 007a9430
    bool IsPartyChecked() const;

    /// \brief Tell, if the game option is checked
    /// \details If the option is checked, the game will print game related information
    ///          to the system message log.
    /// \address 007a9440
    bool IsGameChecked() const;

private:
    /// \brief Callback for click-events on the checkboxes.
    /// \details Called when a checkbox on the form is checked or unchecked. Stores the checkbox states into
    ///          a file.
    /// \address 007a9510
    void OnOptionChanged();

private:
    CIFCheckBox *m_pGDR_COB_CB_GAIN; // 0x036c
    CIFCheckBox *m_pGDR_COB_CB_FIGHT; // 0x0370
    CIFCheckBox *m_pGDR_COB_CB_STATUS; // 0x0374
    CIFCheckBox *m_pGDR_COB_CB_PARTY; // 0x0378
    CIFCheckBox *m_pGDR_COB_CB_GAME; // 0x037c

private:
    BEGIN_FIXTURE()
        ENSURE_SIZE(0x380)
        ENSURE_OFFSET(m_pGDR_COB_CB_GAIN, 0x036c)
        ENSURE_OFFSET(m_pGDR_COB_CB_FIGHT, 0x0370)
        ENSURE_OFFSET(m_pGDR_COB_CB_STATUS, 0x0374)
        ENSURE_OFFSET(m_pGDR_COB_CB_PARTY, 0x0378)
        ENSURE_OFFSET(m_pGDR_COB_CB_GAME, 0x037c)
    END_FIXTURE()

    RUN_FIXTURE(CIFChatOptionBoard)
};
