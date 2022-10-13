#pragma once
#include <IFMainFrame.h>
#include <IFNormalTile.h>
#include <IFButton.h>
#include <IFEdit.h>
#include <IFStatic.h>

class CIFTestExample : public CIFMainFrame
{
    GFX_DECLARE_DYNCREATE(CIFTestExample)
    GFX_DECLARE_MESSAGE_MAP(CIFTestExample)
public:
    CIFTestExample(void);
    ~CIFTestExample(void);

    bool OnCreate(long ln) override;
    void OnUpdate() override;
private:
    CIFNormalTile* m_tile;
    CIFButton* m_btn1;
    CIFStatic* m_static0;
private:
    void On_m_btn1();

};
