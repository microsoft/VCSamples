/*
 * IADVSINK.CPP
 *
 * Implementation of the IAdviseSink interface for the Data User, Chapter 6
/*

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/*
 * Kraig Brockschmidt, Software Design Engineer
 * Microsoft Systems Developer Relations
 *
 * Internet  :  kraigb@microsoft.com
 * Compuserve:  >INTERNET:kraigb@microsoft.com
 */
#include "stdafx.h"
#include "iview.h"
#include "util.h"
#include "idataobj.h"
#include "iadvsink.h"

/*
 * CImpIAdviseSink::CImpIAdviseSink
 * CImpIAdviseSink::~CImpIAdviseSink
 *
 * Parameters (Constructor):
 *  pAV             LPAPPVARS to the application
 *
 */

CImpIAdviseSink::CImpIAdviseSink( CIDataObjectDlg FAR* lpIDOD )
	{
	m_cRef=0;
	m_pIDOD=lpIDOD;
	return;
	}

CImpIAdviseSink::~CImpIAdviseSink(void)
	{
	m_pIDOD->m_pSink = NULL; // make sure the container knows I've been deleted. SteveBl
	return;
	}




/*
 * CImpIAdviseSink::QueryInterface
 * CImpIAdviseSink::AddRef
 * CImpIAdviseSink::Release
 *
 * Purpose:
 *  IUnknown members for CImpIAdviseSink object.
 */

STDMETHODIMP CImpIAdviseSink::QueryInterface(REFIID riid, LPVOID FAR *ppv)
	{
	*ppv=NULL;

	//Any interface on this object is the object pointer.
	if (IsEqualIID(riid, IID_IUnknown) || IsEqualIID(riid, IID_IAdviseSink))
		*ppv=(LPVOID)this;

	/*
	 * If we actually assign an interface to ppv we need to AddRef it
	 * since we're returning a new pointer.
	 */
	if (NULL!=*ppv)
		{
		((LPUNKNOWN)*ppv)->AddRef();
		return NOERROR;
		}

	return ResultFromScode(E_NOINTERFACE);
	}


STDMETHODIMP_(ULONG) CImpIAdviseSink::AddRef(void)
	{
	return ++m_cRef;
	}


STDMETHODIMP_(ULONG) CImpIAdviseSink::Release(void)
	{
	ULONG   cRefT;

	cRefT=--m_cRef;

	if (0==cRefT)
		delete this;

	return cRefT;
	}




/*
 * IAdviseSink::OnDataChange
 *
 * Purpose:
 *  Notifes the advise sink that data changed in a data object.  On
 *  this message you may request a new data rendering and update your
 *  displays as necessary.  Any data sent to this function is owned
 *  by the caller, not by this advise sink!
 *
 *  All Advise Sink methods should be considered asynchronous and therefore
 *  we should attempt no synchronous calls from within them to an EXE
 *  object.  If we do, we'll get RPC_E_CALLREJECTED as shown below.
 *
 * Parameters:
 *  pFE             LPFORMATETC describing format that changed
 *  pSTM            LPSTGMEDIUM providing the medium in which the data
 *                  is provided.
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CImpIAdviseSink::OnDataChange(LPFORMATETC pFE, LPSTGMEDIUM pSTM)
{
	UINT        cf;

	//See if we're interested
	cf=pFE->cfFormat;

	if (!(DVASPECT_CONTENT & pFE->dwAspect))
		return;

/*
	BOOL        fUsable=TRUE;
	//Check media types
	switch (cf)
	{
	#ifdef UNICODE
		case CF_UNICODETEXT:
	#else
		case CF_TEXT:
	#endif
			fUsable=(BOOL)(TYMED_HGLOBAL & pFE->tymed);
		break;
		case CF_BITMAP:
			fUsable=(BOOL)(TYMED_GDI & pFE->tymed);
		break;

		case CF_METAFILEPICT:
			fUsable=(BOOL)(TYMED_MFPICT & pFE->tymed);
		break;

		default:
		break;
	}

	if (!fUsable)
		return;
*/

	if (NULL==m_pIDOD->m_lpDO)
		return;

	// If we are doing a 'warm link' then the data does not come with the
	// OnDataChange.   Post a message back to ourselves so that we can
	// call GetData when it's convienient
	//
	if (m_pIDOD->m_advf & ADVF_NODATA)
	{
		if (m_pIDOD->m_fDoOnGetDataPosted == FALSE)
		{
			m_pIDOD->m_fDoOnGetDataPosted = TRUE ;
			PostMessage( m_pIDOD->m_hDlg, WM_COMMAND,  IDC_DOGETDATA, 0L ) ;
		}
		return ;
	}

	// for Hot links the data comes with the OnDataChange
	m_pIDOD->GotData( pFE, pSTM ) ;
	return ;
}

/*
 * IAdviseSink::OnViewChange
 *
 * Purpose:
 *  Notifes the advise sink that presentation data changed in the data
 *  object to which we're connected providing the right time to update
 *  displays using such presentations.
 *
 * Parameters:
 *  dwAspect        DWORD indicating which aspect has changed.
 *  lindex          LONG indicating the piece that changed.
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CImpIAdviseSink::OnViewChange(DWORD , LONG )
	{
	return;
	}





/*
 * IAdviseSink::OnRename
 *
 * Purpose:
 *  Informs the advise sink that an IOleObject has been renamed, primarily
 *  when its linked.
 *
 * Parameters:
 *  pmk             LPMONIKER providing the new name of the object
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CImpIAdviseSink::OnRename(LPMONIKER)
	{
	return;
	}






/*
 * IAdviseSink::OnSave
 *
 * Purpose:
 *  Informs the advise sink that the OLE object has been saved
 *  persistently.  The primary purpose of this is for containers that
 *  want to make optimizations for objects that are not in a saved
 *  state, so on this you have to disable such optimizations.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CImpIAdviseSink::OnSave(void)
	{
	return;
	}





/*
 * IAdviseSink::OnClose
 *
 * Purpose:
 *  Informs the advise sink that the OLE object has closed and is
 *  no longer bound in any way.  On this you typically change state
 *  variables and redraw shading, etc.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  None
 */

STDMETHODIMP_(void) CImpIAdviseSink::OnClose(void)
	{
	return;
	}
