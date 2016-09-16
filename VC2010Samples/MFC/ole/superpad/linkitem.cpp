// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#include "stdafx.h"
#include "padview.h"
#include "paddoc.h"
#include "paditem.h"
#include "linkitem.h"
#include <limits.h>

IMPLEMENT_DYNAMIC(CPadLinkItem, CEmbeddedItem)

CPadLinkItem::CPadLinkItem(CPadDoc* pContainerDoc, LPCTSTR pszItemName)
	: CEmbeddedItem(pContainerDoc)
{
	CString strItemName(pszItemName);
	SetItemName(strItemName);
	VERIFY( _stscanf_s(strItemName, _T("%d %d"), &m_nBeg, &m_nEnd) == 2 );
}

CPadLinkItem::CPadLinkItem(CPadDoc* pContainerDoc, int nFrom, int nTo)
	: CEmbeddedItem(pContainerDoc)
{
	m_nBeg = nFrom;
	m_nEnd = nTo;
	TCHAR buf[30];
	_stprintf_s(buf, 30, _T("%d %d"), m_nBeg, m_nEnd);
	SetItemName(buf);
}

void CPadLinkItem::OnShow()
{
	CPadDoc* pDoc = (CPadDoc*)GetDocument();
	ENSURE(pDoc != NULL);
	ENSURE_VALID(pDoc);
	ASSERT_KINDOF(CPadDoc, pDoc);
	pDoc->SetSelection(m_nBeg, m_nEnd);

	CEmbeddedItem::OnShow();
}

/////////////////////////////////////////////////////////////////////////////
