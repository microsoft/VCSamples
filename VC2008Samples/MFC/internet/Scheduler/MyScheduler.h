// File: MyScheduler.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#ifndef __MYSCHEDULER_H_
#define __MYSCHEDULER_H_

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CMyScheduler command target

class CMyScheduler : public CObject
{
public:
	CMyScheduler();
	virtual ~CMyScheduler();
	virtual void Serialize( CArchive& ar );
	const CMyScheduler& operator=(const CMyScheduler& scheduler);

	int m_iMonth;
	int m_iDay;
	int m_iYear;
	int m_iStartHour;
	int m_iStartMinutes;
	int m_iEndHour;
	int m_iEndMinutes;
	int m_iId;
	CString m_szTitle;
	CString m_szDescription;

protected:
	DECLARE_SERIAL( CMyScheduler )
};

#endif

/////////////////////////////////////////////////////////////////////////////
