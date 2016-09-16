// Scribble.cpp : Defines the class behaviors for the application.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "Scribble.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "IpFrame.h"
#include "ScribDoc.h"
#include "ScribVw.h"
#include "PluginBld.h"
#include "WebService.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Static global functions
#ifdef _MANAGED
static char * ManagedStr2CStr(String ^ str)
{
	pin_ptr<const wchar_t> pwc = PtrToStringChars(str);
	size_t nChars = str->Length + 1;
	char* pc = new char[nChars];
	size_t sizeInBytes = nChars * sizeof(pc[0]);
	size_t nConvertedChars;
	wcstombs_s(&nConvertedChars, pc, sizeInBytes, pwc, sizeInBytes);

	return pc;
}
#endif

/////////////////////////////////////////////////////////////////////////////
// CScribbleApp

BEGIN_MESSAGE_MAP(CScribbleApp, CWinApp)
	//{{AFX_MSG_MAP(CScribbleApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScribbleApp construction

CScribbleApp::CScribbleApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	EnableHtmlHelp();
#ifdef _MANAGED
	m_pluginMap = gcnew Dictionary<UINT, IScribblePlugin ^>();
	m_webService = gcnew ScribbleWSClass();
#endif
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CScribbleApp object

CScribbleApp theApp;

// This identifier was generated to be statistically unique for your app.
// You may change it if you prefer to choose a specific identifier.

// {7559FD90-9B93-11CE-B0F0-00AA006C28B3}
static const CLSID clsid =
{ 0x7559fd90, 0x9b93, 0x11ce, { 0xb0, 0xf0, 0x0, 0xaa, 0x0, 0x6c, 0x28, 0xb3 } };

/////////////////////////////////////////////////////////////////////////////
// CScribbleApp initialization

BOOL CScribbleApp::InitInstance()
{
	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	
	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_SCRIBBTYPE,
		RUNTIME_CLASS(CScribbleDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CScribbleView));

	pDocTemplate->SetServerInfo(
		IDR_SCRIBBTYPE_SRVR_EMB, IDR_SCRIBBTYPE_SRVR_IP,
		RUNTIME_CLASS(CInPlaceFrame));

	AddDocTemplate(pDocTemplate);
	// Connect the COleTemplateServer to the document template.
	//  The COleTemplateServer creates new documents on behalf
	//  of requesting OLE containers by using information
	//  specified in the document template.
	m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);

	// Register all OLE server factories as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleTemplateServer::RegisterAll();
		// Note: MDI applications register all server objects without regard
		//  to the /Embedding or /Automation on the command line.


	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;

	// Enable drag/drop open.  We don't call this in Win32, since a
	//  document file extension wasn't chosen while running AppWizard.
	m_pMainWnd->DragAcceptFiles();

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Check to see if launched as OLE server
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Application was run with /Embedding or /Automation.  Don't show the
		//  main window in this case.
		return TRUE;
	}

	// When a server application is launched stand-alone, it is a good idea
	//  to update the system registry in case it has been damaged.
	m_server.UpdateRegistry(OAT_INPLACE_SERVER);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
    
	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	// Load our plugins
	LoadPlugins();

	// Add web service menu
	AddWebServiceMenu();

	return TRUE;
}


int FindMenuItem(CMenu * menu, LPCTSTR menuString)
{
	ENSURE(menu);
	ENSURE(::IsMenu(menu->GetSafeHmenu()));

	int count = menu->GetMenuItemCount();
	for (int i = 0; i < count; ++i)
	{
		CString str;
		if (menu->GetMenuString(i, str, MF_BYPOSITION) 
			&& (strcmp(str, menuString) == 0))
		{
			return i;
		}
	}

	return -1;
}

