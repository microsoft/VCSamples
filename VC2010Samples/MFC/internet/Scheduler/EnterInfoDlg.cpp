// File: EnterInfoDlg.cpp
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

// EnterInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EnterInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnterInfoDlg dialog

IMPLEMENT_DYNCREATE(CEntryInfoDlg, CDHtmlDialog)

CEntryInfoDlg::CEntryInfoDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CEntryInfoDlg::IDD, CEntryInfoDlg::IDH, pParent)
{
	SetDefaultSettings();
}

CEntryInfoDlg::~CEntryInfoDlg()
{
}

void CEntryInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_DHtml_SelectString (pDX, _T("ListStartTime"), m_szStartTime);
	DDX_DHtml_SelectString (pDX, _T("ListEndTime"), m_szEndTime);
	DDX_DHtml_ElementValue (pDX, _T("Title"), m_szTitle);
	DDX_DHtml_ElementValue (pDX, _T("Description"), m_szDescription);
	DDV_MaxChars(pDX, m_szTitle, 30);
	DDV_MaxChars(pDX, m_szDescription, 200);
}

BOOL CEntryInfoDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	m_szEndTime = _T("6:00 pm");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(CEntryInfoDlg, CDHtmlDialog)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CEntryInfoDlg)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOVER, _T("buttons"),  OnMouseOverButtons)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOUT, _T("buttons"),  OnMouseOutButtons)
	DHTML_EVENT_ONCLICK(_T("BSave"), OnButtonSave)
	DHTML_EVENT_ONCLICK(_T("BCancel"), OnButtonCancel)
	DHTML_EVENT_ONCLICK(_T("BClear"), OnButtonClear)
	DHTML_EVENT_ONCLICK(_T("BModify"), OnButtonModify)
	DHTML_EVENT_ONCLICK(_T("BDelete"), OnButtonDelete)
END_DHTML_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// CEnterInfoDlg message handlers


/*********************************************************************************************
Called when the user wants to save a schedule. Checks if the information entered is valid.
Valid information: 'Title' field should not be null.  The 'Start' time should be < 'End' time
**********************************************************************************************/
HRESULT CEntryInfoDlg::OnButtonSave(IHTMLElement* /*pElement*/)
{
	UpdateData(true);

	if (CheckValidTitle() && CheckValidDescription() && CheckStartEndTime())
	{
		ASSERT(m_szTitle);
		ASSERT(m_szDescription.GetLength() <= 200);

		m_fUpdateScheduleDisplay = true;
		OnOK();
	}
	else
		m_fUpdateScheduleDisplay = false;
	
	return S_OK;
}

/*********************************************************************************************
When the 'Cancel' button is clicked, no changes are made to the Scheduler or the data 
structures
**********************************************************************************************/
HRESULT CEntryInfoDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	m_fCancelSchedule = true;
	OnCancel();
	return S_OK;
}

/*********************************************************************************************
When the 'Clear' button is clicked, the dialog is set to its default settings
**********************************************************************************************/
HRESULT CEntryInfoDlg::OnButtonClear(IHTMLElement* /*pElement*/)
{
	m_fClearSchedule = true;
	m_szTitle.Empty();
	m_szDescription.Empty();
	UpdateData (false);
	return S_OK;
}

/*********************************************************************************************
When the 'Modify' button is clicked, the old meeting information is overwritten by the 
modified meeting information if the entered information is valid
Valid Information: 'Title' field should not be null.  The 'Start' time should be < 'End' time
**********************************************************************************************/
HRESULT CEntryInfoDlg::OnButtonModify(IHTMLElement* /*pElement*/)
{
	UpdateData(true);
	
	if (CheckValidTitle() && CheckValidDescription() && CheckStartEndTime())
	{
		ASSERT(m_szTitle);
		ASSERT(m_szDescription.GetLength() <= 200);

		m_fModifySchedule = true;
		OnOK();
	}
	else
		m_fModifySchedule = false;

	return S_OK;
}

/*********************************************************************************************
When the 'Delete' button is clicked, the selected meeting is deleted from the scheduler(table)
and the data structure
**********************************************************************************************/
HRESULT CEntryInfoDlg::OnButtonDelete(IHTMLElement* /*pElement*/)
{
	m_fDeleteSchedule = true;
	OnCancel();
	return S_OK;
}

