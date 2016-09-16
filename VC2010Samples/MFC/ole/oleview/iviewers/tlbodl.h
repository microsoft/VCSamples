// tlbodl.h : header file
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
// CTypeLibODLView view

class CTypeLibODLView : public CEditView
{
friend class CTypeLibWnd ;
protected:
	CTypeLibODLView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTypeLibODLView)

// Attributes
public:
	CFont   m_Font ;

// Operations
public:
	HRESULT  DeCompileTypeLib( IStream* pstm, ITypeLib* ptlb, UINT uiIndent  = 0 ) ;
	HRESULT  DeCompileTypedef( IStream* pstm, ITypeInfo* pti, UINT uiIndent  = 0 ) ;
	HRESULT  DeCompileModule( IStream* pstm, ITypeInfo* pti, UINT uiIndent  = 0 ) ;
	HRESULT  DeCompileInterface( IStream* pstm, ITypeInfo* pti, UINT uiIndent  = 0 ) ;
	HRESULT  DeCompileDispinterface( IStream* pstm, ITypeInfo* pti, UINT uiIndent  = 0 ) ;
	HRESULT  DeCompileCoClass( IStream* pstm, ITypeInfo* pti, UINT uiIndent  = 0 ) ;
	HRESULT  DeCompileFunc( IStream* pstm, ITypeInfo* pti, MEMBERID memid, UINT uiIndent  = 0 ) ;
	HRESULT  DumpFunc( IStream* pstm, ITypeInfo* pti, TYPEATTR* pattr, MEMBERID memid, UINT uiIndent  = 0 ) ;
	HRESULT  DeCompileVar( IStream* pstm, ITypeInfo* pti, MEMBERID memid, UINT uiIndent  = 0 ) ;
	HRESULT  DumpVar( IStream* pstm, ITypeInfo* pti, TYPEATTR* pattr, MEMBERID memid, UINT uiIndent  = 0 ) ;
	HRESULT  DeCompileConst( IStream* pstm, ITypeInfo* pti, MEMBERID memid, UINT uiIndent  = 0, BOOL fConst = TRUE  ) ;
	HRESULT  DumpConst( IStream* pstm, ITypeInfo* pti, TYPEATTR* pattr, MEMBERID memid, UINT uiIndent = 0, BOOL fConst = TRUE ) ;
// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTypeLibODLView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTypeLibODLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTypeLibODLView)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
