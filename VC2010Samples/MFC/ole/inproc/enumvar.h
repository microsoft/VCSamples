// enumvar.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CEnumVariant command target

class CEnumVariant : public CCmdTarget
{
	DECLARE_DYNCREATE(CEnumVariant)
public:
	CEnumVariant();         // protected constructor used by dynamic creation

// Attributes
public:
	int m_nIndex;           // next/current position w/in m_rgContents
	int m_nCount;           // total count of variants
	VARIANT* m_pContents;   // contents of collection

// Operations
public:
	void SetContents(VARIANT* pContents, int nCount, int nIndex = 0);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumVariant)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CEnumVariant();
	CEnumVariant* m_pClonedFrom;

	// Generated message map functions
	//{{AFX_MSG(CEnumVariant)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// Implementation of IEnumVARIANT
	BEGIN_INTERFACE_PART(EnumVARIANT, IEnumVARIANT)
		STDMETHOD(Next)(ULONG celt, VARIANT* rgvar, ULONG* pceltFetched);
		STDMETHOD(Skip)(ULONG celt) ;
		STDMETHOD(Reset)() ;
		STDMETHOD(Clone)(IEnumVARIANT** ppenum);
	END_INTERFACE_PART(EnumVARIANT)
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
