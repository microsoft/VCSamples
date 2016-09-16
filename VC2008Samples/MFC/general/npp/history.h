// history.h : interface of the CHistoryList class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//

class CHistoryList : public CStringList
{
// Operations
public:
	void FillCombobox();
	BOOL AddString(CString &s1);

// Implementation
protected:
	void SwapStrings(CWnd* pWnd, CString &s1);
};
