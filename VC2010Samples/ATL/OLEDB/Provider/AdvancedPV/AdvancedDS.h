// AdvancedDS.h : Declaration of the CAdvancedSource
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#pragma once

#include "resource.h"       // main symbols
#include "AdvancedRS.h"
#include "AdvancedSess.h"

#pragma warning ( disable : 4680 )	//suppress default interface warning

// CAdvancedSource

[
	coclass,
	threading(apartment),
	vi_progid("AdvancedPV.Advanced"),
	progid("AdvancedPV.Advanced.1"),
	version(1.0),
	uuid("55FA2C89-8371-492E-8FD6-AD1ADEFBF539"),
	//default(IDispatch), source(IDBCreateSession),
	helpstring("Advanced Class"),
	registration_script("provider.rgs")
]
class ATL_NO_VTABLE CAdvancedSource : 
	public IDBCreateSessionImpl<CAdvancedSource, CAdvancedSession>,
	public IDBInitializeImpl<CAdvancedSource>,
	public IDBPropertiesImpl<CAdvancedSource>,
	public IPersistImpl<CAdvancedSource>,
	public IInternalConnectionImpl<CAdvancedSource>
{
public:
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return FInit();
	}
	
	void FinalRelease() 
	{
	}


BEGIN_PROPSET_MAP(CAdvancedSource)
	BEGIN_PROPERTY_SET(DBPROPSET_DATASOURCEINFO)
		PROPERTY_INFO_ENTRY(ACTIVESESSIONS)
		PROPERTY_INFO_ENTRY_VALUE(DATASOURCEREADONLY, VARIANT_FALSE)
		PROPERTY_INFO_ENTRY(BYREFACCESSORS)
		PROPERTY_INFO_ENTRY(OUTPUTPARAMETERAVAILABILITY)
		PROPERTY_INFO_ENTRY(PROVIDEROLEDBVER)
		PROPERTY_INFO_ENTRY(DSOTHREADMODEL)
		PROPERTY_INFO_ENTRY(SUPPORTEDTXNISOLEVELS)
		PROPERTY_INFO_ENTRY(USERNAME)
		PROPERTY_INFO_ENTRY_VALUE(PROVIDERNAME, OLESTR("ADVANCEDPV.DLL"))
		PROPERTY_INFO_ENTRY_VALUE(SQLSUPPORT, DBPROPVAL_SQL_NONE)
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
		PROPERTY_INFO_ENTRY(INIT_PROMPT)
		PROPERTY_INFO_ENTRY(INIT_PROVIDERSTRING)
		PROPERTY_INFO_ENTRY(INIT_TIMEOUT)
		PROPERTY_INFO_ENTRY_VALUE(INIT_CATALOG, OLESTR("c:\\public\\DataFile.dat"))
	END_PROPERTY_SET(DBPROPSET_DBINIT)
	CHAIN_PROPERTY_SET(CAdvancedSession)
	CHAIN_PROPERTY_SET(CAdvancedCommand)
END_PROPSET_MAP()

public:
};

