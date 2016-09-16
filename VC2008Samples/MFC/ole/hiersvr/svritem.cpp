// svritem.cpp : implementation of the CServerNode class
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
#include <afxpriv.h>    // for CSharedFile
#include <malloc.h>     // for _alloca

#include "hiersvr.h"
#include "svritem.h"
#include "svrdoc.h"
#include "svrview.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Local dialogs used for implementation

class CChangeNameDlg : public CDialog
{
// Construction
public:
	CChangeNameDlg(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CChangeNameDlg)
	enum { IDD = IDD_CHANGE_NAME };
	int     m_shape;
	CString m_strDescription;
	CString m_strLinkKey;
	CEdit   m_editDescription;
	CButton m_btnOK;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CChangeNameDlg)
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CAddNodeDlg : public CDialog
{
// Construction
public:
	CAddNodeDlg(CWnd* pParent = NULL);  // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddNodeDlg)
	enum { IDD = IDD_ADD_NODE };
	CString m_strDescription;
	CString m_strLinkKey;
	int     m_shape;
	CEdit   m_editDescription;
	CButton m_btnOK;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	// Generated message map functions
	//{{AFX_MSG(CAddNodeDlg)
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CServerNode

IMPLEMENT_SERIAL(CServerNode, CObject, 0);

CServerNode::CServerNode(CServerDoc* pServerDoc)
{
	m_shape = shapeRect;
	m_bHideChildren = FALSE;
	m_pDocument = pServerDoc;

	m_pServerItem = NULL;   // will get connected if need be
}

// Special "new" operator for root node
CServerNode* CServerNode::CreateRootNode(CServerDoc* pDoc)
{
	CServerNode* pRoot = NULL;
	TRY
	{
		pRoot = new CServerNode(pDoc);
		pRoot->InitRootNode();
	}
	CATCH(CException, e)
	{
		delete pRoot;
		pRoot = NULL;
	}
	END_CATCH

	return pRoot;
}

// Special constructor for root node
void CServerNode::InitRootNode()
{
	DeleteChildNodes(); // initalized root node has no children

	m_strDescription = "Root node";
	m_strLinkKey = "%ROOT%";    // link name for root
	UpdateItemName();
}

BOOL CServerNode::FindAndDelete(CServerNode* pNode)
{
	POSITION pos = m_listChild.GetHeadPosition();
	while (pos != NULL)
	{
		POSITION posPrev = pos;
		CServerNode *pChild = (CServerNode*)m_listChild.GetNext(pos);
		if (pChild == pNode)
		{
			m_listChild.RemoveAt(posPrev);
			delete pNode;
			return TRUE;
		}
		if (pChild->FindAndDelete(pNode) == TRUE)
			return TRUE;
	}
	return FALSE;
}

CServerNode* CServerNode::FindNode(LPCTSTR pszItemName)
{
	// return this node if it matches!
	if (GetItemName() == pszItemName)
		return this;

	POSITION pos = m_listChild.GetHeadPosition();
	while (pos != NULL)
	{
		CServerNode* pChild = (CServerNode*)m_listChild.GetNext(pos);
		if (pChild->GetItemName() == pszItemName)
			return pChild;

		// recurse down the tree
		pChild = pChild->FindNode(pszItemName);
		if (pChild != NULL)
			return pChild;
	}
	return NULL;
}

void CServerNode::DeleteChildNodes()
{
	// delete child nodes
	POSITION pos = m_listChild.GetHeadPosition();
	while (pos != NULL)
		delete m_listChild.GetNext(pos);
	m_listChild.RemoveAll();
}

CServerNode::~CServerNode()
{
	// if we are the root of a document, clear it
	if (GetDocument()->m_pRoot == this)
		GetDocument()->m_pRoot = NULL;

	// if we are attached to a server item, detach from it
	if (m_pServerItem != NULL)
	{
		CServerItem* pItem = m_pServerItem;
		m_pServerItem = NULL;
		delete pItem;
	}

	// delete all of the child nodes of this node
	DeleteChildNodes();
}

BOOL CServerNode::IsChild(const CServerNode* pPotentialChild) const
{
	if (pPotentialChild == this)
		return TRUE;
	POSITION pos = m_listChild.GetHeadPosition();
	while (pos != NULL)
	{
		CServerNode* pNode = (CServerNode*)m_listChild.GetNext(pos);
		if (pNode->IsChild(pPotentialChild))
			return TRUE;
	}
	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CServerNode bounding rect helpers

#define CX_INSET    4
#define CY_INSET    2

// calc node size for arbitrary dc and return
//  (result is in logical units for the given DC)
void CServerNode::CalcNodeSize(CDC* pDC, CSize& sizeNode)
{
	ENSURE(pDC != NULL);
	sizeNode = pDC->GetTextExtent(m_strDescription,	m_strDescription.GetLength());
	sizeNode += CSize(CX_INSET * 2, CY_INSET * 2);
}

// calculate bounding rect using pointer to member for each node
void CServerNode::CalcBounding(CDC* pDC, CPoint& ptStart, CSize& sizeMax)
{
	ASSERT(sizeMax.cx >= 0 && sizeMax.cy >= 0);
	ASSERT(ptStart.x >= 0 && ptStart.y >= 0);

	CSize sizeNode;
	CalcNodeSize(pDC, sizeNode);

	ptStart.y += sizeNode.cy + CY_SEPARATOR;
	if (ptStart.y > sizeMax.cy)
		sizeMax.cy = ptStart.y;

	if (ptStart.x + sizeNode.cx > sizeMax.cx)
		sizeMax.cx = ptStart.x + sizeNode.cx;
	ptStart.x += CX_INDENT;
	// add in the kids
	if (!m_bHideChildren)
	{
		POSITION pos = m_listChild.GetHeadPosition();
		while (pos != NULL)
		{
			CServerNode* pNode = (CServerNode*)m_listChild.GetNext(pos);
			pNode->CalcBounding(pDC, ptStart, sizeMax);
		}
	}
	ptStart.x -= CX_INDENT;
}

/////////////////////////////////////////////////////////////////////////////
// CServerNode drawing helpers

BOOL CServerNode::Draw(CDC* pDC, CPoint pt, BOOL bSelected, CSize sizeNode)
{
	CRect rect(pt, sizeNode);
	if (!pDC->RectVisible(&rect))
		return TRUE;

	// draw a the bounding shape
	BOOL bOK = TRUE;

	CPen* pOldPen = NULL;
	CPen penHilite;
	int nPenStyle = (m_bHideChildren) ? PS_DASH : PS_SOLID;
	COLORREF crPen = (bSelected) ? RGB(255,0,0) : RGB(0,0,0);
	if (penHilite.CreatePen(nPenStyle, 0, crPen))
		pOldPen = pDC->SelectObject(&penHilite);

	switch (m_shape)
	{
	case shapeRect:
		bOK = pDC->Rectangle(rect);
		break;
	case shapeRound:
		bOK = pDC->RoundRect(rect, CPoint(7, 7));
		break;
	case shapeOval: // really just a rounder rounded rect
		bOK = pDC->RoundRect(rect, CPoint(14, 14));
		break;
	default:
		TRACE1("Error: unknown shape %d\n", m_shape);
		bOK = FALSE;
		break;
	}
	if (pOldPen != NULL)
		pDC->SelectObject(pOldPen);

	if (!bOK)
		return FALSE;

	// inset a bit
	rect.InflateRect(-CX_INSET, -CY_INSET);

	if (!pDC->ExtTextOut(rect.left, rect.top, ETO_OPAQUE, rect,
	  m_strDescription, m_strDescription.GetLength(), NULL))
		return FALSE;

	// all OK
	return TRUE;
}

int CServerNode::DrawTree(CDC* pDC, CPoint ptStart, CServerNode* pNodeSel)
{
	ENSURE(pDC != NULL);
	ASSERT(ptStart.x >= 0 && ptStart.y >= 0);

	// root node starts here
	int cyDrawn = 0;
	CSize sizeNode;
	CalcNodeSize(pDC, sizeNode);
	Draw(pDC, ptStart, this == pNodeSel, sizeNode);
	cyDrawn += sizeNode.cy + CY_SEPARATOR;

	if (m_listChild.GetCount() == 0 || m_bHideChildren)
		return cyDrawn;     // nothing more to draw

	// indent for the kids
	CPoint ptKid(ptStart.x + CX_INDENT, ptStart.y + cyDrawn);

	// draw the kids
	int yMid = 0;
	POSITION pos = m_listChild.GetHeadPosition();
	while (pos != NULL)
	{
		CServerNode *pChild = (CServerNode*)m_listChild.GetNext(pos);

		// add the little line
		yMid = ptKid.y + (sizeNode.cy)/2;
		pDC->MoveTo(ptStart.x + CX_BACKDENT, yMid);
		pDC->LineTo(ptKid.x, yMid);

		// draw the child node
		int cyKid = pChild->DrawTree(pDC, ptKid, pNodeSel);
		if (cyKid == -1)
			return -1;      // error

		cyDrawn += cyKid;
		ptKid.y += cyKid;
	}
	ASSERT(ptKid.y == ptStart.y + cyDrawn);

	// draw the connecting line (down to last yMid)
	ENSURE(yMid != 0);
	int xLine = ptStart.x + CX_BACKDENT;
	pDC->MoveTo(xLine, ptStart.y + sizeNode.cy);
	pDC->LineTo(xLine, yMid);
	return cyDrawn;
}

// Serializes to file or to embedded OLE stream
void CServerNode::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << (WORD)m_shape;

		ASSERT(m_strLinkKey.IsEmpty() || m_strDescription != m_strLinkKey);
		if (m_pServerItem != NULL)
			ar << m_pServerItem->GetItemName();
		else
			ar << m_strLinkKey;
		ar << m_strDescription;
		ar << (WORD)m_bHideChildren;
	}
	else
	{
		// get back-pointer to document
		m_pDocument = (CServerDoc*)ar.m_pDocument;

		WORD wTemp;
		ar >> wTemp; m_shape = (EShape)wTemp;
		if (m_shape >= shapeMax)
			m_shape = shapeRect;
		ar >> m_strLinkKey >> m_strDescription;
		UpdateItemName();
		ar >> wTemp;
		m_bHideChildren = (BOOL)wTemp;
	}
	m_listChild.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CServerNode support for CF_TEXT format

void CServerNode::SaveAsText(CArchive& ar, int nLevel)
{
	ASSERT(ar.IsStoring());

	// indent node text
	char szTabs[MAX_LEVEL];
	int nTabs = min(nLevel, MAX_LEVEL);
	memset(szTabs, '\t', nTabs);
	ar.Write(szTabs, nTabs);

	// write node text itself
#ifdef _UNICODE
	int nLen = m_strDescription.GetLength();
	char* psz = (char*)_alloca(nLen+1);
	wcstombs(psz, m_strDescription, nLen+1);
	ar.Write(psz, nLen);
#else
	ar.Write(m_strDescription, m_strDescription.GetLength()*sizeof(TCHAR));
#endif

	// terminate line with CRLF
	static char BASED_CODE szCRLF[] = "\r\n";
	ar.Write(szCRLF, sizeof(szCRLF)-1);

	// write kids
	POSITION pos = m_listChild.GetHeadPosition();
	while (pos != NULL)
	{
		CServerNode* pNode = (CServerNode*)m_listChild.GetNext(pos);
		pNode->SaveAsText(ar, nLevel+1);
	}
}

void CServerNode::UpdateItemName()
{
	// empty link key if same as description (it is redundant)
	if (m_strLinkKey == m_strDescription)
		m_strLinkKey.Empty();

	// update link name in item if attached
	if (m_pServerItem != NULL)
	{
		CString* pstr;
		if (m_strLinkKey.IsEmpty())
			pstr = &m_strDescription;
		else
			pstr = &m_strLinkKey;
		m_pServerItem->SetItemName(*pstr);

		// empty link key since it is redundant with the server item
		m_strLinkKey.Empty();
	}
}

const CString& CServerNode::GetItemName()
{
	// use item name in server item if connected
	if (m_pServerItem != NULL)
		return m_pServerItem->GetItemName();

	// use description or link key depending on state of link key
	else if (m_strLinkKey.IsEmpty())
		return m_strDescription;
	else
		return m_strLinkKey;
}

BOOL CServerNode::PromptChangeNode()
{
	CChangeNameDlg dlg;
	dlg.m_strDescription = m_strDescription;
	dlg.m_strLinkKey = GetItemName();
	if (dlg.m_strLinkKey == dlg.m_strDescription)
		dlg.m_strLinkKey.Empty(); // leave empty for tracking link name
	dlg.m_shape = m_shape;

	if (dlg.DoModal() == IDOK)
	{
		m_strDescription = dlg.m_strDescription;
		m_strLinkKey = dlg.m_strLinkKey;
		UpdateItemName();   // syncronize names as appropriate
		m_shape = (EShape)dlg.m_shape;
		return TRUE;
	}
	return FALSE;
}

////////////////////////////////////////////////////////////////
// Creating child nodes

// Special constructor for child node
CServerNode* CServerNode::CreateChildNode(LPCTSTR lpszDescription)
{
	CServerNode* pNew = NULL;
	TRY
	{
		pNew = new CServerNode(GetDocument());
		pNew->m_strDescription = lpszDescription;
			// both item name and description start out the same

		// add as the last child
		m_listChild.AddTail(pNew);
	}
	CATCH (CException, e)
	{
		delete pNew;
		pNew = NULL;
	}
	END_CATCH

	return pNew;
}

CServerNode* CServerNode::PromptNewChildNode()
{
	CAddNodeDlg dlg;
	dlg.m_shape = (EShape)shapeRect;
	if (dlg.DoModal() != IDOK)
		return NULL;

	CServerNode* pNew = CreateChildNode(dlg.m_strDescription);
	if (pNew == NULL)
		AfxThrowMemoryException();
	pNew->m_shape = (EShape)dlg.m_shape;
	pNew->m_strLinkKey = dlg.m_strLinkKey;
	pNew->UpdateItemName();

	return pNew;
}

CServerNode* CServerNode::GetNext(CServerNode* pNode, BOOL bInit)
{
	static BOOL bFound;
	if (bInit)
		bFound = FALSE;

	if (pNode == this)
		bFound = TRUE;
	if (!m_bHideChildren)
	{
		POSITION pos = m_listChild.GetHeadPosition();
		while (pos != NULL)
		{
			CServerNode* pChild = (CServerNode*)m_listChild.GetNext(pos);
			if (bFound)
				return pChild;
			pChild = pChild->GetNext(pNode, FALSE);
			if (pChild != NULL)
				return pChild;
		}
	}
	// if reached top and last level return original
	if (bInit)
		return pNode;
	else
		return NULL;
}

CServerNode* CServerNode::GetPrev(CServerNode* pNode,BOOL bInit)
{
	static CServerNode* pPrev;
	if (bInit)
		pPrev = this;

	if (pNode == this)
		return pPrev;

	pPrev = this;

	if (!m_bHideChildren)
	{
		POSITION pos = m_listChild.GetHeadPosition();
		while (pos != NULL)
		{
			CServerNode* pCur = (CServerNode*)m_listChild.GetNext(pos);
			CServerNode* pChild = pCur->GetPrev(pNode, FALSE);
			if (pChild != NULL)
				return pChild;
		}
	}
	if (bInit)
		return pPrev;
	else
		return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// CChangeNameDlg dialog

CChangeNameDlg::CChangeNameDlg(CWnd* pParent)
	: CDialog(CChangeNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeNameDlg)
	//}}AFX_DATA_INIT
}

BOOL CChangeNameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	OnChange(); // after DDX
	return TRUE;
}

void CChangeNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeNameDlg)
	DDX_CBIndex(pDX, IDC_COMBO1, m_shape);
	DDX_Text(pDX, IDC_EDIT1, m_strDescription);
	DDX_Text(pDX, IDC_EDIT2, m_strLinkKey);
	DDX_Control(pDX, IDC_EDIT1, m_editDescription);
	DDX_Control(pDX, IDOK, m_btnOK);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChangeNameDlg, CDialog)
	//{{AFX_MSG_MAP(CChangeNameDlg)
	ON_EN_CHANGE(IDC_EDIT1, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CChangeNameDlg::OnChange()
{
	if (m_btnOK.m_hWnd)
		m_btnOK.EnableWindow(m_editDescription.GetWindowTextLength() > 0);
}

/////////////////////////////////////////////////////////////////////////////
// CAddNodeDlg dialog

CAddNodeDlg::CAddNodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddNodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddNodeDlg)
	//}}AFX_DATA_INIT
}

BOOL CAddNodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	OnChange(); // after DDX
	return TRUE;
}

void CAddNodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddNodeDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strDescription);
	DDX_Text(pDX, IDC_EDIT2, m_strLinkKey);
	DDX_CBIndex(pDX, IDC_COMBO1, m_shape);
	DDX_Control(pDX, IDC_EDIT1, m_editDescription);
	DDX_Control(pDX, IDOK, m_btnOK);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddNodeDlg, CDialog)
	//{{AFX_MSG_MAP(CAddNodeDlg)
	ON_EN_CHANGE(IDC_EDIT1, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CAddNodeDlg::OnChange()
{
	if (m_btnOK.m_hWnd)
		m_btnOK.EnableWindow(m_editDescription.GetWindowTextLength() > 0);
}

//////////////////////////////////////////////////////////////////////////////
// CServerItem construction

CServerItem::CServerItem(CServerDoc* pServerDoc, CServerNode* pServerNode)
	: COleServerItem(pServerDoc, TRUE)
{
	// need to attach this server item to the node in the document
	ASSERT_VALID(pServerNode);
	m_pServerNode = pServerNode;
	pServerNode->m_pServerItem = this;
	pServerNode->UpdateItemName();

	// support CF_TEXT format
	GetDataSource()->DelayRenderFileData(CF_TEXT);
}

CServerItem::~CServerItem()
{
	if (m_pServerNode != NULL)
	{
		m_pServerNode->m_pServerItem = NULL;
		m_pServerNode->m_strLinkKey = GetItemName();
		m_pServerNode->UpdateItemName();
	}
}

//////////////////////////////////////////////////////////////////////////////
// CServerItem verb handling

void CServerItem::OnOpen()
{
	if (IsLinkedItem() && m_pServerNode != NULL)
	{
		// for linked items, try to select this node in the document
		CServerDoc* pDoc = GetDocument();
		ASSERT(pDoc != NULL);
		POSITION pos = pDoc->GetFirstViewPosition();
		ASSERT(pos != NULL);
		CServerView* pView = (CServerView*)pDoc->GetNextView(pos);
		ASSERT_KINDOF(CServerView, pView);

		pView->SetSelection(m_pServerNode);
		pView->ScrollToItem(m_pServerNode, TRUE);
	}
	COleServerItem::OnOpen();
}

/////////////////////////////////////////////////////////////////////////////
// CServerItem drawing

BOOL CServerItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// determine extent based on screen dc
	rSize = CSize(0, 0);
	if (m_pServerNode != NULL)
	{
		CClientDC dc(NULL);
		dc.SetMapMode(MM_ANISOTROPIC);
		CServerDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		CPoint ptStart(CX_MARGIN, CY_MARGIN);
		pDoc->CalcBounding(&dc, m_pServerNode, ptStart, rSize);
		rSize.cx += CX_MARGIN;
		dc.LPtoHIMETRIC(&rSize); // convert pixels to HIMETRIC
	}
	return TRUE;
}

