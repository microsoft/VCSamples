/*+==========================================================================
  File:      APPUTIL.H

  Summary:   Include file for the general application utility classes
             and functions offered by the APPUTIL library.  APPUTIL is
             meant to be statically linked to applications that want
             to exploit it.

             For a comprehensive tutorial code tour of APPUTIL's
             contents and offerings see the accompanying APPUTIL.TXT file.
             For more specific details on the internal workings see the
             comments dispersed throughout the APPUTIL source code.

  Classes:   CVirWindow, CVirDialog, CAboutBox, CMsgBox, CMsgLog,
             CThreaded.

  Functions: WindowProc, DialogProc, FileExist, MakeFamilyPath, CmdExec,
             ReadMe, ReadMeFile, ReadSource, OutputDebugFmt, lRandom,
             UcToAnsi, A_StringFromGUID2, A_WriteFmtUserTypeStg,
             A_StgIsStorageFile, A_StgCreateDocfile, A_StgOpenStorage,
             CreateColorScalePalette, PaintWindow.

  Origin:    7-27-95: atrent - Created based on WINHLPRS by stevebl.

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

// Don't allow recursive includes of this file.
#ifndef APPUTIL_H
#define APPUTIL_H


// This pragma disables the C4355 warning which reads:
//
// "'this': used in base member initializer list."
//
// This warning is triggered by the nested interface implementation
// classes--a coding technique used throughout the sample series.
// The warning says: "The 'this' pointer is only valid within nonstatic
// member functions, but was used in the initializer list for a base class.
// This is a level 1 warning when Microsoft extensions are enabled (/Ze)
// but a level 4 warning otherwise."  The initializer technique is
// necessary for the coding of nested class interface implementations.
// See COMOBJ.TXT for details on the technique.
#pragma warning( disable : 4355 )


// Types that should be in OLE2.H.
#ifndef PPVOID
typedef LPVOID* PPVOID;
#endif

// Convenient macros.

#define DELETE_POINTER(p)\
{\
  if (NULL != p)\
  {\
    delete p;\
    p = NULL;\
  }\
}

#define RELEASE_INTERFACE(p)\
{\
  IUnknown* pTmp = (IUnknown*)p;\
  p = NULL;\
  if (NULL != pTmp)\
    pTmp->Release();\
}

#define GETINSTANCE(hWnd)   (HANDLE)GetWindowLong(hWnd,GWL_HINSTANCE)
#define GETCLASSBRUSH(hWnd) (HBRUSH)GetClassLongPtr(hWnd,GCLP_HBRBACKGROUND)


// Some General defines for Message Boxes and Dialogs
#define GUID_SIZE 128
#define MAX_STRING_LENGTH 256
#define MAXLOGST 128
#define MAX_LOG_LINES 500

#define COLOR_SCALE_RED     1
#define COLOR_SCALE_GREEN   2
#define COLOR_SCALE_BLUE    3
#define COLOR_SCALE_GRAY    4

#define EDITOR_FILE_STR "notepad.exe "
#define OFN_SOURCEFILES_STR "Source Files (*.CPP;*.H;*.RC;*.C;*.MAK;*.TXT;*.)\0*.CPP;*.H;*.RC;*.C;*.MAK;*.TXT;makefile\0"
#define OFN_SOURCETITLE_STR "Open Source File"
#define NOTICE_TITLE_STR "-Notice-"
#define ERROR_TITLE_STR "-Error-"
#define NOEDITOR_ERROR_STR "Can't run editor."
#define NOREADME_ERROR_STR "Can't find .TXT file."
#define ASSERTFAIL_ERROR_STR "Assertion Failed."
#define HELP_FILE_EXT    ".hlp"
#define README_FILE_EXT  ".txt"
#define LICENSE_FILE_EXT ".lic"


#ifdef __cplusplus
// If compiling under C++ Ensure that Windows callbacks are
// undecorated extern C calls.
extern "C" {
#endif


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: WindowProc

  Summary:  Standard WindowProc callback function that forwards Windows
            messages on to the CVirWindow::WindowProc method.  This
            Window procedure expects that it will receive a "this"
            pointer as the lpCreateParams member passed as part of the
            WM_NCCREATE message.  It saves the "this" pointer in the
            GWL_USERDATA field of the window structure.

  Args:     HWND hWnd,
              Window handle
            UINT uMsg,
              Windows message
            WPARAM wParam,
              First message parameter (word sized)
            LPARAM lParam);
              Second message parameter (long sized)

  Returns:  LRESULT.  Windows window procedure callback return value.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
LRESULT CALLBACK WindowProc(
                   HWND hWnd,
                   UINT uMsg,
                   WPARAM wParam,
                   LPARAM lParam);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: DialogProc

  Summary:  The general dialog procedure callback function.  Used by all
            CVirDialog class objects.  This procedure is the DialogProc
            registered for all dialogs created with the CVirDialog class.
            It uses the parameter passed with the WM_INITDIALOG message
            to identify the dialog classes' "this" pointer which it then
            stores in the window structure's GWL_USERDATA field.
            All subsequent messages can then be forwarded on to the
            correct dialog class's DialogProc method by using the pointer
            stored in the GWL_USERDATA field.

  Args:     HWND hWndDlg,
              Handle of dialog box.
            UINT uMsg,
              Message
            WPARAM wParam,
              First message parameter (word sized).
            LPARAM lParam);
              Second message parameter (long sized).

  Returns:  BOOL.  Return of the CVirDialog::DialogProc method.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL CALLBACK DialogProc(
                HWND hWndDlg,
                UINT uMsg,
                WPARAM wParam,
                LPARAM lParam);


#ifdef __cplusplus
}


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CVirWindow

  Summary:  Abstract base class for wrapping a window.

            This class allows a window to be cleanly wrapped in a
            c++ class.  Specifically, it provides a way for a c++ class
            to use one of its methods as a WindowProc, giving it a "this"
            pointer and allowing it to have direct access to all of its
            private members.

  Methods:  Create:
              Maps to Windows' CreateWindow function.
            WindowProc:
              Pure virtual WindowProc for the window.
            Gethwnd:
              Get the handle to the window.
            CVirWindow:
              Constructor.
            ~CVirWindow:
              Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CVirWindow
{
public:
  // Constructor
  CVirWindow()
  {
    m_hWnd = NULL;
    m_hInst = NULL;
  };

  // Destructor
  virtual ~CVirWindow(){};

  // Envelopes the Windows' CreateWindow function call.
  HWND Create(
         LPTSTR lpszClassName,   // Address of registered class name
         LPTSTR lpszWindowName,  // Address of window name
         DWORD dwStyle,          // Window style
         int x,                  // Horizontal position of window
         int y,                  // Vertical position of window
         int nWidth,             // Window width
         int nHeight,            // Window height
         HWND hWndParent,        // Handle of parent or owner window
         HMENU hmenu,            // Handle of menu, or child window identifier
         HINSTANCE hinst);       // Handle of application instance

  // Get the protected handle of this window.
  HWND GetHwnd(void)
  {
    return(m_hWnd);
  }

  // WindowProc is a pure virtual member function and MUST be over-ridden
  // in any derived classes.
  virtual LRESULT WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

protected:
  // Instance handle for this window.
  HINSTANCE m_hInst;
  // Handle of this window.
  HWND m_hWnd;

  // Tell the compiler that the outside WindowProc callback is a friend
  // of this class and can get at its protected data members.
  friend LRESULT CALLBACK ::WindowProc(
                              HWND hWnd,
                              UINT uMsg,
                              WPARAM wParam,
                              LPARAM lParam);
};


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CVirDialog

  Summary:  Abstract base class for wrapping a Windows dialog box window.

            This class allows a dialog box to be cleanly wrapped in
            a c++ class.  Specifically, it provides a way for a c++ class
            to use one of its methods as a DialogProc, giving it a "this"
            pointer and allowing it to have direct access to all of its
            private members.

  Methods:  ShowDialog:
              Maps to Windows' DialogBox function.
            GetHwnd:
              Get the handle to the dialog window.
            DialogProc:
              Pure virtual DialogProc for the dialog box
            ~CVirDialog:
              Destructor
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CVirDialog
{
public:
  // Destructor
  virtual ~CVirDialog(){};

  // ShowDialog creates the Dialog (using the DialogBoxParam API).
  virtual INT_PTR ShowDialog(
                HINSTANCE hInst,
                LPTSTR lpszTemplate,
                HWND hWndOwner);

  // DialogProc is a pure virtual member function and MUST be over-ridden
  // in any derived classes.
  virtual BOOL DialogProc(
                 HWND hWndDlg,
                 UINT uMsg,
                 WPARAM wParam,
                 LPARAM lParam) = 0;

protected:
  HINSTANCE m_hInst;
  HWND m_hWnd;

  // Tell the compiler that the outside DialogProc callback is a friend
  // of this class and can get at its protected data members.
  friend BOOL CALLBACK ::DialogProc(
                           HWND hWndDlg,
                           UINT uMsg,
                           WPARAM wParam,
                           LPARAM lParam);
};


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CAboutBox

  Summary:  A class that implements a common About Dialog Box
            functionality for the APPUTIL library.

  Methods:  DialogProc
              Dialog procedure
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CAboutBox: public CVirDialog
{
public:
  // This DialogProc method definition overrides the same-named pure
  // virtual function in abstract base class CVirDialog thus giving
  // AboutBox-unique message dispatching behavior to this derivation
  // of CVirDialog.  The remaining behavior of CAboutBox is inherited
  // from CVirDialog and is common to all CVirDialogs.
  BOOL DialogProc(
         HWND hWndDlg,
         UINT uMsg,
         WPARAM wParam,
         LPARAM lParam);
};


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CMsgBox

  Summary:  Class for showing messages in a Message Box dialog.  Uses the
            standard Windows MessageBox function but retrieves the box
            title and message strings from the application's resources
            using specified resource IDs.  These message boxes have only
            an OK button.

  Methods:  Init
              Initializes the owner window and the module instance.
            Error
              Shows a message string in an Error MessageBox Dialog.
            ErrorID
              Shows a resource message string in an Error MessageBox Dialog.
            Note
              Shows a message string in a Notice MessageBox Dialog.
            NoteID
              Shows a resource message string in a Notice MessageBox Dialog.
            NoteFmt
              Shows a printf-style formatted message string in a Notice
              MessageBox Dialog.
            NoteFmtID
              Shows a printf-style formatted resource message string in a
              Notice MessageBox Dialog.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CMsgBox
{
public:
  // Constructor.
  CMsgBox()
  {
    m_hInst = 0;
    m_hWndOwner = 0;
  };

  BOOL Init(HINSTANCE hInst, HWND hWndOwner);
  int  Error(LPTSTR szMsg);
  int  ErrorID(UINT uMsgID);
  int  Note(LPTSTR szMsg);
  int  NoteID(UINT uMsgID);
  int  NoteFmt(LPTSTR szFmtMsg, ...);
  int  NoteFmtID(UINT uMsgID, ...);

private:
  // Remember the App Instance Handle.
  HINSTANCE m_hInst;
  // Remember the Owner Window Handle.
  HWND m_hWndOwner;
};


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CMsgLog

  Summary:  Class for logging messages to a Listbox.  This is for tutorial
            code samples that employ debug messages to announce internal
            activity in the code being studied.  When used, this Message
            Log listbox occupies the entire client area of the parent
            window.  The various message output functions use string
            resource IDs to retrieve the message strings from the app's
            resources.

  Methods:  Create
              Creates the Trace Message Log ListBox window.
            Logging
              Toggles logging on or off.
            Msg
              Logs a message as a separate line.
            MsgFmt
              Logs a printf-style formated message as a separate line.
            Resize
              Resizes the listbox to a new width and height.
            Clear
              Clears all logged messages from the message log.
            CMsgLog
              Constructor.
            ~CMsgLog
              Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CMsgLog
{
public:
  // Constructor.
  CMsgLog()
  {
    m_hInstLog = 0;
    m_hWndLog = 0;
    m_bChild = FALSE;
    m_bLogging = FALSE;
    m_hLogData = 0;
  };

  BOOL Create(HINSTANCE hInst, HWND hWndParent, BOOL bChild);
  BOOL Logging(BOOL bLogging);
  BOOL Msg(LPTSTR szMsg);
  BOOL MsgFmt(LPTSTR szFmtMsg, ...);
  BOOL MsgID(int iMsgID);
  BOOL MsgFmtID(int iFmtID, ...);
  BOOL Resize(int nWidth, int nHeight);
  BOOL Clear(void);
  BOOL Copy(void);

private:
  // Remember the App Instance Handle.
  HINSTANCE m_hInstLog;
  // Remember the handle of the listbox window.
  HWND m_hWndLog;
  // Remember if CMsgLog was created as child window.
  BOOL m_bChild;
  // Remember whether logging or not.
  BOOL m_bLogging;
  // Remember the global handle to clipboard data.
  HGLOBAL m_hLogData;
};


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CSendLog

  Summary:  Class for logging messages to a CMsgLog facility in another
            application process. This is for tutorial code samples that
            employ debug messages to announce internal activity in the
            code being studied.  Uses the WM_COPYDATA message of the
            Win32 SendMessage API.

  Methods:  CreateServerLog
              Initializes the SendLog facility and creates the Trace
              Message Log ListBox window shown in the local server app.
            SetClient
              Sets destination client window handle.
            LogToServer
              Set whether logging is to local server or to client.
            Msg
              Logs a message as a separate line.
            MsgFmt
              Logs a printf-style formated message as a separate line.
            Resize
              Resizes the listbox to a new width and height.
            Clear
              Clears all logged messages from the message log.
            CSendLog
              Constructor.
            ~CSendLog
              Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CSendLog
{
public:
  // Constructor.
  CSendLog()
  {
    m_hInstSender = 0;
    m_hWndSender = 0;
    m_hWndReceiver = 0;
    m_hWndListBox = 0;
    m_bLogToServer = FALSE;
    m_bChild = FALSE;
    m_hLogData = 0;
  };

  BOOL CreateServerLog(HINSTANCE hInst, HWND hWndParent, BOOL bChild);
  BOOL SetClient(HINSTANCE hInstSender, HWND hWndSender, HWND hWndReceiver);
  BOOL LogToServer(BOOL bLogToServer);
  BOOL Msg(LPTSTR szMsg);
  BOOL MsgFmt(LPTSTR szFmtMsg, ...);
  BOOL MsgID(int iMsgID);
  BOOL MsgFmtID(int iFmtID, ...);
  BOOL Resize(int nWidth, int nHeight);
  BOOL Clear(void);
  BOOL Copy(void);

private:
  // Remember the Sender App Instance Handle.
  HINSTANCE m_hInstSender;
  // Remember the handle of the sending application main window.
  HWND m_hWndSender;
  // Remember the handle of the destination receiving window.
  HWND m_hWndReceiver;
  // Remember the handle of the server's listbox window.
  HWND m_hWndListBox;
  // Boolean for logging to client or logging to server.
  BOOL m_bLogToServer;
  // Remember if CMsgLog was created as child window.
  BOOL m_bChild;
  // Remember the global handle to clipboard data.
  HGLOBAL m_hLogData;
};


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CThreaded

  Summary:  Derive a class from this class to provide multi-threaded
            access to objects of the derived class. This is a utility
            base class providing useful methods for achieving mutually
            exclusive access to data in objects of the derived class.

  Methods:  OwnThis
              Blocks executing thread until access to this object is
              permitted at which point the thread "owns" this object.
            UnOwnThis
              Executed by owning thread to relinquish ownership of
              this object.
            CThreaded
              Constructor. Creates mutex to govern mutually exclusive
              access to data in this object by multiple threads.
            ~CThreaded
              Destructor. Destroys mutex.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CThreaded
{
  protected:
    // Variables for providing mutually exclusive access by multiple
    // threads to objects of classes derived from this class.
    HANDLE m_hOwnerMutex;
    BOOL   m_bOwned;

  public:
    // Methods.
    CThreaded(void) :
      m_hOwnerMutex(CreateMutex(0,FALSE,0)),
      m_bOwned(FALSE)
    {
    };

    ~CThreaded(void)
    {
      // Close down the mutex.
      CloseHandle(m_hOwnerMutex);
    };

    // The following virtual functions have overriding definitions in
    // the derived class to provide convenient trace logging. Rely on
    // the below default definitions for non-tutorial applications.

    virtual BOOL OwnThis(void)
    {
      BOOL bOwned = FALSE;

      if (WAIT_OBJECT_0 == WaitForSingleObject(m_hOwnerMutex, INFINITE))
        m_bOwned = bOwned = TRUE;

      return bOwned;
    };

    virtual void UnOwnThis(void)
    {
      if (m_bOwned)
      {
        m_bOwned = FALSE;
        ReleaseMutex(m_hOwnerMutex);
      }

      return;
    };
};


#endif //__cplusplus


#if !defined(UNICODE)

/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: UcToAnsi

  Summary:  Convert an UNICODE input string to an output ANSI string for
            specified number of characters.

  Args:     LPWSTR pszUnicodeString
              Pointer to an input wide UNICODE string.
            LPSTR pszAnsiString
              Pointer to output ANSI string.
            int cch
              Character count. If cch == 0 then all input characters are
              converted.

  Returns:  HRESULT
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
HRESULT UcToAnsi(
          LPWSTR pszUc,
          LPSTR pszAnsi,
          int cch);


/*---------------------------------------------------------------------------
  Here are some surrogate API macro prototypes--all names begin with A_.
  These are for use when the code sample is being compiled for ANSI
  strings (the default) and the calls they stand in place of only support
  UNICODE (thus forcing some string conversions from ANSI to UNICODE
  before the real call is made inside the surrogate). For example, if
  UNICODE is NOT defined during the compile then any calls in the samples
  to the OLE StringFromGUID2 function are actually changed (by the below
  macros) into calls to an A_StringFromGUID2 function implemented in
  APPUTIL. This function accepts the ANSI input string pointer, calls the
  actual OLE StringFromGUID2 call, and does the necessary Unicode to ANSI
  conversion. Other A_ calls will convert input ANSI strings to Unicode
  strings prior to calling the actual OLE function.
---------------------------------------------------------------------------*/

