
// MFCXPSSample.h : main header file for the MFCXPSSample application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols

typedef HRESULT (__stdcall * STARTXPSPRINTJOB)(const LPCWSTR printerName, const LPCWSTR jobName,
  const LPCWSTR outputFileName, HANDLE progressEvent, HANDLE completionEvent, UINT8 *printablePagesOn,
  UINT32 printablePagesOnCount, IXpsPrintJob **xpsPrintJob, IXpsPrintJobStream **documentStream,
  IXpsPrintJobStream **printTicketStream);

// CMFCXPSSampleApp:
// See MFCXPSSample.cpp for the implementation of this class
//

class CMFCXPSSampleApp : public CWinAppEx
{
public:
	CMFCXPSSampleApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	HRESULT StartPrintJob(const LPCWSTR printerName, const LPCWSTR jobName, const LPCWSTR outputFileName, 
						  	HANDLE progressEvent, HANDLE completionEvent, UINT8 *printablePagesOn,
  							UINT32 printablePagesOnCount, IXpsPrintJob **xpsPrintJob, IXpsPrintJobStream **documentStream,
  							IXpsPrintJobStream **printTicketStream);


// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

protected:
	HMODULE m_hXPSPrintModule;
	STARTXPSPRINTJOB m_pfnStartPrintJob;
};

extern CMFCXPSSampleApp theApp;
