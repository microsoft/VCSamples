// TESTDLL1.H Public API exported from 'TESTDLL1.DLL'
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// Note: This sample uses AFX_EXT_CLASS to export an entire class.
// This avoids creating a .DEF file with all the decorated names for
// the class.  Creating a .DEF file is more efficient since the names
// can be exported by ordinal.  To use that method of exporting, much
// like MFC does itself, uncomment the following two lines and add
// the appropriate lines to your .DEF file.

//#undef AFX_DATA
//#define AFX_DATA AFX_EXT_DATA

// Initialize the DLL, register the classes etc
extern "C" AFX_EXT_API void WINAPI InitTestDLL1();

/////////////////////////////////////////////////////////////////////////////
// Simple Text document

class AFX_EXT_CLASS CTextDoc : public CDocument
{
	DECLARE_DYNCREATE(CTextDoc)
protected:
	void Serialize(CArchive& ar);
	//{{AFX_MSG(CTextDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Simple output view

class AFX_EXT_CLASS CHelloView : public CView
{
	DECLARE_DYNCREATE(CHelloView)
public:
	CHelloView();

// Implementation
protected:
	UINT m_nIDColor;        // last color command
	COLORREF m_clrText;

	virtual void OnDraw(CDC* pDC);
	// message handlers
	//{{AFX_MSG(CHelloView)
	afx_msg void OnColor();
	afx_msg void OnCustomColor();
	afx_msg void OnUpdateColor(CCmdUI* pCmdUI);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Simple do-nothing document

class AFX_EXT_CLASS CDummyDoc : public CDocument
{
	DECLARE_DYNCREATE(CDummyDoc)
protected:
	//{{AFX_MSG(CDummyDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#undef AFX_DATA
#define AFX_DATA

/////////////////////////////////////////////////////////////////////////////