STDAPI A_StringFromGUID2(REFGUID, LPSTR, int);

STDAPI A_WriteFmtUserTypeStg(IStorage*, CLIPFORMAT, LPSTR);

STDAPI A_StgIsStorageFile(LPSTR);
STDAPI A_StgCreateDocfile(LPSTR, DWORD, DWORD, IStorage**);
STDAPI A_StgOpenStorage(LPSTR, IStorage*, DWORD, SNB, DWORD, IStorage**);

#if !defined(_NOANSIMACROS_)

#undef StringFromGUID2
#define StringFromGUID2(a, b, c) A_StringFromGUID2(a, b, c)

#undef WriteFmtUserTypeStg
#define WriteFmtUserTypeStg(a, b, c) A_WriteFmtUserTypeStg(a, b, c)

#undef StgIsStorageFile
#define StgIsStorageFile(a) A_StgIsStorageFile(a)

#undef StgCreateDocfile
#define StgCreateDocfile(a, b, c, d) A_StgCreateDocfile(a, b, c, d)

#undef StgOpenStorage
#define StgOpenStorage(a, b, c, d, e, f) A_StgOpenStorage(a, b, c, d, e, f)

#endif

#endif


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: lRandom

  Summary:  Simple random number generator. Returns a random DWORD.

  Args:     void

  Returns:  DWORD
              Random number.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
