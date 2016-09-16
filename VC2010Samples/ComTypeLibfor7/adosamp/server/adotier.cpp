// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Visual C++ Language  Reference and related
// electronic documentation provided with Microsoft Visual C++.
// See these sources for detailed information regarding the
// Microsoft Visual C++ product.

// ADOTier.cpp : Implementation of CADOSampApp and DLL registration.

#include "stdafx.h"
#include "ADOTier.h"

/////////////////////////////////////////////////////////////////////////////
//

// Need two distinct "empty" VARIANTs for Command::Execute
static VARIANT* pvtEmpty = static_cast<VARIANT*> (&vtMissing);
static _variant_t vtMissing2(DISP_E_PARAMNOTFOUND, VT_ERROR);
static VARIANT* pvtEmpty2 = static_cast<VARIANT*> (&vtMissing2);

STDMETHODIMP CADOTier::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IADOTier,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CADOTier::Open(BSTR source, BSTR user, BSTR pwd)
{
	HRESULT hr = m_connection.CreateInstance("ADODB.Connection");
	if (SUCCEEDED(hr))
		hr = m_connection->Open(source, user, pwd,0);
	if (SUCCEEDED(hr))
		hr = m_command.CreateInstance(__uuidof(Command));
	if (SUCCEEDED(hr))
		hr = m_command->putref_ActiveConnection(m_connection);
	if (SUCCEEDED(hr))
		hr = m_recordset.CreateInstance(__uuidof(Recordset));

	return hr;
}

STDMETHODIMP CADOTier::OpenRecordset(VARIANT query)
{
	VARIANT v;
	V_VT(&v) = VT_DISPATCH;
	V_DISPATCH(&v) = (IDispatch*) m_connection;

	// Need the AddRef() as VariantClear() calls Release(), unless fAddRef
	// false indicates we're taking ownership
	//
	V_DISPATCH(&v)->AddRef();

	return m_recordset->Open(query, v, adOpenDynamic, adLockOptimistic, adCmdText);
}

STDMETHODIMP CADOTier::CloseRecordset()
{
	return m_recordset->Close();
}

STDMETHODIMP CADOTier::ExecuteConnection(BSTR query, VARIANT_BOOL bChangeRec)
{
	_Recordset* prec = 0;
	HRESULT hr = m_connection->Execute(query, pvtEmpty, adCmdText, &prec);
	if (SUCCEEDED(hr))
	{
		if (bChangeRec)
			m_recordset = prec;
		else
			prec->Release();
	}
	return hr;
}

STDMETHODIMP CADOTier::ExecuteCommand(VARIANT_BOOL bStoredProcedure, VARIANT_BOOL bChangeRec)
{
	_Recordset* prec = 0;
	HRESULT hr;
	if (bStoredProcedure)
		hr = m_command->Execute(pvtEmpty, pvtEmpty2, adCmdStoredProc, &prec);
	else
		hr = m_command->Execute(pvtEmpty, pvtEmpty2, adCmdText, &prec);
	if (SUCCEEDED(hr))
	{
		if (bChangeRec)
			m_recordset = prec;
		else
			prec->Release();
	}
	return hr;
}

STDMETHODIMP CADOTier::get_CommandText(BSTR * newVal)
{
	return m_command->get_CommandText(newVal);
}

STDMETHODIMP CADOTier::put_CommandText(BSTR newVal)
{
	return m_command->put_CommandText(newVal);
}

STDMETHODIMP CADOTier::AppendParameter(enum DataTypeEnum type, VARIANT value, enum ParameterDirectionEnum where, long size)
{
	_ParameterPtr param;
	HRESULT hr = param.CreateInstance(__uuidof(Parameter));
	if (SUCCEEDED(hr))
		hr = param->put_Type(type);
	if (SUCCEEDED(hr))
		hr = param->put_Value(value);
	if (SUCCEEDED(hr))
		hr = param->put_Direction(where);
	if (SUCCEEDED(hr))
		hr = param->put_Size(size);

	Parameters* params = 0;
	if (SUCCEEDED(hr))
		hr = m_command->get_Parameters(&params);
	if (SUCCEEDED(hr))
		hr = params->Append(param);

	if (SUCCEEDED(hr))
	{
		params->Release();
		param->Release();
	}
	return hr;
}

STDMETHODIMP CADOTier::Update()
{
	return m_recordset->Update();
}

STDMETHODIMP CADOTier::Delete()
{
	return m_recordset->Delete(adAffectCurrent);
}

STDMETHODIMP CADOTier::get_Field(VARIANT idx, VARIANT * newVal)
{
	Fields* fields = 0;
	HRESULT hr = m_recordset->get_Fields(&fields);
	Field* field = 0;
	if (SUCCEEDED(hr))
		hr = fields->get_Item(idx, &field);
	if (SUCCEEDED(hr))
		hr = field->get_Value(newVal);

	if (SUCCEEDED(hr))
	{
		fields->Release();
		field->Release();
	}
	return hr;
}

