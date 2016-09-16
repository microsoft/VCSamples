#if !defined(AFX_IMEEDIT_H__F425503C_0F3C_4C7D_A2E5_A9A7E35AC07B__INCLUDED_)
#define AFX_IMEEDIT_H__F425503C_0F3C_4C7D_A2E5_A9A7E35AC07B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IMEEdit.h : header file
//

// Define constant for CIMEEdit
#define X_INIT					5		
#define Y_INIT					5
#define FONT_HEIGHT				16
#define FONT_WIDTH				16
#define BUFFERSIZE				30
#define WCHARSIZE				2

// Define language ID
#define LID_TRADITIONAL_CHINESE	0x0404
#define LID_JAPANESE			0x0411
#define LID_KOREAN				0x0412
#define LID_SIMPLIFIED_CHINESE	0x0804

//define custom message
#define WM_SETINPUTLANG	WM_USER + 1
#define WM_SETMODE		WM_USER + 2
#define WM_RESETMODE	WM_USER + 3
#define WM_TOGGLE		WM_USER + 4

/////////////////////////////////////////////////////////////////////////////
// CIMEEdit window

class CIMEEdit : public CEdit
{
// Construction
public:
	CIMEEdit();

// Attributes
protected:
	int		m_xEndPos;					// End position of buffer 
	int		m_xInsertPos;				// Insert position of buffer
	int		m_xCaretPos;				// Caret position of buffer
	int		m_nComSize;					// Composition string size
	int		m_nComCursorPos;			// Current cursor position in composition string
	DWORD	m_nComAttrSize;				// The size of the attribute of the composition string
	int		m_nInvertStart;				// Start position of invert string
	int		m_nInvertEnd;				// End position of invert string
	DWORD	m_dwProperty;				// Property of IME
	UINT	m_nCodePage;				// Code page
	BYTE	m_nCharSet;					// Character set
	HFONT	m_hFont;					// Font
	BOOL	m_fShowInvert;				// If true, sample show invert string 
	BOOL	m_fStat;					// If true, IME composite string
	BYTE	m_bComAttr[BUFFERSIZE+1];	// The attributes of the composition string
	DWORD	m_dwCompCls[BUFFERSIZE+1];	// The composition 
	wchar_t	m_szBuffer[BUFFERSIZE+1];	// Buffer for input string
	wchar_t	m_szComStr[BUFFERSIZE+1];	// Buffer for composition string
	wchar_t	m_szBackup[BUFFERSIZE+1];	// Buffer for backup last string

public:
	wchar_t m_szWFontName[50];			// Font name in UNICODE
	char	m_szMBFontName[50];			// Font name in multibyte
	int		m_nLanguage;				// Internal index of language
	BOOL	m_fIsNT;					// If true, NT. Or Win9X
	BOOL	m_fIsXP;						// if true, Windows XP or higher version
// Operations
public:
	BOOL OnImeComposition(WPARAM wParam,LPARAM lParam);
	void OnImeStartComposition(WPARAM wParam,LPARAM lParam);	
	void OnImeEndComposition(WPARAM wParam,LPARAM lParam);
	int	 InsertCompStr();
	void ShowCaretOnView();
	int  GetWidthOfString(wchar_t*);
	void SetFont(HKL hKeyboardLayout, LPCTSTR szSelectedFont);
	void ClearBuffer();
	int  GetCombinedCharLength(int); 
	void SetCandiDateWindowPos();
	void SetCompositionWindowPos();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIMEEdit)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIMEEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIMEEdit)
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMEEDIT_H__F425503C_0F3C_4C7D_A2E5_A9A7E35AC07B__INCLUDED_)