/*********************************************************************************************
When the dialog is completed before being displayed, the colors of the buttons are modified 
and only the default buttons 'Save' 'Cancel' and 'Clear' are visible. 'Modify' and 'Delete' 
are hidden
**********************************************************************************************/
void CEntryInfoDlg::OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl)
{
	CDHtmlDialog::OnDocumentComplete(pDisp, szUrl);

	CComPtr<IHTMLElement> pModifyElement;
	CComPtr<IHTMLElement> pDeleteElement;
	CComPtr<IHTMLElement> pSaveElement;
	CComPtr<IHTMLElement> pClearElement;
	CComPtr<IHTMLElement> pCancelElement;
	CComPtr<IHTMLStyle> pModifyStyle;
	CComPtr<IHTMLStyle> pDeleteStyle;
	CComPtr<IHTMLStyle> pSaveStyle;
	CComPtr<IHTMLStyle> pClearStyle;
	CComPtr<IHTMLStyle> pCancelStyle;

	HRESULT result;
	CComBSTR bstr;
	CComBSTR Defaultbstr;
	CString szStr;
	CString szDefaultstr;
	COleVariant varColor;

	if (!m_fVisibleButtons)
		szStr = _T("hidden");
	else
		szStr = _T("visible");

	if (!m_fVisibleDefaultButtons)
		szDefaultstr = _T("hidden");
	else
		szDefaultstr = _T("visible");

	result = GetElement(_T("BModify"), &pModifyElement);
	result = GetElement(_T("BDelete"), &pDeleteElement); 
	result = GetElement(_T("BSave"), &pSaveElement);
	result = GetElement(_T("BClear"), &pClearElement); 
	result = GetElement(_T("BCancel"), &pCancelElement);
	
	ASSERT(pModifyElement);
	ASSERT(pDeleteElement);
	ASSERT(pSaveElement);
	ASSERT(pClearElement);
	ASSERT(pCancelElement);

	pModifyElement->get_style(&pModifyStyle);
	pDeleteElement->get_style(&pDeleteStyle);
	pSaveElement->get_style(&pSaveStyle);
	pClearElement->get_style(&pClearStyle);
	pCancelElement->get_style(&pCancelStyle);

	ASSERT(pModifyStyle);
	ASSERT(pDeleteStyle);
	ASSERT(pSaveStyle);
	ASSERT(pClearStyle);
	ASSERT(pCancelStyle);
	
	bstr = szStr.AllocSysString();
	Defaultbstr = szDefaultstr.AllocSysString();
	
	if (pModifyStyle && pDeleteStyle && pSaveStyle && pClearStyle && pCancelStyle)
	{
		pModifyStyle->put_visibility(bstr);
		pDeleteStyle->put_visibility(bstr);
		pSaveStyle->put_visibility(Defaultbstr);
		pClearStyle->put_visibility(Defaultbstr);
		varColor = YELLOW;
		pModifyStyle->put_color(varColor);
		pDeleteStyle->put_color(varColor);
		pSaveStyle->put_color(varColor);
		pClearStyle->put_color(varColor);
		pCancelStyle->put_color(varColor);
		varColor = BLACK;
		pModifyStyle->put_backgroundColor(varColor);
		pDeleteStyle->put_backgroundColor(varColor);
		pSaveStyle->put_backgroundColor(varColor);
		pClearStyle->put_backgroundColor(varColor);
		pCancelStyle->put_backgroundColor(varColor);
	}
}

/*********************************************************************************************
Enables the text on the 'Save', 'Cancel', 'Clear', 'Modify' and 'Delete' buttons to change 
color when the mouse runs over it
*********************************************************************************************/
HRESULT CEntryInfoDlg::OnMouseOverButtons(IHTMLElement* pElement)
{
	CComPtr<IHTMLStyle> phtmlStyle;
	COleVariant varColor;

	pElement->get_style(&phtmlStyle);

	ASSERT(phtmlStyle);

	if (phtmlStyle)
	{
		varColor = AQUA;
		phtmlStyle->put_color(varColor);
		phtmlStyle->put_cursor(L"hand");
	}
	return NULL;
}

/*********************************************************************************************
Sets the default styles when the mouse is no longer on the 'Save', 'Cancel', 'Clear', 'Modify'
and 'Delete' buttons
*********************************************************************************************/
HRESULT CEntryInfoDlg::OnMouseOutButtons(IHTMLElement* pElement)
{
	CComPtr<IHTMLStyle> phtmlStyle;
	COleVariant varColor;

	pElement->get_style(&phtmlStyle);

	ASSERT(phtmlStyle);

	if (phtmlStyle)
	{
		varColor = YELLOW;
		phtmlStyle->put_color(varColor);
	}
	return NULL;
}

/*********************************************************************************************
Sets 'Save', 'Cancel' and 'Clear' buttons to visible and 'Modify' and 'Delete' to hidden
*********************************************************************************************/
void CEntryInfoDlg::SetDefaultSettings()
{
	m_fVisibleButtons = false;
	m_fVisibleDefaultButtons = true;
	m_fUpdateScheduleDisplay = false;
	m_fDeleteSchedule = false;
	m_fModifySchedule = false;
	m_fClearSchedule = false;
	m_fCancelSchedule = false;
	m_iStartHour = 0;
	m_iEndHour = 0;
}