BOOL CServerItem::OnDraw(CDC* pDC, CSize& rSize)
{
	if (m_pServerNode != NULL)
	{
		// determine extent of this item in the document
		CServerDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		rSize = CSize(0, 0);
		CPoint ptStart(CX_MARGIN, CY_MARGIN);
		pDoc->CalcBounding(pDC, m_pServerNode, ptStart, rSize);
		rSize.cx += CX_MARGIN;

		// prepare to draw and remember the extent in himetric units
		pDC->SetWindowOrg(0, 0);
		pDC->SetWindowExt(rSize);
		pDC->SetViewportExt(rSize);  // Note: only affects the m_hAttribDC

		pDC->LPtoHIMETRIC(&rSize);   // convert pixels to HIMETRIC

		// CServerDoc::DrawTree selects and releases font automatically
		pDoc->DrawTree(pDC, ptStart, NULL, m_pServerNode);
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CServerItem clipboard handling

void CServerItem::Serialize(CArchive& ar)
{
	// serialize font info from document (so it looks like a document)
	CServerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->SerializeFontInfo(ar);

	// serialize node info
	ASSERT_VALID(m_pServerNode);
	m_pServerNode->Serialize(ar);
}

BOOL CServerItem::OnRenderFileData(LPFORMATETC lpFormatEtc, CFile* pFile)
{
	ENSURE(lpFormatEtc != NULL);
	if (lpFormatEtc->cfFormat != CF_TEXT)
		return COleServerItem::OnRenderFileData(lpFormatEtc, pFile);

	BOOL bResult = FALSE;
	if (m_pServerNode != NULL)
	{
		TRY
		{
			// save as text
			CArchive ar(pFile, CArchive::store);
			m_pServerNode->SaveAsText(ar, 0);
			ar << (BYTE)'\0';   // terminate with NUL character
			bResult = TRUE;
		}
		END_TRY
	}
	return bResult;
}

// OnGetClipboardData is used by CopyToClipboard and DoDragDrop
COleDataSource* CServerItem::OnGetClipboardData(BOOL bIncludeLink,
	LPPOINT pptOffset, LPSIZE pSize)
{
	ASSERT_VALID(this);

	if (m_pServerNode == NULL)
		return NULL;

	COleDataSource* pDataSource = new COleDataSource;
	TRY
	{
		GetNativeClipboardData(pDataSource);
		GetClipboardData(pDataSource, bIncludeLink, pptOffset, pSize);
	}
	CATCH_ALL(e)
	{
		delete pDataSource;
		THROW_LAST();
	}
	END_CATCH_ALL

	ASSERT_VALID(pDataSource);
	return pDataSource;
}

void CServerItem::GetNativeClipboardData(COleDataSource *pDataSource)
{
	ASSERT_VALID(this);
	ASSERT(CServerDoc::m_cfPrivate != NULL);

	// Create a shared file and associate a CArchive with it
	CSharedFile file;
	CArchive ar(&file,CArchive::store);

	// Serialize selected objects to the archive
	m_pServerNode->Serialize(ar);
	ar.Close();

	// put on local format instead of or in addation to
	pDataSource->CacheGlobalData(CServerDoc::m_cfPrivate,file.Detach());
}

/////////////////////////////////////////////////////////////////////////////
