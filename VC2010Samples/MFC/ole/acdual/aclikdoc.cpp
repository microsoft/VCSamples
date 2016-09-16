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
	DISP_FUNCTION(CAutoClickDoc, "TestError", TestErrorHandler, VT_EMPTY, VTS_I2)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// DUAL_SUPPORT_START
//    Original code:
//       // Note: we add support for IID_IAClick to support typesafe binding
//       //  from VBA.  This IID must match the GUID that is attached to the
//       //  dispinterface in the .ODL file.
//
//       // {47D53E05-CC33-11CE-8F35-00DD01109044}
//       static const IID IID_IAClick =
//       { 0x47d53e05, 0xcc33, 0x11ce, { 0x8f, 0x35, 0x0, 0xdd, 0x1, 0x10, 0x90, 0x44 } };
//
//       BEGIN_INTERFACE_MAP(CAutoClickDoc, CDocument)
//          INTERFACE_PART(CAutoClickDoc, IID_IAClick, Dispatch)
//       END_INTERFACE_MAP()
//

// Note: we add support for DIID_IAClick to support typesafe binding
// from VBA.  We add support for IID_IDualAClick to support our dual
// interface. See ACDual.H for the definition of DIID_IAClick and
// IID_IDualAClick.
//
// DUAL_ERRORINFO_PART indicates we support OLE Automation
// error handling.
//
BEGIN_INTERFACE_MAP(CAutoClickDoc, CDocument)
	INTERFACE_PART(CAutoClickDoc, DIID_IAClick, Dispatch)
	INTERFACE_PART(CAutoClickDoc, IID_IDualAClick, DualAClick)
	DUAL_ERRORINFO_PART(CAutoClickDoc)
END_INTERFACE_MAP()

// DUAL_SUPPORT_END

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

void CAutoClickDoc::TestErrorHandler(short wCode)
{
	CString strError;
	strError.Format(IDS_TESTERROR, wCode);
	AfxThrowOleDispatchException((WORD)wCode,
								 strError,
								 (UINT)wCode);
}

// DUAL_SUPPORT_START

// delegate standard IDispatch methods to MFC IDispatch implementation
DELEGATE_DUAL_INTERFACE(CAutoClickDoc, DualAClick)

// Our method and property functions can generally just
// delegate back to the methods we generated using
// ClassWizard. However, if we set up properties to
// access variables directly, we will need to write the
//  code to get/put the value into the variable.

STDMETHODIMP CAutoClickDoc::XDualAClick::put_text(BSTR newText)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		// MFC automatically converts from Unicode BSTR to
		// Ansi CString, if necessary...
		pThis->m_str = newText;
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::get_text(BSTR* retval)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		// MFC automatically converts from Ansi CString to
		// Unicode BSTR, if necessary...
		pThis->m_str.SetSysString(retval);
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::put_x(short newX)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		pThis->SetX(newX);
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::get_x(short FAR* retval)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		*retval = pThis->GetX();
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::put_y(short newY)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		pThis->SetY(newY);
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::get_y(short FAR* retval)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		*retval = pThis->GetY();
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::put_Position(
	IDualAutoClickPoint FAR* newPosition)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		// Passing IDispatch-based interface pointers around doesn't
		// work quite as smoothly as you might think, especially if
		// you need to call CCmdTarget::FromIDispatch(), as our
		// SetPosition method does. Here's one way to work around this -
		// give SetPosition the original IDispatch that MFC sets up.

		LPDISPATCH lpDisp = NULL;
		newPosition->QueryInterface(IID_IDispatch, (LPVOID*)&lpDisp);
		pThis->SetPosition(lpDisp);
		lpDisp->Release();
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::putref_Position(
	IDualAutoClickPoint FAR* newPosition)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		// Passing IDispatch-based interface pointers around doesn't
		// work quite as smoothly as you might think, especially if
		// you need to call CCmdTarget::FromIDispatch(), as our
		// SetPosition method does. Here's one way to work around this -
		// give SetPosition the original IDispatch that MFC sets up.

		LPDISPATCH lpDisp = NULL;
		newPosition->QueryInterface(IID_IDispatch, (LPVOID*)&lpDisp);
		pThis->SetPosition(lpDisp);
		lpDisp->Release();
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::get_Position(
	IDualAutoClickPoint FAR* FAR* retval)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		// GetPosition gives us the original IDispatch that MFC
		// sets up, so we need to QI for the custom interface.
		LPDISPATCH lpDisp;
		lpDisp = pThis->GetPosition();
		lpDisp->QueryInterface(IID_IDualAutoClickPoint, (LPVOID*)retval);
		lpDisp->Release();

		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::RefreshWindow()
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		pThis->Refresh();
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::SetAllProps(
	short x, short y, BSTR text)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		CString strTemp(text);
		pThis->SetAllProps(x, y, strTemp);
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::ShowWindow()
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		pThis->ShowWindow();
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CAutoClickDoc::XDualAClick::TestError(short wCode)
{
	METHOD_PROLOGUE(CAutoClickDoc, DualAClick)

	TRY_DUAL(IID_IDualAClick)
	{
		pThis->TestErrorHandler(wCode);
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

// Implement ISupportErrorInfo to indicate we support the
// OLE Automation error handler.
IMPLEMENT_DUAL_ERRORINFO(CAutoClickDoc, IID_IDualAClick)

// DUAL_SUPPORT_END
