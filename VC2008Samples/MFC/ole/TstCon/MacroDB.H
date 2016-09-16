// File: MacroDB.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

class CMacroDialogBar :
   public CDialogBar
{
   DECLARE_DYNAMIC( CMacroDialogBar )

public:
   BOOL Create( CWnd* pParent, UINT nStyle, UINT nID );

protected:
   CSize CalcFixedLayout( BOOL tStretch, BOOL tHorz );

protected:
   CMacroComboBox m_cboxMacroName;

protected:
	DECLARE_MESSAGE_MAP()
};
