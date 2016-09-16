// BindDoc.cpp : implementation of the CMFCBindDoc class
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
#include "MFCBind.h"

#include "BindDoc.h"
#include "BindView.h"
#include "CntrItem.h"
#include "MainFrm.h"
#include "ObjView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCBindDoc

IMPLEMENT_DYNCREATE(CMFCBindDoc, COleDocument)

BEGIN_MESSAGE_MAP(CMFCBindDoc, COleDocument)
	//{{AFX_MSG_MAP(CMFCBindDoc)
	ON_COMMAND(ID_OLE_INSERT_NEW, OnOleInsertNew)
	ON_COMMAND(ID_SECTION_REMOVE, OnSectionRemove)
	ON_UPDATE_COMMAND_UI(ID_SECTION_REMOVE, OnUpdateSectionRemove)
	ON_COMMAND(ID_FILE_PRINT, OnFilePrint)
	ON_COMMAND(ID_FILE_PRINTALLSECTIONS, OnFilePrintAll)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST, COleDocument::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCBindDoc construction/destruction

CMFCBindDoc::CMFCBindDoc()
{
	// Use OLE compound files
	EnableCompoundFile();
}

CMFCBindDoc::~CMFCBindDoc()
{
}

BOOL CMFCBindDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;
	CMainFrame *pFrame = NULL;
	CObjListView* pView = NULL;
	pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	if(!pFrame)
		return TRUE;

	pView = pFrame->GetObjListView();
	ASSERT(pView != NULL);

	if(pView)
		pView->RemoveAllItems();
	CMFCBindCntrItem::m_nDocID=1;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCBindDoc serialization

void CMFCBindDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class COleDocument enables serialization
	//  of the container document's COleClientItem objects.
	COleDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCBindDoc diagnostics

#ifdef _DEBUG
void CMFCBindDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CMFCBindDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCBindDoc commands

void CMFCBindDoc::OnOleInsertNew()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CMFCBindCntrItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal(COleInsertDialog::DocObjectsOnly) != IDOK)
		return;

	CMainFrame* pFrame = (CMainFrame*) AfxGetApp()->m_pMainWnd;
	ENSURE(pFrame != NULL);

	CMFCBindView* pViewObjCont = (CMFCBindView*) pFrame->GetDocView();
	ENSURE(pViewObjCont != NULL);

	pViewObjCont->BeginWaitCursor();

	CMFCBindCntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		pItem = new CMFCBindCntrItem(this);
		ASSERT_VALID(pItem);

		//have the dialog create the item
		if (!dlg.CreateItem(pItem))
		{
			delete pItem;
			return;
		}
		ASSERT_VALID(pItem);

		// make sure we deactivate any active items first.
		COleClientItem* pActiveItem = GetInPlaceActiveItem(pViewObjCont);
		if (pActiveItem != NULL)
			pActiveItem->Deactivate();

		// If item created from class list (not from file) then launch
		//  the server to edit the item.
		pItem->Activate(OLEIVERB_SHOW, pViewObjCont);
		ASSERT_VALID(pItem);

		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted.

		// TODO: reimplement selection as appropriate for your application

		// set selection to last inserted item
		pViewObjCont->m_pSelection = (CMFCBindCntrItem*) pItem;
		UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();

			pFrame->GetObjListView()->RemoveItem(pItem);
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	pViewObjCont->EndWaitCursor();
}

void CMFCBindDoc::OnSectionRemove()
{
	// This is the menu handler for the Remove menu item.  We get
	// the currently selected item, close it, remove it from the document's
	// list of items and remove it's icon from the list box.

	CMainFrame *pFrame = (CMainFrame*) AfxGetApp()->m_pMainWnd;
	ENSURE(pFrame != NULL);

	CView *pViewObjCont = (CView*) pFrame->GetDocView();
	ENSURE(pViewObjCont != NULL);

	COleClientItem* pItem = GetPrimarySelectedItem(pViewObjCont);

	if (pItem != NULL)
	{
		// remove the item from the list box.
		pItem->Delete();
		pFrame->GetObjListView()->RemoveItem(pItem);
	}
}

void CMFCBindDoc::OnUpdateSectionRemove(CCmdUI* pCmdUI)
{
	// we'll only enable the Remove menu item if there is a selected object
	CMainFrame *pFrame = (CMainFrame*) AfxGetApp()->m_pMainWnd;
	ENSURE(pFrame != NULL);

	CView *pObjCont = (CView*) pFrame->GetDocView();

	if (pObjCont != NULL)
		pCmdUI->Enable(); //we have an object selected
	else
		pCmdUI->Enable(FALSE);

}


void CMFCBindDoc::OnFilePrint()
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	ENSURE(pFrame != NULL);

	CMFCBindView *pView = pFrame->GetDocView();
	ENSURE(pView != NULL);

	CPrintInfo pi;
	pView->DoPreparePrinting(&pi);
	if( COleDocObjectItem::OnPreparePrinting(pView,&pi) )
	{
		COleDocObjectItem::OnPrint(pView,&pi);
	}
}

void CMFCBindDoc::OnFilePrintAll()
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	ENSURE(pFrame != NULL);

	CMFCBindView *pView = pFrame->GetDocView();
	ENSURE(pView != NULL);

	CPrintInfo pi;
	pView->DoPreparePrinting(&pi);
	if( COleDocObjectItem::OnPreparePrinting(pView,&pi,TRUE) )
	{
		COleDocObjectItem::OnPrint(pView,&pi,TRUE);
	}


}

BOOL CMFCBindDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	//Make sure all items are removed from the object list view.
	CMainFrame *pFrame = NULL;
	CObjListView *pObjView=NULL;
	pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	if(pFrame)
		pObjView = pFrame->GetObjListView();
	if(pObjView)
		pObjView->RemoveAllItems();

	//Open the new document
	if (!COleDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	POSITION pos = GetStartPosition();
	//activate and set focus to the first item.
	COleClientItem *pActiveItem = GetNextClientItem(pos);
	if(pActiveItem)
	{
		ENSURE(pFrame);
		pActiveItem->Activate(OLEIVERB_SHOW,pFrame->GetDocView());
		pActiveItem->GetInPlaceWindow()->SetFocus();
		CMFCBindView *pView = pFrame->GetDocView();
		pView->m_pSelection = (CMFCBindCntrItem*)pActiveItem;
		pFrame->GetObjListView()->m_listbox.SetCurSel(0);
	}
	CMFCBindCntrItem::m_nDocID=1;

	return TRUE;
}

void CMFCBindDoc::OnCloseDocument()
{
	CMainFrame *pFrame = NULL;
	CObjListView* pView = NULL;
	pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	ENSURE(pFrame != NULL);

	pView = pFrame->GetObjListView();
	ENSURE(pView != NULL);

	if(pView)
		pView->RemoveAllItems();

	COleDocument::OnCloseDocument();
}
