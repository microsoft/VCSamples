// strcoll.h : header file
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
// CStringCollect command target

class CStringCollect : public CCmdTarget
{
    DECLARE_DYNCREATE(CStringCollect)
protected:
    CStringCollect();           // protected constructor used by dynamic creation

// Attributes
public:
    CStringArray m_strArray;

// Operations
public:
    void CheckIndex(long nIndex);

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CStringCollect)
    public:
    virtual void OnFinalRelease();
    //}}AFX_VIRTUAL

// Implementation
protected:
    virtual ~CStringCollect();

    // Generated message map functions
    //{{AFX_MSG(CStringCollect)
        // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
    DECLARE_OLECREATE(CStringCollect)

    // Generated OLE dispatch map functions
    //{{AFX_DISPATCH(CStringCollect)
    afx_msg long GetCount();
    afx_msg long Add(LPCTSTR newValue);
    afx_msg long Find(LPCTSTR findValue);
    afx_msg long Remove(const VARIANT FAR& removeValue);
    afx_msg void RemoveAll();
    afx_msg BSTR GetItem(long nIndex);
    afx_msg void SetItem(long nIndex, LPCTSTR lpszNewValue);
    //}}AFX_DISPATCH
    afx_msg LPUNKNOWN GetNewEnum();

    DECLARE_DISPATCH_MAP()

    DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
