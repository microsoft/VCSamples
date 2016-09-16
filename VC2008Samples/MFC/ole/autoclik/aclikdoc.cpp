// AClikDoc.cpp : implementation of the CAutoClickDoc class
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
#include "AutoClik.h"

#include "AClikDoc.h"
#include "Dialogs.h"
#include "ClikPnt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoClickDoc

IMPLEMENT_DYNCREATE(CAutoClickDoc, CDocument)

BEGIN_MESSAGE_MAP(CAutoClickDoc, CDocument)
	//{{AFX_MSG_MAP(CAutoClickDoc)
	ON_COMMAND(ID_EDIT_CHANGETEXT, OnEditChangetext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAutoClickDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CAutoClickDoc)
	DISP_PROPERTY(CAutoClickDoc, "text", m_str, VT_BSTR)
	DISP_PROPERTY_EX(CAutoClickDoc, "x", GetX, SetX, VT_I2)
	DISP_PROPERTY_EX(CAutoClickDoc, "y", GetY, SetY, VT_I2)
	DISP_PROPERTY_EX(CAutoClickDoc, "Position", GetPosition, SetPosition, VT_DISPATCH)
	DISP_FUNCTION(CAutoClickDoc, "RefreshWindow", Refresh, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CAutoClickDoc, "SetAllProps", SetAllProps, VT_EMPTY, VTS_I2 VTS_I2 VTS_BSTR)
	DISP_FUNCTION(CAutoClickDoc, "ShowWindow", ShowWindow, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IAClick to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {47D53E05-CC33-11CE-8F35-00DD01109044}
static const IID IID_IAClick =
{ 0xfc866850, 0x9F96, 0x11ce, { 0xb0, 0xf2, 0x00, 0xaa, 0x00, 0x6c, 0x28, 0xb3 } };

BEGIN_INTERFACE_MAP(CAutoClickDoc, CDocument)
	INTERFACE_PART(CAutoClickDoc, IID_IAClick, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoClickDoc construction/destruction

CAutoClickDoc::CAutoClickDoc()
{
	EnableAutomation();
	m_pt = CPoint(10, 10);
	m_str = _T("Automation!");

	AfxOleLockApp();
}

CAutoClickDoc::~CAutoClickDoc()
{
	AfxOleUnlockApp();
}

BOOL CAutoClickDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

void CAutoClickDoc::Refresh()
{
	UpdateAllViews(NULL);
	SetModifiedFlag();
}

/////////////////////////////////////////////////////////////////////////////
// CAutoClickDoc serialization

void CAutoClickDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_pt << m_str;
	}
	else
	{
		ar >> m_pt >> m_str;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAutoClickDoc diagnostics

#ifdef _DEBUG
void CAutoClickDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAutoClickDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAutoClickDoc commands

void CAutoClickDoc::OnEditChangetext() 
{
	CChangeText dlg;
	dlg.m_str = m_str;
	if (dlg.DoModal())
	{
		m_str = dlg.m_str;
		Refresh();
	}
}

short CAutoClickDoc::GetX()
{
	return (short)m_pt.x;
}

void CAutoClickDoc::SetX(short nNewValue)
{
	m_pt.x = nNewValue;
	Refresh();
}

short CAutoClickDoc::GetY()
{
	return (short)m_pt.y;
}

void CAutoClickDoc::SetY(short nNewValue)
{
	m_pt.y = nNewValue;
	Refresh();
}

void CAutoClickDoc::SetAllProps(short x, short y, LPCTSTR text)
{
	m_pt.x = x;
	m_pt.y = y;
	m_str = text;
	Refresh();
}

void CAutoClickDoc::ShowWindow()
{
	POSITION pos = GetFirstViewPosition();
	CView* pView = GetNextView(pos);
	if (pView != NULL)
	{
		CFrameWnd* pFrameWnd = pView->GetParentFrame();
		pFrameWnd->ActivateFrame(SW_SHOW);
		pFrameWnd = pFrameWnd->GetParentFrame();
		if (pFrameWnd != NULL)
			pFrameWnd->ActivateFrame(SW_SHOW);
	}
}



LPDISPATCH CAutoClickDoc::GetPosition() 
{
   #pragma warning (suppress: 6014)
	CAutoClickPoint* pPos = new CAutoClickPoint;
	pPos->SetClickPoint(m_pt);

	LPDISPATCH lpResult = pPos->GetIDispatch(FALSE);
	return lpResult;
}

void CAutoClickDoc::SetPosition(LPDISPATCH newValue) 
{
	CAutoClickPoint* pPos = (CAutoClickPoint*)CCmdTarget::FromIDispatch(newValue);
	if (pPos != NULL && pPos->IsKindOf(RUNTIME_CLASS(CAutoClickPoint)))
	{
		m_pt = pPos->GetClickPoint();
		Refresh();
	}
}
