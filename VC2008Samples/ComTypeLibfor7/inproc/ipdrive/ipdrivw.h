// ipdrivw.h : interface of the CDriverView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CDriverView : public CFormView
{
protected: // create from serialization only
    CDriverView();
    DECLARE_DYNCREATE(CDriverView)

public:
    //{{AFX_DATA(CDriverView)
    enum { IDD = IDD_IPDRIVE_FORM };
    CEdit   m_toValue;
    CComboBox   m_toType;
    CEdit   m_ctrlValue;
    CComboBox   m_ctrlType;
    //}}AFX_DATA

// Attributes
public:
    CDriverDoc* GetDocument();

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDriverView)
    public:
    virtual void OnInitialUpdate();
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CDriverView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    // formatting strings for the dialog
    CString m_strCurrentCount;
    CString m_strLastType;
    CString m_strLastValue;
    BOOL m_bInitialized;

    _variant_t GetFromVariant();
    _variant_t GetToVariant();

    void UpdateCurrentCount();
    void UpdateToNothing();
    void UpdateCurrentVariant(const _variant_t& va);

// Generated message map functions
protected:
    //{{AFX_MSG(CDriverView)
    afx_msg void OnLookup();
    afx_msg void OnRemove();
    afx_msg void OnAdd();
    afx_msg void OnButton1();
    afx_msg void OnButton2();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ipdrivw.cpp
inline CDriverDoc* CDriverView::GetDocument()
   { return (CDriverDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
