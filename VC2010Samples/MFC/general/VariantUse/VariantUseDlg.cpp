// VariantUseDlg.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "VariantUse.h"
#include "VariantUseDlg.h"
#include <atlconv.h>
#include <atlbase.h>
#include <comdef.h>
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
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVarUseDlg dialog

CVarUseDlg::CVarUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVarUseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVarUseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVarUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVarUseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVarUseDlg, CDialog)
	//{{AFX_MSG_MAP(CVarUseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Currency, OnCurrency)
	ON_BN_CLICKED(IDC_Strings, OnStrings)
	ON_BN_CLICKED(IDC_Basic, OnBasic)
	ON_BN_CLICKED(IDC_SafeArray, OnSafeArray)
	ON_BN_CLICKED(IDC_OleArray, OnOleArray)
	ON_BN_CLICKED(IDC_MultiDimensionArray, OnMultiDimensionArray)
	ON_BN_CLICKED(IDC_Date, OnDate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVarUseDlg message handlers

BOOL CVarUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVarUseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVarUseDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVarUseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVarUseDlg::OnCurrency() 
{
	VARIANT myVar;
	myVar.vt = VT_CY;
	

	// put 15.15 into the currency variant.
	CURRENCY myValue;
	myValue.Hi = 0;
	myValue.Lo = (LONG)(15*10000 + 1537); // set the value to $15.15;
	myVar.cyVal = myValue;
	//or
	myValue.int64 = (151234);
	myVar.cyVal = myValue;
	
	
	
	//Now get the value from a float and put it into the currency.
	float myMoney = (float)5.37;
	myVar.vt = VT_R4;
	myVar.fltVal = myMoney;
	//no loss of precission.
	ENSURE(SUCCEEDED(VariantChangeType(&myVar, &myVar, 0, VT_CY)));
	

	//Now get the value from a String
	USES_CONVERSION;
	myVar.bstrVal = SysAllocString(L"23.4345");
	myVar.vt = VT_BSTR;
	ENSURE(SUCCEEDED(VariantChangeType(&myVar, &myVar, 0, VT_CY)));

	//Finally output a currency to a string.
	myVar.cyVal.int64 += myVar.cyVal.int64; // + myVar.cyVal;
	ENSURE(SUCCEEDED(VariantChangeType(&myVar, &myVar, 0, VT_BSTR)));
	
}

void CVarUseDlg::OnStrings() 
{
	//Create a BSTR and assign it to a Variant
	BSTR x = SysAllocString(L"Hello");
	VARIANT myVariant;
	myVariant.vt = VT_BSTR;
	myVariant.bstrVal = x;
	SysFreeString(x);

	//Create a CString and change it to a variant;
	CString myCString(_T("My String"));
	CString mySecondString;
	
	BSTR y = myCString.AllocSysString();
	myVariant.bstrVal = y;
	mySecondString = y;
	SysFreeString(y);

	
	//Create two BSTRs and add them.
	BSTR a = SysAllocString(L"One two ");
	BSTR b = SysAllocString(L"three four.");
	_bstr_t my_bstr_t(a, TRUE);
	my_bstr_t += b;
	myVariant.bstrVal = my_bstr_t;
	// or
	myVariant.bstrVal = _bstr_t(a, FALSE) + b;

	//Change a bstr to a CString.
	CString ANewString(b);
	//or if CString already exists.
	myCString = b;


	//Use of CComBSTR
	CComBSTR myCComBSTR(L"Hello");
	myCComBSTR.Append(L", how are you?");
	VARIANT varFromCCom;
	varFromCCom.vt = VT_BSTR;
	varFromCCom.bstrVal = myCComBSTR;
	
}

void CVarUseDlg::OnBasic() 
{
	//create a variant of the character 'c'
	VARIANT varC;
	varC.vt=VT_UI1;
	varC.cVal = 'c';

	//create a variant of the short 12
	VARIANT varS;
	varS.vt = VT_I2;
	varS.iVal = 12;

	//create a variant of the long 1234567;
	VARIANT varL;
	varL.vt = VT_I4;
	varL.lVal = 1234567;	
}

void CVarUseDlg::OnSafeArray() 
{

	//Create a standard array;
	int* pMyOriginalArray = new int[100];
	int count;
	for(count = 0; count < 100; count++) pMyOriginalArray[count] = count;

	
	//Now get ready to put it into a safe array
	HRESULT hr;
	//create an array bound
	SAFEARRAYBOUND rgsabound[1];
	rgsabound[0].lLbound = 0;		//The first (and only) collumn of our array starts at 0.
	rgsabound[0].cElements = 100;	//and has 100 elements.
	
	//create the array
	SAFEARRAY FAR* pMySafeArray;
	pMySafeArray = SafeArrayCreate(VT_I4, 1, rgsabound); //create the array of 4byte integers, one dimension
														 //with the bounds stored in rgsabound.
	
	//now access the safe array's data.
	int* pData;
	hr = SafeArrayAccessData(  pMySafeArray, (void**)&pData); //Get a pointer to the data.
	
	
	//copy the 400 bytes of data from our old array to the new one.
	memcpy_s(pData, 400, pMyOriginalArray, 400);
	
	//here we verify to you that the data is correct.
	for(count = 0; count < 100; count++) ASSERT(pData[count] == pMyOriginalArray[count]);
	SafeArrayUnaccessData(pMySafeArray);
	
	
	//To put the SafeArray in a Variant
	VARIANT myVariant; 
	myVariant.parray = pMySafeArray;
	myVariant.vt = VT_ARRAY|VT_I4; // state it's an array and what type it holds.
	
	
	//pass the Variant to a function call.	
	FunctionCallWithVariant(myVariant);
	//see that the original array was modified.
	hr = SafeArrayAccessData(myVariant.parray, (void**)&pData); //Get a pointer to the data.
	ASSERT(pData[0] == 1234);
	SafeArrayUnaccessData(pMySafeArray);
	
	//Copy the variant.
	VARIANT NewVariant;
	NewVariant.vt = VT_EMPTY; // must set variant type for copy to work.
	hr = VariantCopy(&NewVariant, &myVariant);

	//check array in copy of variant
	int* pNewData;
	hr = SafeArrayAccessData(NewVariant.parray, (void**) &pNewData);
	for(count = 0; count < 100; count++) ASSERT(pData[count] == pNewData[count]);
	ASSERT(pData != pNewData); //copying the varriant created a new copy of the 
							   //array it contained too.  There is now 2 copies of the data.
	SafeArrayUnaccessData(NewVariant.parray);

	//Or you could use CreateVector to create the 1 dimensional array.
	SAFEARRAY* pMyVector = SafeArrayCreateVector(VT_I4, -50, 100);  //Vecoor of VT_I4, starting at 0
																//with 100 elements.
	int* pVectorData;
	hr = SafeArrayAccessData(pMyVector, (void**)&pVectorData);
	memcpy_s(pVectorData, 400, pMyOriginalArray, 400); //copy the 400 bytes of data from our old array into the new one.
	int element;
	long location[1] = {-50};
	hr = SafeArrayGetElement(pMyVector, location, (void*)&element);
	ASSERT(element == 0); //element -50 is the first element from the original array
	location[0] = 0;
	hr = SafeArrayGetElement(pMyVector, location, (void*)&element);
	ASSERT(element == 50); // element 0 is the 50th element from the original array
	delete[] pMyOriginalArray;
	hr = SafeArrayDestroy(pMySafeArray);
	hr = SafeArrayDestroy(pMyVector);
	hr = SafeArrayDestroy(NewVariant.parray);
	
}

void CVarUseDlg::OnOleArray() 
{
	//Create and fill an array.
	int* pMyOriginalArray = new int[100];
	int* pData;
	int count;
	for(count = 0; count < 100; count++) pMyOriginalArray[count]=count;
	
	//Put it into a safe array.
	COleSafeArray myOleSafeArray;
	myOleSafeArray.CreateOneDim(VT_I4, 100, pMyOriginalArray); // create one dimension array of 4-byte values
														       // 100 entries w/data from pMyOriginalArray.
	// Access that safe array.
	//Get a pointer to the Data.
	myOleSafeArray.AccessData((void**)&pData); 
	//verify all of the data.
	for(count = 0; count < 100; count++) ASSERT(pData[count] == pMyOriginalArray[count]);
	myOleSafeArray.UnaccessData();
	
	//clean up.
	delete[] pMyOriginalArray;	
}

void CVarUseDlg::OnMultiDimensionArray() 
{
	short pMyOriginalData[2][3][4][5];
	HRESULT hr;
	//initialize data
	for(short a = 0; a < 2; a++)
		for(short b = 0; b < 3; b++)
			for(short c = 0; c < 4; c++)
				for(short d = 0; d < 5; d++)
					pMyOriginalData[a][b][c][d] = a*b*c*d;



	SAFEARRAY* pMyArray;
	SAFEARRAYBOUND rgsabound[4];
	for(int count = 2; count < 6; count++)
	{
		rgsabound[count - 2].lLbound = 0;
		rgsabound[count - 2].cElements = count;
	}
	pMyArray = SafeArrayCreate(VT_I2, 4, rgsabound);
	short* pData;
	hr = SafeArrayAccessData(pMyArray, (void**)&pData);
	memcpy_s(pData, 2*3*4*5*2, pMyOriginalData, 2*3*4*5*2);
	short element;
	long location[4] = {1,2,3,4};
	hr = SafeArrayGetElement(pMyArray, location, (void*)&element);
	ASSERT(element == 1*2*3*4);
	
	
	
	hr = SafeArrayDestroy(pMyArray);
	ASSERT(hr != S_OK);
	hr = SafeArrayUnaccessData(pMyArray);
	hr = SafeArrayDestroy(pMyArray);
	ASSERT(hr == S_OK);
	
}

void CVarUseDlg::OnDate() 
{
	VARIANT timeSelection;
	COleDateTime timeNow;
	DATE curDate;
	HRESULT hr;
	//Get current Time.
	timeNow = COleDateTime::GetCurrentTime();
	
	//Put time into variant.
	timeSelection.vt = VT_DATE;
	timeSelection.date = timeNow.m_dt;
	
	//Convert Variant into string using Variant Change Type.
	hr = VariantChangeType(&timeSelection, &timeSelection, 0, VT_BSTR);
	CString sCurTime(timeSelection.bstrVal);
	
	
	//Get Time as System Time.
	SYSTEMTIME mySysTime;
	timeNow.GetAsSystemTime(mySysTime);
	
	//Use COleDateTime functionality to get change SYSTEMTIME into DATE.
	COleDateTime pastTime(mySysTime);
	curDate = pastTime.m_dt;


	//Use COldeDateTime Format command to get date as CString.
	LPCTSTR format = _T("%X %z");  //Current time and time zone.
	//Note see "strftime" help for valid formating strings.	
	CString sTime = pastTime.Format(format);

}

void CVarUseDlg::FunctionCallWithVariant(VARIANT myVariant)
{
	HRESULT hr;
	int* pData;
	int count;
	hr = SafeArrayAccessData(myVariant.parray, (void**)&pData); //access the array stored in the varriant.
	for(count = 0; count < 100; count++) ASSERT(pData[count] == count); //check data;
	pData[0] = 1234; //modify data
	SafeArrayUnaccessData(myVariant.parray);
}
