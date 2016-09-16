// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef __SECURITY_H__
#define __SECURITY_H__

#include "stdafx.h"
#include "resource.h"       // main symbols

#define USERNAMELEN 64

CComBSTR GuidToBstr(REFGUID guid);

class CComSpy;

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
Class:   CSecuritySub
Summary: Security Events Subscriber 
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/ 
class ATL_NO_VTABLE CSecuritySub : 
	public CSysLCESub,
	public IComSecurityEvents
{
public:
	CSecuritySub()
	{
		m_pSpy = NULL;
	}
	CSecuritySub(CComSpy * pSpy)
	{
		m_pSpy = pSpy;
	}

	DECLARE_NOT_AGGREGATABLE(CSecuritySub)
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CSecuritySub)
		COM_INTERFACE_ENTRY(IComSecurityEvents)
		COM_INTERFACE_ENTRY_CHAIN(CSysLCESub)
	END_COM_MAP()

	STDMETHODIMP GetEventType(EventEnum * e){*e = Security;return S_OK;}
	STDMETHODIMP GetEventClass(LPGUID guid){*guid = CLSID_ComServiceEvents;return S_OK;}
	STDMETHODIMP GetInterface(IID* iid){*iid = IID_IComSecurityEvents;return S_OK;}

	STDMETHODIMP OnAuthenticate(  COMSVCSEVENTINFO * pInfo, 
								  REFGUID guidActivity, 
								  ULONG64 ObjectID,
								  REFGUID guidIID, 
								  ULONG iMeth,
								  ULONG cbByteOrig,  
								  BYTE * pSidOriginalUser,
								  ULONG cbByteCur,   
								  BYTE * pSidCurrentUser, 
								  BOOL bCurrentUserInpersonatingInProc
							)
	{

		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnAuthenticate"), GuidToBstr(pInfo->guidApp));
		CComBSTR sGuidActivity = GuidToBstr(guidActivity);
		m_pSpy -> AddParamValueToList(L"guidActivity", sGuidActivity);

		WCHAR sObjId[32];
		wsprintfW(sObjId,L"0x%016X", ObjectID);
		m_pSpy -> AddParamValueToList(L"ObjectID", sObjId);


		CComBSTR sGuidIID = GuidToBstr(guidIID);
		m_pSpy -> AddParamValueToList(L"guidIID", sGuidIID);

		WCHAR sMethod[16];
		wsprintfW(sMethod,L"0x%08X", iMeth);
		m_pSpy -> AddParamValueToList(L"iMeth", sMethod);


		WCHAR sOriginalUser[256];
		ZeroMemory(sOriginalUser, 256*sizeof(WCHAR));

		if (GetDomainSlashUser(pSidOriginalUser, sOriginalUser, RTL_NUMBER_OF(sOriginalUser)))
			m_pSpy -> AddParamValueToList(L"Original User", sOriginalUser);
		else
			m_pSpy -> AddParamValueToList(L"Original User", L"<Error converting SID>");

		WCHAR sDirectUser[256];
		ZeroMemory(sDirectUser, 256*sizeof(WCHAR));

		if (GetDomainSlashUser(pSidCurrentUser, sDirectUser, RTL_NUMBER_OF(sDirectUser)))
			m_pSpy -> AddParamValueToList(L"Direct User", sDirectUser);
		else
			m_pSpy -> AddParamValueToList(L"Direct User", L"<Error converting SID>");

		m_pSpy -> AddParamValueToList(L"Direct User Inpersonating InProc", bCurrentUserInpersonatingInProc ? L"Yes" : L"No");

		
		IF_AUDIT_DO(OnAuthenticate)(pInfo->perfCount,
									GuidToBstr(pInfo->guidApp),
									sGuidActivity,	
									sObjId, 
									sGuidIID, 
									sMethod, 
									sOriginalUser,						
									sDirectUser,			
									bCurrentUserInpersonatingInProc);

		return S_OK;
	}

	STDMETHODIMP OnAuthenticateFail(  COMSVCSEVENTINFO * pInfo, 
								  REFGUID guidActivity, 
								  ULONG64 ObjectID,
								  REFGUID guidIID, 
								  ULONG iMeth,
								  ULONG cbByteOrig,  
								  BYTE * pSidOriginalUser,
								  ULONG cbByteCur,   
								  BYTE * pSidCurrentUser, 
								  BOOL bCurrentUserInpersonatingInProc
							   )
	{

		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnAuthenticateFail"), GuidToBstr(pInfo->guidApp));
		CComBSTR sGuidActivity = GuidToBstr(guidActivity);
		m_pSpy -> AddParamValueToList(L"guidActivity", sGuidActivity);


		WCHAR sObjId[32];
		wsprintfW(sObjId,L"0x%016X", ObjectID);
		m_pSpy -> AddParamValueToList(L"ObjectID", sObjId);

		CComBSTR sGuidIID = GuidToBstr(guidIID);
		m_pSpy -> AddParamValueToList(L"guidIID", sGuidIID);

		WCHAR sMethod[16];
		wsprintfW(sMethod,L"0x%08X", iMeth);
		m_pSpy -> AddParamValueToList(L"iMeth", sMethod);


		WCHAR sOriginalUser[256];
		ZeroMemory(sOriginalUser, 256*sizeof(WCHAR));

		if (GetDomainSlashUser(pSidOriginalUser, sOriginalUser, RTL_NUMBER_OF(sOriginalUser)))
			m_pSpy -> AddParamValueToList(L"Original User", sOriginalUser);
		else
			m_pSpy -> AddParamValueToList(L"Original User", L"<Error converting SID>");

		WCHAR sDirectUser[256];
		ZeroMemory(sDirectUser, 256*sizeof(WCHAR));

		if (GetDomainSlashUser(pSidCurrentUser, sDirectUser, RTL_NUMBER_OF(sDirectUser)))
			m_pSpy -> AddParamValueToList(L"Direct User", sDirectUser);
		else
			m_pSpy -> AddParamValueToList(L"Direct User", L"<Error converting SID>");

		m_pSpy -> AddParamValueToList(L"Direct User Inpersonating InProc", bCurrentUserInpersonatingInProc ? L"Yes" : L"No");

		IF_AUDIT_DO(OnAuthenticateFail)(pInfo->perfCount,
									GuidToBstr(pInfo->guidApp),
									sGuidActivity,	
									sObjId, // objectID
									sGuidIID, //interface ID
									sMethod, //
									sOriginalUser,						
									sDirectUser,			
									bCurrentUserInpersonatingInProc);

		return S_OK;
	}


	BOOL GetDomainSlashUser(
		 PSID Sid,							// in
		 WCHAR* DomainSlashUser,			// out
		 size_t cchDomainSlashUser)			// in
	{
		WCHAR Name[USERNAMELEN + 1];
		DWORD cbName = USERNAMELEN;
		DWORD cbReferencedDomainName = USERNAMELEN;
		SID_NAME_USE eUse;
		ZeroMemory(Name, cbName);
		if (!LookupAccountSid(NULL,	Sid, Name, &cbName, DomainSlashUser, &cbReferencedDomainName, &eUse))
			return FALSE;

		// concat domain\user
		wcscat_s(DomainSlashUser, cchDomainSlashUser, L"\\");
		wcscat_s(DomainSlashUser, cchDomainSlashUser, Name);
		return TRUE;
	}

};

#endif //__SECURITYSUB_H__
