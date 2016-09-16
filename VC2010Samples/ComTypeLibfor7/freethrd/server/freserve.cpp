/*+==========================================================================
  File:      FRESERVE.CPP

  Summary:   Implementation file for a DLL COM Component server providing
             a Ball-related COM Component: Ball. Access to Class Factories
             is provided in this module.  This server also supports self
             registration and unregistration. FRESERVE is a thread-safe
             server for the COBall COM objects.

             For a comprehensive tutorial code tour of FRESERVE's contents
             and offerings see the accompanying FRESERVE.TXT file. For
             more specific technical details on the internal workings see
             the comments dispersed throughout the FRESERVE source code.
             FRESERVE is functioned by the multi-threaded server, FRECLIEN.
             For more details see FRECLIEN.TXT in the sibling FRECLIEN
             directory.

  Classes:   none.

  Functions: DllMain, DllGetClassObject, DllCanUnloadNow, DllRegisterServer,
             DllUnregisterServer.

  Origin:    4-6-96: atrent - Editor-inheritance from DLLSERVE.CPP in
               the DLLSERVE OLE Tutorial Code Sample.

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
  We include OLE2.H because we will be making calls to the OLE Libraries
    in future exploitation of this DLL skeleton.
  We include INITGUID.H only once (here) in the entire DLL because we
    will be defining GUIDs and want them as constants in the data segment.
  We include APPUTIL.H because we will be building this DLL using
    the convenient Virtual Window and Dialog classes and other
    utility functions in the APPUTIL Library (ie, APPUTIL.LIB).
  We include IBALL.H and BALLGUID.H for the common ball-related Interface
    class, GUID, and CLSID specifications.
  We include FRESERVE.H because it has the main declerations of all the
    car related interfaces and their GUIDs.  It also has the _DLLEXPORT_
    controlled import and export specifications.
  We include SERVER.H because it has the necessary internal class and
    resource definitions for this DLL.
  We include FACTORY.H because it has the necessary internal class factory
    declarations for this DLL component server.
---------------------------------------------------------------------------*/

#include "preserve.h"
#include "factory.h"
#include "Strsafe.h"
#include "assert.h"

// Global variable definitions. Some Initialized in DllMain() below.

// We encapsulate the control of this COM server (eg, lock and object
// counting) in a server control C++ object.  Here is it's pointer.
CServer* g_pServer = NULL;


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
  Function: DllMain

  Summary:  Like WinMain is for an EXE application, this DllMain function
            is the main entry point for this DLL.  It is called when the
            DLL is loaded by a process, and when new threads are created
            by a process that has already loaded this DLL.  DllMain is
            also called when threads of a process that has loaded the DLL
            exit cleanly and when the process itself unloads the DLL.

            If you want to use C runtime libraries, keep this function
            named "DllMain" and you won't have to do anything special to
            initialize the runtime libraries.

            When fdwReason == DLL_PROCESS_ATTACH, the return value is used
            to determine if the DLL should remain loaded, or should be
            immediately unloaded depending upon whether the DLL could be
            initialized properly.  For all other values of fdwReason, the
            return value is ignored.

  Args:     HINSTANCE hDLLInst,
              Instance handle of the DLL.
            DWORD fdwReason,
              Process attach/detach or thread attach/detach.
              Reason for calling.
            LPVOID lpvReserved)
              Reserved and not used.

  Returns:  BOOL,
              Return value is used only when fdwReason == DLL_PROCESS_ATTACH.
              TRUE  -  Used to signify that the DLL should remain loaded.
              FALSE -  Used to signify that the DLL should be
                immediately unloaded.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
