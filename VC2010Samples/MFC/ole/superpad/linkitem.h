// linkitem.h : interface of the CEmbeddedItem class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#ifndef __LINKITEM_H__
#define __LINKITEM_H__

class CPadDoc;
class CPadView;

class CPadLinkItem : public CEmbeddedItem
{
	DECLARE_DYNAMIC(CPadLinkItem)

// Constructors
public:
	CPadLinkItem(CPadDoc* pContainerDoc, LPCTSTR pszItemName);
	CPadLinkItem(CPadDoc* pContainerDoc, int nFrom, int nTo);

protected:
	virtual void OnShow();
};

#endif  // __LINKITEM_H__
