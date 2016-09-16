// TESTDLL2.H - Public API exported from 'TESTDLL2.DLL'
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// Note: This sample uses AFX_EXT_CLASS to export an entire class.
// This avoids creating a .DEF file with all the decorated names for
// the class.  Creating a .DEF file is more efficient since the names
// can be exported by ordinal.  To use that method of exporting, much
// like MFC does itself, uncomment the following two lines and add
// the appropriate lines to your .DEF file.

//#undef AFX_DATA
//#define AFX_DATA AFX_EXT_DATA

// Initialize the DLL, register the classes etc
extern "C" AFX_EXT_API void WINAPI InitTestDLL2();

/////////////////////////////////////////////////////////////////////////////
// This DLL exports a general purpose MDIChildWnd that can be used for
//   a list output (stores data in a listbox)
// All the public interfaces are exported in TESTDLL2.DEF

class AFX_EXT_CLASS CListOutputFrame : public CMDIChildWnd
{
private:
	using CMDIChildWnd::Create;

	DECLARE_DYNAMIC(CListOutputFrame)

// Constructors
public:
	// NOTE: always export explicit constructors and destructor to be safe
	CListOutputFrame();
	~CListOutputFrame();
	BOOL Create(LPCTSTR lpszWindowName,
		DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		const RECT& rect = rectDefault,
		CMDIFrameWnd* pParentWnd = NULL);

// Operations
	void Clear();       // clears list
	void AddString(LPCTSTR lpszItem);        // adds to end of list
	void SetBackpointer(CListOutputFrame** ppThis);

// Implementation
protected:
	CMenu       m_menu;         // menu to give to the the MDI Frame
	CDialogBar  m_dlgBar;
	CListBox    m_listBox;
	CListOutputFrame** m_ppThis;  // backpointer to clear when frame destroyed
	HGLOBAL GetTextData();

	//{{AFX_MSG(CListOutputFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEditClear();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

// inlines do not need to be exported
inline void CListOutputFrame::SetBackpointer(CListOutputFrame** ppThis)
	{ m_ppThis = ppThis; }

#undef AFX_DATA
#define AFX_DATA

/////////////////////////////////////////////////////////////////////////////