BOOL WINAPI DllMain(
              HINSTANCE hDllInst,
              DWORD fdwReason,
              LPVOID )
{
  BOOL bResult = TRUE;

  // Dispatch this main call based on the reason it was called.
  switch (fdwReason)
  {
    case DLL_PROCESS_ATTACH:
      // The DLL is being loaded for the first time by a given process.
      // Perform per-process initialization here.  If the initialization
      // is successful, return TRUE; if unsuccessful, return FALSE.
      bResult = FALSE;
      if (UnicodeOk())
      {
        // Instantiate the CServer utility class.
        g_pServer = new CServer;
        if (NULL != g_pServer)
        {
          // Remember the DLL Instance handle.
          g_pServer->m_hDllInst = hDllInst;
          bResult = TRUE;
        }
      }
      break;

    case DLL_PROCESS_DETACH:
      // The DLL is being unloaded by a given process.  Do any
      // per-process clean up here, such as undoing what was done in
      // DLL_PROCESS_ATTACH.  The return value is ignored.
      DELETE_POINTER(g_pServer);
      break;

    case DLL_THREAD_ATTACH:
      // A thread is being created in a process that has already loaded
      // this DLL.  Perform any per-thread initialization here.  The
      // return value is ignored.
      break;

    case DLL_THREAD_DETACH:
      // A thread is exiting cleanly in a process that has already
      // loaded this DLL.  Perform any per-thread clean up here.  The
      // return value is ignored.
      break;

    default:
      break;
  }

  return (bResult);
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: DllGetClassObject

  Summary:  The standard exported function that the COM service library
            uses to obtain an object class of the class factory for a
            specified component provided by this server DLL.

  Args:     REFCLSID rclsid,
              [in] The CLSID of the requested Component.
            REFIID riid,
              [in] The requested interface on the Class Factory.
            PPVOID ppv)
              [in/out] The output interface pointer to the Class Factory.

  Returns:  HRESULT
              E_FAIL if requested component isn't supported.
              E_OUTOFMEMORY if out of memory.
              Error code out of the QueryInterface.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
