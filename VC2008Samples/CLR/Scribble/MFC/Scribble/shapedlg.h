#pragma once
#include "afxwin.h"


// CRecInfoDlg dialog

class CRecInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CRecInfoDlg)

public:
	CRecInfoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRecInfoDlg();

// Dialog Data
	enum { IDD = IDD_SHAPE_INFO_REC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_posX;
	int m_posY;
	int m_width;
	int m_height;
};
#pragma once


// CCircleInfoDlg dialog

class CCircleInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CCircleInfoDlg)

public:
	CCircleInfoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCircleInfoDlg();

// Dialog Data
	enum { IDD = IDD_SHAPE_INFO_CIR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_posX;
	int m_posY;
	int m_radius;
};
