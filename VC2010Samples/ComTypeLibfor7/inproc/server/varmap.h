// varmap.h : header file
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
// CVariantMap command target

class CVariantMap : public CCmdTarget
{
    DECLARE_DYNCREATE(CVariantMap)
protected:
    CVariantMap();           // protected constructor used by dynamic creation

// Attributes
public:
    CString m_str2;
    long m_i2;

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CVariantMap)
    public:
    virtual void OnFinalRelease();
    //}}AFX_VIRTUAL

// Implementation
protected:
    virtual ~CVariantMap();
    CMapVariantToVariant m_map;

    // Generated message map functions
    //{{AFX_MSG(CVariantMap)
        // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
    DECLARE_OLECREATE(CVariantMap)

    // Generated OLE dispatch map functions
    //{{AFX_DISPATCH(CVariantMap)
    CString m_str1;
    long m_i1;
    afx_msg BSTR GetStr2();
    afx_msg void SetStr2(LPCTSTR lpszNewValue);
    afx_msg long GetI2();
    afx_msg void SetI2(long nNewValue);
    afx_msg long GetCount();
    afx_msg void SetAt(const VARIANT FAR& from, const VARIANT FAR& to);
    afx_msg void RemoveAll();
    afx_msg void RemoveKey(const VARIANT FAR& key);
    afx_msg BOOL IsEmpty();
    afx_msg VARIANT GetItem(const VARIANT FAR& from);
    //}}AFX_DISPATCH
    DECLARE_DISPATCH_MAP()
    afx_msg LPUNKNOWN GetNewEnum();

    DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