STDAPI DllGetClassObject(
         REFCLSID rclsid,
         REFIID riid,
         PPVOID ppv)
{
  HRESULT hr = CLASS_E_CLASSNOTAVAILABLE;
  IUnknown* pCob = NULL;

  if (CLSID_Ball == rclsid)
  {
    hr = E_OUTOFMEMORY;
    pCob = new CFBall(NULL, g_pServer);
  }

  if (NULL != pCob)
  {
    g_pServer->ObjectsUp();
    hr = pCob->QueryInterface(riid, ppv);
    if (FAILED(hr))
    {
      g_pServer->ObjectsDown();
	DELETE_POINTER(pCob);
    }
  }

  return hr;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: DllCanUnloadNow

  Summary:  The standard exported function that the COM service library
            uses to determine if this server DLL can be unloaded.

  Args:     void.

  Returns:  HRESULT
              S_OK if this DLL server can be unloaded.
              S_FALSE if this DLL can not be unloaded.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
STDAPI DllCanUnloadNow(void)
{
  HRESULT hr;

  // We return S_OK of there are no longer any living objects AND
  // there are no outstanding client locks on this server.
  hr = g_pServer->CanUnloadNow();

  return hr;
}


/*F+F++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: SetRegKeyValue

  Summary:  Internal utility function to set a Key, Subkey, and value
            in the system Registry under HKEY_CLASSES_ROOT.

  Args:     LPTSTR pszKey,
            LPTSTR pszSubkey,
            LPTSTR pszValue)

  Returns:  BOOL
              TRUE if success; FALSE if not.
------------------------------------------------------------------------F-F*/
BOOL SetRegKeyValue(
       LPTSTR pszKey,
       LPTSTR pszSubkey,
       LPTSTR pszValue)
{
  BOOL bOk = FALSE;
  HRESULT hr;
  LONG ec;
  HKEY hKey;
  TCHAR szKey[MAX_STRING_LENGTH];

  hr = StringCbCopy(szKey, sizeof(szKey), pszKey);
  assert(hr == S_OK);

  if (NULL != pszSubkey)
  {
    hr = StringCbCat(szKey, sizeof(szKey), TEXT("\\"));
	assert(hr == S_OK);
    hr = StringCbCat(szKey, sizeof(szKey), pszSubkey);
	assert(hr == S_OK);
  }

  ec = RegCreateKeyEx(
         HKEY_CLASSES_ROOT,
         szKey,
         0,
         NULL,
         REG_OPTION_NON_VOLATILE,
         KEY_ALL_ACCESS,
         NULL,
         &hKey,
         NULL);

  if (NULL != pszValue && ERROR_SUCCESS == ec)
  {
    ec = RegSetValueEx(
           hKey,
           NULL,
           0,
           REG_SZ,
           (BYTE *)pszValue,
           (lstrlen(pszValue)+1)*sizeof(TCHAR));
    if (ERROR_SUCCESS == ec)
      bOk = TRUE;
    RegCloseKey(hKey);
  }

  return bOk;
}


/*F+F++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: AddRegNamedValue

  Summary:  Internal utility function to add a named data value to an
            existing Key (with optional Subkey) in the system Registry
            under HKEY_CLASSES_ROOT.

  Args:     LPTSTR pszKey,
            LPTSTR pszSubkey,
            LPTSTR pszValueName,
            LPTSTR pszValue)

  Returns:  BOOL
              TRUE if success; FALSE if not.
------------------------------------------------------------------------F-F*/
BOOL AddRegNamedValue(
       LPTSTR pszKey,
       LPTSTR pszSubkey,
       LPTSTR pszValueName,
       LPTSTR pszValue)
{
  BOOL bOk = FALSE;
  HRESULT hr;
  LONG ec;
  HKEY hKey;
  TCHAR szKey[MAX_STRING_LENGTH];

  hr = StringCbCopy(szKey, sizeof(szKey), pszKey);
  assert(hr == S_OK);

  if (NULL != pszSubkey)
  {
    hr = StringCbCat(szKey, sizeof(szKey), TEXT("\\"));
	assert(hr == S_OK);
    hr = StringCbCat(szKey, sizeof(szKey), pszSubkey);
	assert(hr == S_OK);
  }

  ec = RegOpenKeyEx(
         HKEY_CLASSES_ROOT,
         szKey,
         0,
         KEY_ALL_ACCESS,
         &hKey);

  if (NULL != pszValue && ERROR_SUCCESS == ec)
  {
    ec = RegSetValueEx(
           hKey,
           pszValueName,
           0,
           REG_SZ,
           (BYTE *)pszValue,
           (lstrlen(pszValue)+1)*sizeof(TCHAR));
    if (ERROR_SUCCESS == ec)
      bOk = TRUE;
    RegCloseKey(hKey);
  }

  return bOk;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: DllRegisterServer

  Summary:  The standard exported function that can be called to command
            this DLL server to register itself in the system registry.

  Args:     void.

  Returns:  HRESULT
              NOERROR
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
STDAPI DllRegisterServer(void)
{
  HRESULT  hr = NOERROR;
  TCHAR    szID[GUID_SIZE+1];
  TCHAR    szCLSID[GUID_SIZE+1];
  TCHAR    szModulePath[MAX_PATH];

  // Obtain the path to this module's executable file for later use.
  GetModuleFileName(
    g_pServer->m_hDllInst,
    szModulePath,
    sizeof(szModulePath)/sizeof(TCHAR));

  /*-------------------------------------------------------------------------
    Create registry entries for the DllBall Component.
  -------------------------------------------------------------------------*/
  // Create some base key strings.
  StringFromGUID2(CLSID_Ball, szID, GUID_SIZE);
  hr = StringCbCopy(szCLSID, sizeof(szCLSID), TEXT("CLSID\\"));
  assert(hr == S_OK);
  hr = StringCbCat(szCLSID, sizeof(szCLSID), szID);
  assert(hr == S_OK);

  // Create ProgID keys.
  SetRegKeyValue(
    TEXT("DllBall1.0"),
    NULL,
    TEXT("DllBall Component - FRESERVE Code Sample"));
  SetRegKeyValue(
    TEXT("DllBall1.0"),
    TEXT("CLSID"),
    szID);

  // Create VersionIndependentProgID keys.
  SetRegKeyValue(
    TEXT("DllBall"),
    NULL,
    TEXT("DllBall Component - FRESERVE Code Sample"));
  SetRegKeyValue(
    TEXT("DllBall"),
    TEXT("CurVer"),
    TEXT("DllBall1.0"));
  SetRegKeyValue(
    TEXT("DllBall"),
    TEXT("CLSID"),
    szID);

  // Create entries under CLSID.
  SetRegKeyValue(
    szCLSID,
    NULL,
    TEXT("DllBall Component - FRESERVE Code Sample"));
  SetRegKeyValue(
    szCLSID,
    TEXT("ProgID"),
    TEXT("DllBall1.0"));
  SetRegKeyValue(
    szCLSID,
    TEXT("VersionIndependentProgID"),
    TEXT("DllBall"));
  SetRegKeyValue(
    szCLSID,
    TEXT("NotInsertable"),
    NULL);
  SetRegKeyValue(
    szCLSID,
    TEXT("InprocServer32"),
    szModulePath);
  AddRegNamedValue(
    szCLSID,
    TEXT("InprocServer32"),
    TEXT("ThreadingModel"),
    TEXT("Free"));

  return hr;
}


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: DllUnregisterServer

  Summary:  The standard exported function that can be called to command
            this DLL server to unregister itself from the system Registry.

  Args:     void.

  Returns:  HRESULT
              NOERROR
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
STDAPI DllUnregisterServer(void)
{
  HRESULT  hr = NOERROR;
  TCHAR    szID[GUID_SIZE+1];
  TCHAR    szCLSID[GUID_SIZE+1];
  TCHAR    szTemp[GUID_SIZE+1];

  /*-------------------------------------------------------------------------
    Delete registry entries for the Ball Component.
  -------------------------------------------------------------------------*/
  //Create some base key strings.
  StringFromGUID2(CLSID_Ball, szID, GUID_SIZE);
  hr = StringCbCopy(szCLSID, sizeof(szCLSID), TEXT("CLSID\\"));
  assert(hr == S_OK);
  hr = StringCbCat(szCLSID, sizeof(szCLSID), szID);
  assert(hr == S_OK);

  RegDeleteKey(HKEY_CLASSES_ROOT, TEXT("DllBall\\CurVer"));
  RegDeleteKey(HKEY_CLASSES_ROOT, TEXT("DllBall\\CLSID"));
  RegDeleteKey(HKEY_CLASSES_ROOT, TEXT("DllBall"));

  RegDeleteKey(HKEY_CLASSES_ROOT, TEXT("DllBall1.0\\CLSID"));
  RegDeleteKey(HKEY_CLASSES_ROOT, TEXT("DllBall1.0"));

  hr = StringCbPrintf(szTemp, sizeof(szTemp), TEXT("%s\\%s"), szCLSID, TEXT("ProgID"));
  assert(hr == S_OK);
  RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);

  hr = StringCbPrintf(szTemp, sizeof(szTemp), TEXT("%s\\%s"), szCLSID, TEXT("VersionIndependentProgID"));
  assert(hr == S_OK);
  RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);

  hr = StringCbPrintf(szTemp, sizeof(szTemp), TEXT("%s\\%s"), szCLSID, TEXT("NotInsertable"));
  assert(hr == S_OK);
  RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);

  hr = StringCbPrintf(szTemp, sizeof(szTemp), TEXT("%s\\%s"), szCLSID, TEXT("InprocServer32"));
  assert(hr == S_OK);
  RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);

  RegDeleteKey(HKEY_CLASSES_ROOT, szCLSID);

  return hr;
}
