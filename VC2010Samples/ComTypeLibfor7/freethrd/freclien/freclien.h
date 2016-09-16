/*+==========================================================================
  File:      FRECLIEN.H

  Summary:   Include file for the FRECLIEN code sample application.
             In addition to class definitions, this FRECLIEN.H file
             contains definitions of the application's menu, string,
             and other resource IDs.

             For a comprehensive tutorial code tour of FRECLIEN's contents
             and offerings see the accompanying FRECLIEN.TXT file. For
             more specific technical details on the internal workings see
             the comments dispersed throughout the FRECLIEN source code.

  Classes:   CMainWindow

  Functions: WinMain

  Origin:    4-6-96: atrent - Editor-inheritance from the DLLCLIEN source.

----------------------------------------------------------------------------
  This file is part of the Microsoft OLE Tutorial Code Samples.

  Copyright (c) Microsoft Corporation, 1996.  All rights reserved.

  This source code is intended only as a supplement to Microsoft
  Development Tools and/or on-line documentation.  See these other
  materials for detailed information regarding Microsoft code samples.

  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  PARTICULAR PURPOSE.
==========================================================================+*/

#if !defined(FRECLIEN_H)
#define FRECLIEN_H

#ifdef __cplusplus

extern CMsgLog* g_pMsgLog;

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CMainWindow

  Summary:  Class to encapsulate the application's main window, menu, and
            message dispatching behavior.

  Methods:  CMainWindow
              Constructor.
            InitInstance
              Creates a new instance of the main window.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CMainWindow: public CVirWindow
{
public:
  CMainWindow();
  ~CMainWindow();
  BOOL InitInstance(HINSTANCE, int);

  TCHAR m_szFileName[MAX_PATH];
  CMsgBox*  m_pMsgBox;
  CGuiBall* m_pGuiBall;

protected:
  LRESULT WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
  LRESULT DoMenu(WPARAM wParam, LPARAM lParam);

  WORD m_wWidth;
  WORD m_wHeight;
  TCHAR m_szHelpFile[MAX_PATH];
  TCHAR m_szFileTitle[MAX_PATH];
  TEXTMETRIC m_tm;
  OPENFILENAME m_ofnFile;
};


#endif // __cplusplus

// Window Class String Macros.
#define MAIN_WINDOW_TITLE_STR       "FRECLIEN: OLE Tutorial Code Sample"
#define MAIN_WINDOW_CLASS_NAME_STR  "FRECLIENWindow"
#define MAIN_WINDOW_CLASS_MENU_STR  "FRECLIENMenu"

// File Name String Macros.
#define READMEDLL_SERVER_FILE_STR          "..\\server\\freserve.txt"
#define READMEDLL_CLIENT_FILE_STR          "freclien.txt"

// OpenFile-related String Macros.
#define OFN_DEFAULTFILES_STR "All Files (*.*)\0*.*\0"
#define OFN_DEFAULTTITLE_STR "Open File"

// File Menu Command Identifiers.
#define IDM_FILE_EXIT               1000

// Help Menu Command Identifiers.
#define IDM_HELP_CONTENTS           1900
#define IDM_HELP_README             1901
#define IDM_HELP_READMEDLL          1902
#define IDM_HELP_READSOURCE         1904
#define IDM_HELP_ABOUT              1905
#define IDM_HELP_ABOUTSERVER        1906

// Error-related String Identifiers.
#define IDS_OLEINITFAILED           2000
#define IDS_APPINITFAILED           2001
#define IDS_OUTOFMEMORY             2002
#define IDS_NOHELPFILE              2003
#define IDS_NOUNICODE               2004
#define IDS_NOSERVER                2005

#define IDS_ASSERT_FAIL             2200

// Notice-related String Identifiers.
#define IDS_NOTIMPLEMENTED          2301

// Log Message String Identifiers.
#define IDS_START_MESSAGE_LOG       2400

// Help Context IDs.
#define IDH_CONTENTS                0xE142

#endif
