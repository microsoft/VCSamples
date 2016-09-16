// paditem.h : interface of the CEmbeddedItem class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#ifndef __PADITEM_H__
#define __PADITEM_H__

class CPadDoc;
class CPadView;

class CEmbeddedItem : public COleServerItem
{
	DECLARE_DYNAMIC(CEmbeddedItem)

// Constructors
public:
	CEmbeddedItem(CPadDoc* pContainerDoc);

// Attributes
	UINT m_nBeg, m_nEnd;
	CPadDoc* GetDocument() const
		{ return (CPadDoc*) COleServerItem::GetDocument(); }
	CPadView* GetView() const;

// Implementation
public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

protected:
	virtual BOOL OnRenderFileData(LPFORMATETC lpFormatEtc, CFile* pFile);
	virtual void Serialize(CArchive& ar);   // overridden for document i/o

	void SaveToFile(CFile* pFile);
};

#endif  // __PADITEM_H__