DWORD lRandom(void);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: CreateColorScalePalette

  Summary:  This routine creates a palette representing the scale values
            of a particular RGB color.  A gray-scale palette can also be
            created.

  Args:     HDC hDC,
              Handle to device context.
            int nColor
              New color.

  Returns:  HPALETTE
              Handle to new pallete.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
HPALETTE CreateColorScalePalette(HWND hDC, int nColor);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: PaintWindow

  Summary:  This routine is used to wash the background of a window.

  Args:     HWND hWnd,
              Window handle.
            int nColor
              New window color.

  Returns:  void.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
VOID PaintWindow(HWND hWnd, int nColor);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: FileExist

  Summary:  Function to test for the existance of a file.

  Args:     TCHAR* szFileName
              String pointer to file's path/name.

  Returns:  BOOL.  TRUE if file exists; FALSE if not.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL FileExist(TCHAR *szFileName);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: MakeFamilyPath

  Summary:  Function to make a family file/path/name string using the
            detetected pathname of the current executable module.

  Args:     HINSTANCE hInst
              Handle to the module intstance.
            TCHAR* pszNewPath
              String pointer to the new path/name.
            int nPathLength
              Length of pszNewPath.
            TCHAR* pszFileExt
              String pointer to the filename extension for the new path.

  Returns:  BOOL.  TRUE if success; FALSE if not.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL MakeFamilyPath(
       HINSTANCE hInst,
       TCHAR* pszNewPath,
       int nPathLength,
       TCHAR* pszFileExt);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: CmdExec

  Summary:  Execute an EXE Win32 program by creating a process and
            running the specified EXE in it.  A Unicode version of
            WinExec that always has SW_SHOW.

  Args:     LPTSTR szCmd,
              Entire command line (eg, "notepad.exe mytext.txt")

  Returns:  BOOL
              TRUE if succeed; FALSE if fail.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL CmdExec(
       LPTSTR szCmd);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: ReadMe

  Summary:  For use by code sample applications that study themselves as
            it were.  This function assumes a "family" named <sample>.TXT
            "readme" text file is located next to the main .EXE file for
            the code sample.  This function launches a reader/editor on
            that text file.  The default editor\reader is NOTEPAD.EXE.
            You can change that editor by changing EDITOR_FILE_STR in
            APPUTIL.H above.

  Args:     HINSTANCE hInst,
              Handle of the executable module instance.
            HWND hWndOwner,
              Handle to owner parent window.

  Returns:  void
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
void ReadMe(
       HINSTANCE hInst,
       HWND hWndOwner);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: ReadMeFile

  Summary:  For use by code sample applications that study themselves
            as it were.  This function allows you to pass a filename for
            the <sample>.TXT "readme" file associated with the code sample
            and to launch a reader/editor on that file.  The default
            editor\reader is NOTEPAD.EXE.  You can change that editor by
            changing EDITOR_FILE_STR in APPUTIL.H above.

  Args:     HWND hWndOwner,
              Handle to owner parent window.
            LPTSTR szFileName,
              Filename string.

  Returns:  void
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
void ReadMeFile(
       HWND hWndOwner,
       LPTSTR szFileName);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: ReadSource

  Summary:  For use by code sample applications that study themselves
            as it were.  This function allows you to select one of the
            source files of this code sample and launch a reader to
            edit/read it.  NOTEPAD.EXE is the default editor/reader.
            You can change this by changing EDITOR_FILE_STR in
            APPUTIL.H above.

  Args:     HWND hWndOwner
              Handle of parent window.
            OPENFILENAME* pofn,
              Pointer to the Open File Name Common Dialog structure.

  Returns:  void
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
void ReadSource(
       HWND hWndOwner,
       OPENFILENAME* pOfn);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: OutputDebugFmt

  Summary:  Wraps the Win32 OutputDebugString API call to provide
            printf-style formatted (and variable argument) output.

  Args:     LPTSTR szFmt,
              Format string.
            [...]
              Arguments to match those specified in the format string.

  Returns:  void
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
void OutputDebugFmt(
       LPTSTR szFmt,
       ...);


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: GetErrorMsg

  Summary:  Accepts a Win32 error code and retrieves a human readable
            system message for it.

  Args:     HRESULT hr
              SCODE error code.
            LPTSTR pszMsg
              Pointer string where message will be placed.
            UINT uiSize
              Max size of the msg string.

  Returns:  BOOL
              TRUE if hr was error; FALSE if not.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL GetErrorMsg(
       HRESULT hr,
       LPTSTR pszMsg,
       UINT uiSize);


