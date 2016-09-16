// BmpProp.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

struct BITMAPINFO256 : public BITMAPINFO
{
	RGBQUAD bmiOtherColors[255];
};

/////////////////////////////////////////////////////////////////////////////
// CBitmapProperty command target

class CBitmapProperty : public CDataPathProperty
{
	DECLARE_DYNAMIC(CBitmapProperty)
//Constructor
public:
	CBitmapProperty(COleControl* pControl = NULL);

// Attributes
public:
	CBitmap m_Bitmap;
	CSize m_BitmapSize;
	BITMAPINFO256 m_bmInfo;
	CMemFile m_CacheFile;
	enum DLState
	{
		dlNone,
		dlFileHeader,
		dlInfoHeader,
		dlColorTable,
		dlDone
	} m_dlState;
	int m_nScanLine;
	DWORD m_cbRead;

// Operations
public:
	BOOL ReadStruct(DWORD& rdwSize, void* pb, int cLen);
	int ReadArray(DWORD& rdwSize, void** pb, int cElem, int cMax);


// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapProperty)
	public:
	virtual void ResetData();
	protected:
	virtual void OnDataAvailable(DWORD dwSize, DWORD bscfFlag);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CBitmapProperty)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
public:
	virtual ~CBitmapProperty();
protected:
};

/////////////////////////////////////////////////////////////////////////////
