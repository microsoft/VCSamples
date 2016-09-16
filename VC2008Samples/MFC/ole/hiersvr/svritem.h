// svritem.h : interface of the CServerNode class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef _SVRITEM_H
#define _SVRITEM_H

#define CX_MARGIN   8
#define CY_MARGIN   4

#define CX_INDENT   12
#define CX_BACKDENT 5
#define CY_SEPARATOR 4

class CServerDoc;
class CServerItem;

// in this example a CServerNode represents a node in a graph
class CServerNode : public CObject
{
	DECLARE_SERIAL(CServerNode);

// Constructors
public:
	CServerNode(CServerDoc* pServerDoc = NULL);
	static CServerNode* CreateRootNode(CServerDoc* pDoc);
	void InitRootNode();

	// create from parent node
	CServerNode* CreateChildNode(LPCTSTR lpszDescription);
	CServerNode* PromptNewChildNode();  // create with user interface

// Attributes
	CString     m_strDescription;       // node description/caption
	CString     m_strLinkKey;           // link node if different from caption
	CServerItem* m_pServerItem;         // pointer to active item (may be NULL)
	CObList     m_listChild;            // list of children
	BOOL        m_bHideChildren;
	CServerDoc* m_pDocument;            // back pointer to document

	enum EShape
	{
		shapeRect,
		shapeRound,
		shapeOval,
		shapeMax
	} m_shape;      // shape to draw

	CServerDoc* GetDocument() const // return type-safe container
		{ return (CServerDoc*)m_pDocument; }
	BOOL HasChildren() const
		{ return m_listChild.GetCount() != 0; }
	BOOL IsChild(const CServerNode* pPotentialChild) const;
	// for popup context sensitive menus (in IDR_POPUPS)
	int GetPopupMenuIndex()
		{ return 0; }   // 0 for simple menu
	CServerNode* GetNext(CServerNode *pItem, BOOL bInit = TRUE);
	CServerNode* GetPrev(CServerNode *pItem, BOOL bInit = TRUE);
	const CString& GetItemName();
	void UpdateItemName();

// Operations
	// bounding rect helpers
	void CalcNodeSize(CDC* pDC, CSize& sizeNode);

	// drawing helpers
	BOOL Draw(CDC* pDC, CPoint pt, BOOL bSelected, CSize sizeNode);
	BOOL FindAndDelete(CServerNode *pItem);
		// find pItem, remove it and all of its children
	void DeleteChildNodes();    // remove all child nodes from a given node
	CServerNode* FindNode(LPCTSTR pszItemName);

	// recursive bounding rect and drawing helpers
	void CalcBounding(CDC* pDC, CPoint& ptStart, CSize& sizeMax);
	int DrawTree(CDC* pDC, CPoint ptStart, CServerNode* pItemSel);

	// simple UI helpers
	BOOL PromptChangeNode();

	virtual void Serialize(CArchive& ar);        // for native data

// Implementation
public:
	~CServerNode();

protected:
	void SaveAsText(CArchive& ar, int nLevel);

	friend class CServerItem;   // CServerItem is an extension of a CServerNode
};


// CServerItem represents the OLE glue to a CServerNode.  Such items
//  are only allocated as necessary.

class CServerItem : public COleServerItem
{
// Constructors
public:
	CServerItem(CServerDoc* pDoc, CServerNode* pNode);

// Attributes
	CServerNode* m_pServerNode;     // back pointer to node (may be NULL)

	CServerDoc* GetDocument() const // return type-safe container
		{ return (CServerDoc*)COleServerItem::GetDocument(); }

// Overridables
protected:
	virtual void Serialize(CArchive& ar);   // called for clipboard save

	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	virtual void OnOpen();      // select the node when a link is shown

	virtual BOOL OnRenderFileData(LPFORMATETC lpFormatEtc, CFile* pFile);
	virtual COleDataSource* OnGetClipboardData(BOOL bIncludeLink,
		LPPOINT pptOffset, LPSIZE pSize);

// Implementation
public:
	~CServerItem();

protected:
	// GetNativeClipboardData called by overrided OnGetClipboardData
	void GetNativeClipboardData(COleDataSource *pDataSource);

	friend class CServerNode;   // CServerNode is an extension of CServerItem
};

#endif

/////////////////////////////////////////////////////////////////////////////
