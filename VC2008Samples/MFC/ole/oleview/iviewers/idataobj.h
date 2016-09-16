// idataobj.h
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// Header file for the IDataObject interface viewer.
//


#ifndef _IDATAOBJ_H_
#define _IDATAOBJ_H_

int WINAPI GetTextMetricsCorrectly( HDC hDC, LPTEXTMETRIC lpTM ) ;
typedef struct FAR tagCOLUMNSTRUCT
{
   int   nLeft ;       // starting x position of the column
   int   nRight ;      // ending x position of the column
   UINT  uiFlags ;      // format flags

} COLUMNSTRUCT, *PCOLUMNSTRUCT, FAR *LPCOLUMNSTRUCT ;

void WINAPI ColumnTextOut( HDC hdc, int nX, int nY, LPTSTR lpszIN,
							int cColumns, LPCOLUMNSTRUCT rgColumns );
void WINAPI DlgCenter( HWND hwndCenter, HWND hwndWithin, BOOL fClient ) ;

class CImpIAdviseSink ;

#define CCHOUTPUTMAX        8192
#define CLINESMAX           500
#define WM_OUTPUTBUFFERHASDATA      (WM_USER+1000)

/////////////////////////////////////////////////////////////////////////////
// CIDataObjectDlg dialog
//
extern "C"
BOOL CALLBACK fnIDataObjectDlg( HWND hDlg, UINT uiMsg, WPARAM wParam, LPARAM lParam ) ;

class FAR CIDataObjectDlg
{
	friend BOOL CALLBACK fnIDataObjectDlg( HWND hDlg, UINT uiMsg, WPARAM wParam, LPARAM lParam ) ;
	friend class CImpIAdviseSink ;

public:

	CIDataObjectDlg( HWND hwnd, LPDATAOBJECT lpDO, REFIID riid, LPTSTR lpszName ) ;
	~CIDataObjectDlg() ;

	int DoModal( void ) ;

	LPDATAOBJECT    m_lpDO ;
	LPTSTR          m_lpszName ;

	FORMATETC       m_fetc ;
	DWORD           m_advf ;
	BOOL            m_fDoOnGetDataPosted ;

	HWND        m_hWndParent ;
	HWND        m_hDlg ;

	HWND        m_btnDoGetData ;
	HWND        m_btnSetupAdvise ;
	HWND        m_lbGetData ;
	HWND        m_edtAdvise ;
	TCHAR       m_szOutput[CCHOUTPUTMAX] ;
	METAFILEPICT m_MetaFile ;

	UINT        m_cchOutput ;
	UINT        m_cLinesOutput ;

	HWND        m_chkUpdateDisplay ;
	BOOL        m_fUpdateDisplay ;
	HWND        m_chkPrimeFirst ;

	HWND        m_lbFmtEtc ;

	HWND        m_chkDump ;

	DWORD       m_dwTime ;
	DWORD       m_cOnDataChanges ;

	CImpIAdviseSink FAR* m_pSink ;
	DWORD               m_dwConn ;

// Implementation
protected:
	BOOL DoIDataObject( UINT nLevel, LPDATAOBJECT pI ) ;
	BOOL DoIEnumFormatEtc( UINT nLevel, LPENUMFORMATETC pI ) ;

	int AddItem( UINT nLevel, LPTSTR sz, LPVOID lpData, UINT uiType, int cColumns, LPCOLUMNSTRUCT  rgCol ) ;
	int AddItem( UINT nLevel, LPTSTR sz, LPVOID lpData, UINT uiType ) ;
	int AddItem( UINT nLevel, LPTSTR sz, LPVOID lpData ) ;

	BOOL OnInitDialog();

	void OnDoGetData() ;
	HRESULT GotData( LPFORMATETC lpfetc, LPSTGMEDIUM lpstm ) ;
	void OnSetupAdvise() ;
	void OnKillAdvise() ;

	void OnSize(UINT nType, int cx, int cy);
	void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void OnDblClkFormatEtc();
	void OnSelChangeFormatEtc();
	void OnDestroy();
	BOOL  WriteToOutput( LPTSTR lpsz ) ;
	void OnOutputBufferHasData() ;
};

#endif // _IDATAOBJ_H_
