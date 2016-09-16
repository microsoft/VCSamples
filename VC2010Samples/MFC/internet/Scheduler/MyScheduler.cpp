// MyScheduler.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "Scheduler.h"
#include "MyScheduler.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyScheduler

/*********************************************************************************************
Constructur: Initializes all the member variables
*********************************************************************************************/
CMyScheduler::CMyScheduler()
{
	m_iMonth = 0;
	m_iDay = 0;
	m_iYear = 0;
	m_iStartHour = 0;
	m_iEndHour = 0;
	m_iStartMinutes = 0;
	m_iEndMinutes = 0;
	m_szTitle = _T("");
	m_szDescription = _T("");
	m_iId = 0;
}

CMyScheduler::~CMyScheduler()
{
}

/////////////////////////////////////////////////////////////////////////////
// CMyScheduler member functions

IMPLEMENT_SERIAL(CMyScheduler,CObject,1)

/*********************************************************************************************
Sequentially loads and stores all the member variables to the archive
*********************************************************************************************/
void CMyScheduler::Serialize( CArchive& ar )
{
	CObject::Serialize( ar );

	if ( ar.IsStoring() )
   {
		ar << m_szTitle << m_iMonth << m_iDay << m_iYear << m_iStartHour << m_iStartMinutes << m_iEndHour << m_iEndMinutes << m_szDescription << m_iId;
   }
   else
   {
		ar >> m_szTitle >> m_iMonth >> m_iDay >> m_iYear >> m_iStartHour >> m_iStartMinutes >> m_iEndHour >> m_iEndMinutes >> m_szDescription >> m_iId; 
   }
}


/*********************************************************************************************
The overloaded assignment operator for the CMyScheduler object
*********************************************************************************************/
const CMyScheduler& CMyScheduler::operator= (const CMyScheduler& scheduler)
{
	if (this != &scheduler)
	{
		m_iMonth = scheduler.m_iMonth;
		m_iDay = scheduler.m_iDay;
		m_iYear = scheduler.m_iYear;
		m_iStartHour = scheduler.m_iStartHour;
		m_iEndHour = scheduler.m_iEndHour;
		m_iStartMinutes = scheduler.m_iStartMinutes;
		m_iEndMinutes = scheduler.m_iEndMinutes;
		m_szTitle = scheduler.m_szTitle;
		m_szDescription = scheduler.m_szDescription;
		m_iId = scheduler.m_iId;
	}
	return *this;
}
