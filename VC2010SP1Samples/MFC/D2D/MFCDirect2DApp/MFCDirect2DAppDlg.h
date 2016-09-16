
// MFCDirect2DAppDlg.h : header file
//

#pragma once

// CMFCDirect2DAppDlg dialog
class CMFCDirect2DAppDlg : public CDialogEx
{
// Construction
public:
	CMFCDirect2DAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCDIRECT2DAPP_DIALOG };

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

// Operations
	CD2DBitmapBrush* CreateGridPatternBrush(CRenderTarget& renderTarget);
	CD2DPathGeometry* CreatePathGeometry(CRenderTarget& renderTarget);

// Overrides:
protected:
//	virtual BOOL OnDraw2D(CHwndRenderTarget& RenderTarget);

	// Example members:
    CD2DTextFormat*				m_pTextFormat;
    CD2DPathGeometry*			m_pPathGeometry;
    CD2DLinearGradientBrush*	m_pLinearGradientBrush;
    CD2DSolidColorBrush*		m_pBlackBrush;
    CD2DBitmapBrush*			m_pGridPatternBitmapBrush;
    CD2DBitmap*					m_pBitmap;
    CD2DBitmap*					m_pAnotherBitmap;
	afx_msg LRESULT OnAfxDraw2D(WPARAM wParam, LPARAM lParam);
};