STDMETHODIMP CADOTier::put_Field(VARIANT idx, VARIANT newVal)
{
	Fields* fields = 0;
	HRESULT hr = m_recordset->get_Fields(&fields);
	Field* field = 0;
	if (SUCCEEDED(hr))
		hr = fields->get_Item(idx, &field);
	if (SUCCEEDED(hr))
		hr = field->put_Value(newVal);

	if (SUCCEEDED(hr))
	{
		fields->Release();
		field->Release();
	}
	return hr;
}

STDMETHODIMP CADOTier::get_FieldCount(long * newVal)
{
	Fields* fields = 0;
	HRESULT hr = m_recordset->get_Fields(&fields);
	if (SUCCEEDED(hr))
		hr = fields->get_Count(newVal);
	if (SUCCEEDED(hr))
		fields->Release();
	return hr;
}

STDMETHODIMP CADOTier::Close()
{
	return m_connection->Close();
}

STDMETHODIMP CADOTier::First()
{
	return m_recordset->MoveFirst();
}

STDMETHODIMP CADOTier::Next()
{
	return m_recordset->MoveNext();
}

STDMETHODIMP CADOTier::Last()
{
	return m_recordset->MoveLast();
}

STDMETHODIMP CADOTier::Prev()
{
	return m_recordset->MovePrevious();
}

STDMETHODIMP CADOTier::get_EOF(VARIANT_BOOL * newVal)
{
	return m_recordset->get_EOF(newVal);
}

STDMETHODIMP CADOTier::get_BOF(VARIANT_BOOL * newVal)
{
	return m_recordset->get_BOF(newVal);
}

STDMETHODIMP CADOTier::ParamQuery(BSTR query, long idx1, BSTR idx2, BSTR idx3)
{
	HRESULT hr = ChangeParameter(0, adInteger, (_variant_t) idx1, adParamInput, -1);
	if (SUCCEEDED(hr))
		hr = ChangeParameter(1, adVarChar, (_variant_t) idx2, adParamInput, 25);
	if (SUCCEEDED(hr))
		hr = ChangeParameter(2, adVarChar, (_variant_t) idx3, adParamInput, 80);
	if (SUCCEEDED(hr))
		hr = m_command->put_CommandText(query);
	_Recordset* prec = 0;
	if (SUCCEEDED(hr))
		hr = m_command->Execute(pvtEmpty, pvtEmpty2, adCmdText, &prec);
	if (SUCCEEDED(hr))
		prec->Release();
	return hr;
}

STDMETHODIMP CADOTier::CallStoredProc(long idx1, BSTR idx2, BSTR idx3)
{
	HRESULT hr = ChangeParameter(0, adInteger, (_variant_t) idx1, adParamInput, 4);
	if (SUCCEEDED(hr))
		hr = ChangeParameter(1, adVarChar, (_variant_t) idx2, adParamInput, 25);
	if (SUCCEEDED(hr))
		hr = ChangeParameter(2, adVarChar, (_variant_t) idx3, adParamInput, 80);
	if (SUCCEEDED(hr))
		hr = m_command->put_CommandText(L"{call MyProc (?, ?, ?)}");
	_Recordset* prec = 0;
	if (SUCCEEDED(hr))
		hr = m_command->Execute(pvtEmpty, pvtEmpty2, adCmdText, &prec);
	if (SUCCEEDED(hr))
		prec->Release();
	return hr;
}

STDMETHODIMP CADOTier::put_StoredProc(BSTR newVal)
{
	if (newVal == NULL)
		newVal = ::SysAllocString(L"create procedure MyProc @i integer, @g varchar(25), @g varchar(80) into Guns (ID, Gun, [Gun Description]) values (@i, @g, @d) return");
	HRESULT hr = m_command->put_CommandText(newVal);
	_Recordset* prec = 0;
	if (SUCCEEDED(hr))
		hr = m_command->Execute(pvtEmpty, pvtEmpty2, adCmdText, &prec);
	if (SUCCEEDED(hr))
		prec->Release();
	return hr;
}


STDMETHODIMP CADOTier::ChangeParameter(long idx, enum DataTypeEnum type, VARIANT value, enum ParameterDirectionEnum where, long size)
{
	Parameters* params = 0;
	HRESULT hr = m_command->get_Parameters(&params);

	_Parameter* param = 0;
	VARIANT v;
	V_VT(&v) = VT_I4;
	V_I4(&v) = idx;
	if (SUCCEEDED(hr))
		hr = params->get_Item(v, &param);

	if (SUCCEEDED(hr))
		hr = param->put_Type(type);
	if (SUCCEEDED(hr))
		hr = param->put_Value(value);
	if (SUCCEEDED(hr))
		hr = param->put_Direction(where);
	if (SUCCEEDED(hr))
		hr = param->put_Size(size);
	if (SUCCEEDED(hr))
	{
		params->Release();
		param->Release();
	}
	return hr;
}

STDMETHODIMP CADOTier::Requery()
{
	return m_recordset->Requery(0);
}

STDMETHODIMP CADOTier::ADORelease()
{
	m_command = 0;
	m_recordset = 0;
	m_connection = 0;
	return S_OK;
}

STDMETHODIMP CADOTier::get_Empty(VARIANT_BOOL * bEmpty)
{
	HRESULT hr = m_recordset->get_EOF(bEmpty);
	if (SUCCEEDED(hr) && bEmpty)
		hr = m_recordset->get_BOF(bEmpty);
	return hr;
}