/*********************************************************************************************
Check if the 'Start Time' < 'End Time'
*********************************************************************************************/
BOOL CEntryInfoDlg::CheckStartEndTime()
{
	BOOL fRetval = true;

	ResetVariables();

	//Get the hour and minutes for the start time
	GetHourMinute(m_szStartTime, m_szStartTimeHour, m_szStartTimeMinute, m_iStartHour);

	//Get the hour and minutes for the end time
	GetHourMinute(m_szEndTime, m_szEndTimeHour, m_szEndTimeMinute, m_iEndHour);

	CTime startTime(2000, 8, 27, m_iStartHour, atoi(m_szStartTimeMinute), 0);
	CTime endTime(2000, 8, 27, m_iEndHour, atoi(m_szEndTimeMinute), 0);

	if (startTime >= endTime)
	{
		AfxMessageBox(IDS_INVALIDTIME);
		fRetval = false;
	}
		
	return fRetval;
}

/*********************************************************************************************
The overloaded assignment operator for the CEntryInfoDlg object
*********************************************************************************************/
const CEntryInfoDlg& CEntryInfoDlg::operator= (const CEntryInfoDlg& InfoDlg)
{
	if (this != &InfoDlg)
	{
		m_fUpdateScheduleDisplay = InfoDlg.m_fUpdateScheduleDisplay;
		m_fDeleteSchedule = InfoDlg.m_fDeleteSchedule;
		m_fModifySchedule = InfoDlg.m_fModifySchedule;
		m_fClearSchedule = InfoDlg.m_fClearSchedule;
		m_fVisibleButtons = InfoDlg.m_fVisibleButtons;
		m_fVisibleDefaultButtons = InfoDlg.m_fVisibleDefaultButtons;
		m_szStartTime = InfoDlg.m_szStartTime;
		m_szEndTime = InfoDlg.m_szEndTime;
		m_szTitle = InfoDlg.m_szTitle;
		m_szDescription = InfoDlg.m_szDescription;
		m_szStartTimeHour = InfoDlg.m_szStartTimeHour;
		m_szStartTimeMinute = InfoDlg.m_szStartTimeMinute;
		m_szEndTimeHour = InfoDlg.m_szEndTimeHour;
		m_szEndTimeMinute = InfoDlg.m_szEndTimeMinute;
		m_iStartHour = InfoDlg.m_iStartHour;
		m_iEndHour = InfoDlg.m_iEndHour;
	}
	return *this;
}

/*********************************************************************************************
Checks if the 'Title' is not null
A meeting will not be stored in the scheduler if the 'Title' field is empty
*********************************************************************************************/
BOOL CEntryInfoDlg::CheckValidTitle()
{
	BOOL fRetval;
	CComPtr<IHTMLControlElement> pTitleControlElement;
	HRESULT result;

	if (m_szTitle.IsEmpty())
	{
		AfxMessageBox(IDS_ENTERTITLE);

		result = GetElementInterface(_T("Title"), &pTitleControlElement);
		
		ASSERT(pTitleControlElement);

		result = pTitleControlElement->focus();

		fRetval = false;
	}
	else
		fRetval = true;

	return fRetval;
}

/*********************************************************************************************
Checks if the 'Description' field does not contain more than 150 characters
A meeting will not be stored in the scheduler if the 'Title' field is empty
*********************************************************************************************/
BOOL CEntryInfoDlg::CheckValidDescription()
{
	BOOL fRetval = true;

	if (m_szDescription.GetLength() > 200)
		fRetval = false;

	return fRetval;
}

/*********************************************************************************************
Set the member variables to "" so that they can be re-used
*********************************************************************************************/
void CEntryInfoDlg::ResetVariables()
{
	m_szStartTimeHour.Empty();
	m_szStartTimeMinute.Empty();
	m_szEndTimeHour.Empty();
	m_szEndTimeMinute.Empty();
}

/*********************************************************************************************
Retrieves the 'Hour' and 'Minute' from the time string
e.g. Time string = 8:00 am
Hour = 8, Minute = 00
e.g. Time string = 6:00 pm
Hour = 18 (6 + 12), Minute = 00
*********************************************************************************************/
void CEntryInfoDlg::GetHourMinute(CString szTime, CString &szHour, CString &szMinute, int &iHour)
{
	CString szAmpm;
	int iTime;

	//Retrieving the hour
	//eg. 8, if the selected start time is 8:00am or 8:30am
	for (iTime =0; szTime.GetAt(iTime) != ':';iTime++)
		szHour += szTime.GetAt(iTime);
	
	//Retrieving the minute
	//eg. 00 or 30, if the selected start time minute is 8:00am or 8:30am
	iTime++; //To exclude ':'
	for (iTime; szTime.GetAt(iTime) != ' ';iTime++)
		szMinute += szTime.GetAt(iTime);
	
	//Retrieving whether am or pm
	szAmpm = szTime.Right(2);

	iHour = atoi(szHour);

	if (iHour != 12 && !strcmp(szAmpm, _T("pm")))
		iHour += 12;
}