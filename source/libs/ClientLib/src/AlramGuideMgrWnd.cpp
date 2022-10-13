#include "AlramGuideMgrWnd.h"

#include "IFConfirmReputationGuide.h"
#include "IFEventGuide.h"
#include "IFQuestInfoGuide.h"
#include "IFLetterAlarmGuide.h"
#include "IFServerEventGuide.h"
#include "IFOpenMarketAlramGuide.h"
#include "IFEventGuideSecond.h"
#include "IFflorian0Guide.h"
#include "IFWebItemAlram.h"
#include "IFDailyLoginAlram.h"
#include "IFAttendanceEventGuid.h"
#include "IFFacebookLinkAlram.h"
#include "IFSurvivalPVPEstimateTimeAlram.h"
#include "IFSignLocationGuide.h"
#include "IFMacroSystemGuide.h"
#include "IFSignLocationGuide.h"
#include "IFMagicLampAlram.h"

#define GUIDE_EVENT 41
#define GUIDE_QUESTINFO 46
#define GUIDE_LETTERALARM 55
#define GUIDE_CONFIRMREPUTATION 165
#define GUIDE_SERVEREVENT  179
#define GUIDE_OPENMARKETALRAM  198
#define GUIDE_WebItemAlram 206
#define GUIDE_SignLocationGuide 250
#define GUIDE_MacroSystemGuide 261
#define GUIDE_MagicLampAlram 267
#define GUIDE_EVENTSECOND  30006
#define GUIDE_AttendanceEventGuide 169
#define GUIDE_SurvivalPVPEstimateTimeAlram 276
#define GUIDE_FacebookLinkAlram 278
#define GUIDE_DailyLoginAlram 280
#define GUIDE_TESTEXAMPLE 1337
GFX_IMPLEMENT_DYNAMIC_EXISTING(CAlramGuideMgrWnd, 0x1179BF8)

CAlramGuideMgrWnd::CAlramGuideMgrWnd() :
        m_numberOfIcons(0) {

}

CGWnd *CAlramGuideMgrWnd::GetGuide(int windowId) {

    // Try to find the element in the list
    for (std::list<CGWnd *>::iterator it = m_list.begin(); it != m_list.end(); ++it) {
        if ((*it)->UniqueID() == windowId) {
            return *it;
        }
    }

    // List did not contain the element, try to create it
    RECT rect = {0,0, 0x28,0x28};

    CGWnd* pObj = 0;

    switch(windowId) {
        case GUIDE_CONFIRMREPUTATION:
            pObj = CGWnd::CreateInstance(this, GFX_RUNTIME_CLASS(CIFConfirmReputationGuide), rect, GUIDE_CONFIRMREPUTATION, 0);
            break;

        case GUIDE_EVENT:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFEventGuide), rect, GUIDE_EVENT, 0);
            break;

        case GUIDE_QUESTINFO:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFQuestInfoGuide), rect, GUIDE_QUESTINFO, 0);
            break;

        case GUIDE_LETTERALARM:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFLetterAlarmGuide), rect, GUIDE_LETTERALARM, 0);
            break;

        case GUIDE_SERVEREVENT:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFServerEventGuide), rect, GUIDE_SERVEREVENT, 0);
            break;

        case GUIDE_OPENMARKETALRAM:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFOpenMarketAlramGuide), rect, GUIDE_OPENMARKETALRAM, 0);
            break;

        case GUIDE_EVENTSECOND:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFEventGuideSecond), rect, GUIDE_EVENTSECOND, 0);
            break;

        case GUIDE_WebItemAlram:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFWebItemAlram), rect, GUIDE_WebItemAlram, 0);
            break;

        case GUIDE_SignLocationGuide:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFSignLocationGuide), rect, GUIDE_SignLocationGuide, 0);
            break;

        case GUIDE_MacroSystemGuide:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFMacroSystemGuide), rect, GUIDE_MacroSystemGuide, 0);
            break;

        case GUIDE_MagicLampAlram:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFMagicLampAlram), rect, GUIDE_MagicLampAlram, 0);
            break;

        case GUIDE_AttendanceEventGuide:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFAttendanceEventGuide), rect, GUIDE_AttendanceEventGuide, 0);
            break;

        case GUIDE_SurvivalPVPEstimateTimeAlram:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFSurvivalPVPEstimateTimeAlram), rect, GUIDE_SurvivalPVPEstimateTimeAlram, 0);
            break;

        case GUIDE_FacebookLinkAlram:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFFacebookLinkAlram), rect, GUIDE_FacebookLinkAlram, 0);
            break;

        case GUIDE_DailyLoginAlram:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFDailyLoginAlram), rect, GUIDE_DailyLoginAlram, 0);
            break;

        case GUIDE_FLORIAN0:
            pObj = CreateInstance(this, GFX_RUNTIME_CLASS(CIFflorian0Guide), rect, GUIDE_FLORIAN0, 0);
            break;

        default:
            assert(false);
    }

    m_list.push_back(pObj);
    m_numberOfIcons++;

    UpdatePositions();

    return pObj;
}

void CAlramGuideMgrWnd::UpdatePositions() {
    reinterpret_cast<void(__thiscall*)(CAlramGuideMgrWnd*)>(0x00738DF0)(this);
}
