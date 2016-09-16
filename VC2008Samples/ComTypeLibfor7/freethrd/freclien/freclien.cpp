/*+==========================================================================
  File:      FRECLIEN.CPP

  Summary:   Based largely on the DLLCLIEN.EXE application code, this
             module is meant to use use muitiple threads in the client to
             load and access a free threaded COM component in a separate
             in-process COM Server (FRESERVE built in the sibling FRESERVE
             directory).  Thus to run FRECLIEN you must build FRESERVE
             first. This client application is meant to exercise the
             FRESERVE in-process server using multiple client threads.
             Three such worker threads are created to function the
             principal COM object in the FRESERVE server. This object is
             a COBall object which maintains logic and data to simulate a
             ball bouncing inside of an enclosed 2-dimensional area. The
             worker threads all continuously attempt to move this virtual
             ball.

             In this client application the main process thread also
             asynchronously queries the ball for its display data and
             renders this data into a moving GUI image on the screen.
             There is no GUI behavior in the server--it is all in this
             client.  This client instantiates one instance of the
             server's COBall COM object and exercises it with multiple
             threads. There is a minimal menu in FRECLIEN. All the action
             is automatic. The main application window's client area is
             used for visual display of the moving ball.

             For a comprehensive tutorial code tour of FRECLIEN's contents
             and offerings see the accompanying FRECLIEN.TXT file. For
             more specific technical details on the internal workings see
             the comments dispersed throughout the FRECLIEN source code.
             For more details on the FRESERVE.DLL that FRECLIEN works with
             see the FRESERVE.TXT file in the sibling FRESERVE directory.

  Classes:   CMainWindow

  Functions: InitApplication, WinMain

  Origin:    4-6-96: atrent - Editor-inheritance from the DLLCLIEN source.
             Also borrows from the GDIDEMO sample in the Win32 samples of
             the Win32 SDK.

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

/*--------------------------------------------------------------------------
  We include WINDOWS.H for all Win32 applications.
  We include OLE2.H because we will be making calls to the OLE Libraries.
  We include INITGUID.H only once (here) in the entire app because we
    will be defining GUIDs and want them as constants in the data segment.
  We include COMMDLG.H because we will be using the Open File and
    potentially other Common dialogs.
  We include APPUTIL.H because we will be building this application using
    the convenient Virtual Window and Dialog classes and other
    utility functions in the APPUTIL Library (ie, APPUTIL.LIB).
  We include IBALL.H and BALLGUID.H for the common Ball-related Interface
    class, GUID, and CLSID specifications.
  We include FRECLIEN.H because it has class and resource definitions
    specific to this FRECLIEN application.
  We include GUIBALL.H because it has the C++ class used for GUI display
    of the moving ball.
---------------------------------------------------------------------------*/
#include "preclien.h"
#include <commdlg.h>

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMainWindow::CMainWindow

  Summary:  CMainWindow Constructor.

  Args:     .

  Modifies: .

  Returns:  .
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
CMainWindow::CMainWindow()
{
  // Ensure these member variable strings are null strings.
  m_szFileName[0] = 0;
  m_szFileTitle[0] = 0;

  // Fill in the Open File Name Common Dialog's OPENFILENAME structure.
  m_ofnFile.lStructSize = sizeof(OPENFILENAME);
  m_ofnFile.hwndOwner = m_hWnd;
  m_ofnFile.hInstance = m_hInst;
  m_ofnFile.lpstrFilter = TEXT(OFN_DEFAULTFILES_STR);
  m_ofnFile.lpstrCustomFilter = NULL;
  m_ofnFile.nMaxCustFilter = 0;
  m_ofnFile.nFilterIndex = 1;
  m_ofnFile.lpstrFile = m_szFileName;
  m_ofnFile.nMaxFile = MAX_PATH;
  m_ofnFile.lpstrInitialDir = TEXT(".");
  m_ofnFile.lpstrFileTitle = m_szFileTitle;
  m_ofnFile.nMaxFileTitle = MAX_PATH;
  m_ofnFile.lpstrTitle = TEXT(OFN_DEFAULTTITLE_STR);
  m_ofnFile.lpstrDefExt = NULL;
  m_ofnFile.Flags = OFN_HIDEREADONLY;

  m_pMsgBox  = NULL;
  m_pGuiBall = NULL;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMainWindow::~CMainWindow

  Summary:  CMainWindow Destructor.  Destruction of the main window
            indicates that the application should quit and thus the
            PostQuitMessage API is called.

  Args:     .

  Modifies: .

  Returns:  .
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
CMainWindow::~CMainWindow()
{
  // CMainWindow is derived from CVirWindow which traps the WM_DESTROY
  // message and causes a delete of CMainWindow which in turn causes this
  // destructor to run. The WM_DESTROY results when the window is destoyed
  // after a close of the window. Prior to exiting the main message loop:

  // We delete the CGuiBall and CMsgBox objects that were made in
  // Initinstance.
  delete m_pGuiBall;
  delete m_pMsgBox;

  // We then post a WM_QUIT message to cause an exit of the main thread's
  // message loop and an exit of this instance of the application.
  PostQuitMessage(0);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMainWindow::InitInstance

  Summary:  Instantiates an instance of the main application window.
            This method must be called only once, immediately after
            window class construction.  We take care to delete 'this'
            CMainWindow if we must return the error condition FALSE.

  Args:     HINSTANCE hInstance,
              Handle of the application instance.
            int nCmdShow)
              Command to pass to ShowWindow.

  Modifies: m_szHelpFile, m_pMsgBox.

  Returns:  BOOL.
              TRUE if succeeded.
              FALSE if failed.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMainWindow::InitInstance(
       HINSTANCE hInstance,
       int nCmdShow)
{
  BOOL bOk = FALSE;
  HWND hWnd = NULL;

  // Create the Message Box and Message Log objects.
  m_pMsgBox = new CMsgBox;

  // Create the CGuiBall object.
  m_pGuiBall = new CGuiBall;

  if (NULL != m_pMsgBox && NULL != m_pGuiBall)
  {
    // Note, the Create method sets the m_hWnd member so we don't
    // need to set it explicitly here first. Here is the create of this
    // window.  Size the window reasonably. Create sets both m_hInst and
    // m_hWnd. This creates the main client window.
    hWnd = Create(
             TEXT(MAIN_WINDOW_CLASS_NAME_STR),
             TEXT(MAIN_WINDOW_TITLE_STR),
             WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
               | WS_MAXIMIZEBOX | WS_THICKFRAME,
             CW_USEDEFAULT,
             CW_USEDEFAULT,
             ::GetSystemMetrics(SM_CXSCREEN)*2/5,
             ::GetSystemMetrics(SM_CYSCREEN)*2/5,
             NULL,
             NULL,
             hInstance);
    if (NULL != hWnd)
    {
      // Init the new GuiBall.
      bOk = m_pGuiBall->Init(m_hWnd);
      if (bOk)
      {
        // Ensure the new window is shown on screen and content
        // is painted.
        ::ShowWindow(m_hWnd, nCmdShow);
        ::UpdateWindow(m_hWnd);

        // Build a path to where the help file should be (it should be in
        // the same directory as the .EXE but with the .HLP extension.
        MakeFamilyPath(hInstance, m_szHelpFile, MAX_PATH, TEXT(HELP_FILE_EXT));

        // Init the Message Box object.
        bOk = m_pMsgBox->Init(m_hInst, m_hWnd);
      }
    }
  }

  if (!bOk)
  {
    delete m_pMsgBox;
    delete m_pGuiBall;
  }

  return (bOk);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMainWindow::DoMenu

  Summary:  Dispatch and handle the main menu commands.

  Args:     WPARAM wParam,
              First message parameter (word sized).
            LPARAM lParam)
              Second message parameter (long sized).

  Modifies: m_ofnFile, ...

  Returns:  LRESULT
              Standard Windows WindowProc return value.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
LRESULT CMainWindow::DoMenu(
          WPARAM wParam,
          LPARAM lParam)
{
  LRESULT lResult = FALSE;

  switch (LOWORD(wParam))
  {
    //----------------------------------------------------------------------
    // Handle File Menu Commands.
    //----------------------------------------------------------------------
    case IDM_FILE_EXIT:
      // The user commands us to exit this application so we tell the
      // Main window to close itself.
    ::PostMessage(m_hWnd, WM_CLOSE, 0, 0);
      break;

    //----------------------------------------------------------------------
    // Handle Help Menu Commands.
    //----------------------------------------------------------------------
    case IDM_HELP_CONTENTS:
      // We have some stubbed support here for bringing up the online
      //   Help for this application.
      if (::FileExist(m_szHelpFile))
        ::WinHelp(m_hWnd, m_szHelpFile, HELP_CONTEXT, IDH_CONTENTS);
      else
        m_pMsgBox->ErrorID(IDS_NOHELPFILE);
      break;
    case IDM_HELP_README:
      // Call the APPUTIL utility function ReadMe to read the FRECLIEN.TXT
      // "readme" file associated with this tutorial code sample.
      ReadMeFile(m_hWnd, TEXT(READMEDLL_CLIENT_FILE_STR));
      break;
    case IDM_HELP_READMEDLL:
      // Call the APPUTIL utility function ReadMe to read the FRESERVE.TXT
      // "readme" file associated with the companion FRESERVE DLL.
      ReadMeFile(m_hWnd, TEXT(READMEDLL_SERVER_FILE_STR));
      break;
    case IDM_HELP_READSOURCE:
      // Call the APPUTIL utility function ReadSource to allow the
      // user to open and read any of the source files of FRECLIEN.
      ReadSource(m_hWnd, &m_ofnFile);
      break;
    case IDM_HELP_ABOUT:
      {
        CAboutBox dlgAboutBox;

        // Show the standard About Box dialog for this EXE by telling the
        // dialog C++ object to show itself by invoking its ShowDialog
        // method.  Pass it this EXE instance and the parent window handle.
        // Use a dialog resource ID for the dialog template stored in
        // this EXE module's resources.
        dlgAboutBox.ShowDialog(
          m_hInst,
          MAKEINTRESOURCE(IDM_HELP_ABOUT),
          m_hWnd);
      }
      break;

    default:
      // Defer all messages NOT handled here to the Default Window Proc.
      lResult = ::DefWindowProc(m_hWnd, WM_COMMAND, wParam, lParam);
      break;
  }

  return(lResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMainWindow::WindowProc

  Summary:  Main window procedure for this window object.  See CVirWindow
            in the APPUTIL library (APPUTIL.CPP) for details on how this
            method gets called by the global WindowProc.

  Args:     UINT uMsg,
              Windows message that is "sent" to this window.
            WPARAM wParam,
              First message parameter (word sized).
            LPARAM lParam)
              Second message parameter (long sized).

  Modifies: ...

  Returns:  LRESULT
              Standard Windows WindowProc return value.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
LRESULT CMainWindow::WindowProc(
          UINT uMsg,
          WPARAM wParam,
          LPARAM lParam)
{
  LRESULT lResult = FALSE;

  switch (uMsg)
  {
    case WM_CREATE:
      break;

    case WM_MEASUREITEM:
      // Get setup for painting text in this window.
      {
        LPMEASUREITEMSTRUCT lpmis = (LPMEASUREITEMSTRUCT) lParam;
        lpmis->itemHeight = m_tm.tmHeight + m_tm.tmExternalLeading;
        lpmis->itemWidth = m_wWidth;
        lResult = TRUE;
      }

    case WM_SIZE:
      // Handle a resize of this window.
      m_wWidth = LOWORD(lParam);
      m_wHeight = HIWORD(lParam);
      // Handle a resize of this window.
      // Restart the ball from upper left, clear window.
      m_pGuiBall->Restart();
      break;

    case WM_TIMER:
      // This is our timed attempt to continuously paint the moving ball.
      // It doesn't move it. Other non-GUI threads move the virtual ball.
      m_pGuiBall->PaintBall();
      break;

    case WM_COMMAND:
      // Dispatch and handle any Menu command messages received.
      lResult = DoMenu(wParam, lParam);
      break;

    case WM_CHAR:
      if (wParam == 0x1b)
      {
        // Exit this app if user hits ESC key.
        PostMessage(m_hWnd,WM_CLOSE,0,0);
        break;
      }
    case WM_LBUTTONUP:
    case WM_PAINT:
      // If something major happened or user clicks or hits key then
      // repaint the whole window.
      m_pGuiBall->PaintWin();
      break;

    case WM_CLOSE:
      // The user selected Close on the main window's System menu
      // or Exit on the File menu.
    case WM_QUIT:
      // If the app is being quit then close any associated help windows.
      // ::WinHelp(m_hWnd, m_szHelpFile, HELP_QUIT, 0);
    default:
      // Defer all messages NOT handled here to the Default Window Proc.
      lResult = ::DefWindowProc(m_hWnd, uMsg, wParam, lParam);
      break;
  }

  return(lResult);
}


/*F+F++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: UnicodeOk

  Summary:  Checks if the platform will handle unicode versions of
            Win32 string API calls.

  Args:     void

  Returns:  BOOL
              TRUE if unicode support; FALSE if not.
------------------------------------------------------------------------F-F*/
BOOL UnicodeOk(void)
{
  BOOL bOk = TRUE;
  TCHAR szUserName[MAX_STRING_LENGTH];
  DWORD dwSize = MAX_STRING_LENGTH;

  if (!GetUserName(szUserName, &dwSize))
    bOk = ERROR_CALL_NOT_IMPLEMENTED == GetLastError() ? FALSE : TRUE;

  return bOk;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: InitApplication

  Summary:  Initializes the application and registers its main window
            class. InitApplication is called only once (in WinMain).

  Args:     HINSTANCE hInstance)
              Handle to the first instance of the application.

  Returns:  BOOL.
              TRUE if success.
              FALSE if fail.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL InitApplication(
       HINSTANCE hInstance)
{
  BOOL bOK;
  // The window class for all instances of the main frame window.
  WNDCLASSEX wcf;

  // Assign the appropriate values for this main frame window class.
  wcf.cbSize        = sizeof(WNDCLASSEX);
  wcf.style         = CS_HREDRAW | CS_VREDRAW; // Class style(s).
  wcf.lpfnWndProc   = &WindowProc;             // Global Window Procedure for
                                               // all windows of this class.
  wcf.cbClsExtra    = 0;                       // No per-class extra data.
  wcf.cbWndExtra    = 0;                       // No per-window extra data.
  wcf.hInstance     = hInstance;               // Owner of this class.
  wcf.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);      // Default color.
  wcf.lpszMenuName  = TEXT(MAIN_WINDOW_CLASS_MENU_STR); // Menu name from .RC.
  wcf.lpszClassName = TEXT(MAIN_WINDOW_CLASS_NAME_STR); // Class name from .RC.
  wcf.hCursor       = LoadCursor(NULL, IDC_ARROW);      // Cursor.
  wcf.hIcon         = LoadIcon(                         // Icon name from .RC.
                        hInstance,
                        TEXT("AppIcon"));
  wcf.hIconSm       = (HICON)LoadImage(                        // Load small icon.
                        hInstance,
                        TEXT("AppIcon"),
                        IMAGE_ICON,
                        16, 16,
                        0);

  // Register the window class and return FALSE if unsuccesful.
  bOK = RegisterClassEx(&wcf);
  if (!bOK)
  {
    // If RegisterClassEx() didn't work then try RegisterClass().
    bOK = RegisterClass((LPWNDCLASS)&wcf.style);
  }

  return (bOK);
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: WinMain

  Summary:  The Windows main entry point function for this application.
            Initializes the application, the OLE Libraries, and starts
            the main application message loop.

  Args:     HINSTANCE hInstance,
              Instance handle; a new one for each invocation of this app.
            HINSTANCE hPrevInstance,
              Instance handle of the previous instance. NULL in Win32.
            LPSTR lpCmdLine,
              Windows passes a pointer to the application's
              invocation command line.
            int nCmdShow)
              Bits telling the show state of the application.

  Returns:  int
              msg.wParam (upon exit of message loop).
              FALSE if this instance couldn't initialize and run.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
extern "C" int PASCAL WinMain(
                        HINSTANCE hInstance,
                        HINSTANCE ,
                        LPSTR ,
                        int nCmdShow)
{
  CMainWindow* pWin = NULL;
  MSG msg;
  HACCEL hAccel = NULL;
  int iRun = FALSE;

  // If we were compiled for UNICODE and the platform seems OK with this
  // then proceed.  Else we error and exit the app.
  if (UnicodeOk())
  {
    // Call to initialize the OLE COM Library.  Use the OLE SUCCEEDED macro
    // to detect success.  If fail then exit app with error message.
    // Tell COM that this client process and all subordinate threads
    // will live in a multi-threaded world. This means that all subsequent
    // COM objects created and functioned by this client must be coded
    // to be thread-safe. This is where we tell COM that we are using
    // the "Free-threading" model (rather than the default Apartment Model).
    if (SUCCEEDED(CoInitializeEx(NULL, COINIT_MULTITHREADED)))
    {
      // If we succeeded in initializing the COM Library we proceed to
      // initialize the application.  If we can't init the application
      // then we signal shut down with an error message exit.
      iRun = InitApplication(hInstance);
      if (iRun)
      {
        // Assume we'll set iRun to TRUE when initialization is done.
        iRun = FALSE;
        // We are still go for running so we try to create a nifty new
        // CMainWindow object for this app instance.
        pWin = new CMainWindow;
        if (NULL != pWin)
        {
          // Now we initialize an instance of the new CMainWindow.
          // This includes creating the main window.  Note: if
          // InitInstance fails then it would have already deleted
          // pWin so we wouldn't need to delete it here.
          if (pWin->InitInstance(hInstance, nCmdShow))
          {
            // Load the keyboard accelerators from the resources.
            hAccel = LoadAccelerators(hInstance, TEXT("AppAccel"));
            if (NULL != hAccel)
            {
              // Signal App Initialization is successfully done.
              iRun = TRUE;
            }
          }
        }
	}

      if (iRun)
      {
        // If we initialized the app instance properly then we are still
        // go for running.  We then start up the main message pump for
        // the application.
        while (GetMessage(&msg, NULL, 0, 0))
        {
          if (!TranslateAccelerator(pWin->GetHwnd(), hAccel, &msg))
          {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
          }
        }

        // We also ask COM to unload any unused COM Servers, including our
        // friend, FRESERVE.
        CoFreeUnusedLibraries();

        // We'll pass to Windows the reason why we exited the message loop.
        iRun = (int) msg.wParam;
      }
      else
      {
        // We failed to initialize the application--issue an error
        // messagebox.
        TCHAR szMsg[MAX_STRING_LENGTH];

        // Load the error message string from the resources.
        if (LoadString(
              hInstance,
              IDS_APPINITFAILED,
              szMsg,
              MAX_STRING_LENGTH))
        {
          // Put up error message box saying that application couldn't be
          // initialized.  Parent window is desktop (ie, NULL).
          MessageBox(
            NULL,
            szMsg,
            TEXT(ERROR_TITLE_STR),
            MB_OK | MB_ICONEXCLAMATION);
        }
	  delete pWin;
      }

      // We're exiting this app (either normally or by init failure) so
      // shut down the OLE COM Library.
      CoUninitialize();
    }
    else
    {
      // We failed to Initialize the OLE COM Library.
      TCHAR szMsg[MAX_STRING_LENGTH];

      // Load the error message string from the resources.
      if (LoadString(
            hInstance,
            IDS_OLEINITFAILED,
            szMsg,
            MAX_STRING_LENGTH))
      {
        // Put up error message box saying that OLE COM Library
        // couldn't be initialized.  Parent window is desktop (ie, NULL).
        // And exit the failed application.
        MessageBox(
          NULL,
          szMsg,
          TEXT(ERROR_TITLE_STR),
          MB_OK | MB_ICONEXCLAMATION);
      }
    }
  }
  else
  {
    // If we were compiled for UNICODE but the platform has problems with
    // this then indicate an error and exit the app immediately.
    CHAR szMsg[MAX_STRING_LENGTH];

    if (LoadStringA(
          hInstance,
          IDS_NOUNICODE,
          szMsg,
          MAX_STRING_LENGTH))
    {
      MessageBoxA(
        NULL,
        szMsg,
        ERROR_TITLE_STR,
        MB_OK | MB_ICONEXCLAMATION);
    }
  }

  return iRun;
}
