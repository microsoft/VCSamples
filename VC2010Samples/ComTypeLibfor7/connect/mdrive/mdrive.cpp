// MDrive.cpp : Defines the class behaviors for the application.
//

#include "premdriv.h"
#include "MDrive.h"
#include "DriveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDriveApp

BEGIN_MESSAGE_MAP(CMDriveApp, CWinApp)
    //{{AFX_MSG_MAP(CMDriveApp)
        // NOTE - the ClassWizard will add and remove mapping macros here.
        //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG
    ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDriveApp construction

CMDriveApp::CMDriveApp()
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMDriveApp object

CMDriveApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMDriveApp initialization

BOOL CMDriveApp::InitInstance()
{
    // Initialize OLE libraries -- free threaded
    HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);
    //if (!AfxOleInit())
    if (FAILED(hRes))
    {
        AfxMessageBox(IDP_OLE_INIT_FAILED);
        return FALSE;
    }

    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.

#if _MFC_VER < 0x0500
#ifdef _AFXDLL
    Enable3dControls();         // Call this when using MFC in a shared DLL
#else
    Enable3dControlsStatic();   // Call this when linking to MFC statically
#endif
#endif

    // Parse the command line to see if launched as OLE server
    if (RunEmbedded() || RunAutomated())
    {
        // Register all OLE server (factories) as running.  This enables the
        //  OLE libraries to create objects from other applications.
        COleTemplateServer::RegisterAll();

        // Application was run with /Embedding or /Automation.  Don't show the
        //  main window in this case.
        return TRUE;
    }

    // When a server application is launched stand-alone, it is a good idea
    //  to update the system registry in case it has been damaged.
    COleObjectFactory::UpdateRegistryAll();

    CMDriveDlg dlg;
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
//      dlg.OnStopAll();
    }
    else if (nResponse == IDCANCEL)
    {
//      dlg.OnStopAll();
    }

    // Since the dialog has been closed, return FALSE so that we exit the
    //  application, rather than start the application's message pump.
    return FALSE;
}
