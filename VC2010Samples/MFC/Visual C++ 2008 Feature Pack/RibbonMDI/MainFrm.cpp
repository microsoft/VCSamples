// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "RibbonMDIDemo.h"

#include "MainFrm.h"

#include <memory>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)


BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_WINDOW_MANAGER, OnWindowManager)
	ON_UPDATE_COMMAND_UI(ID_WINDOW_MANAGER, OnUpdateWindowManager)
	ON_COMMAND(ID_MDI_MOVE_TO_NEXT_GROUP, OnMdiMoveToNextGroup)
	ON_COMMAND(ID_MDI_MOVE_TO_PREV_GROUP, OnMdiMoveToPrevGroup)
	ON_COMMAND(ID_MDI_NEW_HORZ_TAB_GROUP, OnMdiNewHorzTabGroup)
	ON_COMMAND(ID_MDI_NEW_VERT_GROUP, OnMdiNewVertGroup)
	ON_COMMAND(ID_MDI_CANCEL, OnMdiCancel)
	ON_COMMAND(ID_VIEW_WORKSPACE, OnViewWorkspace)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WORKSPACE, OnUpdateViewWorkspace)
	ON_COMMAND(ID_VIEW_WORKSPACE2, OnViewWorkspace2)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WORKSPACE2, OnUpdateViewWorkspace2)
	ON_COMMAND(ID_VIEW_OUTPUT, OnViewOutput)
	ON_UPDATE_COMMAND_UI(ID_VIEW_OUTPUT, OnUpdateViewOutput)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	CMFCVisualManager::SetDefaultManager (RUNTIME_CLASS (CMFCVisualManagerOffice2007));

	CMDITabInfo mdiTabParams;
	mdiTabParams.m_bTabIcons = TRUE;
	mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D_ONENOTE;
	mdiTabParams.m_bAutoColor = TRUE;

	EnableMDITabbedGroups (TRUE, mdiTabParams);

	CDockingManager::SetDockingMode (DT_SMART);

	m_wndRibbonBar.Create (this);

	InitRibbon ();

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// Load control bar icons:
	CMFCToolBarImages imagesWorkspace;
	imagesWorkspace.SetImageSize (CSize (16, 16));
	imagesWorkspace.SetTransparentColor (RGB (255, 0, 255));
	imagesWorkspace.Load (IDB_WORKSPACE);

	if (!m_wndWorkSpace.Create (_T("View  1"), this, CRect (0, 0, 200, 200),
		TRUE, ID_VIEW_WORKSPACE,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create Workspace bar\n");
		return FALSE;      // fail to create
	}

	m_wndWorkSpace.SetIcon (imagesWorkspace.ExtractIcon (0), FALSE);

	if (!m_wndWorkSpace2.Create (_T("View 2"), this, CRect (0, 0, 200, 200),
		TRUE, ID_VIEW_WORKSPACE2,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create Workspace bar 2\n");
		return FALSE;      // fail to create
	}

	m_wndWorkSpace2.SetIcon (imagesWorkspace.ExtractIcon (1), FALSE);

	if (!m_wndOutput.Create (_T("Output"), this, CRect (0, 0, 150, 150),
		TRUE /* Has gripper */, ID_VIEW_OUTPUT,
		WS_CHILD | WS_VISIBLE | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create output bar\n");
		return -1;      // fail to create
	}

	m_wndOutput.SetIcon (imagesWorkspace.ExtractIcon (2), FALSE);

	m_wndWorkSpace.EnableDocking(CBRS_ALIGN_ANY);
	m_wndWorkSpace2.EnableDocking(CBRS_ALIGN_ANY);
	m_wndOutput.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	EnableAutoHidePanes(CBRS_ALIGN_ANY);
	DockPane (&m_wndWorkSpace);
	m_wndWorkSpace2.AttachToTabWnd (&m_wndWorkSpace, DM_STANDARD, FALSE, NULL);
	DockPane(&m_wndOutput);

	// Enable windows manager:
	EnableWindowsDialog (ID_WINDOW_MANAGER, IDS_WINDOWS_MANAGER, TRUE);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnWindowManager() 
{
	ShowWindowsDialog ();
}

void CMainFrame::OnUpdateWindowManager(CCmdUI* pCmdUI)
{
	pCmdUI->Enable (!IsPrintPreviewMode ());
}

BOOL CMainFrame::OnShowMDITabContextMenu (CPoint point, DWORD dwAllowedItems, BOOL bDrop)
{
	CMenu menu;
	VERIFY(menu.LoadMenu (bDrop ? IDR_POPUP_DROP_MDITABS : IDR_POPUP_MDITABS));

	CMenu* pPopup = menu.GetSubMenu(0);
	ASSERT(pPopup != NULL);

	if (pPopup)
	{
		if ((dwAllowedItems & AFX_MDI_CREATE_HORZ_GROUP) == 0)
		{
			pPopup->DeleteMenu (ID_MDI_NEW_HORZ_TAB_GROUP, MF_BYCOMMAND);
		}

		if ((dwAllowedItems & AFX_MDI_CREATE_VERT_GROUP) == 0)
		{
			pPopup->DeleteMenu (ID_MDI_NEW_VERT_GROUP, MF_BYCOMMAND);
		}

		if ((dwAllowedItems & AFX_MDI_CAN_MOVE_NEXT) == 0)
		{
			pPopup->DeleteMenu (ID_MDI_MOVE_TO_NEXT_GROUP, MF_BYCOMMAND);
		}

		if ((dwAllowedItems & AFX_MDI_CAN_MOVE_PREV) == 0)
		{
			pPopup->DeleteMenu (ID_MDI_MOVE_TO_PREV_GROUP, MF_BYCOMMAND);
		}

		CMFCPopupMenu* pPopupMenu = new CMFCPopupMenu;
		if (pPopupMenu)
		{
			pPopupMenu->SetAutoDestroy (FALSE);
			pPopupMenu->Create (this, point.x, point.y, pPopup->GetSafeHmenu ());
		}
	}
	return TRUE;
}

void CMainFrame::OnMdiMoveToNextGroup() 
{
	MDITabMoveToNextGroup ();
}

void CMainFrame::OnMdiMoveToPrevGroup() 
{
	MDITabMoveToNextGroup (FALSE);
}

void CMainFrame::OnMdiNewHorzTabGroup() 
{
	MDITabNewGroup (FALSE);
}

void CMainFrame::OnMdiNewVertGroup() 
{
	MDITabNewGroup ();
}

void CMainFrame::OnMdiCancel() 
{
	// TODO: Add your command handler code here
	
}

CMDIChildWndEx* CMainFrame::CreateDocumentWindow (LPCTSTR lpcszDocName, CObject* /*pObj*/)
{
	if (lpcszDocName != NULL && lpcszDocName [0] != '\0')
	{
		CDocument* pDoc = AfxGetApp()->OpenDocumentFile (lpcszDocName);

		if (pDoc != NULL)
		{
			POSITION pos = pDoc->GetFirstViewPosition();

			if (pos != NULL)
			{
				CView* pView = pDoc->GetNextView (pos);
				if (pView == NULL)
				{
					return NULL;
				}

				return DYNAMIC_DOWNCAST (CMDIChildWndEx, pView->GetParent ());
			}   
		}
	}

	return NULL;
}

void CMainFrame::OnViewWorkspace() 
{
	ShowPane (&m_wndWorkSpace,
					!(m_wndWorkSpace.IsVisible ()),
					FALSE, TRUE);
	RecalcLayout ();
}

void CMainFrame::OnUpdateViewWorkspace(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck (m_wndWorkSpace.IsVisible ());
	pCmdUI->Enable (!IsPrintPreviewMode ());
}

void CMainFrame::OnViewWorkspace2() 
{
	ShowPane (&m_wndWorkSpace2,
					!(m_wndWorkSpace2.IsVisible ()),
					FALSE, TRUE);
	RecalcLayout ();
}

void CMainFrame::OnUpdateViewWorkspace2(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck (m_wndWorkSpace2.IsVisible ());
	pCmdUI->Enable (!IsPrintPreviewMode ());
}

void CMainFrame::OnViewOutput() 
{
	ShowPane (&m_wndOutput,
					!(m_wndOutput.IsVisible ()),
					FALSE, TRUE);
	RecalcLayout ();
}

void CMainFrame::OnUpdateViewOutput(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck (m_wndOutput.IsVisible ());
	pCmdUI->Enable (!IsPrintPreviewMode ());
}

void CMainFrame::InitRibbon ()
{
	//-------------------
	// Load panel images:
	//-------------------
	m_PanelImages.SetImageSize (CSize (16, 16));
	m_PanelImages.Load (IDB_BUTTONS);

	//------------------
	// Init main button:
	//------------------
	m_MainButton.SetImage (IDB_MAIN);
	m_MainButton.SetText (_T("\nf"));
	m_MainButton.SetToolTipText (_T("File"));

	m_wndRibbonBar.SetApplicationButton (&m_MainButton, CSize (45, 45));

	m_wndRibbonBar.SetApplicationButton (&m_MainButton, CSize (45, 45));

	CMFCRibbonMainPanel* pMainPanel = m_wndRibbonBar.AddMainCategory (
		_T("File"), IDB_FILESMALL, IDB_FILELARGE);

	pMainPanel->Add (new CMFCRibbonButton (ID_FILE_NEW, _T("&New"), 0, 0));
	pMainPanel->Add (new CMFCRibbonButton (ID_FILE_OPEN, _T("&Open..."), 1, 1));

	pMainPanel->Add (new CMFCRibbonButton (ID_FILE_SAVE, _T("&Save"), 2, 2));

	pMainPanel->Add (new CMFCRibbonButton (ID_FILE_SAVE_AS, _T("Save &As..."), 3, 3));

	std::auto_ptr<CMFCRibbonButton> apBtnPrint(new CMFCRibbonButton (ID_FILE_PRINT, _T("Print"), 6, 6));
	apBtnPrint->SetKeys (_T("p"), _T("w"));

	apBtnPrint->AddSubItem (new CMFCRibbonLabel (_T("Preview and print the document")));
	apBtnPrint->AddSubItem (new CMFCRibbonButton (ID_FILE_PRINT_DIRECT, _T("&Quick Print"), 7, 7, TRUE));
	apBtnPrint->AddSubItem (new CMFCRibbonButton (ID_FILE_PRINT_PREVIEW, _T("Print Pre&view"), 8, 8, TRUE));

	pMainPanel->Add (apBtnPrint.release());

	pMainPanel->Add (new CMFCRibbonSeparator (TRUE));
	pMainPanel->Add (new CMFCRibbonButton (ID_FILE_CLOSE, _T("&Close"), 9, 9));

	pMainPanel->AddRecentFilesList (_T("Recent Documents"));

	pMainPanel->AddToBottom (new CMFCRibbonMainPanelButton (ID_APP_EXIT, _T("E&xit"), 15));

	//--------------------------------------------
	// Add "Home" category with "Clipboard" panel:
	//--------------------------------------------
	CMFCRibbonCategory* pCategory = m_wndRibbonBar.AddCategory (
		_T("&Home"),
		IDB_WRITE,
		IDB_WRITELARGE);

	//--------------------------
	// Create "Clipboard" panel:
	//--------------------------
	CMFCRibbonPanel* pPanelClipboard = pCategory->AddPanel (
		_T("Clipboard\nd"), 
		m_PanelImages.ExtractIcon (27));

	CMFCRibbonButton* pBtnPaste = new CMFCRibbonButton (ID_EDIT_PASTE, _T("Paste\nv"), 0, 0);
	pBtnPaste->SetMenu (IDR_PASTE_MENU, TRUE);
	pPanelClipboard->Add (pBtnPaste);

	pPanelClipboard->Add (new CMFCRibbonButton (ID_EDIT_CUT, _T("Cut\nx"), 1));
	pPanelClipboard->Add (new CMFCRibbonButton (ID_EDIT_COPY, _T("Copy\nc"), 2));
	pPanelClipboard->Add (new CMFCRibbonButton (0, _T("Paint\np"), 3));

	//-----------------------
	// Create "Window" panel:
	//-----------------------
	CMFCRibbonPanel* pPanelWindow = pCategory->AddPanel (
		_T("Window\nw"), 
		m_PanelImages.ExtractIcon (7));

	pPanelWindow->Add (new CMFCRibbonCheckBox (ID_VIEW_WORKSPACE, _T("View 1\n1")));
	pPanelWindow->Add (new CMFCRibbonCheckBox (ID_VIEW_WORKSPACE2, _T("View 2\n2")));
	pPanelWindow->Add (new CMFCRibbonCheckBox (ID_VIEW_OUTPUT, _T("Output\no")));
	pPanelWindow->Add (new CMFCRibbonSeparator);

	CMFCRibbonButton* pBtnWindows = new CMFCRibbonButton (0, _T("Windows\ni"), -1, 1);
	pBtnWindows->SetMenu (IDR_WINDOWS_MENU, TRUE);
	pPanelWindow->Add (pBtnWindows);

	//-----------------------------------
	// Add quick access toolbar commands:
	//-----------------------------------
	CList<UINT, UINT> lstQATCmds;

	lstQATCmds.AddTail (ID_FILE_SAVE);
	lstQATCmds.AddTail (ID_FILE_PRINT_DIRECT);

	m_wndRibbonBar.SetQuickAccessCommands (lstQATCmds);

	m_wndRibbonBar.AddToTabs (new CMFCRibbonButton (ID_APP_ABOUT, _T("\na"), m_PanelImages.ExtractIcon (0)));
}

BOOL CMainFrame::IsPrintPreviewMode ()
{
	return GetDockingManager()->IsPrintPreviewValid();
}
