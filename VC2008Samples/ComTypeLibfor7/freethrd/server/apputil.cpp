/*+==========================================================================
  File:      APPUTIL.CPP

  Summary:   Implementation file for the general application utility
             classes and functions offered by the APPUTIL library.

             For a comprehensive tutorial code tour of APPUTIL's
             contents and offerings see the accompanying APPUTIL.TXT file.
             For more specific details see the comments dispersed
             throughout the APPUTIL source code.

  Classes:   CVirWindow, CVirDialog, CAboutBox, CMsgBox, CMsgLog

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

/*---------------------------------------------------------------------------
  We include WINDOWS.H for all Win32 applications.
  We include TCHAR.H for general Unicode/Ansi prototype of utility
    functions like _tsplitpath, etc.
  We include APPUTIL.H for the defines of this APPUTIL library.  We use
    the _NOANSIMACROS_ to turn off the ANSI macro undefines so that
    function calls to certain OLE APIs inside this module get to the
    original OLE functions instead of the ANSI surrogates.
---------------------------------------------------------------------------*/

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdarg.h>
#define _NOANSIMACROS_
#include "apputil.h"

#if !defined(UNICODE)

/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: UcToAnsi

  Summary:  Convert a UNICODE input string to an output ANSI string.

  Args:     LPWSTR pszUc
              Pointer to a caller's input UNICODE wide string.
            LPSTR pszAnsi
              Pointer to a caller's output ANSI string.
            int cch
              Character count. If 0 then use length of pszUc.

  Returns:  HRESULT
              Standard OLE result code. NOERROR for success.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
