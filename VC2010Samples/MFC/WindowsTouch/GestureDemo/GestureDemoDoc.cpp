// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// GestureDemoDoc.cpp : implementation of the CGestureDemoDoc class
//

#include "stdafx.h"
#include "GestureDemo.h"

#include "GestureDemoDoc.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGestureDemoDoc

IMPLEMENT_DYNCREATE(CGestureDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CGestureDemoDoc, CDocument)
END_MESSAGE_MAP()


// CGestureDemoDoc construction/destruction

CGestureDemoDoc::CGestureDemoDoc()
{
	// TODO: add one-time construction code here

}

CGestureDemoDoc::~CGestureDemoDoc()
{
}

BOOL CGestureDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

BOOL CGestureDemoDoc::OnOpenDocument(LPCTSTR lpszFile)
{
	if (!m_Image.IsNull())
	{
		m_Image.Destroy();
	}

	HRESULT hr = m_Image.Load(lpszFile);
	if (FAILED(hr))
	{
		UpdateAllViews(NULL);

		CString strErr;
		strErr.Format(_T("Cannot open image file \"%s\"\r\nError Code is: %x"), lpszFile, hr);
		AfxMessageBox(strErr);
		return FALSE;
	}

	UpdateAllViews(NULL);
	return TRUE;
}



// CGestureDemoDoc serialization

void CGestureDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CGestureDemoDoc diagnostics

#ifdef _DEBUG
void CGestureDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGestureDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGestureDemoDoc commands
