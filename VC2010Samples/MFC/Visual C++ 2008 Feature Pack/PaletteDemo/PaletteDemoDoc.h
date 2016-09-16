// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

class CPaletteDemoDoc : public CDocument
{
protected: // create from serialization only
	CPaletteDemoDoc();
	DECLARE_DYNCREATE(CPaletteDemoDoc)

// Attributes
public:
	UINT	m_uiCurrTool;

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CPaletteDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnPaletteTool(UINT uiCmd);
	afx_msg void OnUpdatePaletteTool(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
};
