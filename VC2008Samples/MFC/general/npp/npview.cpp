// npview.cpp : implementation of the CNotepadView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//

#include "stdafx.h"
#include "np.h"
#include "combobar.h"
#include "mainfrm.h"
#include "npdoc.h"
#include "npview.h"
#include "gotodlg.h"
#include "finddlg.h"

#include <afxcoll.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotepadView

IMPLEMENT_DYNCREATE(CNotepadView, CEditView)

BEGIN_MESSAGE_MAP(CNotepadView, CEditView)
	//{{AFX_MSG_MAP(CNotepadView)
	ON_COMMAND(ID_EDIT_GOTO, OnEditGoto)
	ON_UPDATE_COMMAND_UI(ID_EDIT_GOTO, OnUpdateEditGoto)
	ON_COMMAND(ID_EDIT_FIND, OnEditFind)
	ON_UPDATE_COMMAND_UI(ID_EDIT_FIND, OnUpdateEditFind)
	ON_COMMAND(ID_VIEW_FIND_NEXT, OnViewFindNext)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotepadView construction/destruction

CNotepadView::CNotepadView()
{
	m_pFindDialog = new CFindDlg;
	m_pGotoDialog = new CGotoDlg;
}

CNotepadView::~CNotepadView()
{
	delete  m_pGotoDialog;
	delete  m_pFindDialog;
}

/////////////////////////////////////////////////////////////////////////////
// CNotepadView drawing

void CNotepadView::OnDraw(CDC* /*pDC*/)
{
	CNotepadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CNotepadView printing

BOOL CNotepadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CNotepadView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CNotepadView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CNotepadView diagnostics

#ifdef _DEBUG
void CNotepadView::AssertValid() const
{
	CEditView::AssertValid();
}

void CNotepadView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CNotepadDoc* CNotepadView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNotepadDoc)));
	return (CNotepadDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNotepadView message handlers


void CNotepadView::OnEditGoto()
{
	if(m_pGotoDialog->DoModal() != IDOK)
		return;

	if(m_pGotoDialog->m_nLineNum < 1)
	{
		CString s1;
		s1.LoadString(NPERROR_INVALID_LINENUM);
		AfxMessageBox(s1);
		return;
	}

	CEdit &edit = GetEditCtrl();
	int i = edit.LineFromChar();            // this is the current line the cursor is on
	int nLine = m_pGotoDialog->m_nLineNum;  // line number to go to

	if(nLine > (edit.GetLineCount()))
	{
		CString s1;

		s1.LoadString(NPERROR_NUM_TOO_BIG);
		AfxMessageBox(s1);
		return;
	}

	// move window and caret
	--nLine;                    // edit control is zero based
	edit.LineScroll(nLine-i);   // new line number - the current line

	int idx;
	idx = edit.LineIndex(nLine);
	edit.SetSel(idx, idx);
}

void CNotepadView::OnUpdateEditGoto(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(GetWindowTextLength());
}

void CNotepadView::OnEditFind()
{
	CString s1, s2;
	CComboBox& comboBox = ((CMainFrame*)AfxGetMainWnd())->m_wndToolBar.m_toolBarCombo;

	// add user selected text from CEditView to the buffer
	GetSelectedText(s1);
	s2 = m_pFindDialog->m_szText; // save old string if user cancels

	if(s1.GetLength())
		m_pFindDialog->m_szText = s1;

	if(m_pFindDialog->DoModal() != IDOK)
	{
		m_pFindDialog->m_szText = s2; // restore old string.  user selected cancel
		return;
	}

	ASSERT(m_pFindDialog->m_szText.GetLength());

	// add it to the combo control on the toolbar
	comboBox.SetWindowText(m_pFindDialog->m_szText);
	m_searchHistory.AddString(m_pFindDialog->m_szText);

	if(m_pFindDialog->m_szText.GetLength())
		OnFindNext(m_pFindDialog->m_szText, m_pFindDialog->m_nDirection, m_pFindDialog->m_bMatchCase);
}

void CNotepadView::OnUpdateEditFind(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(GetWindowTextLength());
}

void CNotepadView::OnViewFindNext(CString &s1)
{
	OnFindNext(s1, m_pFindDialog->m_nDirection, m_pFindDialog->m_bMatchCase);
}

void CNotepadView::OnViewFindNext()
{
	CString s1;

	// if the user presses F3, see if there is a search pattern. if not, ask for one
	if (m_pFindDialog->m_szText.GetLength())
		OnFindNext(m_pFindDialog->m_szText, m_pFindDialog->m_nDirection, m_pFindDialog->m_bMatchCase);
	else
		PostMessage(WM_COMMAND, ID_EDIT_FIND);
}

BOOL CNotepadView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// change the view's font to SYSTEM_FIXED_FONT
	CFont *font = CFont::FromHandle((HFONT)::GetStockObject(SYSTEM_FIXED_FONT));
	BOOL bResult = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
	SetFont(font);

	return bResult;
}

void CNotepadView::OnEditPaste()
{
	CWnd* pComboWnd;
	CWnd* pFocusWnd;
	CComboBox& comboBox = ((CMainFrame*)AfxGetMainWnd())->m_wndToolBar.m_toolBarCombo;

	// Note: this is the handler for the accelerator (CTRL+V).  Since the accelerator goes to the
	// frame, find who has the focus to determine where to paste to.

	pFocusWnd = GetFocus();
	pComboWnd = comboBox.GetDlgItem(1001);

	ENSURE(pFocusWnd);
	ENSURE(pComboWnd);

	// if the focus is in the combobox edit control, do the paste in the control
	if(pFocusWnd->m_hWnd == pComboWnd->m_hWnd)
		comboBox.Paste();
	else
		GetEditCtrl().Paste();
}

void CNotepadView::OnEditCopy()
{
	CWnd* pComboWnd;
	CWnd* pFocusWnd;
	CComboBox& comboBox = ((CMainFrame*)AfxGetMainWnd())->m_wndToolBar.m_toolBarCombo;

	// Note: this is the handler for the accelerator (CTRL+C).  Since the accelerator goes to the
	// frame, find who has the focus to determine where to copy from.

	pFocusWnd = GetFocus();
	pComboWnd = comboBox.GetDlgItem(1001);

	ENSURE(pFocusWnd);
	ENSURE(pComboWnd);

	// if the focus is in the combobox edit control, do the copy from the control
	if(pFocusWnd->m_hWnd == pComboWnd->m_hWnd)
		comboBox.Copy();
	else
		GetEditCtrl().Copy();
}