void CScribbleApp::LoadPlugins()
{
#ifdef _MANAGED
	String ^ fileName = "plugins.xml";
	List<IScribblePlugin ^> ^ pluginList;

	// Load the plugins
	try
	{
		pluginList = PluginBuilder::GetPlugins(fileName);
	}
	catch (PluginFileException ^ e)
	{
		char * cStr = ManagedStr2CStr(e->Message);
		MessageBox(m_pMainWnd->m_hWnd, cStr, "Error", MB_ICONERROR | MB_OK);
		delete cStr;
		return;
	}
	catch (PluginLoadException ^ e)
	{
		char * cStr = ManagedStr2CStr(e->Message);
		MessageBox(m_pMainWnd->m_hWnd, cStr, "Error", MB_ICONERROR | MB_OK);
		delete cStr;

		return;
	}

	// Build the plugin menu
	CMenu * cmMainMenu = m_pMainWnd->GetMenu();
	CMenu * cmPluginMenu = new CMenu();
	cmPluginMenu->CreatePopupMenu();

	unsigned int curID = ID_PLUGIN_MENU_START;
	for (int iPlugin = 0; iPlugin < pluginList->Count; ++iPlugin, ++curID)
	{
		// Add to our plugin map where the map is indexed by the
		//  menu ID of the plugin
		m_pluginMap->Add(curID, pluginList->default[iPlugin]);

		// Append to our popup menu
		char * cStr = ManagedStr2CStr(pluginList->default[iPlugin]->Name);
		cmPluginMenu->AppendMenuA(MF_STRING, curID, cStr);
		delete cStr;
	}

	// Find the help menu ID
	int helpMenuID = FindMenuItem(cmMainMenu, "&Help");

	// Insert the plugin menu before the help menu
	cmMainMenu->InsertMenu(helpMenuID, MF_BYPOSITION | MF_POPUP, 
		(UINT_PTR) cmPluginMenu->Detach(), "&Plugins");

	// Set the original main menu with the inserted plugin menu
	//  as the main menu
	SetMenu(m_pMainWnd->m_hWnd, cmMainMenu->m_hMenu);
	cmMainMenu->Detach();

	delete cmPluginMenu;
#endif
}

void CScribbleApp::AddWebServiceMenu()
{
#ifdef _MANAGED
	// Build the web service menu
	CMenu * cmMainMenu = m_pMainWnd->GetMenu();
	CMenu * cmWebServiceMenu = new CMenu();
	cmWebServiceMenu->CreatePopupMenu();

	// Add web service menu items
	cmWebServiceMenu->AppendMenuA(MF_STRING, ID_WEBSERVICE_ADDSHAPE_SQR, "Add Square");
	cmWebServiceMenu->AppendMenuA(MF_STRING, ID_WEBSERVICE_ADDSHAPE_REC, "Add Rectangle");
	cmWebServiceMenu->AppendMenuA(MF_STRING, ID_WEBSERVICE_ADDSHAPE_CIR, "Add Circle");
	
	// Find the help menu ID
	int helpMenuID = FindMenuItem(cmMainMenu, "&Help");

	// Insert the web service menu before the help menu
	cmMainMenu->InsertMenu(helpMenuID, MF_BYPOSITION | MF_POPUP, 
		(UINT_PTR) cmWebServiceMenu->Detach(), "&Web Services");

	// Set the original main menu with the inserted web service
	//  menu as the main menu
	SetMenu(m_pMainWnd->m_hWnd, cmMainMenu->m_hMenu);
	cmMainMenu->Detach();

	delete cmWebServiceMenu;
#endif
}

void CScribbleApp::ExecutePlugin(CScribbleDoc * pScribDoc, UINT pluginMenuID)
{
#ifdef _MANAGED
	MyScribApp ^ scribApp = gcnew MyScribApp(pScribDoc);
	m_pluginMap->default[pluginMenuID]->Run(scribApp);
#endif
}

void CScribbleApp::AddRectangle(CScribbleDoc * pScribDoc, int posX, int posY, int width, int height) 
{
	ASSERT_VALID(pScribDoc);
#ifdef _MANAGED
	try {
		Shape^ shape = m_webService->GetRectangle(width, height);
		this->AddShape(pScribDoc, shape, posX, posY);
	} catch (Exception^ e) {
		char * cStr = ManagedStr2CStr(e->Message);
		MessageBox(m_pMainWnd->m_hWnd, cStr, "Error", MB_ICONERROR | MB_OK);
		delete cStr;
		return;
	}
#endif
	return;
}

void CScribbleApp::AddCircle(CScribbleDoc * pScribDoc, int posX, int posY, int radius) 
{
	ASSERT_VALID(pScribDoc);
#ifdef _MANAGED
	try {
		Shape^ shape = m_webService->GetCircle(radius);
		this->AddShape(pScribDoc, shape, posX, posY);
	} catch (Exception^ e) {
		char * cStr = ManagedStr2CStr(e->Message);
		MessageBox(m_pMainWnd->m_hWnd, cStr, "Error", MB_ICONERROR | MB_OK);
		delete cStr;
		return;
	}
#endif
	return;
}

#ifdef _MANAGED
void CScribbleApp::AddShape(CScribbleDoc * pScribDoc, Shape^ pShape, int posX, int posY)
{
	ASSERT_VALID(pScribDoc);
	if (pShape != nullptr) {
		CStroke* stroke = pScribDoc->NewStroke();
		for (int i = 0; i < pShape->Points->Length; ++i) {
			stroke->m_pointArray.Add(CPoint(posX + pShape->Points[i]->X, posY -  pShape->Points[i]->Y));
		}
		stroke->FinishStroke();
		pScribDoc->UpdateAllViews(NULL, 0L, stroke);
	}

}
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
		// No message handlers
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

// App command to run the dialog
void CScribbleApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CScribbleApp commands
