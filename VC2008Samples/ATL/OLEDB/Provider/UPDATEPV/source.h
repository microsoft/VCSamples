// source.h : Declaration of the CUpdateSource
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#ifndef __CUpdateSource_H_
#define __CUpdateSource_H_
#include "resource.h"       // main symbols
#include "rowset.h"

#define INIT_CATALOG_Flags ( DBPROPFLAGS_DBINIT | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE )
#define INIT_CATALOG_Type VT_BSTR 

/////////////////////////////////////////////////////////////////////////////
// CDataSource
class ATL_NO_VTABLE CUpdateSource : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CUpdateSource, &CLSID_UpProv>,
	public IDBCreateSessionImpl<CUpdateSource, CUpdateSession>,
	public IDBInitializeImpl<CUpdateSource>,
	public IDBPropertiesImpl<CUpdateSource>,
	public IPersistImpl<CUpdateSource>,
	public IInternalConnectionImpl<CUpdateSource>
{
public:
	HRESULT FinalConstruct()
	{
		return FInit();
	}
DECLARE_REGISTRY_RESOURCEID(IDR_UPPROV)
BEGIN_PROPSET_MAP(CUpdateSource)
	BEGIN_PROPERTY_SET(DBPROPSET_DATASOURCEINFO)
		PROPERTY_INFO_ENTRY(ACTIVESESSIONS)
		PROPERTY_INFO_ENTRY_VALUE(DATASOURCEREADONLY, VARIANT_FALSE)
		PROPERTY_INFO_ENTRY(BYREFACCESSORS)
		PROPERTY_INFO_ENTRY(OUTPUTPARAMETERAVAILABILITY)
		PROPERTY_INFO_ENTRY(PROVIDEROLEDBVER)
		PROPERTY_INFO_ENTRY_VALUE(DSOTHREADMODEL, DBPROPVAL_RT_FREETHREAD)
		PROPERTY_INFO_ENTRY(SUPPORTEDTXNISOLEVELS)
		PROPERTY_INFO_ENTRY(USERNAME)
		PROPERTY_INFO_ENTRY_VALUE(PROVIDERNAME, OLESTR("UPDATEPV.DLL"))
		PROPERTY_INFO_ENTRY(ROWSETCONVERSIONSONCOMMAND)
		PROPERTY_INFO_ENTRY_VALUE(PERSISTENTIDTYPE, DBPROPVAL_PT_GUID_NAME)
		PROPERTY_INFO_ENTRY_VALUE(SQLSUPPORT, DBPROPVAL_SQL_NONE)
//		PROPERTY_INFO_ENTRY_VALUE(DBPROP_DBMSNAME, OLESTR("UpdatePV"))
	END_PROPERTY_SET(DBPROPSET_DATASOURCEINFO)
	BEGIN_PROPERTY_SET(DBPROPSET_DBINIT)
		PROPERTY_INFO_ENTRY(AUTH_PASSWORD)
		PROPERTY_INFO_ENTRY(AUTH_PERSIST_SENSITIVE_AUTHINFO)
		PROPERTY_INFO_ENTRY(AUTH_USERID)
		PROPERTY_INFO_ENTRY(INIT_DATASOURCE)
		PROPERTY_INFO_ENTRY(INIT_HWND)
		PROPERTY_INFO_ENTRY(INIT_LCID)
		PROPERTY_INFO_ENTRY(INIT_LOCATION)
		PROPERTY_INFO_ENTRY(INIT_MODE)
		PROPERTY_INFO_ENTRY(INIT_PROVIDERSTRING)
		PROPERTY_INFO_ENTRY_VALUE(INIT_PROMPT, DBPROMPT_NOPROMPT)
		PROPERTY_INFO_ENTRY_VALUE(INIT_CATALOG, OLESTR("c:\\public\\myData.txt")) // modify the path to point to your default data file
	END_PROPERTY_SET(DBPROPSET_DBINIT)
	CHAIN_PROPERTY_SET(CUpdateSession)
	CHAIN_PROPERTY_SET(CUpdateCommand)
END_PROPSET_MAP()
BEGIN_COM_MAP(CUpdateSource)
	COM_INTERFACE_ENTRY(IDBCreateSession)
	COM_INTERFACE_ENTRY(IDBInitialize)
	COM_INTERFACE_ENTRY(IDBProperties)
	COM_INTERFACE_ENTRY(IPersist)
	COM_INTERFACE_ENTRY(IInternalConnection)
END_COM_MAP()

	///////////////////////////////////////////////////////////////////////
	// Conformance Testing Functions

	virtual HRESULT	IsValidValue(ULONG /*iCurSet*/, DBPROP* pDBProp)
	{
		ATLENSURE(pDBProp != NULL);
		CComVariant var = pDBProp->vValue;

		if (var.vt == VT_BOOL)
		{
			if (var.boolVal != VARIANT_TRUE && var.boolVal != VARIANT_FALSE)
				return S_FALSE;
		}

		switch(pDBProp->dwPropertyID)
		{
		case DBPROP_INIT_MODE:
			{
				long dwMask = ~(DB_MODE_READ | DB_MODE_WRITE | DB_MODE_READWRITE |
								DB_MODE_SHARE_DENY_READ | DB_MODE_SHARE_DENY_WRITE |
								DB_MODE_SHARE_EXCLUSIVE | DB_MODE_SHARE_DENY_NONE);

				if ((pDBProp->vValue.lVal & dwMask) != 0)
					return S_FALSE;
			}
			break;
		case DBPROP_INIT_PROMPT:
			{
				if (pDBProp->vValue.iVal != DBPROMPT_PROMPT &&
					pDBProp->vValue.iVal != DBPROMPT_COMPLETE &&
					pDBProp->vValue.iVal != DBPROMPT_COMPLETEREQUIRED &&
					pDBProp->vValue.iVal != DBPROMPT_NOPROMPT)
					return S_FALSE;
			}
			break;
		default:
			break;
		}
		return S_OK;
	}
public:
};

OBJECT_ENTRY_AUTO(__uuidof(UpProv), CUpdateSource)

#endif //__CUpdateSource_H_