HRESULT UcToAnsi(
          LPWSTR pszUc,
          LPSTR pszAnsi,
          int cch)
{
  HRESULT hr = E_FAIL;
  int cSize;
  int cOut;

  if (0 == cch)
    cSize = WideCharToMultiByte(CP_ACP,0,pszUc,-1,NULL,0,NULL,NULL);
  else
    cSize = cch;

  if (0 != cSize)
  {
    cOut = WideCharToMultiByte(CP_ACP,0,pszUc,-1,pszAnsi,cSize,NULL,NULL);
    if (0 != cOut)
      hr = NOERROR;
  }

  return hr;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: A_StringFromGUID2

  Summary:  ANSI Surrogate for the OLE Unicode API call.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
STDAPI A_StringFromGUID2(REFGUID guid, LPSTR pszGUID, int cch)
{
  HRESULT hr = E_INVALIDARG;
  LPWSTR  pszUc;
  IMalloc* pIMalloc;

  if (NULL != pszGUID && 0 < cch)
  {
    hr = CoGetMalloc(MEMCTX_TASK, &pIMalloc);
    if (SUCCEEDED(hr))
    {
      pszUc = (LPWSTR)pIMalloc->Alloc((cch+1)*sizeof(TCHAR));
      pIMalloc->Release();
      if (NULL != pszUc)
      {
        hr = StringFromGUID2(guid, pszUc, cch);
        if (SUCCEEDED(hr))
          hr = UcToAnsi(pszUc, pszGUID, cch);
        CoTaskMemFree((void *)pszUc);
      }
      else
        hr = E_OUTOFMEMORY;
    }
  }

  return hr;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: A_WriteFmtUserTypeStg

  Summary:  ANSI Surrogate for the OLE Unicode API call.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
STDAPI A_WriteFmtUserTypeStg(
         IStorage* pIStorage,
         CLIPFORMAT ClipFmt,
         LPSTR pszUserType)
{
  HRESULT hr = E_INVALIDARG;
  WCHAR szUc[MAX_PATH];

  if (NULL != pszUserType)
  {
    MultiByteToWideChar(CP_ACP, 0, pszUserType, -1, szUc, MAX_PATH);
    hr = WriteFmtUserTypeStg(pIStorage, ClipFmt, szUc);
  }

  return hr;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: A_StgIsStorageFile

  Summary:  ANSI Surrogate for the OLE Unicode API call.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
STDAPI A_StgIsStorageFile(
         LPSTR pszFileName)
{
  HRESULT hr = E_INVALIDARG;
  WCHAR szUc[MAX_PATH];

  if (NULL != pszFileName)
  {
    MultiByteToWideChar(CP_ACP, 0, pszFileName, -1, szUc, MAX_PATH);
    hr = StgIsStorageFile(szUc);
  }

  return hr;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: A_StgCreateDocfile

  Summary:  ANSI Surrogate for the OLE Unicode API call.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
STDAPI A_StgCreateDocfile(
         LPSTR pszFileName,
         DWORD dwAccessMode,
         DWORD reserved,
         IStorage** ppIStorage)
{
  HRESULT hr = E_INVALIDARG;
  WCHAR szUc[MAX_PATH];
  LPWSTR pszUc = NULL;

  // Null the caller's output variable.
  *ppIStorage = NULL;

  if (NULL != pszFileName)
  {
    MultiByteToWideChar(CP_ACP, 0, pszFileName, -1, szUc, MAX_PATH);
    pszUc = szUc;
  }

  hr = StgCreateDocfile(pszUc, dwAccessMode, reserved, ppIStorage);

  return hr;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: A_StgOpenStorage

  Summary:  ANSI Surrogate for the OLE Unicode API call.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
STDAPI A_StgOpenStorage(
         LPSTR pszFileName,
         IStorage* pIStorage,
         DWORD dwAccessMode,
         SNB snbExclude,
         DWORD reserved,
         IStorage** ppIStorage)
{
  HRESULT hr = E_INVALIDARG;
  WCHAR szUc[MAX_PATH];
  LPWSTR pszUc = NULL;

  // Null the caller's output variable.
  *ppIStorage = NULL;

  if (NULL != pszFileName)
  {
    MultiByteToWideChar(CP_ACP, 0, pszFileName, -1, szUc, MAX_PATH);
    pszUc = szUc;
  }

  hr = StgOpenStorage(
         pszUc,
         pIStorage,
         dwAccessMode,
         snbExclude,
         reserved,
         ppIStorage);

  return hr;
}


#endif  // !UNICODE


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: lRandom

  Summary:  Simple random number generator. Returns a random DWORD.

  Args:     void

  Returns:  DWORD
              Random number.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
DWORD lRandom(void)
{
  static DWORD glSeed = (DWORD)-365387184;

  glSeed *= 69069;

  return(++glSeed);
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: CreateColorScalePalette

  Summary:  This routine creates a palette representing the scale values
            of a particular RGB color.  A gray-scale palette can also be
            created. Borrowed from GDIDEMO in the Win32 samples of the
            Win32 SDK.

  Args:     HDC hDC,
              Handle to device context.
            int nColor
              New color.

  Returns:  HPALETTE
              Handle to new pallete.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
HPALETTE CreateColorScalePalette(HDC hDC, int nColor)
{
  HPALETTE     hPalette;
  GLOBALHANDLE hMem;
  LPLOGPALETTE lpMem;
  int          nReserved;
  unsigned int idx,nSize;

  hPalette = NULL;
  if(GetDeviceCaps(hDC,RASTERCAPS) & RC_PALETTE)
  {
    nReserved = GetDeviceCaps(hDC,NUMRESERVED);
    nSize     = GetDeviceCaps(hDC,SIZEPALETTE) - nReserved;

    if((DWORD)sizeof(LOGPALETTE)+(sizeof(PALETTEENTRY)*nSize) > nSize)
    {
      hMem = GlobalAlloc(
               GHND,
               (DWORD)sizeof(LOGPALETTE)+(sizeof(PALETTEENTRY)*nSize));
      if(hMem)
      {
        lpMem = (LPLOGPALETTE)GlobalLock(hMem);
      
        if(lpMem)
        {
          lpMem->palNumEntries = (WORD)nSize;
          lpMem->palVersion    = (WORD)0x0300;
          switch(nColor)
          {
            case COLOR_SCALE_RED:
              for(idx=0; idx < nSize; idx++)
              {
                lpMem->palPalEntry[idx].peRed   = (BYTE)idx;
                lpMem->palPalEntry[idx].peGreen = 0;
                lpMem->palPalEntry[idx].peBlue  = 0;
                lpMem->palPalEntry[idx].peFlags = PC_RESERVED;
              }
              break;

            case COLOR_SCALE_GREEN:
              for(idx=0; idx < nSize; idx++)
              {
                lpMem->palPalEntry[idx].peRed   = 0;
                lpMem->palPalEntry[idx].peGreen = (BYTE)idx;
                lpMem->palPalEntry[idx].peBlue  = 0;
                lpMem->palPalEntry[idx].peFlags = PC_RESERVED;
              }
              break;

            case COLOR_SCALE_BLUE:
              for(idx=0; idx < nSize; idx++)
              {
                lpMem->palPalEntry[idx].peRed   = 0;
                lpMem->palPalEntry[idx].peGreen = 0;
                lpMem->palPalEntry[idx].peBlue  = (BYTE)idx;
                lpMem->palPalEntry[idx].peFlags = PC_RESERVED;
              }
              break;

            default:
            case COLOR_SCALE_GRAY:
              for(idx=0; idx < nSize; idx++)
              {
                lpMem->palPalEntry[idx].peRed   = (BYTE)idx;
                lpMem->palPalEntry[idx].peGreen = (BYTE)idx;
                lpMem->palPalEntry[idx].peBlue  = (BYTE)idx;
                lpMem->palPalEntry[idx].peFlags = PC_RESERVED;
              }
              break;
          }

          hPalette = CreatePalette(lpMem);

          GlobalUnlock(hMem);
        }
        GlobalFree(hMem);
      }
    }
  }

  return(hPalette);
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: PaintWindow

  Summary:  This routine is used to paint the background of a window.
            Borrowed from GDIDEMO in the Win32 samples of the Win32 SDK.

  Args:     HWND hWnd,
              Window handle.
            int nColor
              New window color.

  Returns:  void.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
VOID PaintWindow(HWND hWnd, int nColor)
{
  HDC         hDC;
  int         nMapMode,idx,nSize,nReserved,nLoop;
  RECT        rect;
  HBRUSH      hBrush;
  PAINTSTRUCT ps;
  HPALETTE    hPal;

  hDC = BeginPaint(hWnd,&ps);
  if(hDC)
  {
    GetClientRect(hWnd,&rect);
    nMapMode = SetMapMode(hDC,MM_ANISOTROPIC);

    if(GetDeviceCaps(hDC,RASTERCAPS) & RC_PALETTE)
    {
      nReserved = GetDeviceCaps(hDC,NUMRESERVED);
      nSize     = GetDeviceCaps(hDC,SIZEPALETTE) - nReserved;

      hPal = CreateColorScalePalette(hDC,nColor);
      
      if(hPal)
      {
        hPal = SelectPalette(hDC,hPal,FALSE);
        RealizePalette(hDC);

        SetWindowExtEx(hDC,nSize,nSize,NULL);
        SetViewportExtEx(hDC,rect.right,-rect.bottom,NULL);
        SetViewportOrgEx(hDC,0,rect.bottom,NULL);

        nLoop = nSize >> 1;
        for(idx=0; idx < nLoop; idx++)
        {
          hBrush = CreateSolidBrush(PALETTEINDEX(idx+nLoop));
          SetRect(&rect,idx,idx,nSize-idx,nSize-idx);
          FillRect(hDC,&rect,hBrush);
          DeleteObject(hBrush);
        }
        DeleteObject(SelectPalette(hDC,hPal,FALSE));
        RealizePalette(hDC);
      }
    }
    else
    {
      SetWindowExtEx(hDC,512,512,NULL);
      SetViewportExtEx(hDC,rect.right,-rect.bottom,NULL);
      SetViewportOrgEx(hDC,0,rect.bottom,NULL);

      for(idx=0; idx < 256; idx++)
      {
        hBrush = CreateSolidBrush(RGB(0,0,idx));
        SetRect(&rect,idx,idx,512-idx,512-idx);
        FillRect(hDC,&rect,hBrush);
        DeleteObject(hBrush);
      }
    }

    SetMapMode(hDC,nMapMode);

    EndPaint(hWnd,&ps);
  }

  return;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: FileExist

  Summary:  Function to test for the existance of a file.

  Args:     TCHAR* pszFileName
              String pointer to file's path/name.

  Returns:  BOOL.  TRUE if file exists; FALSE if not.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL FileExist(TCHAR* pszFileName)
{
  BOOL bExist = FALSE;
  HANDLE hFile;

  if (NULL != pszFileName)
  {
    // Use the preferred Win32 API call and not the older OpenFile.
    hFile = CreateFile(
              pszFileName,
              GENERIC_READ,
              FILE_SHARE_READ | FILE_SHARE_WRITE,
              NULL,
              OPEN_EXISTING,
              0,
              0);

    if (hFile != INVALID_HANDLE_VALUE)
    {
      // If the handle is valid then the file exists.
      CloseHandle(hFile);
      bExist = TRUE;
    }
  }

  return (bExist);
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: MakeFamilyPath

  Summary:  Function to make a family file/path/name string using the
            detetected pathname of the current executable module.
            Makes paths like d:\dir1\dir2\mymodule.hlp,
            d:\dir1\dir2\mymodule.lic, etc.

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
       TCHAR* pszFileExt)
{
  BOOL bOk = FALSE;
  TCHAR  szPath[MAX_PATH];
  TCHAR  szDrive[64];
  TCHAR  szDir[MAX_PATH];
  TCHAR  szName[64];

  if (NULL != pszNewPath)
  {
    pszNewPath[0] = 0;

    bOk = (0 != GetModuleFileName(hInst, szPath, MAX_PATH));
    if (bOk)
    {
      _tsplitpath_s(szPath, szDrive, 64, szDir, MAX_PATH, szName, 64, NULL, 0);
      _tcscpy_s(pszNewPath, nPathLength, szDrive);
      _tcscat_s(pszNewPath, nPathLength, szDir);
      _tcscat_s(pszNewPath, nPathLength, szName);
      _tcscat_s(pszNewPath, nPathLength, pszFileExt);
    }
  }

  return bOk;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: CmdExec

  Summary:  Execute an EXE Win32 program by creating a process and
            running the specified EXE in it.

  Args:     LPTSTR szCmd,
              Entire command line (eg, "notepad.exe mytext.txt")

  Returns:  BOOL
              TRUE if succeed; FALSE if fail.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL CmdExec(
       LPTSTR szCmd)
{
  BOOL bOk;
  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  // Execute the command with a call to the CreateProcess API call.
  memset(&si,0,sizeof(STARTUPINFO));
  si.cb = sizeof(STARTUPINFO);
  si.wShowWindow = SW_SHOW;
  bOk = CreateProcess(NULL,szCmd,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
  CloseHandle(pi.hThread);
  CloseHandle(pi.hProcess);

  return bOk;
}


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
       HWND hWndOwner)
{
  TCHAR szReadCmd[MAX_PATH+12];
  TCHAR szFileName[MAX_PATH];
  BOOL bOk;
  int iResult;

  // Build a path to where the .TXT file should be (it should be in
  // the same directory as the .EXE but with the .TXT extension.
  MakeFamilyPath(hInst, szFileName, MAX_PATH, TEXT(README_FILE_EXT));

  // First check if the readme .TXT file is there at all.
  if (FileExist(szFileName))
  {
    // If the text file is there then assemble a command string.
    _tcscpy_s(szReadCmd, MAX_PATH+12, TEXT(EDITOR_FILE_STR));
    _tcscat_s(szReadCmd, MAX_PATH+12, szFileName);
    // And execute it.
    bOk = CmdExec(szReadCmd);
    if (!bOk)
    {
      // If create procees failed then put up an error box.
      iResult = MessageBox(
                  hWndOwner,
                  TEXT(NOEDITOR_ERROR_STR),
                  TEXT(ERROR_TITLE_STR),
                  MB_OK | MB_ICONEXCLAMATION);
    }
  }
  else
  {
    // If the .TXT file doesn't exist the put up an error box.
    iResult = MessageBox(
                hWndOwner,
                TEXT(NOREADME_ERROR_STR),
                TEXT(ERROR_TITLE_STR),
                MB_OK | MB_ICONEXCLAMATION);
  }

  return;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: ReadMeFile

  Summary:  For use by code sample applications that study themselves
            as it were.  This function allows you to pass a filename for
            the <sample>.TXT "readme" file associated with the code sample
            and to launch a reader/editor on that file.  The default
            editor\reader is NOTEPAD.EXE.  You can change that editor by
            changing EDITOR_FILE_STR in APPUTIL.H.

  Args:     HWND hWndOwner,
              Handle to owner parent window.
            LPTSTR szFileName,
              Filename string.

  Returns:  void
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
void ReadMeFile(
       HWND hWndOwner,
       LPTSTR szFileName)
{
  TCHAR szReadCmd[MAX_PATH+12];
  BOOL bOk;
  int iResult;

  // First check if the readme .TXT file is there at all.
  if (FileExist(szFileName))
  {
    // If the text file is there then assemble a command string.
    _tcscpy_s(szReadCmd, MAX_PATH+12, TEXT(EDITOR_FILE_STR));
    _tcscat_s(szReadCmd, MAX_PATH+12, szFileName);
    // And execute it.
    bOk = CmdExec(szReadCmd);
    if (!bOk)
    {
      // If create procees failed then put up an error box.
      iResult = MessageBox(
                  hWndOwner,
                  TEXT(NOEDITOR_ERROR_STR),
                  TEXT(ERROR_TITLE_STR),
                  MB_OK | MB_ICONEXCLAMATION);
    }
  }
  else
  {
    // If the .TXT file doesn't exist the put up an error box.
    iResult = MessageBox(
                hWndOwner,
                TEXT(NOREADME_ERROR_STR),
                TEXT(ERROR_TITLE_STR),
                MB_OK | MB_ICONEXCLAMATION);
  }

  return;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: ReadSource

  Summary:  For use by code sample applications that study themselves
            as it were.  This function allows you to select one of the
            source files of this code sample and launch a reader to
            edit/read it.  NOTEPAD.EXE is the default editor/reader.
            You can change this by changing EDITOR_FILE_STR in APPUTIL.H.

  Args:     HWND hWndOwner
              Handle of parent window.
            OPENFILENAME* pofn,
              Pointer to the Open File Name Common Dialog structure.

  Returns:  void
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
void ReadSource(
       HWND hWndOwner,
       OPENFILENAME* pOfn)
{
  TCHAR szReadCmd[MAX_PATH+12];
  TCHAR szFileName[MAX_PATH];
  BOOL bOk;
  int iResult;

  // We'll use the OpenFileName Common Dialog (defined in main app).
  // Set the dialog's file filter and title.
  szFileName[0] = 0;
  pOfn->lpstrFilter = TEXT(OFN_SOURCEFILES_STR);
  pOfn->lpstrTitle = TEXT(OFN_SOURCETITLE_STR);
  pOfn->lpstrFile = szFileName;

  // Call up the dialog to get a file name from the user.
  if (GetOpenFileName(pOfn))
  {
    // If the user provided a file name then assemble a command string
    _tcscpy_s(szReadCmd, MAX_PATH+12, TEXT(EDITOR_FILE_STR));
    _tcscat_s(szReadCmd, MAX_PATH+12, szFileName);
    // And execute it.
    bOk = CmdExec(szReadCmd);
    if (!bOk)
    {
      // If create procees failed then put up an error box.
      iResult = MessageBox(
                  hWndOwner,
                  TEXT(NOEDITOR_ERROR_STR),
                  TEXT(ERROR_TITLE_STR),
                  MB_OK | MB_ICONEXCLAMATION);
    }
  }

  return;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: OutputDebugFmt

  Summary:  Wraps the Win32 OutputDebugString API call to provide
            printf-style formatted (and variable argument) output.

  Args:     LPTSTR pszFmt,
              Format string.
            [...]
              Arguments to match those specified in the format string.

  Returns:  void
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
void OutputDebugFmt(
       LPTSTR pszFmt,
       ...)
{
  va_list arglist;
  va_start(arglist, pszFmt);
  TCHAR szMsg[MAX_STRING_LENGTH];

  // Use the format string and arguments to format the content text.
  _vstprintf_s(szMsg, MAX_STRING_LENGTH, pszFmt, arglist);
  // Output the newly formated message string to the debugger display.
  OutputDebugString(szMsg);

  return;
}


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
       UINT uiSize)
{
  BOOL bErr = FAILED(hr);
  DWORD dwSize;

  if (bErr)
  {
    memset(pszMsg, 0, uiSize * sizeof(TCHAR));

    if (HRESULT_FACILITY(hr) == FACILITY_WINDOWS)
      hr = HRESULT_CODE(hr);

    dwSize = FormatMessage(
      FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM,
      NULL,
      hr,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
      pszMsg,
      uiSize,
      NULL);
    if (dwSize>2)
    {
      // Take out the trailing CRLF.
      pszMsg[--dwSize] = 0;
      pszMsg[--dwSize] = 0;
    }
  }

  return bErr;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: WindowProc

  Summary:  Standard WindowProc callback function that forwards Windows
            messages on to the CVirWindow::WindowProc method.  This
            Window procedure expects that it will receive a "this"
            pointer as the lpCreateParams member passed as part of the
            WM_NCCREATE message.  It saves the "this" pointer in the
            GWLP_USERDATA field of the window structure.

  Args:     HWND hWnd,
              Window handle.
            UINT uMsg,
              Windows message.
            WPARAM wParam,
              First message parameter (word sized).
            LPARAM lParam);
              Second message parameter (long sized).

  Returns:  LRESULT.  Windows window procedure callback return value.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
LRESULT CALLBACK WindowProc(
                   HWND hWnd,
                   UINT uMsg,
                   WPARAM wParam,
                   LPARAM lParam)
{
  // Get a pointer to the window class object.
  CVirWindow* pWin = (CVirWindow*) GetWindowLongPtr(hWnd, GWLP_USERDATA);

  switch (uMsg)
  {
    case WM_NCCREATE:
      // Since this is the first time that we can get ahold of
      // a pointer to the window class object, all messages that might
      // have been sent before this are never seen by the Windows object
      // and only get passed on to the DefWindowProc

      // Get the initial creation pointer to the window object
      pWin = (CVirWindow *) ((CREATESTRUCT *)lParam)->lpCreateParams;

      // Set it's protected m_hWnd member variable to ensure that
      // member functions have access to the correct window handle.
      pWin->m_hWnd = hWnd;

      // Set its USERDATA DWORD to point to the window object
      SetWindowLongPtr(hWnd, GWLP_USERDATA, (long) pWin);
      break;

    case WM_DESTROY:
      // This is our signal to destroy the window object.
      SetWindowLongPtr(hWnd, GWLP_USERDATA, 0);
      delete pWin;
      pWin = (CVirWindow *) 0;
      break;

    default:
      break;
  }

  // Call its message proc method.
  if (pWin != (CVirWindow *) 0)
    return (pWin->WindowProc(uMsg, wParam, lParam));
  else
    return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CVirWindow::Create

  Summary:  Envelopes the Windows' CreateWindow call.  Uses its
            window-creation data pointer to pass the 'this' pointer.

  Args:     LPTSTR lpszClassName,
              Address of registered class name.
            LPTSTR lpszWindowName,
              Address of window name/title.
            DWORD dwStyle,
              Window style.
            int x,
              Horizontal position of window.
            int y,
              Vertical position of window.
            int nWidth,
              Window width.
            int nHeight,
              Window height.
            HWND hwndParent,
              Handle of parent or owner window.
            HMENU hmenu,
              Handle of menu, or child window identifier.
            HINSTANCE hinst)
              Handle of application instance.

  Modifies: m_hWnd, m_hInst.

  Returns:  HWND (Window handle) of the created window.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
HWND CVirWindow::Create(
       LPTSTR lpszClassName,
       LPTSTR lpszWindowName,
       DWORD dwStyle,
       int x,
       int y,
       int nWidth,
       int nHeight,
       HWND hWndParent,
       HMENU hMenu,
       HINSTANCE hInst)
{
  // Remember the passed instance handle in a member variable of the
  //   C++ Window object.
  m_hInst = hInst;

  // Call the Win32 API to create the window.
  m_hWnd = ::CreateWindow(
               lpszClassName,
               lpszWindowName,
               dwStyle,
               x,
               y,
               nWidth,
               nHeight,
               hWndParent,
               hMenu,
               hInst,
               this);

  return (m_hWnd);
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: DialogProc

  Summary:  The general dialog procedure callback function.  Used by all
            CVirDialog class objects.  This procedure is the DialogProc
            registered for all dialogs created with the CVirDialog class.
            It uses the parameter passed with the WM_INITDIALOG message
            to identify the dialog classes' "this" pointer which it then
            stores in the window structure's GWLP_USERDATA field.
            All subsequent messages can then be forwarded on to the
            correct dialog class's DialogProc method by using the pointer
            stored in the GWLP_USERDATA field.

  Args:     HWND hWndDlg,
              Handle of dialog box.
            UINT uMsg,
              Message.
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
                LPARAM lParam)
{
  // Get a pointer to the window class object.
  CVirDialog* pdlg = (CVirDialog*) GetWindowLongPtr(hWndDlg, GWLP_USERDATA);

  switch (uMsg)
  {
    case WM_INITDIALOG:
      // Get a pointer to the window class object.
      pdlg = (CVirDialog*) lParam;

      // Assign the m_hWnd member variable.
      pdlg->m_hWnd = hWndDlg;

      // Set the USERDATA word to point to the class object.
      SetWindowLongPtr(hWndDlg, GWLP_USERDATA, (long) pdlg);
      break;

    default:
      break;
  }

  // Call its message proc method.
  if (pdlg != (CVirDialog *) 0)
    return (pdlg->DialogProc(hWndDlg, uMsg, wParam, lParam));
  else
    return (FALSE);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CVirDialog::ShowDialog

  Summary:  Creates the dialog so that it's DialogProc member function can
            be invoked.  The dialog box object exists until deleted by the
            caller.  It can be shown any number of times.  This function is
            analgous to Windows' DialogBox function.  The main difference
            being that you don't specify a DialogProc; you override the
            pure virtal function CVirDialog::DialogProc.

  Args:     HINSTANCE hInst,
              Handle of the module instance.  Needed to specify the
              module instance for fetching the dialog template resource
              (ie, from either a host EXE or DLL).
            LPTSTR lpszTemplate,
              Identifies the dialog box template.
            HWND hwndOwner)
              Handle of the owner window.

  Modifies: m_hInst.

  Returns:  Return value from the DialogBoxParam Windows API function.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
INT_PTR CVirDialog::ShowDialog(
      HINSTANCE hInst,
      LPTSTR lpszTemplate,
      HWND hWndOwner)
{
  INT_PTR iResult;

  // Assign the module instance handle in the Dialog object.
  m_hInst = hInst;

  // Create and show the dialog on screen.  Load the dialog resource
  // from the specified module instance (could be a module other than
  // that of the EXE that is running--the resources could be in a DLL
  // that is calling this ShowDialog).  Pass the 'this' pointer to the
  // dialog object so that it can be assigned inside the dialog object
  // during WM_INITDIALOG and later available to the dailog procedure
  // via the GWLP_USERDATA associated with the dialog window.
  iResult = ::DialogBoxParam(
                hInst,
                lpszTemplate,
                hWndOwner,
                (DLGPROC)::DialogProc,
                (long)this);

  return (iResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CAboutBox::DialogProc

  Summary:  Dialog proc for the About dialog box.  This DialogProc
            method definition overrides the same-named pure virtual
            function in abstract base class CVirDialog thus giving
            AboutBox-unique message dispatching behavior to this
            derivation of CVirDialog.  The remaining behavior of
            CAboutBox is inherited from CVirDialog and is common to
            all CVirDialogs.

  Args:     HWND hWndDlg,
              Handle to the dialog.
            UINT uMsg,
              Windows message to dialog.
            WPARAM wParam,
              First message parameter (word sized).
            LPARAM lParam)
              Second message parameter (long sized).

  Modifies: .

  Returns:  BOOL.  TRUE if message was handled; FALSE otherwise.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CAboutBox::DialogProc(
       HWND hWndDlg,
       UINT uMsg,
       WPARAM wParam,
       LPARAM )
{
  BOOL bResult = TRUE;

  switch (uMsg)
  {
    case WM_INITDIALOG:
      SetFocus(GetDlgItem(hWndDlg,IDOK));
      break;

    case WM_COMMAND:
      if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        ::EndDialog(hWndDlg, TRUE);
      break;

    case WM_PAINT:
      // Wash the background of the aboutbox to give it a nice
      // blue-scaling effect.  Invalidate the OK button to force it to the
      // top.  This seems to be necessary since the OK button gets
      // overwritten during the washing.
      PaintWindow(hWndDlg,COLOR_SCALE_BLUE);
      InvalidateRect(GetDlgItem(hWndDlg,IDOK),NULL,TRUE);
      break;

    default:
      bResult = FALSE;
      break;
  }

  return(bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgBox::Init

  Summary:  CMsgBox constructor.  Initializes private member data handles
            for both the eventual Parent window of any MsgBox and the
            application instance.

  Args:     HINSTANCE hInst,
              Handle of app instance.
            HWND hWndParent)
              Handle of parent window.

  Returns:  BOOL
              TRUE.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgBox::Init(
      HINSTANCE hInst,
      HWND hWndOwner)
{
  m_hInst = hInst;
  m_hWndOwner = hWndOwner;

  return (TRUE);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgBox::Error

  Summary:  Shows a specified message string in an Error MessageBox Dialog.

  Args:     LPTSTR szMsg
              The message string to display.

  Returns:  int
              Result of the MessageBox call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
int CMsgBox::Error(
      LPTSTR szMsg)
{
  int iResult;

  iResult = MessageBox(
              m_hWndOwner,
              szMsg,
              TEXT(ERROR_TITLE_STR),
              MB_OK | MB_ICONEXCLAMATION);

  return (iResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgBox::ErrorID

  Summary:  Shows a resource ID specified message string in an Error
            MessageBox Dialog.

  Args:     UINT uMsgID
              The resource ID of the message string to display.

  Returns:  int
              Result of the MessageBox call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
int CMsgBox::ErrorID(
      UINT uMsgID)
{
  int iResult = FALSE;
  TCHAR szMsg[MAX_STRING_LENGTH];

  if (LoadString(m_hInst, uMsgID, szMsg, MAX_STRING_LENGTH))
  {
    iResult = MessageBox(
                m_hWndOwner,
                szMsg,
                TEXT(ERROR_TITLE_STR),
                MB_OK | MB_ICONEXCLAMATION);
  }

  return (iResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgBox::Note

  Summary:  Shows a specified message string in a Notice MessageBox Dialog.

  Args:     LPTSTR szMsg
              The message string to display.

  Returns:  int
              Result of the MessageBox call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
int CMsgBox::Note(
      LPTSTR szMsg)
{
  int iResult;

  iResult = MessageBox(
              m_hWndOwner,
              szMsg,
              TEXT(NOTICE_TITLE_STR),
              MB_OK | MB_ICONINFORMATION);

  return (iResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgBox::NoteID

  Summary:  Shows a resource ID specified message string in a Notice
            MessageBox Dialog.

  Args:     UINT uMsgID
              The resource ID of the message string to display.

  Returns:  int
              Result of the MessageBox call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
int CMsgBox::NoteID(
      UINT uMsgID)
{
  int iResult = FALSE;
  TCHAR szMsg[MAX_STRING_LENGTH];

  if (LoadString(m_hInst, uMsgID, szMsg, MAX_STRING_LENGTH))
  {
    iResult = MessageBox(
                m_hWndOwner,
                szMsg,
                TEXT(NOTICE_TITLE_STR),
                MB_OK | MB_ICONINFORMATION);
  }

  return (iResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgBox::NoteFmt

  Summary:  Shows a printf-style formatted message string in a Notice
            MessageBox Dialog.

  Args:     LPTSTR szFmtMsg
              The format/message string to display.
            [...]
              Arguments to match those specified in the format string.

  Returns:  int
              Result of the MessageBox call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
int CMsgBox::NoteFmt(
      LPTSTR szFmtMsg
           ...)
{
  int iResult = 0;
  va_list arglist;
  va_start(arglist, szFmtMsg);
  TCHAR szMsg[MAX_STRING_LENGTH];

  // Use the format string to format the messagebox's content text.
  _vstprintf_s(szMsg, MAX_STRING_LENGTH, szFmtMsg, arglist);
  iResult = MessageBox(
              m_hWndOwner,
              szMsg,
              TEXT(NOTICE_TITLE_STR),
              MB_OK | MB_ICONINFORMATION);

  return (iResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgBox::NoteFmtID

  Summary:  Shows a resource ID specified printf-style formatted message
            string in a Notice MessageBox Dialog.

  Args:     UINT uFmtMsgID
              The resource ID of the format message string to display.
            [...]
              Arguments to match those specified in the format string.

  Returns:  int
              Result of the MessageBox call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
int CMsgBox::NoteFmtID(
      UINT uFmtMsgID,
      ...)
{
  int iResult = 0;
  va_list arglist;
  va_start(arglist, uFmtMsgID);
  TCHAR szFmtMsg[MAX_STRING_LENGTH];
  TCHAR szMsg[MAX_STRING_LENGTH];

  if (LoadString(m_hInst, uFmtMsgID, szFmtMsg, MAX_STRING_LENGTH))
  {
    // Use the format string to format the messagebox's content text.
    _vstprintf_s(szMsg, MAX_STRING_LENGTH, szFmtMsg, arglist);
    iResult = MessageBox(
                m_hWndOwner,
                szMsg,
                TEXT(NOTICE_TITLE_STR),
                MB_OK | MB_ICONINFORMATION);
  }

  return (iResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgLog::Create

  Summary:  Creates the ListBox as a child window to fill the client area
            of the specified parent window or to exist as a separate
            window owned by the parent window.

  Args:     HINSTANCE hInst,
              Instance handle of the application.
            HWND hWndparent,
              Window handle for the parent window of the listbox.
            BOOL bChild)
              Flag to create the listbox as a child window.  TRUE means fit
              the child window to fill the client area of the parent window.
              FALSE means the window is a separate (but owned) window.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgLog::Create(
       HINSTANCE hInst,
       HWND hWndParent,
       BOOL bChild)
{
  BOOL bResult = FALSE;
  HWND hWnd;
  RECT rect;
  DWORD dwStyle = WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LBS_NOSEL |
                    LBS_NOINTEGRALHEIGHT;
  TCHAR* pszTitle = bChild ? NULL : TEXT("Trace Log");

  dwStyle |= bChild ? WS_CHILD : WS_OVERLAPPEDWINDOW;

  // Logging will be flagged as on when creation is successful.
  m_bLogging = FALSE;

  if (IsWindow(hWndParent))
  {
    GetClientRect(hWndParent, &rect);

    // Create the child ListBox window and fill the parent window with it.
    hWnd = ::CreateWindowEx(
               0,                // Extended Window Style
               TEXT("LISTBOX"),  // Class Name
               pszTitle,         // Window Title
               dwStyle,          // The window style
               0,                // (x,y)=Upper left of Parent window
               0,
               rect.right,       // Width; Fill Client Window
               rect.bottom,      // Height
               hWndParent,       // Parent Window Handle
               0,                // No menu
               hInst,            // App Instance Handle
               NULL);            // Window Creation Data

    if (NULL != hWnd)
    {
      // Remember the window handle of this listbox window.
      m_hWndLog = hWnd;
      // Remember the instance of this application.
      m_hInstLog = hInst;
      // Remember if this is a child window (bChild==TRUE).
      m_bChild = bChild;
      // Turn on message logging by default after create.
      m_bLogging = TRUE;
      // Return success.
      bResult = TRUE;
    }
  }

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgLog::Logging

  Summary:  Turns logging of or off.

  Args:     BOOL bLogging
              TRUE to turn on; FALSE to turn off.

  Returns:  BOOL
              New logging status.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgLog::Logging(
       BOOL bLogging)
{
  BOOL bResult = bLogging;

  m_bLogging = bLogging;

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgLog::Msg

  Summary:  Logs a message string as a separate line in the listbox.

  Args:     LPTSTR szMsg
              Pointer to String of the message to display/log.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgLog::Msg(
       LPTSTR szMsg)
{
  BOOL bResult = FALSE;
  LRESULT iIndex;

  if (m_bLogging)
  {
    ::SendMessage(
        m_hWndLog,
        LB_ADDSTRING,
        0,
        (LPARAM)szMsg);
    iIndex = ::SendMessage(
                 m_hWndLog,
                 LB_GETCOUNT,
                 0,
                 0);
    if (LB_ERR != iIndex && iIndex > 0)
    {
      --iIndex;
      ::SendMessage(
          m_hWndLog,
          LB_SETCURSEL,
          (WPARAM)iIndex,
          0);
    }
    bResult = TRUE;
  }

#if defined(_DEBUG)
  ::OutputDebugString(szMsg);
#endif

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgLog::MsgFmt

  Summary:  Logs a printf-style formated message as a separate line in the
            Message log listbox.

  Args:     LPTSTR szFmtMsg
              The format/message string to display/log.
            [...]
              Arguments to match those specified in the format string.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgLog::MsgFmt(
       LPTSTR szFmtMsg,
       ...)
{
  BOOL bResult = FALSE;
  va_list arglist;
  va_start(arglist, szFmtMsg);
  TCHAR szMsg[MAX_STRING_LENGTH];
  LRESULT iIndex;

  // Use the format string and arguments to format the content text.
  _vstprintf_s(szMsg, MAX_STRING_LENGTH, szFmtMsg, arglist);

  // Send the newly formated message string to the Log Listbox.
  if (m_bLogging)
  {
    ::SendMessage(
        m_hWndLog,
        LB_ADDSTRING,
        0,
        (LPARAM)szMsg);
    iIndex = ::SendMessage(
                 m_hWndLog,
                 LB_GETCOUNT,
                 0,
                 0);
    if (LB_ERR != iIndex && iIndex > 0)
    {
      --iIndex;
      ::SendMessage(
          m_hWndLog,
          LB_SETCURSEL,
          (WPARAM)iIndex,
          0);
    }
    bResult = TRUE;
  }

#if defined(_DEBUG)
  ::OutputDebugString(szMsg);
#endif

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgLog::MsgID

  Summary:  Logs a message string as a separate line in the listbox.

  Args:     int iMsgID
              String Resource ID for the message to display/log.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgLog::MsgID(
       int iMsgID)
{
  BOOL bResult = FALSE;
  TCHAR szMsg[MAX_STRING_LENGTH];

  if (LoadString(m_hInstLog, iMsgID, szMsg, MAX_STRING_LENGTH))
    bResult = Msg(szMsg);

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgLog::MsgFmtID

  Summary:  Logs a printf-style formated message as a separate line in the
            Message log listbox.

  Args:     int iFmtID
              The resource ID for the format/message string to display/log.
            [...]
              Arguments to match those specified in the format string.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgLog::MsgFmtID(
       int iFmtID,
       ...)
{
  BOOL bResult = FALSE;
  va_list arglist;
  va_start(arglist, iFmtID);
  TCHAR szFormat[MAX_STRING_LENGTH];
  TCHAR szMsg[MAX_STRING_LENGTH];

  // Load the format string from the app's string resources.
  if (LoadString(m_hInstLog, iFmtID, szFormat, MAX_STRING_LENGTH))
  {
    // Use the format string and arguments to format the content text.
    _vstprintf_s(szMsg, MAX_STRING_LENGTH, szFormat, arglist);

    // Send the newly formated message string to the Log Listbox.
    bResult = Msg(szMsg);
  }

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgLog::Resize

  Summary:  Resizes the listbox to a new width and height.  Called during
            the parent window's WM_SIZE to fit the listbox to the client
            area of the parent window.  It only honors this request if it
            is an integral child window.

  Args:     int nWidth
              New width in pixels of the listbox.
            int nHeight
              New height in pixels of the listbox.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgLog::Resize(
       int nWidth,
       int nHeight)
{
  BOOL bResult = FALSE;

  if (m_bChild)
    bResult = ::MoveWindow(m_hWndLog, 0, 0, nWidth, nHeight, TRUE);

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgLog::Clear

  Summary:  Clears all logged messages from the message log listbox.

  Args:     void

  Returns:  BOOL
              TRUE.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgLog::Clear(
       void)
{
  ::SendMessage(
      m_hWndLog,
      LB_RESETCONTENT,
      0,
      0);

  return (TRUE);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CMsgLog::Copy

  Summary:  Copies the current content of the trace message log to the
            Windows clipboard.

  Args:     void

  Returns:  BOOL
              TRUE if success; FALSE if failure.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CMsgLog::Copy(void)
{
  BOOL bResult = FALSE;
  LRESULT iIndex;
  LRESULT cbLen;
  HANDLE hClip = 0;
  LPTSTR pLogData;
  TCHAR szLine[MAX_STRING_LENGTH];
  LRESULT cItems = ::SendMessage(m_hWndLog,LB_GETCOUNT,0,0);

  if (LB_ERR != cItems
      && 0 < cItems
      && MAX_LOG_LINES > cItems
      && OpenClipboard(m_hWndLog))
  {
    if (EmptyClipboard())
    {
      m_hLogData = GlobalAlloc(GHND, cItems * MAX_STRING_LENGTH);
      if (m_hLogData)
      {
        // Lock the global memory while we write to it.
        pLogData = (LPTSTR) GlobalLock(m_hLogData);
        // Loop thru the log text lines and concat them to one big string.
        for (iIndex = 0; iIndex < cItems; iIndex++)
        {
          // Get each log text line.
          cbLen = ::SendMessage(
                      m_hWndLog,
                      LB_GETTEXT,
                      (WPARAM)iIndex,
                      (LPARAM) (LPSTR)szLine);
          if (LB_ERR != cbLen && (MAX_STRING_LENGTH-3) > cbLen && 0 <= cbLen)
          {
            // Put CRLF at end.  Fix this for Unicode!
            szLine[cbLen]   = '\r';
            szLine[cbLen+1] = '\n';
            szLine[cbLen+2] = '\0';
            if (0 == iIndex)
              _tcscpy_s((LPTSTR)pLogData, MAX_STRING_LENGTH, szLine);
            else
              _tcscat_s((LPTSTR)pLogData, MAX_STRING_LENGTH, szLine);
          }
        }
        // We're done with writing so unlock the memory block.
        GlobalUnlock(m_hLogData);
        // If there were any lines at all then copy them to clipboard.
        if (0 < iIndex)
          hClip = SetClipboardData(CF_TEXT, m_hLogData);
        if (!hClip)
        {
          // If we couldn't clip the data then free the global handle.
          GlobalFree(m_hLogData);
          m_hLogData = 0;
        }
        // We're done with the clipboard so close it.
        bResult = CloseClipboard();
      }
    }
  }

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::CreateServerLog

  Summary:  Creates the ListBox as a child window to fill the client area
            of the specified local server's parent window.

  Args:     HINSTANCE hInst,
              Instance handle of the application.
            HWND hWndparent,
              Window handle for the parent window of the listbox.
            BOOL bChild)
              Flag to create the listbox as a child window.  TRUE means fit
              the child window to fill the client area of the parent window.
              FALSE means the window is a separate (but owned) window.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::CreateServerLog(
       HINSTANCE hInst,
       HWND hWndParent,
       BOOL bChild)
{
  BOOL bResult = FALSE;
  HWND hWnd;
  RECT rect;
  DWORD dwStyle = WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LBS_NOSEL |
                    LBS_NOINTEGRALHEIGHT;

  if (bChild)
    dwStyle |= WS_CHILD;
  else
    dwStyle |= WS_OVERLAPPEDWINDOW;

  if (IsWindow(hWndParent))
  {
    GetClientRect(hWndParent, &rect);

    // Create the child ListBox window and fill the parent window with it.
    hWnd = ::CreateWindowEx(
               0,                // Extended Window Style
               TEXT("LISTBOX"),  // Class Name
               NULL,             // No Window Title
               dwStyle,          // The window style
               0,                // (x,y)=Upper left of Parent window
               0,
               rect.right,       // Width; Fill Client Window
               rect.bottom,      // Hight
               hWndParent,       // Parent Window Handle
               0,                // No menu
               hInst,            // App Instance Handle
               NULL);            // Window Creation Data

    if (NULL != hWnd)
    {
      // Remember the instance of this application.
      m_hInstSender = hInst;
      // Remember the window handle of this Sending application.
      m_hWndSender = hWndParent;
      // Remember the window handle of the new listbox window.
      m_hWndListBox = hWnd;
      // Remember if this is a child window (bChild==TRUE).
      m_bChild = bChild;
      // Return success.
      bResult = TRUE;
    }
  }

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::SetClient

  Summary:  Initialize the SendLog facility for logging to the client.

  Args:     HINSTANCE hInstSender,
              Instance handle of the sending server application.
            HWND hWndSender,
              Window handle for the sending server's main window.
            HWND hWndReceiver,
              Window handle for the destination receiving client window.

  Returns:  BOOL
              Returns TRUE.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::SetClient(
       HINSTANCE hInstSender,
       HWND hWndSender,
       HWND hWndReceiver)
{
  BOOL bOk;

  bOk = (NULL != hWndReceiver);

  if (bOk)
  {
    // Remember the instance of this sending application.
    m_hInstSender = hInstSender;
    // Remember the main window of this sending application.
    m_hWndSender = hWndSender;
    // Remember the window handle of the receiving window.
    m_hWndReceiver = hWndReceiver;
  }

  return bOk;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::LogToServer

  Summary:  Switches logging to either server or client display.

  Args:     BOOL bLogToServer
              TRUE for logging to server; FALSE for logging to client.

  Returns:  BOOL
              New logging status.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::LogToServer(
       BOOL bLogToServer)
{
  BOOL bResult = bLogToServer;

  m_bLogToServer = bLogToServer;

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::Msg

  Summary:  Logs a message string as a separate line in the receiving
            CMsgLog facility.

  Args:     LPTSTR szMsg
              Pointer to String of the message to display/log.

  Returns:  BOOL bResult
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::Msg(
       LPTSTR szMsg)
{
  BOOL bResult = FALSE;
  COPYDATASTRUCT cds;

  if (NULL != szMsg)
  {
    if (m_bLogToServer)
    {
      LRESULT iIndex;

      bResult = TRUE;
      ::SendMessage(
          m_hWndListBox,
          LB_ADDSTRING,
          0,
          (LPARAM)szMsg);
      iIndex = ::SendMessage(
                   m_hWndListBox,
                   LB_GETCOUNT,
                   0,
                   0);
      if (LB_ERR != iIndex && iIndex > 0)
      {
        --iIndex;
        ::SendMessage(
            m_hWndListBox,
            LB_SETCURSEL,
            (WPARAM)iIndex,
            0);
      }
    }
    else
    {
      cds.dwData = 0;
      cds.cbData = sizeof(TCHAR) * (lstrlen(szMsg)+1);
      cds.lpData = szMsg;

      bResult = (BOOL) SendMessage(
                  m_hWndReceiver,
                  WM_COPYDATA,
                  (WPARAM) m_hWndSender,
                  (LPARAM) &cds);
    }

    #if defined(_DEBUG)
      ::OutputDebugString(szMsg);
    #endif
  }

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::MsgFmt

  Summary:  Logs a printf-style formated message as a separate line in the
            receiving CMsgLog facility.

  Args:     LPTSTR szFmtMsg
              The format/message string to display/log.
            [...]
              Arguments to match those specified in the format string.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::MsgFmt(
       LPTSTR szFmtMsg,
       ...)
{
  BOOL bResult = FALSE;
  va_list arglist;
  va_start(arglist, szFmtMsg);
  TCHAR szMsg[MAX_STRING_LENGTH];

  if (NULL != szFmtMsg)
  {
    // Use the format string and arguments to format the content text.
    _vstprintf_s(szMsg, MAX_STRING_LENGTH, szFmtMsg, arglist);
    // Send the newly formated message string to the trace Log Listbox.
    bResult = Msg(szMsg);
  }

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::MsgID

  Summary:  Logs a message string as a separate line in the receiving
            CMsgLog facility.

  Args:     int iMsgID
              String Resource ID for the message to display/log.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::MsgID(
       int iMsgID)
{
  BOOL bResult = FALSE;
  TCHAR szMsg[MAX_STRING_LENGTH];

  // Load the message string from the sender's resources and log/send it.
  if (LoadString(m_hInstSender, iMsgID, szMsg, MAX_STRING_LENGTH))
    bResult = Msg(szMsg);

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::MsgFmtID

  Summary:  Logs a printf-style formated message as a separate line in the
            receiving CMsgLog facility.

  Args:     int iFmtID
              The resource ID for the format/message string to display/log.
            [...]
              Arguments to match those specified in the format string.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::MsgFmtID(
       int iFmtID,
       ...)
{
  BOOL bResult = FALSE;
  va_list arglist;
  va_start(arglist, iFmtID);
  TCHAR szFormat[MAX_STRING_LENGTH];
  TCHAR szMsg[MAX_STRING_LENGTH];

  // Load the format string from the app's string resources.
  if (LoadString(m_hInstSender, iFmtID, szFormat, MAX_STRING_LENGTH))
  {
    // Use the format string and arguments to format the content text.
    _vstprintf_s(szMsg, MAX_STRING_LENGTH, szFormat, arglist);
    // Send the newly formated message string to the trace Log Listbox.
    bResult = Msg(szMsg);
  }

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::Resize

  Summary:  Resizes the listbox to a new width and height.  Called during
            the parent window's WM_SIZE to fit the listbox to the client
            area of the parent window.  It only honors this request if it
            is an integral child window.

  Args:     int nWidth
              New width in pixels of the listbox.
            int nHeight
              New height in pixels of the listbox.

  Returns:  BOOL
              TRUE if successful; FALSE if not.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::Resize(
       int nWidth,
       int nHeight)
{
  BOOL bResult = FALSE;

  if (m_bChild)
    bResult = ::MoveWindow(m_hWndListBox, 0, 0, nWidth, nHeight, TRUE);

  return (bResult);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::Clear

  Summary:  Clears all logged messages from the message log listbox.

  Args:     void

  Returns:  BOOL
              TRUE.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::Clear(
       void)
{
  ::SendMessage(
      m_hWndListBox,
      LB_RESETCONTENT,
      0,
      0);

  return (TRUE);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CSendLog::Copy

  Summary:  Copies the current content of the trace message log to the
            Windows clipboard.

  Args:     void

  Returns:  BOOL
              TRUE if success; FALSE if failure.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
BOOL CSendLog::Copy(void)
{
  BOOL bResult = FALSE;
  LRESULT iIndex;
  LRESULT cbLen;
  HANDLE hClip = 0;
  LPTSTR pLogData;
  TCHAR szLine[MAX_STRING_LENGTH];
  LRESULT cItems = ::SendMessage(m_hWndListBox,LB_GETCOUNT,0,0);

  if (LB_ERR != cItems
      && 0 < cItems
      && MAX_LOG_LINES > cItems
      && OpenClipboard(m_hWndListBox))
  {
    if (EmptyClipboard())
    {
      m_hLogData = GlobalAlloc(GHND, cItems * MAX_STRING_LENGTH);
      if (m_hLogData)
      {
        // Lock the global memory while we write to it.
        pLogData = (LPTSTR) GlobalLock(m_hLogData);
        // Loop thru the log text lines and concat them to one big string.
        for (iIndex = 0; iIndex < cItems; iIndex++)
        {
          // Get each log text line.
          cbLen = ::SendMessage(
                      m_hWndListBox,
                      LB_GETTEXT,
                      (WPARAM)iIndex,
                      (LPARAM) (LPSTR)szLine);
          if (LB_ERR != cbLen && (MAX_STRING_LENGTH-3) > cbLen && 0 <= cbLen)
          {
            // Put CRLF at end.  Fix this for Unicode!
            szLine[cbLen]   = '\r';
            szLine[cbLen+1] = '\n';
            szLine[cbLen+2] = '\0';
            if (0 == iIndex)
              _tcscpy_s((LPTSTR)pLogData, MAX_STRING_LENGTH, szLine);
            else
              _tcscat_s((LPTSTR)pLogData, MAX_STRING_LENGTH, szLine);
          }
        }
        // We're done with writing so unlock the memory block.
        GlobalUnlock(m_hLogData);
        // If there were any lines at all then copy them to clipboard.
        if (0 < iIndex)
          hClip = SetClipboardData(CF_TEXT, m_hLogData);
        if (!hClip)
        {
          // If we couldn't clip the data then free the global handle.
          GlobalFree(m_hLogData);
          m_hLogData = 0;
        }
        // We're done with the clipboard so close it.
        bResult = CloseClipboard();
      }
    }
  }

  return (bResult);
}
