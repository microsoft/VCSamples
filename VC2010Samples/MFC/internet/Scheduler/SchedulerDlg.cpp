// SchedulerDlg.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "Scheduler.h"
#include "SchedulerDlg.h"
#include "EnterInfoDlg.h"
#include "MyScheduler.h"
	
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSchedulerDlg dialog

BEGIN_DHTML_EVENT_MAP(CSchedulerDlg)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOVER, _T("time"),  OnMouseOverTime)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOUT, _T("time"),  OnMouseOutTime)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOVER, _T("cmdbuttons"),  OnMouseOverButtons)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOUT, _T("cmdbuttons"),  OnMouseOutButtons)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOVER, _T("timedesc"),  OnMouseOverTimeDesc)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOVER, _T("newElements"),  OnMouseOverNewElements)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOUT, _T("newElements"),  OnMouseOutNewElements)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONCLICK, _T("newElements"),  OnClickNewElements)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONCLICK, _T("time"),  OnClickTime)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONCLICK, _T("timedesc"),  OnClickTimeDesc)
	DHTML_EVENT_AXCONTROL(DISPID_HTMLELEMENTEVENTS_ONCLICK, _T("Calendar1"), OnClickCalendar)
	DHTML_EVENT_ONCLICK(_T("BClearAll"), OnButtonClearAll)
END_DHTML_EVENT_MAP()


CSchedulerDlg::CSchedulerDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CSchedulerDlg::IDD, CSchedulerDlg::IDH, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSchedulerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_DHtml_AxControl(pDX, _T("Calendar1"), DISPID_MONTH, m_month);
	DDX_DHtml_AxControl(pDX, _T("Calendar1"), DISPID_DAY, m_day);
	DDX_DHtml_AxControl(pDX, _T("Calendar1"), DISPID_YEAR, m_year);
}

