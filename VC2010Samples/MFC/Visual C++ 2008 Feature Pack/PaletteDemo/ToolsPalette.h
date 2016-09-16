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

/////////////////////////////////////////////////////////////////////////////
// CToolsPalette window

class CToolsPalette : public CMFCToolBar
{
// Construction
public:
	CToolsPalette();

// Attributes
public:
	int GetColumns () const
	{
		return m_nColumns;
	}

protected:
	int		m_nColumns;		// Number of palette columns
	CRect	m_rectInfo;		// Additional information area

// Operations
public:
	void SetColumns (int nColumns);

// Overrides
	virtual CSize CalcSize (BOOL bVertDock);
	virtual void AdjustLocations ();
	virtual void DoPaint(CDC* pDC);
	virtual BOOL AllowShowOnList () const		
	{	
		return FALSE;	// Don't show me on the toolbars list
	}

// Implementation
public:
	virtual ~CToolsPalette();

protected:
	DECLARE_MESSAGE_MAP()
};
