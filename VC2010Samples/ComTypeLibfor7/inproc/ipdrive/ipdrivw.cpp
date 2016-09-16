// ipdrivw.cpp : implementation of the CDriverView class
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
#include "ipdrive.h"

#include "ipdridoc.h"
#include "ipdrivw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDriverView

IMPLEMENT_DYNCREATE(CDriverView, CFormView)

BEGIN_MESSAGE_MAP(CDriverView, CFormView)
    //{{AFX_MSG_MAP(CDriverView)
    ON_BN_CLICKED(ID_LOOKUP, OnLookup)
    ON_BN_CLICKED(ID_REMOVE, OnRemove)
    ON_BN_CLICKED(ID_ADD, OnAdd)
    ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
    ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriverView construction/destruction

CDriverView::CDriverView()
    : CFormView(CDriverView::IDD)
{
    //{{AFX_DATA_INIT(CDriverView)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT

    m_bInitialized = FALSE;
}

CDriverView::~CDriverView()
{
}

void CDriverView::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDriverView)
    DDX_Control(pDX, IDC_EDIT2, m_toValue);
    DDX_Control(pDX, IDC_COMBO3, m_toType);
    DDX_Control(pDX, IDC_EDIT1, m_ctrlValue);
    DDX_Control(pDX, IDC_COMBO2, m_ctrlType);
    //}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDriverView diagnostics

#ifdef _DEBUG
void CDriverView::AssertValid() const
{
    CFormView::AssertValid();
}

void CDriverView::Dump(CDumpContext& dc) const
{
    CFormView::Dump(dc);
}

CDriverDoc* CDriverView::GetDocument() // non-debug version is inline
{
    return STATIC_DOWNCAST(CDriverDoc, m_pDocument);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDriverView message handlers

void CDriverView::OnInitialUpdate() 
{
    GetParentFrame()->RecalcLayout();
    ResizeParentToFit(FALSE);

    CFormView::OnInitialUpdate();

    if (!m_bInitialized)
    {
        m_bInitialized = TRUE;
        GetDlgItem(IDC_CURRENT_COUNT)->GetWindowText(m_strCurrentCount);
    }

    // initialize the form
    m_ctrlType.SetCurSel(0);
    UpdateToNothing();
}

void CDriverView::UpdateToNothing()
{
    UpdateCurrentCount();
    m_toType.SetCurSel(-1);

    CString str;
    str.LoadString(IDS_NOTHING);
    m_toValue.SetWindowText(str);
}

void CDriverView::UpdateCurrentCount()
{
    CDriverDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    CString str;
    str.Format(m_strCurrentCount, pDoc->m_map->Count);
    SetDlgItemText(IDC_CURRENT_COUNT, str);
}

_variant_t CDriverView::GetFromVariant()
{
    CString strValue;
    m_ctrlValue.GetWindowText(strValue);

    // we can just throw it in as a string, then coerce to chosen type
    _variant_t va = (LPCTSTR) strValue, vaTemp;

    try
    {
        vaTemp.ChangeType(max(0, (VARTYPE)m_ctrlType.GetCurSel()), &va);
    }
    catch (_com_error& e)
    {
        dump_com_error(e);
        AfxMessageBox(IDP_INCOMPATIBLE_TYPE_VALUE);
    }
    return vaTemp;
}

_variant_t CDriverView::GetToVariant()
{
    CString strValue;
    m_toValue.GetWindowText(strValue);

    // we can just throw it in as a string, then coerce to chosen type
    _variant_t va = (LPCTSTR) strValue, vaTemp;

    try
    {
        vaTemp.ChangeType(max(0, (VARTYPE)m_toType.GetCurSel()), &va);
    }
    catch (_com_error& e)
    {
        dump_com_error(e);
        AfxMessageBox(IDP_INCOMPATIBLE_TYPE_VALUE);
    }
    return vaTemp;
}
    
void CDriverView::UpdateCurrentVariant(const _variant_t& va)
{
    m_toType.SetCurSel(va.vt);

    _variant_t vaTemp;
    CString str;
    try
    {
        vaTemp.ChangeType(VT_BSTR, &va);
        str = (LPCTSTR) (_bstr_t) vaTemp;
    }
    catch (...)
    {
        str.LoadString(IDS_UNKNOWN);
    }
    
    m_toValue.SetWindowText(str);
}

void CDriverView::OnLookup() 
{
    CDriverDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    _variant_t vaFrom = GetFromVariant();
    _variant_t vaTo = pDoc->m_map->Item[vaFrom];
    UpdateCurrentVariant(vaTo);
}

void CDriverView::OnRemove() 
{
    CDriverDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    _variant_t vaFrom = GetFromVariant();
    pDoc->m_map->RemoveKey(vaFrom);
    
    UpdateToNothing();
    UpdateCurrentCount();
}

void CDriverView::OnAdd() 
{
    CDriverDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    _variant_t vaFrom = GetFromVariant();
    _variant_t vaTo = GetToVariant();
    pDoc->m_map->SetAt(vaFrom, vaTo);
    
    OnLookup();
    UpdateCurrentCount();
}

void CDriverView::OnButton1() 
{
    CDriverDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    long nCount = 0;
    DWORD dwThen = GetTickCount();

    if (GetKeyState(VK_CONTROL) >= 0)
    {
        while (GetTickCount() - dwThen < 5000)
        {
            pDoc->m_map->str1 = _T("Hello, World");
            ++nCount;
        }
    }
    else
    {
        while (GetTickCount() - dwThen < 5000)
        {
            pDoc->m_map->i1 = 1;
            ++nCount;
        }
    }
    CString str, strFormat;
    strFormat.LoadString(IDP_TIMING_RESULT);
    str.Format(strFormat, nCount);
    AfxMessageBox(str);
}

void CDriverView::OnButton2() 
{
    CDriverDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    long nCount = 0;
    DWORD dwThen = GetTickCount();

    if (GetKeyState(VK_CONTROL) >= 0)
    {
        while (GetTickCount() - dwThen < 5000)
        {
            pDoc->m_map->str2 = _T("Hello, World");
            ++nCount;
        }
    }
    else
    {
        while (GetTickCount() - dwThen < 5000)
        {
            pDoc->m_map->i2 = 1;
            ++nCount;
        }
    }
    CString str, strFormat;
    strFormat.LoadString(IDP_TIMING_RESULT);
    str.Format(strFormat, nCount);
    AfxMessageBox(str);
}