#define TID GetCurrentThreadId()

#if defined(_DEBUG)

//Basic debug and logging macros

// Output debug string; literal or variable.
#define ODS(sMsg) \
{\
  TCHAR szDebug[MAXLOGST];\
  OutputDebugFmt(TEXT("%s"),TEXT(sMsg));\
  _stprintf_s(szDebug, MAXLOGST, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
  OutputDebugString(szDebug);\
}

// Output debug string formatted; one argument.
#define ODF1(sFmt,x) \
{\
  TCHAR szDebug[MAXLOGST];\
  OutputDebugFmt(TEXT(sFmt),x);\
  _stprintf_s(szDebug, MAXLOGST, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
  OutputDebugString(szDebug);\
}

// Output debug string formatted; two argument.
#define ODF2(sFmt,x,y) \
{\
  TCHAR szDebug[MAXLOGST];\
  OutputDebugFmt(TEXT(sFmt),x,y);\
  _stprintf_s(szDebug, MAXLOGST, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
  OutputDebugString(szDebug);\
}

// Output debug string formatted; three argument.
#define ODF3(sFmt,x,y,z) \
{\
  TCHAR szDebug[MAXLOGST];\
  OutputDebugFmt(TEXT(sFmt),x,y,z);\
  _stprintf_s(szDebug, MAXLOGST, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
  OutputDebugString(szDebug);\
}

// Check condition and Output assertion failed message to debugger.
#define ASSERT(condition) \
{\
  if (!(condition))\
    ODS(TEXT("Assertion Failed"));\
}

// Log debug string (output both to Message Log and to Debugger)
#define LOG(sMsg) \
{\
  TCHAR szDebug[MAXLOGST];\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->Msg(TEXT(sMsg));\
  _stprintf_s(szDebug, MAXLOGST, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
  OutputDebugString(szDebug);\
}

// Log debug string (output both to Message Log and to Debugger).
// One argument.
#define LOGF1(sFmt,x) \
{\
  TCHAR szDebug[MAXLOGST];\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->MsgFmt(TEXT(sFmt),x);\
  _stprintf_s(szDebug, MAXLOGST, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
  OutputDebugString(szDebug);\
}

// Log debug string (output both to Message Log and to Debugger).
// Two argument.
#define LOGF2(sFmt,x,y) \
{\
  TCHAR szDebug[MAXLOGST];\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->MsgFmt(TEXT(sFmt),x,y);\
  _stprintf_s(szDebug, MAXLOGST, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
  OutputDebugString(szDebug);\
}

// Log debug string (output both to Message Log and to Debugger).
// Three argument.
#define LOGF3(sFmt,x,y,z) \
{\
  TCHAR szDebug[MAXLOGST];\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->MsgFmt(TEXT(sFmt),x,y,z);\
  _stprintf_s(szDebug, MAXLOGST, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
  OutputDebugString(szDebug);\
}

// Log error message string (output both to Message Log and to Debugger).
// One argument. Pfx = Prefix msg string; Ec = error code.
#define LOGERROR(Pfx,Ec) \
{\
  TCHAR szMsg[MAX_PATH];\
  if (NULL!=g_pMsgLog && GetErrorMsg(Ec,szMsg,MAX_PATH))\
  {\
    g_pMsgLog->MsgFmt(TEXT("%s Error=0x%X: %s"),TEXT(Pfx),Ec,szMsg);\
    _stprintf_s(szMsg, MAX_PATH, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
    OutputDebugString(szMsg);\
  }\
}

// Log debug string (output both to Message Log and to Debugger).
// Use a string resource ID to retrieve the display string.
#define LOGID(id) \
{\
  TCHAR szDebug[MAXLOGST];\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->MsgID(id);\
  _stprintf_s(szDebug, MAXLOGST, TEXT(" [%s, %u]\r\n"), (LPTSTR)__FILE__, __LINE__);\
  OutputDebugString(szDebug);\
}

// Log assertion failure.
#define LOGASSERT(condition) \
{\
  if (!(condition))\
    LOGID(IDS_ASSERT_FAIL);\
}

#else  // !defined(_DEBUG)

#define ODS(x)

#define ODF1(sFmt,x)

#define ODF2(sFmt,x,y)

#define ODF3(sFmt,x,y,z)

#define ASSERT(condition)

#define LOG(sMsg) \
{\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->Msg(TEXT(sMsg));\
}

// Log debug string (output both to Message Log and not to Debugger).
// One argument.
#define LOGF1(sFmt,x) \
{\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->MsgFmt(TEXT(sFmt),x);\
}

// Log debug string (output both to Message Log and not to Debugger).
// Two argument.
#define LOGF2(sFmt,x,y) \
{\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->MsgFmt(TEXT(sFmt),x,y);\
}

// Log debug string (output both to Message Log and not to Debugger).
// Three argument.
#define LOGF3(sFmt,x,y,z) \
{\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->MsgFmt(TEXT(sFmt),x,y,z);\
}

// Log error message string (output both to Message Log and not to Debugger).
// One argument. Pfx = Prefix msg string; Ec = error code.
#define LOGERROR(Pfx,Ec) \
{\
  TCHAR szMsg[MAX_PATH];\
  if (NULL!=g_pMsgLog && GetErrorMsg(Ec,szMsg,MAX_PATH))\
    g_pMsgLog->MsgFmt(TEXT("%s Error=0x%X: %s"),TEXT(Pfx),Ec,szMsg);\
}

// Log debug string (output both to Message Log and not to Debugger).
// Use a string resource ID to retrieve the display string.
#define LOGID(id) \
{\
  if (NULL!=g_pMsgLog)\
    g_pMsgLog->MsgID(id);\
}

// Log assertion failure.
#define LOGASSERT(condition)\
{\
  if (!(condition))\
    LOGID(IDS_ASSERT_FAIL);\
}

#endif // _DEBUG

#endif //APPUTIL_H
