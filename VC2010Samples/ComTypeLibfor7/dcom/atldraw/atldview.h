// ATLDrawView.h : interface of the CATLDrawView class
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.
//
/////////////////////////////////////////////////////////////////////////////

class CATLDrawView : public CView
{
protected: // create from serialization only
    CATLDrawView();
    DECLARE_DYNCREATE(CATLDrawView)

// Attributes
public:
    CATLDrawDoc* GetDocument();

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CATLDrawView)
    public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    protected:
    virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
    virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CATLDrawView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif
    BOOL    ConnectSink(REFIID iid, LPUNKNOWN punkSink);
    void    DisconnectSink(REFIID iid, DWORD dwCookie);

private:
    IDrawServPtr m_pDrawServ;
    BOOL         m_bDragging;
    CPoint       m_pos;
    COLORREF     m_col;
    DWORD        m_dwDrawServ;

// Generated message map functions
protected:
    //{{AFX_MSG(CATLDrawView)
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnServerConnect();
    afx_msg void OnServerDisconnent();
    afx_msg void OnUpdateServerConnect(CCmdUI* pCmdUI);
    afx_msg void OnUpdateServerDisconnent(CCmdUI* pCmdUI);
    afx_msg void OnViewColor();
    afx_msg void OnClear();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
    void    Draw(long x1, long y1, long x2, long y2, unsigned long col);

    BEGIN_INTERFACE_PART(DrawServ, IDrawServ)
        STDMETHOD(GetTypeInfoCount)(unsigned int*)
            { return E_NOTIMPL; }
        STDMETHOD(GetTypeInfo)(unsigned int, LCID, ITypeInfo**)
            { return E_NOTIMPL; }
        STDMETHOD(GetIDsOfNames)(REFIID, LPOLESTR*, unsigned int, LCID, DISPID*)
            { return E_NOTIMPL; }
        STDMETHOD(Invoke)(DISPID, REFIID, LCID, unsigned short, DISPPARAMS*,
                          VARIANT*, EXCEPINFO*, unsigned int*)
            { return E_NOTIMPL; }
        STDMETHOD(raw_Draw)(long x1, long y1, long x2, long y2, unsigned long col);
    END_INTERFACE_PART(DrawServ)

    DECLARE_INTERFACE_MAP()
};

#ifndef _DEBUG  // debug version in ATLDrawView.cpp
inline CATLDrawDoc* CATLDrawView::GetDocument()
   { return (CATLDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
