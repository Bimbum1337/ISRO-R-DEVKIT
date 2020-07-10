#include "IFflorian0.h"
#include <ctime>

#define GDR_FLORIAN0_LABEL 10
#define GDR_FLORIAN0_BTN 11
#define GDR_FLORIAN0_LABEL_TIME 13

GFX_IMPLEMENT_DYNCREATE(CIFflorian0, CIFMainFrame)

GFX_BEGIN_MESSAGE_MAP(CIFflorian0, CIFMainFrame)
	ONG_COMMAND(GDR_FLORIAN0_BTN, &On_BtnClick)
	ONG_WM_4001()
	ONG_WM_4002()
	ONG_WM_4003()
	ONG_VISIBLE_CHANGE()
	ONG_WM_4005()
	ONG_WM_4006()
GFX_END_MESSAGE_MAP()


CIFflorian0::CIFflorian0(void)
{
	printf("> " __FUNCTION__ "\n");
}


CIFflorian0::~CIFflorian0(void)
{
	printf("> " __FUNCTION__ "\n");
}

bool CIFflorian0::OnCreate(long ln)
{
	printf("> " __FUNCTION__ "(%d)\n", ln);

	// Populate inherited members
	CIFMainFrame::OnCreate(ln);

	m_IRM.LoadFromFile("resinfo\\ifflorian0.txt");
	m_IRM.CreateInterfaceSection("Create", this);

	m_mybutton = m_IRM.GetResObj<CIFButton>(GDR_FLORIAN0_BTN, 1);
	m_time_label = m_IRM.GetResObj<CIFStatic>(GDR_FLORIAN0_LABEL_TIME, 1);
	m_custom_label = m_IRM.GetResObj<CIFStatic>(GDR_FLORIAN0_LABEL, 1);
	this->ShowGWnd(false);


	return true;
}

void CIFflorian0::OnUpdate()
{
	time_t rawtime;
	struct tm * timeinfo;
	wchar_t buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	wcsftime(buffer,sizeof(buffer),L"%d-%m-%Y %H:%M:%S",timeinfo);

	m_time_label->SetText(buffer);
}

void CIFflorian0::On_BtnClick()
{
	printf("> " __FUNCTION__ "\n");

	static int i = 0;

	wchar_t buffer[80];
	swprintf(buffer, L"Hello World (%d)", i++);

	m_custom_label->SetText(buffer);
}

int CIFflorian0::On4001(int a1, int a2)
{
	printf("> " __FUNCTION__ " ( %p, %p )\n", a1, a2);
	return 0;
}

int CIFflorian0::On4002(int a1, int a2)
{
	printf("> " __FUNCTION__ " ( %p, %p )\n", a1, a2);
	return 0;
}

int CIFflorian0::On4003(int a1, int a2)
{
	printf("> " __FUNCTION__ " ( %p, %p )\n", a1, a2);
	return 0;
}

int CIFflorian0::OnVisibleStateChange(int newstate, int a2)
{
	printf("> " __FUNCTION__ " ( %p, %p )\n", newstate, a2);
	return 0;
}

int CIFflorian0::On4005(int a1, int a2)
{
	printf("> " __FUNCTION__ " ( %p, %p )\n", a1, a2);
	return 0;
}

int CIFflorian0::On4006(int a1, int a2)
{
	printf("> " __FUNCTION__ " ( %p, %p )\n", a1, a2);
	return 0;
}
