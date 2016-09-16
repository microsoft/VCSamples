// ROWSCRLL.H -- Declaration and Implementation for IRowsetScroll
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#ifndef __ROWSCRLL_H__
#define __ROWSCRLL_H__

template <class T, class RowsetInterface, 
		  class RowClass = CSimpleRow, 
		  class MapClass = CAtlMap < RowClass::KeyType, RowClass* >,
		  class BookmarkKeyType = DBBKMARK, class BookmarkType = DBBKMARK,
		  class BookmarkMapClass = CAtlMap < BookmarkKeyType, BookmarkType > >
class IRowsetScrollImpl : public IRowsetLocateImpl<T, RowsetInterface, RowClass, MapClass, BookmarkKeyType, BookmarkType, BookmarkMapClass >
{
	STDMETHOD (GetApproximatePosition)(HCHAPTER /*hReserved*/, DBBKMARK cbBookmark,
		const BYTE* pBookmark, DBCOUNTITEM* pulPosition, DBCOUNTITEM* pcRows)
	{
		ATLTRACE(_T("IRowsetScrollImpl::GetApproximatePosition"));
		HRESULT hr = E_FAIL;
		T* pT = (T*)this;

		// ValidateBookmarks
		if ((hr = ValidateBookmark(cbBookmark, pBookmark)) != S_OK)
			return hr;

		// Set the rowset to the one specified by pBookmark
		if (cbBookmark != 0)
		{
			DBROWCOUNT iRowsetTemp = *pBookmark;  
			if (*pBookmark == DBBMK_FIRST)
				iRowsetTemp = 1;

			if (*pBookmark == DBBMK_LAST)
				iRowsetTemp = (DBCOUNTITEM)pT->m_rgRowData.GetCount();

			if (pulPosition != NULL)
				*pulPosition = iRowsetTemp;
		}

		if (pcRows != NULL)
			*pcRows = (DBCOUNTITEM)pT->m_rgRowData.GetCount();
		else
		{
			// if pcRows == NULL, then pulPosition is set to NULL
			if (pulPosition != NULL)
				*pulPosition = NULL;
		}

		return S_OK;
	}

	STDMETHOD (GetRowsAtRatio)(HWATCHREGION /*hReserved1*/, HCHAPTER hReserved2,
		DBCOUNTITEM ulNumerator, DBCOUNTITEM ulDenominator, DBROWCOUNT cRows, 
		DBCOUNTITEM* pcRowsObtained, HROW** prghRows)
	{
		ATLTRACE(_T("IRowsetScrollImpl::GetRowsAtRatio"));
		T* pT = (T*)this;

		if (pcRowsObtained == NULL || prghRows == NULL)
			return E_INVALIDARG;

		*pcRowsObtained = 0;
		*prghRows = NULL;

		// Make sure we have a valid ratio
		if ((ulNumerator > ulDenominator) || (ulDenominator == 0))
			return DB_E_BADRATIO;

		// Ensure we don't try to fetch rows backwards if the provider
		// doesn't support it
		if (cRows < 0 && !m_bCanFetchBack)
			return DB_E_CANTFETCHBACKWARDS;

		DBROWOFFSET old_iRowset = m_iRowset;

		if (ulNumerator == 0)
		{
			if (cRows < 0)
				return DB_S_ENDOFROWSET;
			else
				m_iRowset = 0;
		}

		if (ulNumerator == ulDenominator)
		{
			if (cRows < 0)
				m_iRowset = (DBROWOFFSET)pT->m_rgRowData.GetCount();
			else
				return DB_S_ENDOFROWSET;
		}
			
		m_iRowset = (DBROWCOUNT)(ulNumerator / ulDenominator);

		HRESULT hr = GetNextRows(hReserved2, 0, cRows, pcRowsObtained, prghRows);

		m_iRowset = old_iRowset;

		return hr;
	}
};

#endif // __ROWSCRLL_H__