BEGIN_MESSAGE_MAP(CSchedulerDlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
	ON_COMMAND(IDD_HELP_ABOUTSCHEDULER, OnHelpAbout)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSchedulerDlg message handlers

BOOL CSchedulerDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//Initializing the calendar to the current date

	CTime t = CTime::GetCurrentTime();
	m_currMonth = (short)t.GetMonth();
	m_currDay = (short)t.GetDay();
	m_currYear = (short)t.GetYear();

	SetDefaultProperties();

	m_szDivClass = _T("newElements");
	m_iLastDivID = 0;


	VERIFY(SHGetSpecialFolderPath(NULL, m_scheduler_filepath, CSIDL_PERSONAL, 0));
	
	//Saves the file to load/store in the 'My Documents' folder specific to the current user
	if(SHGetSpecialFolderPath(NULL, m_scheduler_filepath, CSIDL_PERSONAL, 0))
		PathAppend(m_scheduler_filepath, _T("Scheduler.sdr"));
		
	ASSERT(m_scheduler_filepath);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSchedulerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSchedulerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSchedulerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


/*********************************************************************************************
Shows that the Time column of the scheduler and Buttons are clickable by modifying the style
*********************************************************************************************/
HRESULT CSchedulerDlg::OnMouseOverTime(IHTMLElement* pElement)
{
	COleVariant varColor;
	CComPtr<IHTMLStyle> phtmlStyle;
	pElement->get_style(&phtmlStyle);

	ASSERT(phtmlStyle);

	if (phtmlStyle)
	{
		varColor = RED;
		phtmlStyle->put_textDecorationUnderline(VARIANT_TRUE);
		phtmlStyle->put_color(varColor);
		phtmlStyle->put_cursor(L"hand");
	}
	return NULL;
}

/*********************************************************************************************
Sets the default styles when the mouse is no longer on the time column of the scheduler and 
buttons
*********************************************************************************************/
HRESULT CSchedulerDlg::OnMouseOutTime(IHTMLElement* pElement)
{
	COleVariant varColor;
	CComPtr<IHTMLStyle> phtmlStyle;
	
	pElement->get_style(&phtmlStyle);

	ASSERT(phtmlStyle);

	if (phtmlStyle)
	{
		varColor = BLACK;
		phtmlStyle->put_textDecorationUnderline(VARIANT_FALSE);
		phtmlStyle->put_color(varColor);
	}
	return NULL;
}

/*********************************************************************************************
Enables the text on the 'ClearAll' button to change color when the mouse runs over it
*********************************************************************************************/
HRESULT CSchedulerDlg::OnMouseOverButtons(IHTMLElement* pElement)
{
	COleVariant varColor;
	CComPtr<IHTMLStyle> phtmlStyle;

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
Sets the default styles when the mouse is no longer on the 'ClearAll' button
*********************************************************************************************/
HRESULT CSchedulerDlg::OnMouseOutButtons(IHTMLElement* pElement)
{
	COleVariant varColor;
	CComPtr<IHTMLStyle> phtmlStyle;

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
Shows that the schedule information column is clickable by modifying the style
*********************************************************************************************/
HRESULT CSchedulerDlg::OnMouseOverTimeDesc(IHTMLElement* pElement)
{
	CComPtr<IHTMLStyle> phtmlStyle;
	pElement->get_style(&phtmlStyle);

	ASSERT(phtmlStyle);

	if (phtmlStyle)
	{
		phtmlStyle->put_cursor(L"hand");
	}
	return NULL;
}


/*********************************************************************************************
Shows that the schedules entered in the scheduler are clickable distinctly by modifying the 
style
*********************************************************************************************/
HRESULT CSchedulerDlg::OnMouseOverNewElements(IHTMLElement* pElement)
{
	COleVariant varColor;
	CComPtr<IHTMLStyle> phtmlStyle;

	pElement->get_style(&phtmlStyle);

	ASSERT(phtmlStyle);

	if (phtmlStyle)
	{
		varColor = RED;
		phtmlStyle->put_textDecorationUnderline(VARIANT_TRUE);
		phtmlStyle->put_color(varColor);
		phtmlStyle->put_cursor(L"hand");
	}
	return NULL;
}

/*********************************************************************************************
Sets the default styles when the mouse is no longer on the schedule entries
*********************************************************************************************/
HRESULT CSchedulerDlg::OnMouseOutNewElements(IHTMLElement* pElement)
{
	COleVariant varColor;
	CComPtr<IHTMLStyle> phtmlStyle;

	pElement->get_style(&phtmlStyle);

	ASSERT(phtmlStyle);

	if (phtmlStyle)
	{
		varColor = BLUE;
		phtmlStyle->put_textDecorationUnderline(VARIANT_FALSE);
		phtmlStyle->put_color(varColor);
	}
	return NULL;
}

/*********************************************************************************************
When the time column is clicked, the EntryInfo dialog is called to enter the schedule 
information.  The schedule is stored in the scheduler if the information entered is valid.
Valid Information: The 'title' field should not be null.
If the information entered is invalid, the user is prompted to re-enter the information.
*********************************************************************************************/
HRESULT CSchedulerDlg::OnClickTime(IHTMLElement *pElement)
{
	CComBSTR getbstr;
	CEntryInfoDlg InfoDlg;
	
	UpdateData(true);

	if (CheckDates())
	{
		//Get the start time selected
		pElement->get_id(&getbstr);
		
		ASSERT(getbstr);

		InfoDlg.m_szStartTime = getbstr;
		InfoDlg.DoModal();

		//If valid schedule information was entered
		if (InfoDlg.m_fUpdateScheduleDisplay)    
			OnUpdateScheduleDisplay(InfoDlg);
	}
	return S_OK;
}


/************************************************************************************************
When the Schedule Information column is clicked, the EntryInfo dialog is called with the default
'Save' 'Cancel' and 'Clear' buttons to enterthe schedule information. The schedule is stored 
in the scheduler if the information entered is valid. 
Valid information: The 'title' field should not be null.
If the information entered is invalid, the user is prompted to re-enter the information.
This event has the same functionality as the 'OnClickTime' event.  They are not merged 
together because the two columns 'Time' and 'Scheduler Information' have different 'ids' in
the html source code and merging them would give an incorrect 'startTime' in the EntryInfo 
dialog.
*************************************************************************************************/
HRESULT CSchedulerDlg::OnClickTimeDesc(IHTMLElement *pElement)
{
	CComBSTR getbstr;
	CEntryInfoDlg InfoDlg;
	CString szStr;
	
	//Get the id of the row that was clicked
	pElement->get_id(&getbstr);
	
	ASSERT(getbstr);

	InfoDlg.m_fVisibleButtons = false;
	InfoDlg.m_fVisibleDefaultButtons = true;
	szStr = getbstr;
	InfoDlg.m_szStartTime = GetStartTimeFormatted(szStr);
	
	InfoDlg.DoModal();

	//If valid schedule information was entered
	if (InfoDlg.m_fUpdateScheduleDisplay)    
		OnUpdateScheduleDisplay(InfoDlg);
	
	return S_OK;
}


/*********************************************************************************************
When the schedules are clicked, the EntryInfo dialog is called with the 'Modify' 'Delete' and 
'Cancel' buttons and the schedule information in it to either Modify/Delete the schedule.
If Modify is clicked, another EntryInfo dialog is called with the schedule information, but 
with the default buttons 'Save' 'Cancel' and 'Clear'.
	Modifying the schedule and clicking 'Save' overwrites the old schedule with the modified 
	schedule
	Clicking 'Save' only (without any modifications) leaves the old schedule unmodified
	Clicking 'Clear' and 'Save' deletes the schedule
	Clicking 'Cancel' leaves the old schedule unmodified
*********************************************************************************************/
HRESULT CSchedulerDlg::OnClickNewElements(IHTMLElement *pElement)
{
	BSTR getbstr = NULL;
	CEntryInfoDlg InfoDlg;
	CMyScheduler scheduler;
	CString szStr;
	CComPtr<IHTMLElement> phtmlElement;
	int iDivID, iScheduleInfo;

	pElement->get_parentElement(&phtmlElement);

	//Get a valid parent element
	ASSERT(phtmlElement);

	if (phtmlElement)
		phtmlElement->get_id(&getbstr);

	//Get a valid parent id
	ASSERT(getbstr);

	szStr = getbstr;
	InfoDlg.m_szStartTime = GetStartTimeFormatted(szStr);

	pElement->get_id(&getbstr);

	//Get a valid id for the new meeting
	ASSERT(getbstr);

	szStr = getbstr;
	iDivID = atoi(szStr);
	
	for (iScheduleInfo=0; iScheduleInfo < m_scheduler_array.GetSize(); iScheduleInfo++)
	{
		scheduler = m_scheduler_array.GetAt(iScheduleInfo);

		if (scheduler.m_iId == iDivID)
			break;
	}
	
	ASSERT(scheduler.m_iId==iDivID);

	InfoDlg.m_szTitle = scheduler.m_szTitle;
	InfoDlg.m_szDescription = scheduler.m_szDescription;

	InfoDlg.m_fVisibleButtons = true;
	InfoDlg.m_fVisibleDefaultButtons = false;
	InfoDlg.DoModal();

	if (InfoDlg.m_fDeleteSchedule) //If the schedule needs to be deleted
	{
		m_scheduler_array.RemoveAt(iScheduleInfo);
		OnDeleteScheduleDisplay(scheduler);
	}	
	else if (InfoDlg.m_fModifySchedule) //If the schedule needs to be modified
	{
		RemoveInfoFromTable();
		OnModifyScheduleDisplay(m_scheduler_array.ElementAt(iScheduleInfo), InfoDlg);
		DateSchedules();
	}
	else //Cancel
		//DO NOTHING

	InfoDlg.SetDefaultSettings();

	return S_OK;
}


/*********************************************************************************************
Removes all the data from the table
Removes all the data from the Scheduler Array
Sets the default table properties
*********************************************************************************************/
HRESULT CSchedulerDlg::OnButtonClearAll(IHTMLElement* /*pElement*/)
{
	RemoveInfoFromTable();
	m_scheduler_array.RemoveAll();
	SetDefaultProperties();
	return S_OK;
}


/*********************************************************************************************
Set the member variables for month, day and year to the current date
Set the Calendar values to the current date
*********************************************************************************************/
void CSchedulerDlg::SetDefaultProperties()
{
	//Set the month, day and year values to the current date
	m_month = m_currMonth;
	m_day = m_currDay;
	m_year = m_currYear;

	UpdateData(false);
}


/*********************************************************************************************
Check if the dates entered are valid
Valid dates: Dates > Current Date
Valid dates: Dates with the year, month and day fields selected
*********************************************************************************************/
BOOL CSchedulerDlg::CheckDates()
{
	BOOL fRetval = true;

	ASSERT(m_month.iVal);
	ASSERT(m_day.iVal);
	ASSERT(m_year.iVal);

	CTime currTime(m_currYear, m_currMonth, m_currDay, 0, 0, 0, 0);
	CTime enteredTime(m_year.iVal, m_month.iVal, m_day.iVal, 0, 0, 0, 0);

	if (!(m_month.iVal && m_day.iVal && m_year.iVal) || (currTime > enteredTime))
	{
		fRetval = false;
		SetDefaultProperties();
		AfxMessageBox (IDS_INVALIDDATE);
	}

	return fRetval;
}


/*********************************************************************************************
Adjusts the 'Start' and 'End' hours to be displayed between '1 - 12
eg. Converts '13:00' to '1:00'
*********************************************************************************************/
CString CSchedulerDlg::AdjustHour(int iHour)
{
	ASSERT(iHour < 24);
	CString szRetval;
	szRetval.Format("%d", iHour < 13 ? iHour : iHour-12);
	return(szRetval);
}


/*********************************************************************************************
Formats the 'Time' string to be displayed in the Scheduler Table
*********************************************************************************************/
CString CSchedulerDlg::SetTimeFormat(int iHour, int iMinutes)
{
	CString szTime_span;

	szTime_span = AdjustHour(iHour);
	
	if (iMinutes)
		szTime_span += _T(":30");
	else
		szTime_span += _T(":00");

	if (iHour >= 12)
		szTime_span += _T(" pm");
	else
		szTime_span += _T(" am");
	 
	return szTime_span;
}


/*********************************************************************************************
Displays all the schedules for the selected date
At the end of the function, all the rows of the table contain information for the specified 
date only!
*********************************************************************************************/
inline void CSchedulerDlg::DateSchedules()
{
	CComBSTR startTime;
	CComBSTR endTime;
	CComBSTR scheduleEntry;
	CComBSTR tempbstr;
	CMyScheduler scheduler;
	CString szTempstr;
	CString szInnerHtml;
	CString szHour;
	CString szDate;
	CString szElementId;
	CString szEid;
	CString szTempstring;
	CTime mytime;
	HRESULT result;
	COleVariant varColor;

	//If the dates entered are valid
	if(CheckDates()) 
	{
		if (m_scheduler_array.GetSize())
		{
			//Iterate through all the schedules stored in the scheduler
			for (int iallDates = 0; iallDates < m_scheduler_array.GetSize(); iallDates++)
			{
				scheduler = m_scheduler_array.GetAt(iallDates);

				//Change the valid dated schedules' background color
				if ((scheduler.m_iYear == m_year.iVal) && (scheduler.m_iMonth == m_month.iVal) && (scheduler.m_iDay == m_day.iVal))
				{
					CTime mytime( m_year.iVal, m_month.iVal, m_day.iVal, scheduler.m_iStartHour, scheduler.m_iStartMinutes, 0); 
					szDate = mytime.Format( "%A, %B %d, %Y" );
				
					//To get the chosen Start and End Times
					//timeSpan contains the duration of the schedule
					//eg. 8:00 am - 9:00 am
					szElementId = SetTimeFormat(scheduler.m_iStartHour, scheduler.m_iStartMinutes);

					for (int j=0; szElementId.GetAt(j) != ' ';j++)
						szEid += szElementId.GetAt(j);

					CComPtr<IHTMLElement> pHTMLElement;

					//Format the new schedule information
					result = GetElement(szEid, &pHTMLElement);

					ASSERT(pHTMLElement);

					szElementId += _T(" - ");
					szElementId += SetTimeFormat(scheduler.m_iEndHour, scheduler.m_iEndMinutes);
					
					CComPtr<IHTMLStyle> phtmlStyle;

					//Change the text color of the schedule information
					if (pHTMLElement)
						pHTMLElement->get_style(&phtmlStyle); 

					ASSERT(phtmlStyle);

					if (phtmlStyle)
					{
						varColor = BLUE;
						phtmlStyle->put_color(varColor);
					}
				
					szInnerHtml = scheduler.m_szTitle;
					szInnerHtml += _T(": ");
					szInnerHtml += szElementId;
					szInnerHtml += _T(" (");
					szInnerHtml += szDate;
					szInnerHtml += _T(")");
					szInnerHtml += _T("\n");	
	
					szTempstr.Format(_T("<DIV class=%s title=%s id=%d>%s</DIV>"), m_szDivClass, "Modify/Delete", 
						scheduler.m_iId, szInnerHtml);
					tempbstr = szTempstr.AllocSysString();

					scheduleEntry = GetElementHtml(szEid);

					//Display the duration of the schedule
					if (scheduleEntry)
						scheduleEntry += tempbstr;
					else
						scheduleEntry = tempbstr;
					
					SetElementHtml(szEid, scheduleEntry);
					szEid.Empty();
					scheduleEntry.Empty();
				}
			}
		}
	}
}


/********************************************************************************************
Undisplays all the contents from the Scheduler table
When the function returns, all the rows of the table are empty
This function DOES NOT AFFECT the data structures that contain the scheduler information
*********************************************************************************************/
void CSchedulerDlg::RemoveInfoFromTable()
{
	CComBSTR blankBstr;
	CMyScheduler schedulerEntry;
	CString szTime;

	for (int iallDates = 0; iallDates < m_scheduler_array.GetSize(); iallDates++)
	{
		schedulerEntry = m_scheduler_array.GetAt(iallDates);
		
		szTime = AdjustHour(schedulerEntry.m_iStartHour);
		szTime += _T(":");

		if (schedulerEntry.m_iStartMinutes)
			szTime += _T("30");
		else
			szTime += _T("00");

		SetElementText(szTime, blankBstr);
	}
}

/********************************************************************************************
Open an existing file
If the file does not exist, an error message is returned
The user has the option of creating a new file
*********************************************************************************************/
void CSchedulerDlg::OpenScheduler(void)
{
	// TODO: Add your command handler code here
	CFile schedulerFile;
	CMyScheduler scheduler;

	if( schedulerFile.Open(m_scheduler_filepath, CFile::modeRead) ) 
	{
		CArchive ar(&schedulerFile, CArchive::load);
		m_scheduler_array.Serialize(ar);
		ar >> m_iLastDivID;

		DateSchedules();
		
		ar.Close();
		schedulerFile.Close();
	}
}

/*********************************************************************************************
Stores the contents of the Scheduler in an archive (file)
If the file does not exist, it creates a new file
If the file exists, the function overwrites the same file every time
*********************************************************************************************/
void CSchedulerDlg::ExitScheduler(void)
{
	// TODO: Add your command handler code here
	CFile schedulerFile;
	CMyScheduler scheduler;
	
	if (m_scheduler_array.GetSize())
	{
		TRY
		{
			if( !schedulerFile.Open(m_scheduler_filepath, CFile::modeCreate | CFile::modeWrite)) 
			{
				//SHOULD NEVER GET HERE
				AfxMessageBox (IDS_CANNOTOPENFILE);
			}
			else
			{
				CArchive ar(&schedulerFile, CArchive::store);
				m_scheduler_array.Serialize(ar);
				ar << m_iLastDivID;

				ar.Close();

				schedulerFile.Close();
			}
		}
		CATCH( CFileException, e )
		{
			#ifdef _DEBUG
				afxDump << "File " << m_scheduler_filepath << " cannot be created\n";
			#endif
		}
		END_CATCH
	}
	else
	{
		if (schedulerFile.Open(m_scheduler_filepath, CFile::modeRead))
		{
			schedulerFile.Close();
			TRY
			{
				CFile::Remove(m_scheduler_filepath);
			}
			CATCH( CFileException, e)
			{
				#ifdef _DEBUG
					afxDump << "File " << m_scheduler_filepath << " cannot be removed\n";
				#endif
			}
			END_CATCH
		}
	}
	PostQuitMessage(0);
}

/*********************************************************************************************
The Help menu gives you information about 'The Scheduler'
**********************************************************************************************/
void CSchedulerDlg::OnHelpAbout(void)
{
	CAboutDlg dlg;
	dlg.DoModal();
}

/*********************************************************************************************
Enters a new schedule to the scheduler
Adds a new schedule entry to the m_scheduler_array
Calls DateSchedules() method to display the new schedule in the scheduler
**********************************************************************************************/
void CSchedulerDlg::OnUpdateScheduleDisplay(const CEntryInfoDlg& InfoDlg)
{
	CMyScheduler schedulerEntry;

	schedulerEntry.m_iMonth = m_month.iVal;
	schedulerEntry.m_iDay = m_day.iVal;
	schedulerEntry.m_iYear = m_year.iVal;
	schedulerEntry.m_szTitle = InfoDlg.m_szTitle;
	schedulerEntry.m_szDescription = InfoDlg.m_szDescription;
	schedulerEntry.m_iStartHour = InfoDlg.m_iStartHour;
	schedulerEntry.m_iEndHour = InfoDlg.m_iEndHour;
	schedulerEntry.m_iStartMinutes = atoi(InfoDlg.m_szStartTimeMinute);
	schedulerEntry.m_iEndMinutes = atoi(InfoDlg.m_szEndTimeMinute);
	schedulerEntry.m_iId = m_iLastDivID++;
	
	m_scheduler_array.Add(schedulerEntry);

	RemoveInfoFromTable();
	
	DateSchedules();
}


/*********************************************************************************************
Binds the user's selected date to the schedules for that given date
Displays all the schedules for the selected date
**********************************************************************************************/
void __stdcall CSchedulerDlg::OnClickCalendar()
{
	UpdateData(true);
	RemoveInfoFromTable();
	DateSchedules();
}


/*********************************************************************************************
Format the start time as displayed in the list box control in 'EntryInfoDlg.htm'
This function is used to determine the start time to be displayed
**********************************************************************************************/
CString CSchedulerDlg::GetStartTimeFormatted(CString szStartTime)
{
	CString szHour;
	CString szAmpm;
	CString szRetval;
	int i, iHour;

	//Getting the start hour to be displayed on the EntryInfoDlg
	for(i=0; szStartTime.GetAt(i) != ':'; i++)
		szHour += szStartTime.GetAt(i);

	ASSERT(szHour);

	iHour = atoi(szHour);

	//Formatting the start hour according to the cell (row) id (HTML source)
	szAmpm.Format("%s", iHour == 12 ? _T(" pm") : iHour > 6 ? _T(" am") : _T(" pm"));

	szRetval = szStartTime;
	szRetval += szAmpm;

	return szRetval;
}

/*********************************************************************************************
Called on deleting a schedule from the scheduler
Sets the inner_html tag of that row to ""
**********************************************************************************************/
void CSchedulerDlg::OnDeleteScheduleDisplay(CMyScheduler& scheduler)
{
	CComBSTR getbstr;
	CString szStr;
	
	szStr.Format("%d", scheduler.m_iId);

	ASSERT(szStr);

	SetElementHtml(szStr, getbstr);
}


/*********************************************************************************************
Called when trying to modify a schedule
Replaces the 'existing' schedule information with the newly entered information
**********************************************************************************************/
void CSchedulerDlg::OnModifyScheduleDisplay(CMyScheduler& scheduler, const CEntryInfoDlg& InfoDlg)
{
	scheduler.m_iMonth = m_month.iVal;
	scheduler.m_iDay = m_day.iVal;
	scheduler.m_iYear = m_year.iVal;
	scheduler.m_szTitle = InfoDlg.m_szTitle;
	scheduler.m_szDescription = InfoDlg.m_szDescription;
	scheduler.m_iStartHour = InfoDlg.m_iStartHour;
	scheduler.m_iEndHour = InfoDlg.m_iEndHour;
	scheduler.m_iStartMinutes = atoi(InfoDlg.m_szStartTimeMinute);
	scheduler.m_iEndMinutes = atoi(InfoDlg.m_szEndTimeMinute);
}

/*********************************************************************************************
When the dialog is completed before being displayed, the color of the 'ClearAll' button is 
modified. The OpenScheduler() method is invoked to open an 'Archive/File' if it exists.
**********************************************************************************************/
void CSchedulerDlg::OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl)
{
	IHTMLElement *pClearAllElement;
	IHTMLStyle *pClearAllStyle;
	VARIANT varColor;
	HRESULT result = GetElement(_T("BClearAll"), &pClearAllElement);
	
	if (SUCCEEDED(result)) {
		pClearAllElement->get_style(&pClearAllStyle);
		varColor.vt = VT_I4;
		varColor.lVal = 0xfffacd;
		pClearAllStyle->put_color(varColor);
		varColor.lVal = 0x00000;
		pClearAllStyle->put_backgroundColor(varColor);
		pClearAllStyle->Release();	
		pClearAllElement->Release();
	}

	OpenScheduler();

	CDHtmlDialog::OnDocumentComplete(pDisp, szUrl);
}
