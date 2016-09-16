// ShapeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Scribble.h"
#include "ShapeDlg.h"


// CRecInfoDlg dialog

IMPLEMENT_DYNAMIC(CRecInfoDlg, CDialog)

CRecInfoDlg::CRecInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecInfoDlg::IDD, pParent)
	, m_posX(0)
	, m_posY(0)
	, m_width(0)
	, m_height(0)
{

}

CRecInfoDlg::~CRecInfoDlg()
{
}

void CRecInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHAPE_POS_X, m_posX);
	DDX_Text(pDX, IDC_SHAPE_POS_Y, m_posY);
	DDX_Text(pDX, IDC_SHAPE_DIM_WIDTH, m_width);
	DDX_Text(pDX, IDC_SHAPE_DIM_HEIGHT, m_height);
}


BEGIN_MESSAGE_MAP(CRecInfoDlg, CDialog)
END_MESSAGE_MAP()


// CCircleInfoDlg dialog

IMPLEMENT_DYNAMIC(CCircleInfoDlg, CDialog)

CCircleInfoDlg::CCircleInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCircleInfoDlg::IDD, pParent)
	, m_posX(0)
	, m_posY(0)
	, m_radius(0)
{

}

CCircleInfoDlg::~CCircleInfoDlg()
{
}

void CCircleInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHAPE_POS_X, m_posX);
	DDX_Text(pDX, IDC_SHAPE_POS_Y, m_posY);
	DDX_Text(pDX, IDC_SHAPE_DIM_RADIUS, m_radius);
}


BEGIN_MESSAGE_MAP(CCircleInfoDlg, CDialog)
END_MESSAGE_MAP()


// CCircleInfoDlg message handlers
